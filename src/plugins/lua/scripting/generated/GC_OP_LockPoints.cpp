#include "../../../core/scripting/generated/classes/GC_OP_LockPoints.h"
#include "../core.h"

void SetupLuaClassGC_OP_LockPoints(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LockPoints>("C_OP_LockPoints")
        .addProperty("MinCol", &GC_OP_LockPoints::GetMinCol, &GC_OP_LockPoints::SetMinCol)
        .addProperty("MaxCol", &GC_OP_LockPoints::GetMaxCol, &GC_OP_LockPoints::SetMaxCol)
        .addProperty("MinRow", &GC_OP_LockPoints::GetMinRow, &GC_OP_LockPoints::SetMinRow)
        .addProperty("MaxRow", &GC_OP_LockPoints::GetMaxRow, &GC_OP_LockPoints::SetMaxRow)
        .addProperty("ControlPoint", &GC_OP_LockPoints::GetControlPoint, &GC_OP_LockPoints::SetControlPoint)
        .addProperty("BlendValue", &GC_OP_LockPoints::GetBlendValue, &GC_OP_LockPoints::SetBlendValue)
        .endClass();
}