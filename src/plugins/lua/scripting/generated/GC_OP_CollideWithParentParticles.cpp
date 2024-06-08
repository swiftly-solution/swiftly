#include "../../../core/scripting/generated/classes/GC_OP_CollideWithParentParticles.h"
#include "../core.h"

void SetupLuaClassGC_OP_CollideWithParentParticles(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_CollideWithParentParticles>("C_OP_CollideWithParentParticles")
        .addProperty("ParentRadiusScale", &GC_OP_CollideWithParentParticles::GetParentRadiusScale, &GC_OP_CollideWithParentParticles::SetParentRadiusScale)
        .addProperty("RadiusScale", &GC_OP_CollideWithParentParticles::GetRadiusScale, &GC_OP_CollideWithParentParticles::SetRadiusScale)
        .endClass();
}