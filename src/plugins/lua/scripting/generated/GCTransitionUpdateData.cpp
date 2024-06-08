#include "../../../core/scripting/generated/classes/GCTransitionUpdateData.h"
#include "../core.h"

void SetupLuaClassGCTransitionUpdateData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTransitionUpdateData>("CTransitionUpdateData")
        .addProperty("SrcStateIndex", &GCTransitionUpdateData::GetSrcStateIndex, &GCTransitionUpdateData::SetSrcStateIndex)
        .addProperty("DestStateIndex", &GCTransitionUpdateData::GetDestStateIndex, &GCTransitionUpdateData::SetDestStateIndex)
        .endClass();
}