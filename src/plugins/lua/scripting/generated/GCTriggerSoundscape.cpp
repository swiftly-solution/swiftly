#include "../../../core/scripting/generated/classes/GCTriggerSoundscape.h"
#include "../core.h"

void SetupLuaClassGCTriggerSoundscape(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerSoundscape>("CTriggerSoundscape")
        .addProperty("Soundscape", &GCTriggerSoundscape::GetSoundscape, &GCTriggerSoundscape::SetSoundscape)
        .addProperty("SoundscapeName", &GCTriggerSoundscape::GetSoundscapeName, &GCTriggerSoundscape::SetSoundscapeName)
        .endClass();
}