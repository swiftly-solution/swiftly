#include "../../../core/scripting/generated/classes/GC_OP_LerpToInitialPosition.h"
#include "../core.h"

void SetupLuaClassGC_OP_LerpToInitialPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LerpToInitialPosition>("C_OP_LerpToInitialPosition")
        .addProperty("ControlPointNumber", &GC_OP_LerpToInitialPosition::GetControlPointNumber, &GC_OP_LerpToInitialPosition::SetControlPointNumber)
        .addProperty("Interpolation", &GC_OP_LerpToInitialPosition::GetInterpolation, &GC_OP_LerpToInitialPosition::SetInterpolation)
        .addProperty("CacheField", &GC_OP_LerpToInitialPosition::GetCacheField, &GC_OP_LerpToInitialPosition::SetCacheField)
        .addProperty("Scale", &GC_OP_LerpToInitialPosition::GetScale, &GC_OP_LerpToInitialPosition::SetScale)
        .endClass();
}