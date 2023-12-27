#include "../../../inc/Scripting.h"
#include "../../../../../commands/CommandsManager.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

class LuaCommandsClass
{
public:
    LuaCommandsClass() {}
};

void SetupLuaCommands(luacpp::LuaState *state, Plugin *plugin)
{
    auto commandsClass = state->CreateClass<LuaCommandsClass>("Commands").DefConstructor();

    commandsClass.DefMember("Unregister", [](LuaCommandsClass *base, const char *command_name) -> void
                            { scripting_Commands_UnregisterCommand(command_name); })
        .DefMember("Register", [plugin](LuaCommandsClass *base, const char *command_name, const luacpp::LuaObject &function) -> void
                   {
                        if(g_commandsManager->FetchCommand(command_name) != nullptr) return;
                       scripting_Commands_RegisterCommand(plugin->GetName().c_str(), command_name, (void*)0x98246324);
                       if(g_commandsManager->commandsLuaReference.find(std::string(command_name)) == g_commandsManager->commandsLuaReference.end()) {
                        g_commandsManager->commandsLuaReference.insert(std::make_pair(std::string(command_name), luacpp::LuaFunction(function)));
                       } });

    state->DoString("commands = Commands()");

    PRINT("Scripting - Lua", "Commands loaded.\n");
}