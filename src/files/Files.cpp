#include "Files.h"

using namespace std;

bool pathChanges = false;

vector<string> split(string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

string implode(vector<string> elements, string delimiter)
{
    string s;
    for (auto ii = elements.begin(); ii != elements.end(); ++ii)
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
    vector<string> path = split(filesystem::current_path().string(),
#ifdef _WIN32
                                "\\"
#else
                                "/"
#endif
    );

    path.pop_back();
#ifdef _WIN32
    path.pop_back();
#endif

    path.push_back("csgo");

#ifdef _WIN32
    filesystem::current_path(implode(path, "\\"));
#else
    filesystem::current_path(implode(path, "/"));
#endif
}

string Files::Read(string path)
{
    ChangePath();
    g_SMAPI->ConPrintf("%s\n", filesystem::current_path().string().c_str());
    if (!filesystem::exists(path))
    {
        // cout << "Invalid file specified: " << path << endl;
        return "";
    }
    ifstream f(path);
    stringstream strStream;
    strStream << f.rdbuf();
    return strStream.str();
}

std::string Files::getBase(string filePath)
{
    ChangePath();
    vector<string> v = split(filePath, "/");
    v.pop_back();
    return implode(v, "/");
}

void Files::Delete(string path)
{
    ChangePath();
    if (!filesystem::exists(path))
    {
        // cout << "Invalid file specified: " << path << endl;
        return;
    }
    filesystem::remove(path);
}

void Files::Append(string path, string content)
{
    ChangePath();
    filesystem::create_directories(Files::getBase(path));
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
    ofstream File(path, ios_base::app);
    File << date << content << endl;
    File.close();
}

bool Files::ExistsPath(string path)
{
    ChangePath();
    return filesystem::exists(path);
}

bool Files::IsDirectory(string path)
{
    ChangePath();
    return filesystem::is_directory(path);
}