#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointToPlayer.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointToPlayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointToPlayer>("C_OP_SetControlPointToPlayer")
        .addProperty("CP1", &GC_OP_SetControlPointToPlayer::GetCP1, &GC_OP_SetControlPointToPlayer::SetCP1)
        .addProperty("CP1Pos", &GC_OP_SetControlPointToPlayer::GetCP1Pos, &GC_OP_SetControlPointToPlayer::SetCP1Pos)
        .addProperty("OrientToEyes", &GC_OP_SetControlPointToPlayer::GetOrientToEyes, &GC_OP_SetControlPointToPlayer::SetOrientToEyes)
        .endClass();
}