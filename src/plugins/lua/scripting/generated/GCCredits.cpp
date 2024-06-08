#include "../../../core/scripting/generated/classes/GCCredits.h"
#include "../core.h"

void SetupLuaClassGCCredits(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCredits>("CCredits")
        .addProperty("OnCreditsDone", &GCCredits::GetOnCreditsDone, &GCCredits::SetOnCreditsDone)
        .addProperty("RolledOutroCredits", &GCCredits::GetRolledOutroCredits, &GCCredits::SetRolledOutroCredits)
        .addProperty("LogoLength", &GCCredits::GetLogoLength, &GCCredits::SetLogoLength)
        .endClass();
}