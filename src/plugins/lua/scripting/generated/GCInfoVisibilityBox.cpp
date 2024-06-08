#include "../../../core/scripting/generated/classes/GCInfoVisibilityBox.h"
#include "../core.h"

void SetupLuaClassGCInfoVisibilityBox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoVisibilityBox>("CInfoVisibilityBox")
        .addProperty("Mode", &GCInfoVisibilityBox::GetMode, &GCInfoVisibilityBox::SetMode)
        .addProperty("BoxSize", &GCInfoVisibilityBox::GetBoxSize, &GCInfoVisibilityBox::SetBoxSize)
        .addProperty("Enabled", &GCInfoVisibilityBox::GetEnabled, &GCInfoVisibilityBox::SetEnabled)
        .endClass();
}