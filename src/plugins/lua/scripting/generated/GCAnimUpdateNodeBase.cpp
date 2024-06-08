#include "../../../core/scripting/generated/classes/GCAnimUpdateNodeBase.h"
#include "../core.h"

void SetupLuaClassGCAnimUpdateNodeBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimUpdateNodeBase>("CAnimUpdateNodeBase")
        .addProperty("NodePath", &GCAnimUpdateNodeBase::GetNodePath, &GCAnimUpdateNodeBase::SetNodePath)
        .addProperty("NetworkMode", &GCAnimUpdateNodeBase::GetNetworkMode, &GCAnimUpdateNodeBase::SetNetworkMode)
        .addProperty("Name", &GCAnimUpdateNodeBase::GetName, &GCAnimUpdateNodeBase::SetName)
        .endClass();
}