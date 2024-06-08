#include "../../../core/scripting/generated/classes/GAggregateSceneObject_t.h"
#include "../core.h"

void SetupLuaClassGAggregateSceneObject_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAggregateSceneObject_t>("AggregateSceneObject_t")
        .addProperty("AllFlags", &GAggregateSceneObject_t::GetAllFlags, &GAggregateSceneObject_t::SetAllFlags)
        .addProperty("AnyFlags", &GAggregateSceneObject_t::GetAnyFlags, &GAggregateSceneObject_t::SetAnyFlags)
        .addProperty("Layer", &GAggregateSceneObject_t::GetLayer, &GAggregateSceneObject_t::SetLayer)
        .addProperty("AggregateMeshes", &GAggregateSceneObject_t::GetAggregateMeshes, &GAggregateSceneObject_t::SetAggregateMeshes)
        .addProperty("LodSetups", &GAggregateSceneObject_t::GetLodSetups, &GAggregateSceneObject_t::SetLodSetups)
        .addProperty("VisClusterMembership", &GAggregateSceneObject_t::GetVisClusterMembership, &GAggregateSceneObject_t::SetVisClusterMembership)
        .addProperty("FragmentTransforms", &GAggregateSceneObject_t::GetFragmentTransforms, &GAggregateSceneObject_t::SetFragmentTransforms)
        .endClass();
}