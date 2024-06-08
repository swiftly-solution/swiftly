#include "../../../core/scripting/generated/classes/GFeSphereRigid_t.h"
#include "../core.h"

void SetupLuaClassGFeSphereRigid_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSphereRigid_t>("FeSphereRigid_t")
        .addProperty("Sphere", &GFeSphereRigid_t::GetSphere, &GFeSphereRigid_t::SetSphere)
        .addProperty("Node", &GFeSphereRigid_t::GetNode, &GFeSphereRigid_t::SetNode)
        .addProperty("CollisionMask", &GFeSphereRigid_t::GetCollisionMask, &GFeSphereRigid_t::SetCollisionMask)
        .addProperty("VertexMapIndex", &GFeSphereRigid_t::GetVertexMapIndex, &GFeSphereRigid_t::SetVertexMapIndex)
        .addProperty("Flags", &GFeSphereRigid_t::GetFlags, &GFeSphereRigid_t::SetFlags)
        .endClass();
}