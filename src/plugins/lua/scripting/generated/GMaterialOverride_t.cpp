#include "../../../core/scripting/generated/classes/GMaterialOverride_t.h"
#include "../core.h"

void SetupLuaClassGMaterialOverride_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialOverride_t>("MaterialOverride_t")
        .addProperty("SubSceneObject", &GMaterialOverride_t::GetSubSceneObject, &GMaterialOverride_t::SetSubSceneObject)
        .addProperty("DrawCallIndex", &GMaterialOverride_t::GetDrawCallIndex, &GMaterialOverride_t::SetDrawCallIndex)
        .endClass();
}