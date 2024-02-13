/*
SMM_API bool scripting_Files_CreateDirectory(const char *path)
*/

#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

class LuaFiles
{
public:
    LuaFiles() {}
};

void SetupLuaFiles(luacpp::LuaState *state, Plugin *plugin)
{
    auto filesClass = state->CreateClass<LuaFiles>("Files").DefConstructor();

    filesClass.DefMember("Read", [](LuaFiles *base, const char *path) -> const char *
                         { return scripting_Files_Read(path); })
        .DefMember("Append", [](LuaFiles *base, const char *path, const char *content, bool hasdate) -> void
                   { scripting_Files_Append(path, content, hasdate); })
        .DefMember("Write", [](LuaFiles *base, const char *path, const char *content, bool hasdate) -> void
                   { scripting_Files_Write(path, content, hasdate); })
        .DefMember("Delete", [](LuaFiles *base, const char *path) -> void
                   { scripting_Files_Delete(path); })
        .DefMember("GetBase", [](LuaFiles *base, const char *path) -> const char *
                   { return scripting_Files_GetBase(path); })
        .DefMember("ExistsPath", [](LuaFiles *base, const char *path) -> bool
                   { return scripting_Files_ExistsPath(path); })
        .DefMember("IsDirectory", [](LuaFiles *base, const char *path) -> bool
                   { return scripting_Files_IsDirectory(path); })
        .DefMember("FetchFileNames", [state](LuaFiles *base, const char *path) -> luacpp::LuaTable
                   {
            std::vector<std::string> files = Files::FetchFileNames(path);
            luacpp::LuaTable tbl = state->CreateTable();
            for(int i = 0; i < files.size(); i++) tbl.SetString(i + 1, files[i].c_str());
            
            return tbl; })
        .DefMember("FetchDirectories", [state](LuaFiles *base, const char *path) -> luacpp::LuaTable
                   {
            std::vector<std::string> files = Files::FetchDirectories(path);
            luacpp::LuaTable tbl = state->CreateTable();
            for(int i = 0; i < files.size(); i++) tbl.SetString(i + 1, files[i].c_str());
            
            return tbl; })
        .DefMember("CreateDirectory", [state](LuaFiles *base, const char *path) -> bool
                   { return scripting_Files_CreateDirectory(path); });

    state->DoString("files = Files()");
}