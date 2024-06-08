#include "../../../core/scripting/generated/classes/GCAimMatrixUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCAimMatrixUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAimMatrixUpdateNode>("CAimMatrixUpdateNode")
        .addProperty("OpFixedSettings", &GCAimMatrixUpdateNode::GetOpFixedSettings, &GCAimMatrixUpdateNode::SetOpFixedSettings)
        .addProperty("Target", &GCAimMatrixUpdateNode::GetTarget, &GCAimMatrixUpdateNode::SetTarget)
        .addProperty("ParamIndex", &GCAimMatrixUpdateNode::GetParamIndex, &GCAimMatrixUpdateNode::SetParamIndex)
        .addProperty("ResetChild", &GCAimMatrixUpdateNode::GetResetChild, &GCAimMatrixUpdateNode::SetResetChild)
        .addProperty("LockWhenWaning", &GCAimMatrixUpdateNode::GetLockWhenWaning, &GCAimMatrixUpdateNode::SetLockWhenWaning)
        .endClass();
}