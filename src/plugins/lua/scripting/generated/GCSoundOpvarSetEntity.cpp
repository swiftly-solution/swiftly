#include "../../../core/scripting/generated/classes/GCSoundOpvarSetEntity.h"
#include "../core.h"

void SetupLuaClassGCSoundOpvarSetEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetEntity>("CSoundOpvarSetEntity")
        .addProperty("StackName", &GCSoundOpvarSetEntity::GetStackName, &GCSoundOpvarSetEntity::SetStackName)
        .addProperty("OperatorName", &GCSoundOpvarSetEntity::GetOperatorName, &GCSoundOpvarSetEntity::SetOperatorName)
        .addProperty("OpvarName", &GCSoundOpvarSetEntity::GetOpvarName, &GCSoundOpvarSetEntity::SetOpvarName)
        .addProperty("OpvarType", &GCSoundOpvarSetEntity::GetOpvarType, &GCSoundOpvarSetEntity::SetOpvarType)
        .addProperty("OpvarIndex", &GCSoundOpvarSetEntity::GetOpvarIndex, &GCSoundOpvarSetEntity::SetOpvarIndex)
        .addProperty("OpvarValue", &GCSoundOpvarSetEntity::GetOpvarValue, &GCSoundOpvarSetEntity::SetOpvarValue)
        .addProperty("OpvarValueString", &GCSoundOpvarSetEntity::GetOpvarValueString, &GCSoundOpvarSetEntity::SetOpvarValueString)
        .addProperty("SetOnSpawn", &GCSoundOpvarSetEntity::GetSetOnSpawn, &GCSoundOpvarSetEntity::SetSetOnSpawn)
        .endClass();
}