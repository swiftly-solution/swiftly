#include "../../../core/scripting/generated/classes/GCSequenceFinishedAnimTag.h"
#include "../core.h"

void SetupLuaClassGCSequenceFinishedAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSequenceFinishedAnimTag>("CSequenceFinishedAnimTag")
        .addProperty("SequenceName", &GCSequenceFinishedAnimTag::GetSequenceName, &GCSequenceFinishedAnimTag::SetSequenceName)
        .endClass();
}