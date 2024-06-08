#include "../../../core/scripting/generated/classes/Gsky3dparams_t.h"
#include "../core.h"

void SetupLuaClassGsky3dparams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gsky3dparams_t>("sky3dparams_t")
        .addProperty("Scale", &Gsky3dparams_t::GetScale, &Gsky3dparams_t::SetScale)
        .addProperty("Origin", &Gsky3dparams_t::GetOrigin, &Gsky3dparams_t::SetOrigin)
        .addProperty("Clip3DSkyBoxNearToWorldFar", &Gsky3dparams_t::GetClip3DSkyBoxNearToWorldFar, &Gsky3dparams_t::SetClip3DSkyBoxNearToWorldFar)
        .addProperty("Clip3DSkyBoxNearToWorldFarOffset", &Gsky3dparams_t::GetClip3DSkyBoxNearToWorldFarOffset, &Gsky3dparams_t::SetClip3DSkyBoxNearToWorldFarOffset)
        .addProperty("Fog", &Gsky3dparams_t::GetFog, &Gsky3dparams_t::SetFog)
        .addProperty("WorldGroupID", &Gsky3dparams_t::GetWorldGroupID, &Gsky3dparams_t::SetWorldGroupID)
        .endClass();
}