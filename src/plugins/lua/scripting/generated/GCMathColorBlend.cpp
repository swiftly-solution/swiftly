#include "../../../core/scripting/generated/classes/GCMathColorBlend.h"
#include "../core.h"

void SetupLuaClassGCMathColorBlend(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMathColorBlend>("CMathColorBlend")
        .addProperty("InMin", &GCMathColorBlend::GetInMin, &GCMathColorBlend::SetInMin)
        .addProperty("InMax", &GCMathColorBlend::GetInMax, &GCMathColorBlend::SetInMax)
        .addProperty("OutColor1", &GCMathColorBlend::GetOutColor1, &GCMathColorBlend::SetOutColor1)
        .addProperty("OutColor2", &GCMathColorBlend::GetOutColor2, &GCMathColorBlend::SetOutColor2)
        .endClass();
}