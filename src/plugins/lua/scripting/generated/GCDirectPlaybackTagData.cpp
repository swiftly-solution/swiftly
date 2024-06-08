#include "../../../core/scripting/generated/classes/GCDirectPlaybackTagData.h"
#include "../core.h"

void SetupLuaClassGCDirectPlaybackTagData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDirectPlaybackTagData>("CDirectPlaybackTagData")
        .addProperty("SequenceName", &GCDirectPlaybackTagData::GetSequenceName, &GCDirectPlaybackTagData::SetSequenceName)
        .addProperty("Tags", &GCDirectPlaybackTagData::GetTags, &GCDirectPlaybackTagData::SetTags)
        .endClass();
}