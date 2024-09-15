#include "../core.h"

void SetupLuaFiles(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<PluginFiles>("Files")
        .addConstructor<void (*)(std::string)>()
        .addFunction("Append", &PluginFiles::Append)
        .addFunction("CreateDirectory", &PluginFiles::CreateDirectory)
        .addFunction("Delete", &PluginFiles::Delete)
        .addFunction("ExistsPath", &PluginFiles::ExistsPath)
        .addFunction("FetchDirectories", &PluginFiles::FetchDirectories)
        .addFunction("FetchFileNames", &PluginFiles::FetchFileNames)
        .addFunction("GetBase", &PluginFiles::GetBase)
        .addFunction("IsDirectory", &PluginFiles::IsDirectory)
        .addFunction("Read", &PluginFiles::Read)
        .addFunction("Write", &PluginFiles::Write)
        .addFunction("Compress", &PluginFiles::Compress)
        .addFunction("Decompress", &PluginFiles::Decompress)
        .endClass();

    luaL_dostring(state, "files = Files(GetCurrentPluginName())");
}