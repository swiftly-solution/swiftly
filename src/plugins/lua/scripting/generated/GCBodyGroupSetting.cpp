#include "../../../core/scripting/generated/classes/GCBodyGroupSetting.h"
#include "../core.h"

void SetupLuaClassGCBodyGroupSetting(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyGroupSetting>("CBodyGroupSetting")
        .addProperty("BodyGroupName", &GCBodyGroupSetting::GetBodyGroupName, &GCBodyGroupSetting::SetBodyGroupName)
        .addProperty("BodyGroupOption", &GCBodyGroupSetting::GetBodyGroupOption, &GCBodyGroupSetting::SetBodyGroupOption)
        .endClass();
}