#include "../../../core/scripting/generated/classes/GFeSimdRodConstraintAnim_t.h"
#include "../core.h"

void SetupLuaClassGFeSimdRodConstraintAnim_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdRodConstraintAnim_t>("FeSimdRodConstraintAnim_t")
        .addProperty("4Weight0", &GFeSimdRodConstraintAnim_t::Get4Weight0, &GFeSimdRodConstraintAnim_t::Set4Weight0)
        .addProperty("4RelaxationFactor", &GFeSimdRodConstraintAnim_t::Get4RelaxationFactor, &GFeSimdRodConstraintAnim_t::Set4RelaxationFactor)
        .endClass();
}