#include "../../../core/scripting/generated/classes/GCMarkupVolumeTagged_NavGame.h"
#include "../core.h"

void SetupLuaClassGCMarkupVolumeTagged_NavGame(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMarkupVolumeTagged_NavGame>("CMarkupVolumeTagged_NavGame")
        .addProperty("FloodFillAttribute", &GCMarkupVolumeTagged_NavGame::GetFloodFillAttribute, &GCMarkupVolumeTagged_NavGame::SetFloodFillAttribute)
        .endClass();
}