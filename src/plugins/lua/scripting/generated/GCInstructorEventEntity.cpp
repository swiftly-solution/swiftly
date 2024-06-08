#include "../../../core/scripting/generated/classes/GCInstructorEventEntity.h"
#include "../core.h"

void SetupLuaClassGCInstructorEventEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInstructorEventEntity>("CInstructorEventEntity")
        .addProperty("Name", &GCInstructorEventEntity::GetName, &GCInstructorEventEntity::SetName)
        .addProperty("HintTargetEntity", &GCInstructorEventEntity::GetHintTargetEntity, &GCInstructorEventEntity::SetHintTargetEntity)
        .addProperty("TargetPlayer", &GCInstructorEventEntity::GetTargetPlayer, &GCInstructorEventEntity::SetTargetPlayer)
        .endClass();
}