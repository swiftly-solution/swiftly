#include "../../../core/scripting/generated/classes/GJiggleBoneSettingsList_t.h"
#include "../core.h"

void SetupLuaClassGJiggleBoneSettingsList_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GJiggleBoneSettingsList_t>("JiggleBoneSettingsList_t")
        .addProperty("BoneSettings", &GJiggleBoneSettingsList_t::GetBoneSettings, &GJiggleBoneSettingsList_t::SetBoneSettings)
        .endClass();
}