#ifndef _lua_plugin_h
#define _lua_plugin_h

#include <luacpp/luacpp.h>

#include "../Plugin.h"

extern std::map<std::string, std::map<std::string, std::vector<luacpp::LuaObject>>> lua_game_events;

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
    {"json", luaopen_rapidjson},
    {NULL, NULL},
};

class LuaPlugin : public Plugin
{
private:
    luacpp::LuaState *luaState;
    lua_State *rawLuaState;
    std::map<std::string, luacpp::LuaObject> luaFunctions;
    std::map<std::string, luacpp::LuaObject> luaExportedFunctions;

    void RegisterFunction(std::string function)
    {
        if (this->luaState)
        {
            luacpp::LuaObject obj = this->luaState->Get(function.c_str());

            if (obj.GetType() == LUA_TFUNCTION)
                this->luaFunctions.insert(std::make_pair(function, obj));
        }
    }

    bool InternalLoadPlugin()
    {
        this->rawLuaState = luaL_newstate();
        const luaL_Reg *lib = lualibs;
        for (; lib->func; lib++)
        {
            luaL_requiref(this->rawLuaState, lib->name, lib->func, 1);
            lua_pop(this->rawLuaState, 1);
        }

        this->HasNextTick = false;
        this->HasTimeout = false;
        this->HasTimers = false;

        this->luaState = new luacpp::LuaState(this->rawLuaState, false);

        std::vector<std::string> files = Files::FetchFileNames(this->m_path);
        for (std::string file : files)
        {
            if (!ends_with(file, ".lua"))
                continue;

            std::string content = Files::Read(file);

            if (!this->HasNextTick && content.find("NextTick") != std::string::npos)
                this->HasNextTick = true;
            if (!this->HasTimeout && content.find("SetTimeout") != std::string::npos)
                this->HasTimeout = true;
            if (!this->HasTimers && content.find("timers:create") != std::string::npos)
                this->HasTimers = true;
        }

        SetupLuaEnvironment(this->luaState, this);
        for (std::string file : files)
        {
            if (!ends_with(file, ".lua"))
                continue;

            std::string errstr;
            if (!this->luaState->DoFile(file.c_str(), &errstr, nullptr))
            {
                PRINTF("LoadPlugin", "Failed to load plugin file '%s'\nError: %s\n", file.c_str(), errstr.c_str());
                this->err = errstr;
                this->StopPlugin();
                return false;
            }
        }

        return true;
    }

public:
    LuaPlugin(std::string path, std::string name, PluginType_t pluginType) : Plugin(path, name, pluginType) {}

    bool FunctionExists(std::string function)
    {
        if (std::find(funcsToLoad.begin(), funcsToLoad.end(), function) != funcsToLoad.end())
            function = "Internal_" + function;

        return (this->luaFunctions.find(function) != this->luaFunctions.end());
    }

    luacpp::LuaObject FetchLuaFunction(std::string function)
    {
        return this->luaFunctions.at(function);
    }

    template <typename T, typename... Args>
    void ExecuteFunction(std::string function, Args &&...args)
    {
        std::string original_func = function;
        if (!this->FunctionExists(function))
            return;

        if (std::find(funcsToLoad.begin(), funcsToLoad.end(), function) != funcsToLoad.end())
            function = "Internal_" + function;

        luacpp::LuaObject func = this->FetchLuaFunction(function);

        LuaFuncWrapper wrapper(func);
        wrapper.PrepForExec();
        luacpp::PushValues(wrapper.GetML(), std::forward<Args>(args)...);
        wrapper.ExecuteNoReturn(original_func, sizeof...(Args));
    }

    template <typename Ret, typename T, typename... Args>
    Ret ExecuteFunctionWithReturn(std::string function, Args &&...args)
    {
        std::string original_func = function;
        if (!this->FunctionExists(function))
            return (Ret) false;

        if (std::find(funcsToLoad.begin(), funcsToLoad.end(), function) != funcsToLoad.end())
            function = "Internal_" + function;

        luacpp::LuaObject func = this->FetchLuaFunction(function);

        LuaFuncWrapper wrapper(func);
        wrapper.PrepForExec();
        luacpp::PushValues(wrapper.GetML(), std::forward<Args>(args)...);
        return wrapper.ExecuteWithReturn<Ret>(original_func, sizeof...(Args));
    }

