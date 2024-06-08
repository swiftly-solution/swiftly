#include "../../../core/scripting/generated/classes/GC_OP_EndCapTimedFreeze.h"
#include "../core.h"

void SetupLuaClassGC_OP_EndCapTimedFreeze(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_EndCapTimedFreeze>("C_OP_EndCapTimedFreeze")
        .addProperty("FreezeTime", &GC_OP_EndCapTimedFreeze::GetFreezeTime, &GC_OP_EndCapTimedFreeze::SetFreezeTime)
        .endClass();
}