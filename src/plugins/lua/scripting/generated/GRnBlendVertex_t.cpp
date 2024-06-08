#include "../../../core/scripting/generated/classes/GRnBlendVertex_t.h"
#include "../core.h"

void SetupLuaClassGRnBlendVertex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnBlendVertex_t>("RnBlendVertex_t")
        .addProperty("Weight0", &GRnBlendVertex_t::GetWeight0, &GRnBlendVertex_t::SetWeight0)
        .addProperty("Index0", &GRnBlendVertex_t::GetIndex0, &GRnBlendVertex_t::SetIndex0)
        .addProperty("Weight1", &GRnBlendVertex_t::GetWeight1, &GRnBlendVertex_t::SetWeight1)
        .addProperty("Index1", &GRnBlendVertex_t::GetIndex1, &GRnBlendVertex_t::SetIndex1)
        .addProperty("Weight2", &GRnBlendVertex_t::GetWeight2, &GRnBlendVertex_t::SetWeight2)
        .addProperty("Index2", &GRnBlendVertex_t::GetIndex2, &GRnBlendVertex_t::SetIndex2)
        .addProperty("Flags", &GRnBlendVertex_t::GetFlags, &GRnBlendVertex_t::SetFlags)
        .addProperty("TargetIndex", &GRnBlendVertex_t::GetTargetIndex, &GRnBlendVertex_t::SetTargetIndex)
        .endClass();
}