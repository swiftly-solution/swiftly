#include "../../../core/scripting/generated/classes/GC_OP_FadeInSimple.h"
#include "../core.h"

void SetupLuaClassGC_OP_FadeInSimple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_FadeInSimple>("C_OP_FadeInSimple")
        .addProperty("FadeInTime", &GC_OP_FadeInSimple::GetFadeInTime, &GC_OP_FadeInSimple::SetFadeInTime)
        .addProperty("FieldOutput", &GC_OP_FadeInSimple::GetFieldOutput, &GC_OP_FadeInSimple::SetFieldOutput)
        .endClass();
}