#include "../../../core/scripting/generated/classes/GCLogicCollisionPair.h"
#include "../core.h"

void SetupLuaClassGCLogicCollisionPair(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicCollisionPair>("CLogicCollisionPair")
        .addProperty("NameAttach1", &GCLogicCollisionPair::GetNameAttach1, &GCLogicCollisionPair::SetNameAttach1)
        .addProperty("NameAttach2", &GCLogicCollisionPair::GetNameAttach2, &GCLogicCollisionPair::SetNameAttach2)
        .addProperty("SupportMultipleEntitiesWithSameName", &GCLogicCollisionPair::GetSupportMultipleEntitiesWithSameName, &GCLogicCollisionPair::SetSupportMultipleEntitiesWithSameName)
        .addProperty("Disabled", &GCLogicCollisionPair::GetDisabled, &GCLogicCollisionPair::SetDisabled)
        .addProperty("Succeeded", &GCLogicCollisionPair::GetSucceeded, &GCLogicCollisionPair::SetSucceeded)
        .endClass();
}