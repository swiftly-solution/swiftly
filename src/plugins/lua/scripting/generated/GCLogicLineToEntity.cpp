#include "../../../core/scripting/generated/classes/GCLogicLineToEntity.h"
#include "../core.h"

void SetupLuaClassGCLogicLineToEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicLineToEntity>("CLogicLineToEntity")
        .addProperty("SourceName", &GCLogicLineToEntity::GetSourceName, &GCLogicLineToEntity::SetSourceName)
        .addProperty("StartEntity", &GCLogicLineToEntity::GetStartEntity, &GCLogicLineToEntity::SetStartEntity)
        .addProperty("EndEntity", &GCLogicLineToEntity::GetEndEntity, &GCLogicLineToEntity::SetEndEntity)
        .endClass();
}