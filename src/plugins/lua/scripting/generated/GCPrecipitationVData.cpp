#include "../../../core/scripting/generated/classes/GCPrecipitationVData.h"
#include "../core.h"

void SetupLuaClassGCPrecipitationVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPrecipitationVData>("CPrecipitationVData")
        .addProperty("InnerDistance", &GCPrecipitationVData::GetInnerDistance, &GCPrecipitationVData::SetInnerDistance)
        .addProperty("AttachType", &GCPrecipitationVData::GetAttachType, &GCPrecipitationVData::SetAttachType)
        .addProperty("BatchSameVolumeType", &GCPrecipitationVData::GetBatchSameVolumeType, &GCPrecipitationVData::SetBatchSameVolumeType)
        .addProperty("RTEnvCP", &GCPrecipitationVData::GetRTEnvCP, &GCPrecipitationVData::SetRTEnvCP)
        .addProperty("RTEnvCPComponent", &GCPrecipitationVData::GetRTEnvCPComponent, &GCPrecipitationVData::SetRTEnvCPComponent)
        .addProperty("Modifier", &GCPrecipitationVData::GetModifier, &GCPrecipitationVData::SetModifier)
        .endClass();
}