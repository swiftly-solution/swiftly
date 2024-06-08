#include "../../../core/scripting/generated/classes/GParticleControlPointConfiguration_t.h"
#include "../core.h"

void SetupLuaClassGParticleControlPointConfiguration_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleControlPointConfiguration_t>("ParticleControlPointConfiguration_t")
        .addProperty("Name", &GParticleControlPointConfiguration_t::GetName, &GParticleControlPointConfiguration_t::SetName)
        .addProperty("Drivers", &GParticleControlPointConfiguration_t::GetDrivers, &GParticleControlPointConfiguration_t::SetDrivers)
        .addProperty("PreviewState", &GParticleControlPointConfiguration_t::GetPreviewState, &GParticleControlPointConfiguration_t::SetPreviewState)
        .endClass();
}