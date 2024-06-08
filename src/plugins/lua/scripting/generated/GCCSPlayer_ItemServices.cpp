#include "../../../core/scripting/generated/classes/GCCSPlayer_ItemServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayer_ItemServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_ItemServices>("CCSPlayer_ItemServices")
        .addProperty("HasDefuser", &GCCSPlayer_ItemServices::GetHasDefuser, &GCCSPlayer_ItemServices::SetHasDefuser)
        .addProperty("HasHelmet", &GCCSPlayer_ItemServices::GetHasHelmet, &GCCSPlayer_ItemServices::SetHasHelmet)
        .addProperty("HasHeavyArmor", &GCCSPlayer_ItemServices::GetHasHeavyArmor, &GCCSPlayer_ItemServices::SetHasHeavyArmor)
        .endClass();
}