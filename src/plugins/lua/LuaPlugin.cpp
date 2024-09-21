#include "LuaPlugin.h"

#include "../../common.h"
#include "../../files/Files.h"
#include "../../commands/CommandsManager.h"
#include "../core/scripting.h"
#include "../PluginManager.h"
#include "../../crashreporter/CallStack.h"

#include <vector>

int luaopen_cmsgpack(lua_State* L);
extern "C"
{
    LUALIB_API int luaopen_rapidjson(lua_State* L);
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

void SetupLuaEnvironment(LuaPlugin* plugin, lua_State* state);
std::string FetchPluginName(lua_State* state);

static int LuaPanicFunction(lua_State* state)
{
    std::string m_what = "Missing Error";
    if (lua_gettop(state) > 0)
    {
        char const* s = lua_tostring(state, -1);
        m_what = s ? s : "";
    }

    PLUGIN_PRINT("Runtime", "A Lua runtime panic has been triggered.\n");
    PLUGIN_PRINTF("Runtime", "Plugin: %s\n", FetchPluginName(state).c_str());
    PLUGIN_PRINTF("Runtime", "Error: %s\n", m_what.c_str());
    return 0;
}

bool LuaPlugin::LoadScriptingEnvironment()
{
    this->SetLoadError("");

    this->state = luaL_newstate();
    const luaL_Reg* lib = lualibs;
    for (; lib->func; lib++)
    {
        luaL_requiref(this->state, lib->name, lib->func, 1);
        lua_pop(this->state, 1);
    }

    SetupLuaEnvironment(this, this->state);

    int loadStatus = luaL_dofile(this->state, "addons/swiftly/bin/scripting/events.lua");

    if (loadStatus != 0)
    {
        std::string error = lua_tostring(this->state, -1);
        PRINTF("Failed to load plugin file '%s'.\n", "addons/swiftly/bin/scripting/events.lua");
        PRINTF("Error: %s\n", error.c_str());

        this->SetLoadError(error);

        lua_pop(this->state, 1);
        return false;
    }

    std::vector<std::string> scriptingFiles = Files::FetchFileNames("addons/swiftly/bin/scripting");
    for (std::string file : scriptingFiles)
    {
        if (file == "addons/swiftly/bin/scripting/events.lua")
            continue;

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

    std::vector<std::string> files = Files::FetchFileNames(g_pluginManager->GetPluginBasePath(this->GetName()) + "/" + this->GetName());
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

    lua_atpanic(this->state, LuaPanicFunction);

    return true;
}

void LuaPlugin::DestroyScriptingEnvironment()
{
    std::vector<std::string> commandNames = g_commandsManager->FetchCommandsByPlugin(this->GetName());
    for (std::string command : commandNames)
        g_commandsManager->UnregisterCommand(command);

    if (this->globalEventHandler)
        delete this->globalEventHandler;

    this->eventHandlers.clear();
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

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    this->PluginTriggerEvent("core", "OnPluginStart", encoders::msgpack::SerializeToString({}), event);
    delete event;

    return true;
}

void LuaPlugin::ExecuteStop()
{
    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    this->PluginTriggerEvent("core", "OnPluginStop", encoders::msgpack::SerializeToString({}), event);
    delete event;
}

void LuaPlugin::ExecuteCommand(void* functionPtr, std::string name, int slot, std::vector<std::string> args, bool silent, std::string prefix)
{
    PERF_RECORD(string_format("command:%s", name.c_str()), this->GetName())

        if (functionPtr == nullptr)
            return;

    luabridge::LuaRef* commandRef = (luabridge::LuaRef*)functionPtr;

    if (!commandRef->isFunction())
        return;

    luabridge::LuaRef command = *commandRef;
    try
    {
        command(slot, args, args.size(), silent, prefix);
    }
    catch (luabridge::LuaException& e)
    {
        PRINTF("An error has occured while executing command '%s'.\n", name.c_str());
        PRINTF("%s\n", e.what());
    }
}

void LuaPlugin::RegisterEventHandler(void* functionPtr)
{
    luabridge::LuaRef* handlerRef = (luabridge::LuaRef*)functionPtr;
    if (!handlerRef->isFunction())
        return;

    this->globalEventHandler = handlerRef;
}

void LuaPlugin::RegisterEventHandling(std::string eventName)
{
    if (this->eventHandlers.find(eventName) == this->eventHandlers.end()) this->eventHandlers.insert(eventName);
}

void LuaPlugin::UnregisterEventHandling(std::string eventName)
{
    auto it = this->eventHandlers.find(eventName);
    if(it != this->eventHandlers.end()) this->eventHandlers.erase(it);
}

EventResult LuaPlugin::PluginTriggerEvent(std::string invokedBy, std::string eventName, std::string eventPayload, PluginEvent* event)
{
    if (this->GetPluginState() == PluginState_t::Stopped && eventName != "OnPluginStart" && eventName != "OnAllPluginsLoaded")
        return EventResult::Continue;

    if (!this->globalEventHandler)
        return EventResult::Continue;

    if (this->eventHandlers.find(eventName) == this->eventHandlers.end())
        return EventResult::Continue;

    if (eventName != "OnGameTick") REGISTER_CALLSTACK(this->GetName(), string_format("Event: %s(invokedBy=\"%s\",payload=\"%s\",event=%p)", eventName.c_str(), invokedBy.c_str(), eventPayload.c_str(), (void*)event));
    PERF_RECORD(string_format("event:%s:%s", invokedBy.c_str(), eventName.c_str()), this->GetName());

    int res = (int)EventResult::Continue;
    try
    {
        luabridge::LuaRef func = *this->globalEventHandler;
        auto result = func(event, invokedBy, eventName, eventPayload);

        if (!result.isNumber())
            return EventResult::Continue;

        res = result.cast<int>();
        if (res < (int)EventResult::Continue || res >(int)EventResult::Handled)
            return EventResult::Continue;
    }
    catch (luabridge::LuaException& e)
    {
        PRINTF("An error has occured: %s\n", e.what());
    }

    return (EventResult)res;
}

std::vector<luabridge::LuaRef> emptyTable;

luabridge::LuaRef LuaSerializeData(std::any data, lua_State* state)
{
    std::any value = data;

    if (!value.has_value())
        return luabridge::LuaRef(state);

    try
    {
        if (value.type() == typeid(const char*))
            return luabridge::LuaRef(state, std::string(std::any_cast<const char*>(value)));
        else if (value.type() == typeid(char*))
            return luabridge::LuaRef(state, std::string(std::any_cast<char*>(value)));
        else if (value.type() == typeid(std::string)) {
            std::string val = std::any_cast<std::string>(value);
            if (starts_with(val, "JSON⇚") && ends_with(val, "⇛")) {
                std::string json = explode(explode(val, "⇚")[1], "⇛")[0];

                luabridge::LuaRef rapidJsonTable = luabridge::getGlobal(state, "json");
                if (!rapidJsonTable["decode"].isFunction())
                    return luabridge::LuaRef(state, emptyTable);

                luabridge::LuaRef decodedResult(state);
                try
                {
                    decodedResult = rapidJsonTable["decode"](json);
                }
                catch (luabridge::LuaException& e)
                {
                    PLUGIN_PRINTF("LuaSerializeData", "An error has occured: %s\n", e.what());
                    return luabridge::LuaRef(state, emptyTable);
                }

                if (decodedResult.isNil())
                    return luabridge::LuaRef(state, emptyTable);

                return decodedResult;
            }
            else return luabridge::LuaRef(state, val);
        }
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
        else if (value.type() == typeid(Color))
            return luabridge::LuaRef(state, std::any_cast<Color>(value));
        else if (value.type() == typeid(Vector2D))
            return luabridge::LuaRef(state, std::any_cast<Vector2D>(value));
        else if (value.type() == typeid(Vector))
            return luabridge::LuaRef(state, std::any_cast<Vector>(value));
        else if (value.type() == typeid(Vector4D))
            return luabridge::LuaRef(state, std::any_cast<Vector4D>(value));
        else if (value.type() == typeid(QAngle))
            return luabridge::LuaRef(state, std::any_cast<QAngle>(value));
        else if (value.type() == typeid(std::nullptr_t))
            return luabridge::LuaRef(state);
        else if (value.type() == typeid(std::vector<std::string>))
        {
            std::vector<std::string> tmpval = std::any_cast<std::vector<std::string>>(value);
            std::string tbl = tmpval[0];

            luabridge::LuaRef load = luabridge::getGlobal(state, "load");
            try
            {
                luabridge::LuaRef loadReturnValue = load(tbl);
                if (!loadReturnValue.isFunction())
                    return luabridge::LuaRef(state, emptyTable);

                luabridge::LuaRef loadFuncRetVal = loadReturnValue();
                if (!loadFuncRetVal.isTable())
                    return luabridge::LuaRef(state, emptyTable);

                return loadFuncRetVal;
            }
            catch (luabridge::LuaException& e)
            {
                PRINTF("Lua Exception: %s\n", e.what());
                return luabridge::LuaRef(state, emptyTable);
            }
        }
        else
        {
            PRINTF("Unknown Data Type: %s\n", value.type().name());
            return luabridge::LuaRef(state);
        }
    }
    catch (std::bad_any_cast& err)
    {
        PRINTF("Invalid casting: %s\n", err.what());
        return luabridge::LuaRef(state);
    }
}

std::any LuaDeserializeData(luabridge::LuaRef ref, lua_State* state)
{
    if (ref.isBool())
        return ref.cast<bool>();
    else if (ref.isNil())
        return nullptr;
    else if (ref.isNumber())
        return ref.cast<int64_t>();
    else if (ref.isString())
        return ref.cast<std::string>();
    else if (ref.isTable())
    {
        luabridge::LuaRef serpentDump = luabridge::getGlobal(state, "serpent")["dump"];
        luabridge::LuaRef serpentDumpReturnValue = serpentDump(ref);

        std::vector<std::string> tmptbl;
        tmptbl.push_back(serpentDumpReturnValue.cast<std::string>());

        return tmptbl;
    }
    else
        return nullptr;
}

std::string LuaPlugin::GetAuthor()
{
    if (this->GetPluginState() == PluginState_t::Stopped)
        return "";

    auto func = luabridge::getGlobal(this->GetState(), "GetPluginAuthor");
    return func().cast<std::string>();
}

std::string LuaPlugin::GetWebsite()
{
    if (this->GetPluginState() == PluginState_t::Stopped)
        return "";

    auto func = luabridge::getGlobal(this->GetState(), "GetPluginWebsite");
    return func().cast<std::string>();
}

std::string LuaPlugin::GetVersion()
{
    if (this->GetPluginState() == PluginState_t::Stopped)
        return "";

    auto func = luabridge::getGlobal(this->GetState(), "GetPluginVersion");
    return func().cast<std::string>();
}

std::string LuaPlugin::GetPlName()
{
    if (this->GetPluginState() == PluginState_t::Stopped)
        return "";

    auto func = luabridge::getGlobal(this->GetState(), "GetPluginName");
    return func().cast<std::string>();
}

int64_t LuaPlugin::GetMemoryUsage()
{
    if (this->GetPluginState() == PluginState_t::Stopped) return 0;
    return (int64_t(lua_gc(this->GetState(), LUA_GCCOUNT, 0)) * 1024) + int64_t(lua_gc(this->GetState(), LUA_GCCOUNTB, 0));
}