#include "../../../core/scripting/generated/classes/GCMessageEntity.h"
#include "../core.h"

void SetupLuaClassGCMessageEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMessageEntity>("CMessageEntity")
        .addProperty("Radius", &GCMessageEntity::GetRadius, &GCMessageEntity::SetRadius)
        .addProperty("MessageText", &GCMessageEntity::GetMessageText, &GCMessageEntity::SetMessageText)
        .addProperty("DrawText", &GCMessageEntity::GetDrawText, &GCMessageEntity::SetDrawText)
        .addProperty("DeveloperOnly", &GCMessageEntity::GetDeveloperOnly, &GCMessageEntity::SetDeveloperOnly)
        .addProperty("Enabled", &GCMessageEntity::GetEnabled, &GCMessageEntity::SetEnabled)
        .endClass();
}