#include "../../../core/scripting/generated/classes/GCParticleModelInput.h"
#include "../core.h"

void SetupLuaClassGCParticleModelInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleModelInput>("CParticleModelInput")
        .addProperty("Type", &GCParticleModelInput::GetType, &GCParticleModelInput::SetType)
        .addProperty("ControlPoint", &GCParticleModelInput::GetControlPoint, &GCParticleModelInput::SetControlPoint)
        .endClass();
}