#include "../../../core/scripting/generated/classes/GCSceneObjectData.h"
#include "../core.h"

void SetupLuaClassGCSceneObjectData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSceneObjectData>("CSceneObjectData")
        .addProperty("MinBounds", &GCSceneObjectData::GetMinBounds, &GCSceneObjectData::SetMinBounds)
        .addProperty("MaxBounds", &GCSceneObjectData::GetMaxBounds, &GCSceneObjectData::SetMaxBounds)
        .addProperty("DrawCalls", &GCSceneObjectData::GetDrawCalls, &GCSceneObjectData::SetDrawCalls)
        .addProperty("DrawBounds", &GCSceneObjectData::GetDrawBounds, &GCSceneObjectData::SetDrawBounds)
        .addProperty("Meshlets", &GCSceneObjectData::GetMeshlets, &GCSceneObjectData::SetMeshlets)
        .addProperty("TintColor", &GCSceneObjectData::GetTintColor, &GCSceneObjectData::SetTintColor)
        .endClass();
}