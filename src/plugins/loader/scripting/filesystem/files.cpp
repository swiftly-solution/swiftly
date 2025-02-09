#include "../../core.h"

LoadScriptingComponent(
    files,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .beginClass<PluginFiles>("Files")
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
            .endClass()
            .addConstant("files", new PluginFiles(FetchPluginName(state)));
    }
)