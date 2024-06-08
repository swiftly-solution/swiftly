#include "../../../core/scripting/generated/classes/GC_OP_ShapeMatchingConstraint.h"
#include "../core.h"

void SetupLuaClassGC_OP_ShapeMatchingConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ShapeMatchingConstraint>("C_OP_ShapeMatchingConstraint")
        .addProperty("ShapeRestorationTime", &GC_OP_ShapeMatchingConstraint::GetShapeRestorationTime, &GC_OP_ShapeMatchingConstraint::SetShapeRestorationTime)
        .endClass();
}