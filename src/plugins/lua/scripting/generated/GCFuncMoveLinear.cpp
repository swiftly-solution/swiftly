#include "../../../core/scripting/generated/classes/GCFuncMoveLinear.h"
#include "../core.h"

void SetupLuaClassGCFuncMoveLinear(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncMoveLinear>("CFuncMoveLinear")
        .addProperty("AuthoredPosition", &GCFuncMoveLinear::GetAuthoredPosition, &GCFuncMoveLinear::SetAuthoredPosition)
        .addProperty("MoveEntitySpace", &GCFuncMoveLinear::GetMoveEntitySpace, &GCFuncMoveLinear::SetMoveEntitySpace)
        .addProperty("MoveDirParentSpace", &GCFuncMoveLinear::GetMoveDirParentSpace, &GCFuncMoveLinear::SetMoveDirParentSpace)
        .addProperty("SoundStart", &GCFuncMoveLinear::GetSoundStart, &GCFuncMoveLinear::SetSoundStart)
        .addProperty("SoundStop", &GCFuncMoveLinear::GetSoundStop, &GCFuncMoveLinear::SetSoundStop)
        .addProperty("CurrentSound", &GCFuncMoveLinear::GetCurrentSound, &GCFuncMoveLinear::SetCurrentSound)
        .addProperty("BlockDamage", &GCFuncMoveLinear::GetBlockDamage, &GCFuncMoveLinear::SetBlockDamage)
        .addProperty("StartPosition", &GCFuncMoveLinear::GetStartPosition, &GCFuncMoveLinear::SetStartPosition)
        .addProperty("OnFullyOpen", &GCFuncMoveLinear::GetOnFullyOpen, &GCFuncMoveLinear::SetOnFullyOpen)
        .addProperty("OnFullyClosed", &GCFuncMoveLinear::GetOnFullyClosed, &GCFuncMoveLinear::SetOnFullyClosed)
        .addProperty("CreateMovableNavMesh", &GCFuncMoveLinear::GetCreateMovableNavMesh, &GCFuncMoveLinear::SetCreateMovableNavMesh)
        .addProperty("CreateNavObstacle", &GCFuncMoveLinear::GetCreateNavObstacle, &GCFuncMoveLinear::SetCreateNavObstacle)
        .endClass();
}