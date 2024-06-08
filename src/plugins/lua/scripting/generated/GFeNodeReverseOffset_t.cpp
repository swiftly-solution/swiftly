#include "../../../core/scripting/generated/classes/GFeNodeReverseOffset_t.h"
#include "../core.h"

void SetupLuaClassGFeNodeReverseOffset_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeNodeReverseOffset_t>("FeNodeReverseOffset_t")
        .addProperty("Offset", &GFeNodeReverseOffset_t::GetOffset, &GFeNodeReverseOffset_t::SetOffset)
        .addProperty("BoneCtrl", &GFeNodeReverseOffset_t::GetBoneCtrl, &GFeNodeReverseOffset_t::SetBoneCtrl)
        .addProperty("TargetNode", &GFeNodeReverseOffset_t::GetTargetNode, &GFeNodeReverseOffset_t::SetTargetNode)
        .endClass();
}