#include "Files.h"

bool pathChanges = false;

void ChangePath()
{
    if (pathChanges)
        return;

    pathChanges = true;
    std::vector<std::string> path = explode(std::filesystem::current_path().string(), WIN_LINUX("\\", "/"));

    path.pop_back();
    path.pop_back();

    path.push_back("csgo");

    std::filesystem::current_path(implode(path, WIN_LINUX("\\", "/")));
}

std::string Files::Read(std::string path)
{
    ChangePath();
    if (!std::filesystem::exists(path))
        return "";

    std::ifstream f(path);
    std::stringstream strStream;
    strStream << f.rdbuf();
    return strStream.str();
}

std::string Files::getBase(std::string filePath)
{
    ChangePath();
    std::vector<std::string> v = explode(filePath, "/");
    v.pop_back();
    return implode(v, "/");
}

void Files::Delete(std::string path)
{
    ChangePath();
    if (!std::filesystem::exists(path))
        return;

    std::filesystem::remove(path);
}

void Files::Append(std::string path, std::string content, bool hasdate)
{
    ChangePath();
    std::filesystem::create_directories(Files::getBase(path));
    time_t now = time(0);
    tm *ltm = localtime(&now);

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
    std::ofstream File(path, std::ios_base::app);
    File << (hasdate ? date : "") << content << std::endl;
    File.close();
}

void Files::Write(std::string path, std::string content, bool hasdate)
{
    ChangePath();
    std::filesystem::create_directories(Files::getBase(path));
    time_t now = time(0);
    tm *ltm = localtime(&now);

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

    std::ofstream File(path, std::ios_base::trunc);
    File << (hasdate ? date : "") << content << std::endl;
    File.close();
}

bool Files::ExistsPath(std::string path)
{
    ChangePath();
    return std::filesystem::exists(path);
}

bool Files::IsDirectory(std::string path)
{
    ChangePath();
    return std::filesystem::is_directory(path);
}

bool Files::CreateDirectory(std::string path)
{
    ChangePath();
    return std::filesystem::create_directory(path);
}

std::vector<std::string> Files::FetchFileNames(std::string path)
{
    ChangePath();

    std::vector<std::string> files;
    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        if (entry.is_directory())
        {
            std::vector<std::string> fls = Files::FetchFileNames(entry.path().string());
            for (auto fl : fls)
                files.push_back(fl);
        }
        else
            files.push_back(entry.path().string());
    }
    return files;
}

std::vector<std::string> Files::FetchDirectories(std::string path)
{
    ChangePath();

    std::vector<std::string> directories;
    for (const auto &entry : std::filesystem::directory_iterator(path))
        if (entry.is_directory())
            directories.push_back(entry.path().string());

    return directories;
}

bool Files::Compress(std::string filePath, std::string outputPath)
{
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
