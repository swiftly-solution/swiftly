#include "../../../core/scripting/generated/classes/Gfogplayerparams_t.h"
#include "../core.h"

void SetupLuaClassGfogplayerparams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gfogplayerparams_t>("fogplayerparams_t")
        .addProperty("Ctrl", &Gfogplayerparams_t::GetCtrl, &Gfogplayerparams_t::SetCtrl)
        .addProperty("TransitionTime", &Gfogplayerparams_t::GetTransitionTime, &Gfogplayerparams_t::SetTransitionTime)
        .addProperty("OldColor", &Gfogplayerparams_t::GetOldColor, &Gfogplayerparams_t::SetOldColor)
        .addProperty("OldStart", &Gfogplayerparams_t::GetOldStart, &Gfogplayerparams_t::SetOldStart)
        .addProperty("OldEnd", &Gfogplayerparams_t::GetOldEnd, &Gfogplayerparams_t::SetOldEnd)
        .addProperty("OldMaxDensity", &Gfogplayerparams_t::GetOldMaxDensity, &Gfogplayerparams_t::SetOldMaxDensity)
        .addProperty("OldHDRColorScale", &Gfogplayerparams_t::GetOldHDRColorScale, &Gfogplayerparams_t::SetOldHDRColorScale)
        .addProperty("OldFarZ", &Gfogplayerparams_t::GetOldFarZ, &Gfogplayerparams_t::SetOldFarZ)
        .addProperty("NewColor", &Gfogplayerparams_t::GetNewColor, &Gfogplayerparams_t::SetNewColor)
        .addProperty("NewStart", &Gfogplayerparams_t::GetNewStart, &Gfogplayerparams_t::SetNewStart)
        .addProperty("NewEnd", &Gfogplayerparams_t::GetNewEnd, &Gfogplayerparams_t::SetNewEnd)
        .addProperty("NewMaxDensity", &Gfogplayerparams_t::GetNewMaxDensity, &Gfogplayerparams_t::SetNewMaxDensity)
        .addProperty("NewHDRColorScale", &Gfogplayerparams_t::GetNewHDRColorScale, &Gfogplayerparams_t::SetNewHDRColorScale)
        .addProperty("NewFarZ", &Gfogplayerparams_t::GetNewFarZ, &Gfogplayerparams_t::SetNewFarZ)
        .endClass();
}