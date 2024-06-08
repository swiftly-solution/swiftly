#include "../../../core/scripting/generated/classes/GC_OP_DragRelativeToPlane.h"
#include "../core.h"

void SetupLuaClassGC_OP_DragRelativeToPlane(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DragRelativeToPlane>("C_OP_DragRelativeToPlane")
        .addProperty("DragAtPlane", &GC_OP_DragRelativeToPlane::GetDragAtPlane, &GC_OP_DragRelativeToPlane::SetDragAtPlane)
        .addProperty("Falloff", &GC_OP_DragRelativeToPlane::GetFalloff, &GC_OP_DragRelativeToPlane::SetFalloff)
        .addProperty("Directional", &GC_OP_DragRelativeToPlane::GetDirectional, &GC_OP_DragRelativeToPlane::SetDirectional)
        .addProperty("ControlPointNumber", &GC_OP_DragRelativeToPlane::GetControlPointNumber, &GC_OP_DragRelativeToPlane::SetControlPointNumber)
        .endClass();
}