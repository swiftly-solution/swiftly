#include "../scripting.h"
#include "../../../files/Files.h"

PluginFiles::PluginFiles(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

void PluginFiles::Append(std::string path, std::string content, bool hasdate)
{
    Files::Append(path, content, hasdate);
}

void PluginFiles::Write(std::string path, std::string content, bool hasdate)
{
    Files::Write(path, content, hasdate);
}

std::string PluginFiles::Read(std::string path)
{
    return Files::Read(path);
}

void PluginFiles::Delete(std::string path)
{
    Files::Delete(path);
}

std::string PluginFiles::GetBase(std::string filePath)
{
    return Files::getBase(filePath);
}

bool PluginFiles::ExistsPath(std::string path)
{
    return Files::ExistsPath(path);
}

bool PluginFiles::IsDirectory(std::string path)
{
    return Files::IsDirectory(path);
}

std::vector<std::string> PluginFiles::FetchFileNames(std::string path)
{
    return Files::FetchFileNames(path);
}

std::vector<std::string> PluginFiles::FetchDirectories(std::string path)
{
    return Files::FetchDirectories(path);
}

bool PluginFiles::CreateDirectory(std::string path)
{
    return Files::CreateDirectory(path);
}

bool PluginFiles::Compress(std::string path, std::string output)
{
    return Files::Compress(path, output);
}
bool PluginFiles::Decompress(std::string path, std::string output)
{
    return Files::Decompress(path, output);
}