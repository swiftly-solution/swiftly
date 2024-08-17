#include "../scripting.h"
#include "../../../entrypoint.h"
#include "../../../convars/convars.h"

PluginConvars::PluginConvars(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

void PluginConvars::CreateFake(std::string cvarname, int32_t type, std::any defaultValue, bool prot)
{
    if (type < 0 || type > 14) return;
    if (FakeConvarExists(cvarname)) return;
    if (FetchCVar(cvarname)) return;

    auto cvar = new FakeConVar(cvarname, (EConVarType)type, defaultValue, prot);
    InsertFakeConvar(cvarname, cvar);
}

void PluginConvars::CreateFakeLua(std::string cvarname, int32_t type, luabridge::LuaRef defaultValue, bool prot)
{
    if (type == EConVarType_Int16) {
        if (!defaultValue.isNumber()) return;
        CreateFake(cvarname, type, defaultValue.cast<int16_t>(), prot);
    }
    else if (type == EConVarType_UInt16) {
        if (!defaultValue.isNumber()) return;
        CreateFake(cvarname, type, defaultValue.cast<uint16_t>(), prot);
    }
    else if (type == EConVarType_UInt32) {
        if (!defaultValue.isNumber()) return;
        CreateFake(cvarname, type, defaultValue.cast<uint32_t>(), prot);
    }
    else if (type == EConVarType_Int32) {
        if (!defaultValue.isNumber()) return;
        CreateFake(cvarname, type, defaultValue.cast<int32_t>(), prot);
    }
    else if (type == EConVarType_UInt64) {
        if (!defaultValue.isNumber()) return;
        CreateFake(cvarname, type, defaultValue.cast<uint64_t>(), prot);
    }
    else if (type == EConVarType_Int64) {
        if (!defaultValue.isNumber()) return;
        CreateFake(cvarname, type, defaultValue.cast<int64_t>(), prot);
    }
    else if (type == EConVarType_Bool) {
        if (!defaultValue.isBool()) return;
        CreateFake(cvarname, type, defaultValue.cast<bool>(), prot);
    }
    else if (type == EConVarType_Float32) {
        if (!defaultValue.isNumber()) return;
        CreateFake(cvarname, type, defaultValue.cast<float>(), prot);
    }
    else if (type == EConVarType_Float64) {
        if (!defaultValue.isNumber()) return;
        CreateFake(cvarname, type, defaultValue.cast<double>(), prot);
    }
    else if (type == EConVarType_String) {
        if (!defaultValue.isString()) return;
        CreateFake(cvarname, type, defaultValue.cast<std::string>(), prot);
    }
    else if (type == EConVarType_Color) {
        if (!defaultValue.isInstance<Color>()) return;
        CreateFake(cvarname, type, defaultValue.cast<Color>(), prot);
    }
    else if (type == EConVarType_Vector2) {
        if (!defaultValue.isInstance<Vector2D>()) return;
        CreateFake(cvarname, type, defaultValue.cast<Vector2D>(), prot);
    }
    else if (type == EConVarType_Vector3) {
        if (!defaultValue.isInstance<Vector>()) return;
        CreateFake(cvarname, type, defaultValue.cast<Vector>(), prot);
    }
    else if (type == EConVarType_Vector4) {
        if (!defaultValue.isInstance<Vector4D>()) return;
        CreateFake(cvarname, type, defaultValue.cast<Vector4D>(), prot);
    }
    else if (type == EConVarType_Qangle) {
        if (!defaultValue.isInstance<QAngle>()) return;
        CreateFake(cvarname, type, defaultValue.cast<QAngle>(), prot);
    }
}

void PluginConvars::DeleteFake(std::string cvarname)
{
    if (!FakeConvarExists(cvarname)) return;

    auto cvar = GetFakeConvar(cvarname);
    delete cvar;
    DeleteFakeConvar(cvarname);
}

std::any PluginConvars::GetConvarValue(std::string cvarname)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::GetConvarValue(cvarname=\"%s\")", cvarname.c_str()));

    return FetchCVarValue(cvarname);
}

luabridge::LuaRef PluginConvars::GetConvarValueLua(std::string cvarname, lua_State* L)
{
    return LuaSerializeData(GetConvarValue(cvarname), L);
}

int16_t PluginConvars::GetConvarType(std::string cvarname)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::GetConvarType(cvarname=\"%s\")", cvarname.c_str()));

    return (int16_t)FetchCVarType(cvarname);
}

void PluginConvars::SetConvar(std::string cvarname, std::string value)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::SetConvar(cvarname=\"%s\", value=\"%s\")", cvarname.c_str(), value.c_str()));

    auto cvartype = FetchCVarType(cvarname);

    if (cvartype == EConVarType_String)
        engine->ServerCommand(string_format("%s \"%s\"", cvarname.c_str(), value.c_str()).c_str());
    else if (cvartype != EConVarType_Invalid)
        engine->ServerCommand(string_format("%s %s", cvarname.c_str(), value.c_str()).c_str());
}