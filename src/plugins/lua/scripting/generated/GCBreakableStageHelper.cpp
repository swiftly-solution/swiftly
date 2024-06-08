#include "../../../core/scripting/generated/classes/GCBreakableStageHelper.h"
#include "../core.h"

void SetupLuaClassGCBreakableStageHelper(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBreakableStageHelper>("CBreakableStageHelper")
        .addProperty("CurrentStage", &GCBreakableStageHelper::GetCurrentStage, &GCBreakableStageHelper::SetCurrentStage)
        .addProperty("StageCount", &GCBreakableStageHelper::GetStageCount, &GCBreakableStageHelper::SetStageCount)
        .endClass();
}