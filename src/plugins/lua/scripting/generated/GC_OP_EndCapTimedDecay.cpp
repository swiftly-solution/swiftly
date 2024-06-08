#include "../../../core/scripting/generated/classes/GC_OP_EndCapTimedDecay.h"
#include "../core.h"

void SetupLuaClassGC_OP_EndCapTimedDecay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_EndCapTimedDecay>("C_OP_EndCapTimedDecay")
        .addProperty("DecayTime", &GC_OP_EndCapTimedDecay::GetDecayTime, &GC_OP_EndCapTimedDecay::SetDecayTime)
        .endClass();
}