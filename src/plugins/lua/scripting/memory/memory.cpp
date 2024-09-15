#include "../core.h"

void SetupLuaMemory(LuaPlugin* plugin, lua_State* state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<PluginMemory>("Memory")
        .addConstructor<void (*)()>()

        .addFunction("LoadFromAddress", &PluginMemory::LoadFromAddress)
        .addFunction("LoadFromSignatureName", &PluginMemory::LoadFromSignatureName)
        .addFunction("LoadFromSignature", &PluginMemory::LoadFromSignature)
        .addFunction("AddOffsetByName", &PluginMemory::AddOffsetByName)
        .addFunction("AddOffset", &PluginMemory::AddOffset)
        .addFunction("RemoveOffsetByName", &PluginMemory::RemoveOffsetByName)
        .addFunction("RemoveOffset", &PluginMemory::RemoveOffset)
        .addFunction("AccessVTable", &PluginMemory::AccessVTable)
        .addFunction("AccessVTableFromOffset", &PluginMemory::AccessVTableFromOffset)
        .addFunction("AccessedVTable", &PluginMemory::AccessedVTable)
        .addFunction("Clear", &PluginMemory::Clear)
        .addFunction("SetBool", &PluginMemory::SetBool)
        .addFunction("SetInt", &PluginMemory::SetInt)
        .addFunction("SetInt64", &PluginMemory::SetInt64)
        .addFunction("SetUint", &PluginMemory::SetUint)
        .addFunction("SetUint64", &PluginMemory::SetUint64)
        .addFunction("SetFloat", &PluginMemory::SetFloat)
        .addFunction("SetDouble", &PluginMemory::SetDouble)
        .addFunction("GetBool", &PluginMemory::GetBool)
        .addFunction("GetInt", &PluginMemory::GetInt)
        .addFunction("GetInt64", &PluginMemory::GetInt64)
        .addFunction("GetUint", &PluginMemory::GetUint)
        .addFunction("GetUint64", &PluginMemory::GetUint64)
        .addFunction("GetFloat", &PluginMemory::GetFloat)
        .addFunction("GetDouble", &PluginMemory::GetDouble)
        .addFunction("GetPtr", &PluginMemory::GetPtr)
        .addFunction("IsValid", &PluginMemory::IsValid)

        .endClass();
}