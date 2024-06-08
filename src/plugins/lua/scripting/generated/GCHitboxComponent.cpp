#include "../../../core/scripting/generated/classes/GCHitboxComponent.h"
#include "../core.h"

void SetupLuaClassGCHitboxComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHitboxComponent>("CHitboxComponent")
        .addProperty("DisabledHitGroups", &GCHitboxComponent::GetDisabledHitGroups, &GCHitboxComponent::SetDisabledHitGroups)
        .endClass();
}