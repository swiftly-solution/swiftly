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
        REGISTER_METHOD(const char *, "", scripting_Files_Read, path);
    }

    void Append(const char *path, const char *content, bool hasdate)
    {
        REGISTER_METHOD_VOID(scripting_Files_Append, path, content, hasdate)
    }

    void Write(const char *path, const char *content, bool hasdate)
    {
        REGISTER_METHOD_VOID(scripting_Files_Write, path, content, hasdate)
    }

    void Delete(const char *path)
    {
        REGISTER_METHOD_VOID(scripting_Files_Delete, path)
    }

    const char *GetBase(const char *path)
    {
        REGISTER_METHOD(const char *, "", scripting_Files_GetBase, path);
    }

    bool ExistsPath(const char *path)
    {
        REGISTER_METHOD(bool, false, scripting_Files_ExistsPath, path);
    }

    bool IsDirectory(const char *path)
    {
        REGISTER_METHOD(bool, false, scripting_Files_IsDirectory, path);
    }

    const char **FetchFileNames(const char *path)
    {
        REGISTER_METHOD(const char **, {}, scripting_Files_FetchFileNames, path);
    }

    const char **FetchDirectories(const char *path)
    {
        REGISTER_METHOD(const char **, {}, scripting_Files_FetchDirectories, path);
    }

    bool CreateDirectory(const char *path)
    {
        REGISTER_METHOD(bool, false, scripting_Files_CreateDirectory, path);
    }
};

export Files *files;

#endif