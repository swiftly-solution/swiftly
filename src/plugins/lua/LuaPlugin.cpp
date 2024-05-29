#include "LuaPlugin.h"

#include "../../common.h"
#include "../../files/Files.h"
#include "../../commands/CommandsManager.h"

void SetupLuaEnvironment(LuaPlugin *plugin, lua_State *state);

bool LuaPlugin::LoadScriptingEnvironment()
{
    this->SetLoadError("");

    this->state = luaL_newstate();
    luaL_openlibs(this->state);

    SetupLuaEnvironment(this, this->state);

    std::vector<std::string> files = Files::FetchFileNames("addons/swiftly/plugins/" + this->GetName());
    for (std::string file : files)
    {
        if (ends_with(file, ".lua"))
        {
            int loadStatus = luaL_dofile(this->state, file.c_str());

            if (loadStatus != 0)
            {
                std::string error = lua_tostring(this->state, -1);
                PRINTF("Failed to load plugin file '%s'.\n", file.c_str());
                PRINTF("Error: %s\n", error.c_str());

                this->SetLoadError(error);

                lua_pop(this->state, 1);
                return false;
            }
        }
    }

    return true;
}

void LuaPlugin::DestroyScriptingEnvironment()
{
    std::vector<std::string> commandNames = g_commandsManager->FetchCommandsByPlugin(this->GetName());
    for (std::string command : commandNames)
        g_commandsManager->UnregisterCommand(command);

    lua_close(this->state);
    this->state = nullptr;
}

bool LuaPlugin::ExecuteStart()
{
    auto PluginAuthor = luabridge::getGlobal(this->state, "GetPluginAuthor");
    if (!PluginAuthor.isFunction())
    {
        PRINTF("Failed to load plugin '%s'.\n", this->GetName().c_str());
        PRINT("Error: Mandatory function 'GetPluginAuthor' is not defined.\n");
        this->SetLoadError("Mandatory function 'GetPluginAuthor' is not defined.");
        return false;
    }

    auto PluginWebsite = luabridge::getGlobal(this->state, "GetPluginWebsite");
    if (!PluginWebsite.isFunction())
    {
        PRINTF("Failed to load plugin '%s'.\n", this->GetName().c_str());
        PRINT("Error: Mandatory function 'GetPluginWebsite' is not defined.\n");
        this->SetLoadError("Mandatory function 'GetPluginWebsite' is not defined.");
        return false;
    }

    auto PluginVersion = luabridge::getGlobal(this->state, "GetPluginVersion");
    if (!PluginVersion.isFunction())
    {
        PRINTF("Failed to load plugin '%s'.\n", this->GetName().c_str());
        PRINT("Error: Mandatory function 'GetPluginVersion' is not defined.\n");
        this->SetLoadError("Mandatory function 'GetPluginVersion' is not defined.");
        return false;
    }

    auto PluginName = luabridge::getGlobal(this->state, "GetPluginName");
    if (!PluginName.isFunction())
    {
        PRINTF("Failed to load plugin '%s'.\n", this->GetName().c_str());
        PRINT("Error: Mandatory function 'GetPluginName' is not defined.\n");
        this->SetLoadError("Mandatory function 'GetPluginName' is not defined.");
        return false;
    }

    return true;
}

void LuaPlugin::ExecuteStop()
{
}

void LuaPlugin::ExecuteCommand(void *functionPtr, std::string name, int slot, std::vector<std::string> args, bool silent)
{
    if (functionPtr == nullptr)
        return;

    luabridge::LuaRef *commandRef = (luabridge::LuaRef *)functionPtr;

    if (!commandRef->isFunction())
        return;

    luabridge::LuaRef command = *commandRef;
    command(slot, args, args.size(), silent);
}