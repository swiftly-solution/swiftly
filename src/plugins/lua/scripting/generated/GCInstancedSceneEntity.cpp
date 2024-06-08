#include "../../../core/scripting/generated/classes/GCInstancedSceneEntity.h"
#include "../core.h"

void SetupLuaClassGCInstancedSceneEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInstancedSceneEntity>("CInstancedSceneEntity")
        .addProperty("Owner", &GCInstancedSceneEntity::GetOwner, &GCInstancedSceneEntity::SetOwner)
        .addProperty("HadOwner", &GCInstancedSceneEntity::GetHadOwner, &GCInstancedSceneEntity::SetHadOwner)
        .addProperty("PostSpeakDelay", &GCInstancedSceneEntity::GetPostSpeakDelay, &GCInstancedSceneEntity::SetPostSpeakDelay)
        .addProperty("PreDelay", &GCInstancedSceneEntity::GetPreDelay, &GCInstancedSceneEntity::SetPreDelay)
        .addProperty("IsBackground", &GCInstancedSceneEntity::GetIsBackground, &GCInstancedSceneEntity::SetIsBackground)
        .addProperty("RemoveOnCompletion", &GCInstancedSceneEntity::GetRemoveOnCompletion, &GCInstancedSceneEntity::SetRemoveOnCompletion)
        .addProperty("Target", &GCInstancedSceneEntity::GetTarget, &GCInstancedSceneEntity::SetTarget)
        .endClass();
}