#include "../../../core/scripting/generated/classes/GC_OP_FadeOutSimple.h"
#include "../core.h"

void SetupLuaClassGC_OP_FadeOutSimple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_FadeOutSimple>("C_OP_FadeOutSimple")
        .addProperty("FadeOutTime", &GC_OP_FadeOutSimple::GetFadeOutTime, &GC_OP_FadeOutSimple::SetFadeOutTime)
        .addProperty("FieldOutput", &GC_OP_FadeOutSimple::GetFieldOutput, &GC_OP_FadeOutSimple::SetFieldOutput)
        .endClass();
}