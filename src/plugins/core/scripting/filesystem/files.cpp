#include "../../scripting.h"
#include "../../../../filesystem/files/Files.h"

PluginFiles::PluginFiles(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

void PluginFiles::Append(std::string path, std::string content, bool hasdate)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginFiles::Append(path=\"%s\", hasdate=%d)", path.c_str(), hasdate));
    Files::Append(path, content, hasdate);
}

void PluginFiles::Write(std::string path, std::string content, bool hasdate)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginFiles::Write(path=\"%s\", hasdate=%d)", path.c_str(), hasdate));
    Files::Write(path, content, hasdate);
}

std::string PluginFiles::Read(std::string path)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginFiles::Read(path=\"%s\")", path.c_str()));
    return Files::Read(path);
}

void PluginFiles::Delete(std::string path)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginFiles::Delete(path=\"%s\")", path.c_str()));
    Files::Delete(path);
}

std::string PluginFiles::GetBase(std::string filePath)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginFiles::GetBase(filePath=\"%s\")", filePath.c_str()));
    return Files::getBase(filePath);
}

bool PluginFiles::ExistsPath(std::string path)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginFiles::ExistsPath(path=\"%s\")", path.c_str()));
    return Files::ExistsPath(path);
}

bool PluginFiles::IsDirectory(std::string path)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginFiles::IsDirectory(path=\"%s\")", path.c_str()));
    return Files::IsDirectory(path);
}

std::vector<std::string> PluginFiles::FetchFileNames(std::string path)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginFiles::FetchFileNames(path=\"%s\")", path.c_str()));
    return Files::FetchFileNames(path);
}

std::vector<std::string> PluginFiles::FetchDirectories(std::string path)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginFiles::FetchDirectories(path=\"%s\")", path.c_str()));
    return Files::FetchDirectories(path);
}

bool PluginFiles::CreateDirectory(std::string path)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginFiles::CreateDirectory(path=\"%s\")", path.c_str()));
    return Files::CreateDirectory(path);
}

bool PluginFiles::Compress(std::string path, std::string output)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginFiles::Compress(path=\"%s\", output=\"%s\")", path.c_str(), output.c_str()));
    return Files::Compress(path, output);
}

bool PluginFiles::Decompress(std::string path, std::string output)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginFiles::Decompress(path=\"%s\", output=\"%s\")", path.c_str(), output.c_str()));
    return Files::Decompress(path, output);
}
