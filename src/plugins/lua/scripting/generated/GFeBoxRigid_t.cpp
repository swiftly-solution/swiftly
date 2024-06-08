#include "../../../core/scripting/generated/classes/GFeBoxRigid_t.h"
#include "../core.h"

void SetupLuaClassGFeBoxRigid_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeBoxRigid_t>("FeBoxRigid_t")
        .addProperty("Node", &GFeBoxRigid_t::GetNode, &GFeBoxRigid_t::SetNode)
        .addProperty("CollisionMask", &GFeBoxRigid_t::GetCollisionMask, &GFeBoxRigid_t::SetCollisionMask)
        .addProperty("Size", &GFeBoxRigid_t::GetSize, &GFeBoxRigid_t::SetSize)
        .addProperty("VertexMapIndex", &GFeBoxRigid_t::GetVertexMapIndex, &GFeBoxRigid_t::SetVertexMapIndex)
        .addProperty("Flags", &GFeBoxRigid_t::GetFlags, &GFeBoxRigid_t::SetFlags)
        .endClass();
}