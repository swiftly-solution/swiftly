#include "../../../core/scripting/generated/classes/GCInfoDynamicShadowHintBox.h"
#include "../core.h"

void SetupLuaClassGCInfoDynamicShadowHintBox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoDynamicShadowHintBox>("CInfoDynamicShadowHintBox")
        .addProperty("BoxMins", &GCInfoDynamicShadowHintBox::GetBoxMins, &GCInfoDynamicShadowHintBox::SetBoxMins)
        .addProperty("BoxMaxs", &GCInfoDynamicShadowHintBox::GetBoxMaxs, &GCInfoDynamicShadowHintBox::SetBoxMaxs)
        .endClass();
}