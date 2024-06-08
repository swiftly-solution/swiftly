#include "../../../core/scripting/generated/classes/GCPointClientUIWorldTextPanel.h"
#include "../core.h"

void SetupLuaClassGCPointClientUIWorldTextPanel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointClientUIWorldTextPanel>("CPointClientUIWorldTextPanel")
        .addProperty("MessageText", &GCPointClientUIWorldTextPanel::GetMessageText, &GCPointClientUIWorldTextPanel::SetMessageText)
        .endClass();
}