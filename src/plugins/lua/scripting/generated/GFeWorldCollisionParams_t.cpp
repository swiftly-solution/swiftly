#include "../../../core/scripting/generated/classes/GFeWorldCollisionParams_t.h"
#include "../core.h"

void SetupLuaClassGFeWorldCollisionParams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeWorldCollisionParams_t>("FeWorldCollisionParams_t")
        .addProperty("WorldFriction", &GFeWorldCollisionParams_t::GetWorldFriction, &GFeWorldCollisionParams_t::SetWorldFriction)
        .addProperty("GroundFriction", &GFeWorldCollisionParams_t::GetGroundFriction, &GFeWorldCollisionParams_t::SetGroundFriction)
        .addProperty("ListBegin", &GFeWorldCollisionParams_t::GetListBegin, &GFeWorldCollisionParams_t::SetListBegin)
        .addProperty("ListEnd", &GFeWorldCollisionParams_t::GetListEnd, &GFeWorldCollisionParams_t::SetListEnd)
        .endClass();
}