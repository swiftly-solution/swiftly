#include "../../../core/scripting/generated/classes/GC_OP_ForceControlPointStub.h"
#include "../core.h"

void SetupLuaClassGC_OP_ForceControlPointStub(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ForceControlPointStub>("C_OP_ForceControlPointStub")
        .addProperty("ControlPoint", &GC_OP_ForceControlPointStub::GetControlPoint, &GC_OP_ForceControlPointStub::SetControlPoint)
        .endClass();
}