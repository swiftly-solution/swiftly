#include "../../../core/scripting/generated/classes/GCSosSoundEventGroupSchema.h"
#include "../core.h"

void SetupLuaClassGCSosSoundEventGroupSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosSoundEventGroupSchema>("CSosSoundEventGroupSchema")
        .addProperty("Name", &GCSosSoundEventGroupSchema::GetName, &GCSosSoundEventGroupSchema::SetName)
        .addProperty("Type", &GCSosSoundEventGroupSchema::GetType, &GCSosSoundEventGroupSchema::SetType)
        .addProperty("IsBlocking", &GCSosSoundEventGroupSchema::GetIsBlocking, &GCSosSoundEventGroupSchema::SetIsBlocking)
        .addProperty("BlockMaxCount", &GCSosSoundEventGroupSchema::GetBlockMaxCount, &GCSosSoundEventGroupSchema::SetBlockMaxCount)
        .addProperty("InvertMatch", &GCSosSoundEventGroupSchema::GetInvertMatch, &GCSosSoundEventGroupSchema::SetInvertMatch)
        .addProperty("MatchPattern", &GCSosSoundEventGroupSchema::GetMatchPattern, &GCSosSoundEventGroupSchema::SetMatchPattern)
        .addProperty("BranchPattern", &GCSosSoundEventGroupSchema::GetBranchPattern, &GCSosSoundEventGroupSchema::SetBranchPattern)
        .addProperty("LifeSpanTime", &GCSosSoundEventGroupSchema::GetLifeSpanTime, &GCSosSoundEventGroupSchema::SetLifeSpanTime)
        .addProperty("Actions", &GCSosSoundEventGroupSchema::GetActions, &GCSosSoundEventGroupSchema::SetActions)
        .endClass();
}