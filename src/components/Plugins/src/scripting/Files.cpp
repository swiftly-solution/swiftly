#include "../../../../common.h"
#include "../../../../files/Files.h"
#include "../../inc/Scripting.h"

SMM_API const char *scripting_Files_Read(const char *path)
{
    if (path == nullptr)
        return "";

    std::string content = Files::Read(path);

    char *result = new char[content.size() + 1];
    strcpy(result, content.c_str());
    return result;
}

SMM_API void scripting_Files_Append(const char *path, const char *content, bool hasdate)
{
    if (path == nullptr || content == nullptr)
        return;

    Files::Append(path, content, hasdate);
}

SMM_API void scripting_Files_Write(const char *path, const char *content, bool hasdate)
{
    if (path == nullptr || content == nullptr)
        return;

    Files::Write(path, content, hasdate);
}

SMM_API void scripting_Files_Delete(const char *path)
{
    if (path == nullptr)
        return;

    Files::Delete(path);
}

SMM_API const char *scripting_Files_GetBase(const char *path)
{
    if (path == nullptr)
        return "";

    std::string content = Files::getBase(path);

    char *result = new char[content.size() + 1];
    strcpy(result, content.c_str());
    return result;
}

SMM_API bool scripting_Files_ExistsPath(const char *path)
{
    if (path == nullptr)
        return false;

    return Files::ExistsPath(path);
}

SMM_API bool scripting_Files_IsDirectory(const char *path)
{
    if (path == nullptr)
        return false;

    return Files::IsDirectory(path);
}

SMM_API const char **scripting_Files_FetchFileNames(const char *path)
{
    if (path == nullptr)
        return {};

    std::vector<std::string> filenames = Files::FetchFileNames(path);

    const char *toSendArgs[512] = {};
    for (uint32_t i = 0; i < filenames.size(); i++)
        toSendArgs[i] = filenames[i].c_str();

    return toSendArgs;
}

SMM_API const char **scripting_Files_FetchDirectories(const char *path)
{
    if (path == nullptr)
        return {};

    std::vector<std::string> directories = Files::FetchDirectories(path);

    const char *toSendArgs[512] = {};
    for (uint32_t i = 0; i < directories.size(); i++)
        toSendArgs[i] = directories[i].c_str();

    return toSendArgs;
}

SMM_API bool scripting_Files_CreateDirectory(const char *path)
{
    if (path == nullptr)
        return false;

    return Files::CreateDirectory(path);
}