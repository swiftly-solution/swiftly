#include "../core.h"

void SetupLuaPrecacher(LuaPlugin* plugin, lua_State* state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<PluginPrecacher>("Precacher")
        .addConstructor<void (*)(std::string)>()
        .addFunction("PrecacheModel", &PluginPrecacher::PrecacheModel)
        .addFunction("PrecacheSound", &PluginPrecacher::PrecacheSound)
        .endClass();

    luaL_dostring(state, "precacher = Precacher(GetCurrentPluginName())");
}