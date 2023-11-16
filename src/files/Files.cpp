#include "Files.h"

bool pathChanges = false;

std::vector<std::string> explode(std::string s, std::string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

std::string implode(std::vector<std::string> elements, std::string delimiter)
{
    std::string s;
    for (std::vector<std::string>::iterator ii = elements.begin(); ii != elements.end(); ++ii)
    {
        s += (*ii);
        if (ii + 1 != elements.end())
        {
            s += delimiter;
        }
    }
    return s;
}

void ChangePath()
{
    if (pathChanges)
        return;

    pathChanges = true;
    std::vector<std::string> path = explode(std::filesystem::current_path().string(), WIN_LINUX("\\", "/"));

    path.pop_back();
#ifdef _WIN32
    path.pop_back();
#endif

    path.push_back("csgo");

    PRINTF("Files", "%s\n", implode(path, WIN_LINUX("\\", "/")).c_str());

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

void Files::Append(std::string path, std::string content)
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
    snprintf(date, sizeof(date), "[%02d/%02d/%04d - %02d:%02d:%02d] ", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
#if GCC_COMPILER
#pragma GCC diagnostic pop
#endif
    std::ofstream File(path, std::ios_base::app);
    File << date << content << std::endl;
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