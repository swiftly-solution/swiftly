#include "../../../core/scripting/generated/classes/GCConstraintAnchor.h"
#include "../core.h"

void SetupLuaClassGCConstraintAnchor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCConstraintAnchor>("CConstraintAnchor")
        .addProperty("MassScale", &GCConstraintAnchor::GetMassScale, &GCConstraintAnchor::SetMassScale)
        .endClass();
}