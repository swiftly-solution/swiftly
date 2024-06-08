#include "../../../core/scripting/generated/classes/GCastSphereSATParams_t.h"
#include "../core.h"

void SetupLuaClassGCastSphereSATParams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCastSphereSATParams_t>("CastSphereSATParams_t")
        .addProperty("RayStart", &GCastSphereSATParams_t::GetRayStart, &GCastSphereSATParams_t::SetRayStart)
        .addProperty("RayDelta", &GCastSphereSATParams_t::GetRayDelta, &GCastSphereSATParams_t::SetRayDelta)
        .addProperty("Radius", &GCastSphereSATParams_t::GetRadius, &GCastSphereSATParams_t::SetRadius)
        .addProperty("MaxFraction", &GCastSphereSATParams_t::GetMaxFraction, &GCastSphereSATParams_t::SetMaxFraction)
        .addProperty("Scale", &GCastSphereSATParams_t::GetScale, &GCastSphereSATParams_t::SetScale)
        .addProperty("Hull", &GCastSphereSATParams_t::GetHull, &GCastSphereSATParams_t::SetHull)
        .endClass();
}