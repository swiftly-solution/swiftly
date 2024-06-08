#include "../../../core/scripting/generated/classes/GCTriggerSndSosOpvar.h"
#include "../core.h"

void SetupLuaClassGCTriggerSndSosOpvar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerSndSosOpvar>("CTriggerSndSosOpvar")
        .addProperty("Position", &GCTriggerSndSosOpvar::GetPosition, &GCTriggerSndSosOpvar::SetPosition)
        .addProperty("CenterSize", &GCTriggerSndSosOpvar::GetCenterSize, &GCTriggerSndSosOpvar::SetCenterSize)
        .addProperty("MinVal", &GCTriggerSndSosOpvar::GetMinVal, &GCTriggerSndSosOpvar::SetMinVal)
        .addProperty("MaxVal", &GCTriggerSndSosOpvar::GetMaxVal, &GCTriggerSndSosOpvar::SetMaxVal)
        .addProperty("OpvarName", &GCTriggerSndSosOpvar::GetOpvarName, &GCTriggerSndSosOpvar::SetOpvarName)
        .addProperty("StackName", &GCTriggerSndSosOpvar::GetStackName, &GCTriggerSndSosOpvar::SetStackName)
        .addProperty("OperatorName", &GCTriggerSndSosOpvar::GetOperatorName, &GCTriggerSndSosOpvar::SetOperatorName)
        .addProperty("VolIs2D", &GCTriggerSndSosOpvar::GetVolIs2D, &GCTriggerSndSosOpvar::SetVolIs2D)
        .addProperty("OpvarNameChar", &GCTriggerSndSosOpvar::GetOpvarNameChar, &GCTriggerSndSosOpvar::SetOpvarNameChar)
        .addProperty("StackNameChar", &GCTriggerSndSosOpvar::GetStackNameChar, &GCTriggerSndSosOpvar::SetStackNameChar)
        .addProperty("OperatorNameChar", &GCTriggerSndSosOpvar::GetOperatorNameChar, &GCTriggerSndSosOpvar::SetOperatorNameChar)
        .addProperty("VecNormPos", &GCTriggerSndSosOpvar::GetVecNormPos, &GCTriggerSndSosOpvar::SetVecNormPos)
        .addProperty("NormCenterSize", &GCTriggerSndSosOpvar::GetNormCenterSize, &GCTriggerSndSosOpvar::SetNormCenterSize)
        .endClass();
}