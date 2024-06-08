#include "../../../core/scripting/generated/classes/GParticleControlPointDriver_t.h"
#include "../core.h"

void SetupLuaClassGParticleControlPointDriver_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleControlPointDriver_t>("ParticleControlPointDriver_t")
        .addProperty("ControlPoint", &GParticleControlPointDriver_t::GetControlPoint, &GParticleControlPointDriver_t::SetControlPoint)
        .addProperty("AttachType", &GParticleControlPointDriver_t::GetAttachType, &GParticleControlPointDriver_t::SetAttachType)
        .addProperty("AttachmentName", &GParticleControlPointDriver_t::GetAttachmentName, &GParticleControlPointDriver_t::SetAttachmentName)
        .addProperty("Offset", &GParticleControlPointDriver_t::GetOffset, &GParticleControlPointDriver_t::SetOffset)
        .addProperty("Offset1", &GParticleControlPointDriver_t::GetOffset1, &GParticleControlPointDriver_t::SetOffset1)
        .addProperty("EntityName", &GParticleControlPointDriver_t::GetEntityName, &GParticleControlPointDriver_t::SetEntityName)
        .endClass();
}