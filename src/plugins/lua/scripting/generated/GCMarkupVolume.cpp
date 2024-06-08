#include "../../../core/scripting/generated/classes/GCMarkupVolume.h"
#include "../core.h"

void SetupLuaClassGCMarkupVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMarkupVolume>("CMarkupVolume")
        .addProperty("Disabled", &GCMarkupVolume::GetDisabled, &GCMarkupVolume::SetDisabled)
        .endClass();
}