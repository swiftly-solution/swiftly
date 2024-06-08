#include "../../../core/scripting/generated/classes/GCSoundOpvarSetPointBase.h"
#include "../core.h"

void SetupLuaClassGCSoundOpvarSetPointBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetPointBase>("CSoundOpvarSetPointBase")
        .addProperty("Disabled", &GCSoundOpvarSetPointBase::GetDisabled, &GCSoundOpvarSetPointBase::SetDisabled)
        .addProperty("Source", &GCSoundOpvarSetPointBase::GetSource, &GCSoundOpvarSetPointBase::SetSource)
        .addProperty("SourceEntityName", &GCSoundOpvarSetPointBase::GetSourceEntityName, &GCSoundOpvarSetPointBase::SetSourceEntityName)
        .addProperty("LastPosition", &GCSoundOpvarSetPointBase::GetLastPosition, &GCSoundOpvarSetPointBase::SetLastPosition)
        .addProperty("StackName", &GCSoundOpvarSetPointBase::GetStackName, &GCSoundOpvarSetPointBase::SetStackName)
        .addProperty("OperatorName", &GCSoundOpvarSetPointBase::GetOperatorName, &GCSoundOpvarSetPointBase::SetOperatorName)
        .addProperty("OpvarName", &GCSoundOpvarSetPointBase::GetOpvarName, &GCSoundOpvarSetPointBase::SetOpvarName)
        .addProperty("OpvarIndex", &GCSoundOpvarSetPointBase::GetOpvarIndex, &GCSoundOpvarSetPointBase::SetOpvarIndex)
        .addProperty("UseAutoCompare", &GCSoundOpvarSetPointBase::GetUseAutoCompare, &GCSoundOpvarSetPointBase::SetUseAutoCompare)
        .endClass();
}