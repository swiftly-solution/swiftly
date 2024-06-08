#include "../../../core/scripting/generated/classes/GC_INIT_GlobalScale.h"
#include "../core.h"

void SetupLuaClassGC_INIT_GlobalScale(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_GlobalScale>("C_INIT_GlobalScale")
        .addProperty("Scale", &GC_INIT_GlobalScale::GetScale, &GC_INIT_GlobalScale::SetScale)
        .addProperty("ScaleControlPointNumber", &GC_INIT_GlobalScale::GetScaleControlPointNumber, &GC_INIT_GlobalScale::SetScaleControlPointNumber)
        .addProperty("ControlPointNumber", &GC_INIT_GlobalScale::GetControlPointNumber, &GC_INIT_GlobalScale::SetControlPointNumber)
        .addProperty("ScaleRadius", &GC_INIT_GlobalScale::GetScaleRadius, &GC_INIT_GlobalScale::SetScaleRadius)
        .addProperty("ScalePosition", &GC_INIT_GlobalScale::GetScalePosition, &GC_INIT_GlobalScale::SetScalePosition)
        .addProperty("ScaleVelocity", &GC_INIT_GlobalScale::GetScaleVelocity, &GC_INIT_GlobalScale::SetScaleVelocity)
        .endClass();
}