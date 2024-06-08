#include "../../../core/scripting/generated/classes/GC_OP_RemapTransformToVelocity.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapTransformToVelocity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapTransformToVelocity>("C_OP_RemapTransformToVelocity")
        .addProperty("TransformInput", &GC_OP_RemapTransformToVelocity::GetTransformInput, &GC_OP_RemapTransformToVelocity::SetTransformInput)
        .endClass();
}