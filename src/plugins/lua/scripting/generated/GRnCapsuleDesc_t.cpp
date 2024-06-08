#include "../../../core/scripting/generated/classes/GRnCapsuleDesc_t.h"
#include "../core.h"

void SetupLuaClassGRnCapsuleDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnCapsuleDesc_t>("RnCapsuleDesc_t")
        .addProperty("Capsule", &GRnCapsuleDesc_t::GetCapsule, &GRnCapsuleDesc_t::SetCapsule)
        .endClass();
}