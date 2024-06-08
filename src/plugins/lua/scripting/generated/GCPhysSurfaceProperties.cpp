#include "../../../core/scripting/generated/classes/GCPhysSurfaceProperties.h"
#include "../core.h"

void SetupLuaClassGCPhysSurfaceProperties(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysSurfaceProperties>("CPhysSurfaceProperties")
        .addProperty("Name", &GCPhysSurfaceProperties::GetName, &GCPhysSurfaceProperties::SetName)
        .addProperty("NameHash", &GCPhysSurfaceProperties::GetNameHash, &GCPhysSurfaceProperties::SetNameHash)
        .addProperty("BaseNameHash", &GCPhysSurfaceProperties::GetBaseNameHash, &GCPhysSurfaceProperties::SetBaseNameHash)
        .addProperty("Hidden", &GCPhysSurfaceProperties::GetHidden, &GCPhysSurfaceProperties::SetHidden)
        .addProperty("Description", &GCPhysSurfaceProperties::GetDescription, &GCPhysSurfaceProperties::SetDescription)
        .addProperty("Physics", &GCPhysSurfaceProperties::GetPhysics, &GCPhysSurfaceProperties::SetPhysics)
        .addProperty("AudioSounds", &GCPhysSurfaceProperties::GetAudioSounds, &GCPhysSurfaceProperties::SetAudioSounds)
        .addProperty("AudioParams", &GCPhysSurfaceProperties::GetAudioParams, &GCPhysSurfaceProperties::SetAudioParams)
        .endClass();
}