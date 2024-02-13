#ifndef _files_h
#define _files_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include "types.h"

typedef const char *(*Plugin_FilesRead)(const char *);
typedef void (*Plugin_FilesAppend)(const char *, const char *, bool);
typedef void (*Plugin_FilesWrite)(const char *, const char *, bool);
typedef void (*Plugin_FilesDelete)(const char *);
typedef const char *(*Plugin_GetBase)(const char *);
typedef bool (*Plugin_ExistsPath)(const char *);
typedef const char **(*Plugin_FetchFileNames)(const char *);

class Files
{
public:
    Files() {}

    const char *Read(const char *path)
    {
        void *files_Read = FetchFunctionPtr(nullptr, "scripting_Files_Read");
        if (files_Read)
            return reinterpret_cast<Plugin_FilesRead>(files_Read)(path);
        else
        {
            NOT_SUPPORTED("scripting_Files_Read");
            return "";
        }
    }

    void Append(const char *path, const char *content, bool hasdate)
    {
        void *files_Append = FetchFunctionPtr(nullptr, "scripting_Files_Append");
        if (files_Append)
            reinterpret_cast<Plugin_FilesAppend>(files_Append)(path, content, hasdate);
        else
            NOT_SUPPORTED("scripting_Files_Append");
    }

    void Write(const char *path, const char *content, bool hasdate)
    {
        void *files_Write = FetchFunctionPtr(nullptr, "scripting_Files_Write");
        if (files_Write)
            reinterpret_cast<Plugin_FilesWrite>(files_Write)(path, content, hasdate);
        else
            NOT_SUPPORTED("scripting_Files_Write");
    }

    void Delete(const char *path)
    {
        void *files_Delete = FetchFunctionPtr(nullptr, "scripting_Files_Delete");
        if (files_Delete)
            reinterpret_cast<Plugin_FilesDelete>(files_Delete)(path);
        else
            NOT_SUPPORTED("scripting_Files_Delete");
    }

    void GetBase(const char *path)
    {
        void *files_GetBase = FetchFunctionPtr(nullptr, "scripting_Files_GetBase");
        if (files_GetBase)
            reinterpret_cast<Plugin_GetBase>(files_GetBase)(path);
        else
            NOT_SUPPORTED("scripting_Files_GetBase");
    }

    bool ExistsPath(const char *path)
    {
        void *files_ExistsPath = FetchFunctionPtr(nullptr, "scripting_Files_ExistsPath");
        if (files_ExistsPath)
            return reinterpret_cast<Plugin_ExistsPath>(files_ExistsPath)(path);
        else
        {
            NOT_SUPPORTED("scripting_Files_ExistsPath");
            return false;
        }
    }

    bool IsDirectory(const char *path)
    {
        void *files_IsDirectory = FetchFunctionPtr(nullptr, "scripting_Files_IsDirectory");
        if (files_IsDirectory)
            return reinterpret_cast<Plugin_ExistsPath>(files_IsDirectory)(path);
        else
        {
            NOT_SUPPORTED("scripting_Files_IsDirectory");
            return false;
        }
    }

    const char **FetchFileNames(const char *path)
    {
        void *files_FetchFileNames = FetchFunctionPtr(nullptr, "scripting_Files_FetchFileNames");
        if (files_FetchFileNames)
            return reinterpret_cast<Plugin_FetchFileNames>(files_FetchFileNames)(path);
        else
        {
            NOT_SUPPORTED("scripting_Files_FetchFileNames");
            return {};
        }
    }

    const char **FetchDirectories(const char *path)
    {
        void *files_FetchDirectories = FetchFunctionPtr(nullptr, "scripting_Files_FetchDirectories");
        if (files_FetchDirectories)
            return reinterpret_cast<Plugin_FetchFileNames>(files_FetchDirectories)(path);
        else
        {
            NOT_SUPPORTED("scripting_Files_FetchDirectories");
            return {};
        }
    }

    bool CreateDirectory(const char *path)
    {
        void *files_CreateDirectory = FetchFunctionPtr(nullptr, "scripting_Files_CreateDirectory");
        if (files_CreateDirectory)
            return reinterpret_cast<Plugin_ExistsPath>(files_CreateDirectory)(path);
        else
        {
            NOT_SUPPORTED("scripting_Files_CreateDirectory");
            return false;
        }
    }
};

export Files *files;

#endif