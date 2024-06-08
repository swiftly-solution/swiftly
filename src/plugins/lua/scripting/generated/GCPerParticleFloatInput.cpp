#include "../../../core/scripting/generated/classes/GCPerParticleFloatInput.h"
#include "../core.h"

void SetupLuaClassGCPerParticleFloatInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPerParticleFloatInput>("CPerParticleFloatInput")

        .endClass();
}