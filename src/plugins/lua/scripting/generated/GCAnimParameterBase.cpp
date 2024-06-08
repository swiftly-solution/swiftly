#include "../../../core/scripting/generated/classes/GCAnimParameterBase.h"
#include "../core.h"

void SetupLuaClassGCAnimParameterBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimParameterBase>("CAnimParameterBase")
        .addProperty("Comment", &GCAnimParameterBase::GetComment, &GCAnimParameterBase::SetComment)
        .addProperty("Group", &GCAnimParameterBase::GetGroup, &GCAnimParameterBase::SetGroup)
        .addProperty("Id", &GCAnimParameterBase::GetId, &GCAnimParameterBase::SetId)
        .addProperty("ComponentName", &GCAnimParameterBase::GetComponentName, &GCAnimParameterBase::SetComponentName)
        .addProperty("NetworkingRequested", &GCAnimParameterBase::GetNetworkingRequested, &GCAnimParameterBase::SetNetworkingRequested)
        .addProperty("IsReferenced", &GCAnimParameterBase::GetIsReferenced, &GCAnimParameterBase::SetIsReferenced)
        .endClass();
}