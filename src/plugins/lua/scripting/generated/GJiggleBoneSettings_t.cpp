#include "../../../core/scripting/generated/classes/GJiggleBoneSettings_t.h"
#include "../core.h"

void SetupLuaClassGJiggleBoneSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GJiggleBoneSettings_t>("JiggleBoneSettings_t")
        .addProperty("BoneIndex", &GJiggleBoneSettings_t::GetBoneIndex, &GJiggleBoneSettings_t::SetBoneIndex)
        .addProperty("SpringStrength", &GJiggleBoneSettings_t::GetSpringStrength, &GJiggleBoneSettings_t::SetSpringStrength)
        .addProperty("MaxTimeStep", &GJiggleBoneSettings_t::GetMaxTimeStep, &GJiggleBoneSettings_t::SetMaxTimeStep)
        .addProperty("Damping", &GJiggleBoneSettings_t::GetDamping, &GJiggleBoneSettings_t::SetDamping)
        .addProperty("BoundsMaxLS", &GJiggleBoneSettings_t::GetBoundsMaxLS, &GJiggleBoneSettings_t::SetBoundsMaxLS)
        .addProperty("BoundsMinLS", &GJiggleBoneSettings_t::GetBoundsMinLS, &GJiggleBoneSettings_t::SetBoundsMinLS)
        .addProperty("SimSpace", &GJiggleBoneSettings_t::GetSimSpace, &GJiggleBoneSettings_t::SetSimSpace)
        .endClass();
}