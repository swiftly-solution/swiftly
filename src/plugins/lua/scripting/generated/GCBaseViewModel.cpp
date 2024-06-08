#include "../../../core/scripting/generated/classes/GCBaseViewModel.h"
#include "../core.h"

void SetupLuaClassGCBaseViewModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseViewModel>("CBaseViewModel")
        .addProperty("LastFacing", &GCBaseViewModel::GetLastFacing, &GCBaseViewModel::SetLastFacing)
        .addProperty("ViewModelIndex", &GCBaseViewModel::GetViewModelIndex, &GCBaseViewModel::SetViewModelIndex)
        .addProperty("AnimationParity", &GCBaseViewModel::GetAnimationParity, &GCBaseViewModel::SetAnimationParity)
        .addProperty("AnimationStartTime", &GCBaseViewModel::GetAnimationStartTime, &GCBaseViewModel::SetAnimationStartTime)
        .addProperty("Weapon", &GCBaseViewModel::GetWeapon, &GCBaseViewModel::SetWeapon)
        .addProperty("VMName", &GCBaseViewModel::GetVMName, &GCBaseViewModel::SetVMName)
        .addProperty("AnimationPrefix", &GCBaseViewModel::GetAnimationPrefix, &GCBaseViewModel::SetAnimationPrefix)
        .addProperty("OldLayer", &GCBaseViewModel::GetOldLayer, &GCBaseViewModel::SetOldLayer)
        .addProperty("OldLayerStartTime", &GCBaseViewModel::GetOldLayerStartTime, &GCBaseViewModel::SetOldLayerStartTime)
        .addProperty("ControlPanel", &GCBaseViewModel::GetControlPanel, &GCBaseViewModel::SetControlPanel)
        .endClass();
}