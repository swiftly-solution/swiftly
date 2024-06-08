#include "../../../core/scripting/generated/classes/GCFootFallAnimTag.h"
#include "../core.h"

void SetupLuaClassGCFootFallAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootFallAnimTag>("CFootFallAnimTag")
        .addProperty("Foot", &GCFootFallAnimTag::GetFoot, &GCFootFallAnimTag::SetFoot)
        .endClass();
}