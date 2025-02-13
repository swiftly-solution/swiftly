#include "../../core.h"

LoadScriptingComponent(
    files,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginFiles>("Files", state)
            .addConstructor<std::string>()
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

        if(state->GetKind() == ContextKinds::Lua) state->RunCode("files = Files(GetCurrentPluginName())");
        else if(state->GetKind() == ContextKinds::JavaScript) state->RunCode("globalThis.files = Files(GetCurrentPluginName())");
    }
)