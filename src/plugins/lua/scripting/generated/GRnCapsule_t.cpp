#include "../../../core/scripting/generated/classes/GRnCapsule_t.h"
#include "../core.h"

void SetupLuaClassGRnCapsule_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnCapsule_t>("RnCapsule_t")
        .addProperty("Center", &GRnCapsule_t::GetCenter, &GRnCapsule_t::SetCenter)
        .addProperty("Radius", &GRnCapsule_t::GetRadius, &GRnCapsule_t::SetRadius)
        .endClass();
}