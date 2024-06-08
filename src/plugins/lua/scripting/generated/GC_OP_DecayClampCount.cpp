#include "../../../core/scripting/generated/classes/GC_OP_DecayClampCount.h"
#include "../core.h"

void SetupLuaClassGC_OP_DecayClampCount(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DecayClampCount>("C_OP_DecayClampCount")
        .addProperty("Count", &GC_OP_DecayClampCount::GetCount, &GC_OP_DecayClampCount::SetCount)
        .endClass();
}