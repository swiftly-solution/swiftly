#include "../core.h"

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

LoadLuaScriptingComponent(
    convars,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginConvars>("ConVars")
            .addConstructor<void (*)(std::string)>()
            .addFunction("CreateFake", &PluginConvars::CreateFakeLua)
            .addFunction("DeleteFake", &PluginConvars::DeleteFake)
            .addFunction("Get", &PluginConvars::GetConvarValue)
            .addFunction("GetType", &PluginConvars::GetConvarType)
            .addFunction("Set", &PluginConvars::SetConvar)
            .addFunction("Exists", &PluginConvars::Exists)
            .addFunction("ExistsFake", &PluginConvars::ExistsFake)
            .addFunction("AddFlags", &PluginConvars::AddFlags)
            .addFunction("RemoveFlags", &PluginConvars::RemoveFlags)
            .addFunction("GetFlags", &PluginConvars::GetFlags)
            .addFunction("HasFlags", &PluginConvars::HasFlags)
            .endClass();

        luaL_dostring(state, "convar = ConVars(GetCurrentPluginName())");
    }
)