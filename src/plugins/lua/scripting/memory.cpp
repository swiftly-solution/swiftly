#include "core.h"

void SetupLuaMemory(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<PluginMemory>("Memory")
        .addConstructor<void (*)()>()

        .addFunction("LoadFromAddress", &PluginMemory::LoadFromAddress)
        .addFunction("LoadFromSignatureName", &PluginMemory::LoadFromSignatureName)
        .addFunction("LoadFromSignature", &PluginMemory::LoadFromSignature)
        .addFunction("AddOffset", &PluginMemory::AddOffset)
        .addFunction("RemoveOffset", &PluginMemory::RemoveOffset)
        .addFunction("Clear", &PluginMemory::Clear)
        .addFunction("GetPtr", &PluginMemory::GetPtr)
        .addFunction("IsValid", &PluginMemory::IsValid)

        .endClass();
}