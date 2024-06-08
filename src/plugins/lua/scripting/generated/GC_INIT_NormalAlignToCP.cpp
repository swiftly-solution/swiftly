#include "../../../core/scripting/generated/classes/GC_INIT_NormalAlignToCP.h"
#include "../core.h"

void SetupLuaClassGC_INIT_NormalAlignToCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_NormalAlignToCP>("C_INIT_NormalAlignToCP")
        .addProperty("TransformInput", &GC_INIT_NormalAlignToCP::GetTransformInput, &GC_INIT_NormalAlignToCP::SetTransformInput)
        .addProperty("ControlPointAxis", &GC_INIT_NormalAlignToCP::GetControlPointAxis, &GC_INIT_NormalAlignToCP::SetControlPointAxis)
        .endClass();
}