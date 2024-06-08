#include "../../../core/scripting/generated/classes/GCBodyGroupAnimTag.h"
#include "../core.h"

void SetupLuaClassGCBodyGroupAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyGroupAnimTag>("CBodyGroupAnimTag")
        .addProperty("Priority", &GCBodyGroupAnimTag::GetPriority, &GCBodyGroupAnimTag::SetPriority)
        .addProperty("BodyGroupSettings", &GCBodyGroupAnimTag::GetBodyGroupSettings, &GCBodyGroupAnimTag::SetBodyGroupSettings)
        .endClass();
}