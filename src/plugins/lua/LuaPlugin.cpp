#include "LuaPlugin.h"

#include "../../common.h"
#include "../../files/Files.h"
#include "../../commands/CommandsManager.h"

int luaopen_cmsgpack(lua_State *L);
extern "C"
{
    LUALIB_API int luaopen_rapidjson(lua_State *L);
}

static const luaL_Reg lualibs[] = {
    {"_G", luaopen_base},
    {LUA_TABLIBNAME, luaopen_table},
    {LUA_STRLIBNAME, luaopen_string},
    {LUA_MATHLIBNAME, luaopen_math},
    {LUA_DBLIBNAME, luaopen_debug},
    {LUA_COLIBNAME, luaopen_coroutine},
    {LUA_UTF8LIBNAME, luaopen_utf8},
    {LUA_IOLIBNAME, luaopen_io},
    {LUA_OSLIBNAME, luaopen_os},
    {"msgpack", luaopen_cmsgpack},
    {"json", luaopen_rapidjson},
    {NULL, NULL},
};

void SetupLuaEnvironment(LuaPlugin *plugin, lua_State *state);

bool LuaPlugin::LoadScriptingEnvironment()
{
    this->SetLoadError("");

    this->state = luaL_newstate();
    const luaL_Reg *lib = lualibs;
    for (; lib->func; lib++)
    {
        luaL_requiref(this->state, lib->name, lib->func, 1);
        lua_pop(this->state, 1);
    }

    SetupLuaEnvironment(this, this->state);

    std::vector<std::string> scriptingFiles = Files::FetchFileNames("addons/swiftly/bin/scripting");
    for (std::string file : scriptingFiles)
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

    luabridge::setGlobal(this->state, NULL, "AddGlobalEvents");

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

    if (this->globalEventHandler)
        delete this->globalEventHandler;

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

void LuaPlugin::RegisterEventHandler(void *functionPtr)
{
    luabridge::LuaRef *handlerRef = (luabridge::LuaRef *)functionPtr;
    if (!handlerRef->isFunction())
        return;

    this->globalEventHandler = handlerRef;
}

void LuaPlugin::RegisterEventHandling(std::string eventName)
{
    if (this->eventHandlers.find(eventName) == this->eventHandlers.end())
        this->eventHandlers.insert({eventName, true});
}

EventResult LuaPlugin::TriggerEvent(std::string invokedBy, std::string eventName, std::string eventPayload, PluginEvent *event)
{
    if (!this->globalEventHandler)
        return EventResult::Continue;

    if (this->eventHandlers.find(eventName) == this->eventHandlers.end())
        return EventResult::Continue;

    int res = (int)EventResult::Continue;
    try
    {
        luabridge::LuaRef func = *this->globalEventHandler;
        auto result = func(event, invokedBy, eventName, eventPayload);

        if (!result.isNumber())
            return EventResult::Continue;

        res = result.cast<int>();
        if (res < (int)EventResult::Continue || res > (int)EventResult::Handled)
            return EventResult::Continue;
    }
    catch (luabridge::LuaException &e)
    {
        PRINTF("An error has occured: %s\n", e.what());
    }

    return (EventResult)res;
}

luabridge::LuaRef LuaSerializeData(std::any data, lua_State *state)
{
    std::any value = data;

    if (!value.has_value())
        return luabridge::LuaRef(state);

    try
    {
        if (value.type() == typeid(const char *))
            return luabridge::LuaRef(state, std::any_cast<const char *>(value));
        else if (value.type() == typeid(std::string))
            return luabridge::LuaRef(state, std::any_cast<std::string>(value));
        else if (value.type() == typeid(uint64))
            return luabridge::LuaRef(state, std::any_cast<uint64>(value));
        else if (value.type() == typeid(uint32))
            return luabridge::LuaRef(state, std::any_cast<uint32>(value));
        else if (value.type() == typeid(unsigned long))
            return luabridge::LuaRef(state, std::any_cast<unsigned long>(value));
        else if (value.type() == typeid(uint16))
            return luabridge::LuaRef(state, std::any_cast<uint16>(value));
        else if (value.type() == typeid(uint8))
            return luabridge::LuaRef(state, std::any_cast<uint8>(value));
        else if (value.type() == typeid(int64))
            return luabridge::LuaRef(state, std::any_cast<int64>(value));
        else if (value.type() == typeid(int32))
            return luabridge::LuaRef(state, std::any_cast<int32>(value));
        else if (value.type() == typeid(long))
            return luabridge::LuaRef(state, std::any_cast<long>(value));
        else if (value.type() == typeid(int16))
            return luabridge::LuaRef(state, std::any_cast<int16>(value));
        else if (value.type() == typeid(int8))
            return luabridge::LuaRef(state, std::any_cast<int8>(value));
        else if (value.type() == typeid(bool))
            return luabridge::LuaRef(state, std::any_cast<bool>(value));
        else if (value.type() == typeid(float))
            return luabridge::LuaRef(state, std::any_cast<float>(value));
        else if (value.type() == typeid(double))
            return luabridge::LuaRef(state, std::any_cast<double>(value));
        else if (value.type() == typeid(std::nullptr_t))
            return luabridge::LuaRef(state);
        else
        {
            PRINTF("Unknown Data Type: %s\n", value.type().name());
            return luabridge::LuaRef(state);
        }
    }
    catch (std::bad_any_cast &err)
    {
        PRINTF("Invalid casting: %s\n", err.what());
        return luabridge::LuaRef(state);
    }
}