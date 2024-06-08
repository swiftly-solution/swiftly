#include "../../../core/scripting/generated/classes/GAnimationSnapshot_t.h"
#include "../core.h"

void SetupLuaClassGAnimationSnapshot_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimationSnapshot_t>("AnimationSnapshot_t")
        .addProperty("EntIndex", &GAnimationSnapshot_t::GetEntIndex, &GAnimationSnapshot_t::SetEntIndex)
        .addProperty("ModelName", &GAnimationSnapshot_t::GetModelName, &GAnimationSnapshot_t::SetModelName)
        .endClass();
}