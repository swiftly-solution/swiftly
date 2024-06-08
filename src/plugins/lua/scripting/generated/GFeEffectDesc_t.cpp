#include "../../../core/scripting/generated/classes/GFeEffectDesc_t.h"
#include "../core.h"

void SetupLuaClassGFeEffectDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeEffectDesc_t>("FeEffectDesc_t")
        .addProperty("Name", &GFeEffectDesc_t::GetName, &GFeEffectDesc_t::SetName)
        .addProperty("NameHash", &GFeEffectDesc_t::GetNameHash, &GFeEffectDesc_t::SetNameHash)
        .addProperty("Type", &GFeEffectDesc_t::GetType, &GFeEffectDesc_t::SetType)
        .endClass();
}