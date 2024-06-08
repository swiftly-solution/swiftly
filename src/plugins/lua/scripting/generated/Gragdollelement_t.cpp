#include "../../../core/scripting/generated/classes/Gragdollelement_t.h"
#include "../core.h"

void SetupLuaClassGragdollelement_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gragdollelement_t>("ragdollelement_t")
        .addProperty("OriginParentSpace", &Gragdollelement_t::GetOriginParentSpace, &Gragdollelement_t::SetOriginParentSpace)
        .addProperty("ParentIndex", &Gragdollelement_t::GetParentIndex, &Gragdollelement_t::SetParentIndex)
        .addProperty("Radius", &Gragdollelement_t::GetRadius, &Gragdollelement_t::SetRadius)
        .endClass();
}