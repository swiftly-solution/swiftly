#include "../../../core/scripting/generated/classes/GVPhysics2ShapeDef_t.h"
#include "../core.h"

void SetupLuaClassGVPhysics2ShapeDef_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysics2ShapeDef_t>("VPhysics2ShapeDef_t")
        .addProperty("Spheres", &GVPhysics2ShapeDef_t::GetSpheres, &GVPhysics2ShapeDef_t::SetSpheres)
        .addProperty("Capsules", &GVPhysics2ShapeDef_t::GetCapsules, &GVPhysics2ShapeDef_t::SetCapsules)
        .addProperty("Hulls", &GVPhysics2ShapeDef_t::GetHulls, &GVPhysics2ShapeDef_t::SetHulls)
        .addProperty("Meshes", &GVPhysics2ShapeDef_t::GetMeshes, &GVPhysics2ShapeDef_t::SetMeshes)
        .addProperty("CollisionAttributeIndices", &GVPhysics2ShapeDef_t::GetCollisionAttributeIndices, &GVPhysics2ShapeDef_t::SetCollisionAttributeIndices)
        .endClass();
}