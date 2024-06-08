#include "../../../core/scripting/generated/classes/GCNmFrameSnapEvent.h"
#include "../core.h"

void SetupLuaClassGCNmFrameSnapEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmFrameSnapEvent>("CNmFrameSnapEvent")
        .addProperty("FrameSnapMode", &GCNmFrameSnapEvent::GetFrameSnapMode, &GCNmFrameSnapEvent::SetFrameSnapMode)
        .endClass();
}