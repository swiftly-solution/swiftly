#include "../../../core/scripting/generated/classes/GFeStiffHingeBuild_t.h"
#include "../core.h"

void SetupLuaClassGFeStiffHingeBuild_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeStiffHingeBuild_t>("FeStiffHingeBuild_t")
        .addProperty("MaxAngle", &GFeStiffHingeBuild_t::GetMaxAngle, &GFeStiffHingeBuild_t::SetMaxAngle)
        .addProperty("Strength", &GFeStiffHingeBuild_t::GetStrength, &GFeStiffHingeBuild_t::SetStrength)
        .addProperty("MotionBias", &GFeStiffHingeBuild_t::GetMotionBias, &GFeStiffHingeBuild_t::SetMotionBias)
        .addProperty("Node", &GFeStiffHingeBuild_t::GetNode, &GFeStiffHingeBuild_t::SetNode)
        .endClass();
}