#include "../../../core/scripting/generated/classes/GC_INIT_RemapQAnglesToRotation.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapQAnglesToRotation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapQAnglesToRotation>("C_INIT_RemapQAnglesToRotation")
        .addProperty("TransformInput", &GC_INIT_RemapQAnglesToRotation::GetTransformInput, &GC_INIT_RemapQAnglesToRotation::SetTransformInput)
        .endClass();
}