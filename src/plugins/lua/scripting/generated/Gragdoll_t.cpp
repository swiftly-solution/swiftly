#include "../../../core/scripting/generated/classes/Gragdoll_t.h"
#include "../core.h"

void SetupLuaClassGragdoll_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gragdoll_t>("ragdoll_t")
        .addProperty("List", &Gragdoll_t::GetList, &Gragdoll_t::SetList)
        .addProperty("BoneIndex", &Gragdoll_t::GetBoneIndex, &Gragdoll_t::SetBoneIndex)
        .addProperty("AllowStretch", &Gragdoll_t::GetAllowStretch, &Gragdoll_t::SetAllowStretch)
        .addProperty("Unused", &Gragdoll_t::GetUnused, &Gragdoll_t::SetUnused)
        .endClass();
}