    luacpp::LuaState *GetLuaState() { return this->luaState; }
    lua_State *GetLuaRawState() { return this->rawLuaState; }

    void *FetchCPPFunction(std::string function) { return nullptr; }

    void DestroyPluginEnvironment()
    {
        this->luaFunctions.clear();
        this->luaExportedFunctions.clear();
        if (lua_game_events.find(this->GetName()) != lua_game_events.end())
            lua_game_events.erase(this->GetName());
    }

    std::any ExecuteExport(std::string export_name, std::vector<std::any> data)
    {
        if (this->luaExportedFunctions.find(export_name) == this->luaExportedFunctions.end())
            return nullptr;

        luacpp::LuaTable tbl = this->luaState->GetTable("expFuncCache");
        luacpp::LuaObject funcObj = tbl.Get(export_name.c_str());
        if (funcObj.GetType() != LUA_TFUNCTION)
            return nullptr;

        LuaFuncWrapper funcWrap(funcObj);
        funcWrap.PrepForExec();
        for (std::any value : data)
        {
            if (value.type() == typeid(const char *))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateString(std::any_cast<const char *>(value)));
            else if (value.type() == typeid(std::string))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateString(std::any_cast<std::string>(value).c_str()));
            else if (value.type() == typeid(uint64_t))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateInteger(std::any_cast<uint64_t>(value)));
            else if (value.type() == typeid(uint32_t))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateInteger(std::any_cast<uint32_t>(value)));
            else if (value.type() == typeid(unsigned long))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateInteger(std::any_cast<unsigned long>(value)));
            else if (value.type() == typeid(uint16_t))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateInteger(std::any_cast<uint16_t>(value)));
            else if (value.type() == typeid(uint8_t))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateInteger(std::any_cast<uint8_t>(value)));
            else if (value.type() == typeid(int64_t))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateInteger(std::any_cast<int64_t>(value)));
            else if (value.type() == typeid(int32_t))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateInteger(std::any_cast<int32_t>(value)));
            else if (value.type() == typeid(long))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateInteger(std::any_cast<long>(value)));
            else if (value.type() == typeid(int16_t))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateInteger(std::any_cast<int16_t>(value)));
            else if (value.type() == typeid(char))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateInteger(std::any_cast<char>(value)));
            else if (value.type() == typeid(bool))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateInteger(std::any_cast<bool>(value) == true ? 1 : 0));
            else if (value.type() == typeid(float))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateNumber(std::any_cast<float>(value)));
            else if (value.type() == typeid(double))
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateNumber(std::any_cast<double>(value)));
            else
                luacpp::PushValue(funcWrap.GetML(), this->luaState->CreateNil());
        }

        luacpp::LuaObject retObj = funcWrap.ExecuteWithReturnRaw(this->GetName() + ":" + export_name, data.size());

        if (retObj.GetType() == LUA_TNIL)
            return nullptr;
        else if (retObj.GetType() == LUA_TSTRING)
            return retObj.ToString();
        else if (retObj.GetType() == LUA_TBOOLEAN)
            return retObj.ToBool();
        else if (retObj.GetType() == LUA_TNUMBER)
        {
            lua_rawgeti(this->GetLuaRawState(), LUA_REGISTRYINDEX, retObj.GetRefIndex());
            bool isint = (lua_isinteger(this->GetLuaRawState(), -1) == 1);
            lua_pop(this->GetLuaRawState(), 1);
            if (isint)
                return retObj.ToInteger();
            else
                return retObj.ToNumber();
        }
        else
            return nullptr;
    }

    void RegisterExport(std::string export_name, void *functionPtr)
    {
        if (this->luaExportedFunctions.find(export_name) != this->luaExportedFunctions.end())
            return;

        this->luaExportedFunctions.insert(std::make_pair(export_name, *static_cast<luacpp::LuaObject *>(functionPtr)));
    }

    void UnregisterExport(std::string export_name)
    {
        if (this->luaExportedFunctions.find(export_name) == this->luaExportedFunctions.end())
            return;

        this->luaExportedFunctions.erase(export_name);
    }
};

#endif