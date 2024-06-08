#include "../../../core/scripting/generated/classes/GCInButtonState.h"
#include "../core.h"

void SetupLuaClassGCInButtonState(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInButtonState>("CInButtonState")
        .addProperty("ButtonStates", &GCInButtonState::GetButtonStates, &GCInButtonState::SetButtonStates)
        .endClass();
}