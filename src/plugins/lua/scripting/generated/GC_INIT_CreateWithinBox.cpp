#include "../../../core/scripting/generated/classes/GC_INIT_CreateWithinBox.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateWithinBox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateWithinBox>("C_INIT_CreateWithinBox")
        .addProperty("Min", &GC_INIT_CreateWithinBox::GetMin, &GC_INIT_CreateWithinBox::SetMin)
        .addProperty("Max", &GC_INIT_CreateWithinBox::GetMax, &GC_INIT_CreateWithinBox::SetMax)
        .addProperty("ControlPointNumber", &GC_INIT_CreateWithinBox::GetControlPointNumber, &GC_INIT_CreateWithinBox::SetControlPointNumber)
        .addProperty("LocalSpace", &GC_INIT_CreateWithinBox::GetLocalSpace, &GC_INIT_CreateWithinBox::SetLocalSpace)
        .addProperty("RandomnessParameters", &GC_INIT_CreateWithinBox::GetRandomnessParameters, &GC_INIT_CreateWithinBox::SetRandomnessParameters)
        .endClass();
}