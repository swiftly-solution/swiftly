#include "../../../core/scripting/generated/classes/GCAnimSequenceParams.h"
#include "../core.h"

void SetupLuaClassGCAnimSequenceParams(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimSequenceParams>("CAnimSequenceParams")
        .addProperty("FadeInTime", &GCAnimSequenceParams::GetFadeInTime, &GCAnimSequenceParams::SetFadeInTime)
        .addProperty("FadeOutTime", &GCAnimSequenceParams::GetFadeOutTime, &GCAnimSequenceParams::SetFadeOutTime)
        .endClass();
}