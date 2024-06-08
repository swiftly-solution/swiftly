#include "../../../core/scripting/generated/classes/GIKTargetSettings_t.h"
#include "../core.h"

void SetupLuaClassGIKTargetSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIKTargetSettings_t>("IKTargetSettings_t")
        .addProperty("TargetSource", &GIKTargetSettings_t::GetTargetSource, &GIKTargetSettings_t::SetTargetSource)
        .addProperty("Bone", &GIKTargetSettings_t::GetBone, &GIKTargetSettings_t::SetBone)
        .addProperty("AnimgraphParameterNamePosition", &GIKTargetSettings_t::GetAnimgraphParameterNamePosition, &GIKTargetSettings_t::SetAnimgraphParameterNamePosition)
        .addProperty("AnimgraphParameterNameOrientation", &GIKTargetSettings_t::GetAnimgraphParameterNameOrientation, &GIKTargetSettings_t::SetAnimgraphParameterNameOrientation)
        .addProperty("TargetCoordSystem", &GIKTargetSettings_t::GetTargetCoordSystem, &GIKTargetSettings_t::SetTargetCoordSystem)
        .endClass();
}