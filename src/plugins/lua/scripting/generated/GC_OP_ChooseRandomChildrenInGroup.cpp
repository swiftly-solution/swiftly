#include "../../../core/scripting/generated/classes/GC_OP_ChooseRandomChildrenInGroup.h"
#include "../core.h"

void SetupLuaClassGC_OP_ChooseRandomChildrenInGroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ChooseRandomChildrenInGroup>("C_OP_ChooseRandomChildrenInGroup")
        .addProperty("ChildGroupID", &GC_OP_ChooseRandomChildrenInGroup::GetChildGroupID, &GC_OP_ChooseRandomChildrenInGroup::SetChildGroupID)
        .addProperty("NumberOfChildren", &GC_OP_ChooseRandomChildrenInGroup::GetNumberOfChildren, &GC_OP_ChooseRandomChildrenInGroup::SetNumberOfChildren)
        .endClass();
}