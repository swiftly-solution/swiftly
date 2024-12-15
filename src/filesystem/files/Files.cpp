#include "Files.h"

std::string GeneratePath(std::string path)
{
    return string_format("%s%scsgo%s%s", Plat_GetGameDirectory(), WIN_LINUX("\\", "/"), WIN_LINUX("\\", "/"), path.c_str());
}

std::string GetRelativePath(std::string path)
{
    return replace(path, string_format("%s%scsgo%s", Plat_GetGameDirectory(), WIN_LINUX("\\", "/"), WIN_LINUX("\\", "/")), "");
}

std::string Files::Read(std::string path)
{
    path = GeneratePath(path);
    if (!std::filesystem::exists(path))
        return "";

    auto fp = std::fopen(path.c_str(), "rb");
    std::string s;
    std::fseek(fp, 0u, SEEK_END);
    auto size = std::ftell(fp);
    std::fseek(fp, 0u, SEEK_SET);
    s.resize(size);
    std::fread(&s[0], 1u, size, fp);
    std::fclose(fp);
    return s;
}

std::string Files::getBase(std::string filePath)
{
    std::vector<std::string> v = explode(filePath, "/");
    v.pop_back();
    return implode(v, "/");
}

void Files::Delete(std::string path)
{
    path = GeneratePath(path);
    if (!std::filesystem::exists(path))
        return;

    std::filesystem::remove(path);
}

void Files::Append(std::string path, std::string content, bool hasdate)
{
    if(!Files::ExistsPath(Files::getBase(path)) && Files::getBase(path) != "") std::filesystem::create_directories(Files::getBase(GeneratePath(path)));

    time_t now = time(0);
    tm* ltm = localtime(&now);

    char date[32];

#if GCC_COMPILER
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-truncation"
#endif
    if (hasdate)
        snprintf(date, sizeof(date), "[%02d/%02d/%04d - %02d:%02d:%02d] ", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
#if GCC_COMPILER
#pragma GCC diagnostic pop
#endif
    std::ofstream File(GeneratePath(path), std::ios_base::app);
    File << (hasdate ? date : "") << content << std::endl;
    File.close();
}

void Files::Write(std::string path, std::string content, bool hasdate)
{
    if(!Files::ExistsPath(Files::getBase(path)) && Files::getBase(path) != "") std::filesystem::create_directories(Files::getBase(GeneratePath(path)));
    time_t now = time(0);
    tm* ltm = localtime(&now);

    char date[32];

#if GCC_COMPILER
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-truncation"
#endif
    if (hasdate)
        snprintf(date, sizeof(date), "[%02d/%02d/%04d - %02d:%02d:%02d] ", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
#if GCC_COMPILER
#pragma GCC diagnostic pop
#endif

    std::ofstream File(GeneratePath(path), std::ios_base::trunc);
    File << (hasdate ? date : "") << content << std::endl;
    File.close();
}

bool Files::ExistsPath(std::string path)
{
    path = GeneratePath(path);
    return std::filesystem::exists(path);
}

bool Files::IsDirectory(std::string path)
{
    path = GeneratePath(path);
    return std::filesystem::is_directory(path);
}

bool Files::CreateDirectory(std::string path)
{
    path = GeneratePath(path);
    return std::filesystem::create_directory(path);
}

std::vector<std::string> Files::FetchFileNames(std::string path)
{
    std::vector<std::string> files;
    if (!ExistsPath(path))
        return files;
    if (!IsDirectory(path))
        return files;

    path = GeneratePath(path);
    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        if (entry.is_directory())
        {
            std::vector<std::string> fls = Files::FetchFileNames(GetRelativePath(entry.path().string()));
            for (auto fl : fls)
                files.push_back(fl);
        }
        else
            files.push_back(GetRelativePath(entry.path().string()));
    }
    return files;
}

std::vector<std::string> Files::FetchDirectories(std::string path)
{
    std::vector<std::string> directories;
    if (!ExistsPath(path))
        return directories;
    if (!IsDirectory(path))
        return directories;

    path = GeneratePath(path);
    for (const auto& entry : std::filesystem::directory_iterator(path))
        if (entry.is_directory())
            directories.push_back(GetRelativePath(entry.path().string()));

    return directories;
}

bool Files::Compress(std::string filePath, std::string outputPath)
{
    filePath = GeneratePath(filePath);
    outputPath = GeneratePath(outputPath);

    std::ifstream inFile(filePath, std::ios_base::binary);
    std::ofstream outFile(outputPath, std::ios_base::binary);

    if (!inFile || !outFile)
    {
        PRINT("Couldn't create read and write streams.\n");
        return false;
    }

    std::vector<char> inBuffer((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close();

    unsigned int outSize = inBuffer.size() * 1.01 + 600;
    std::vector<char> outBuffer(outSize);

    int result = BZ2_bzBuffToBuffCompress(outBuffer.data(), &outSize, inBuffer.data(), inBuffer.size(), 9, 0, 30);

    if (result != BZ_OK)
    {
        PRINTF("Compression failed. Error code: %d\n", result);
        return false;
    }

    outFile.write(outBuffer.data(), outSize);
    outFile.close();

    return true;
}

bool Files::Decompress(std::string filePath, std::string outputPath)
{
    filePath = GeneratePath(filePath);
    outputPath = GeneratePath(outputPath);

    std::ifstream inFile(filePath, std::ios_base::binary);
    std::ofstream outFile(outputPath, std::ios_base::binary);

    if (!inFile || !outFile)
    {
        PRINT("Couldn't create read and write streams.\n");
        return false;
    }

    std::vector<char> inBuffer((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close();

    unsigned int outSize = inBuffer.size() * 10;
    std::vector<char> outBuffer(outSize);

    int result = BZ2_bzBuffToBuffDecompress(outBuffer.data(), &outSize, inBuffer.data(), inBuffer.size(), 0, 0);

    if (result != BZ_OK)
    {
        PRINTF("Decompression failed. Error code: %d\n", result);
        return false;
    }

    outFile.write(outBuffer.data(), outSize);
    outFile.close();

    return true;
}
