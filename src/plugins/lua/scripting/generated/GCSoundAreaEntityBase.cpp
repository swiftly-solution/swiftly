#include "../../../core/scripting/generated/classes/GCSoundAreaEntityBase.h"
#include "../core.h"

void SetupLuaClassGCSoundAreaEntityBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundAreaEntityBase>("CSoundAreaEntityBase")
        .addProperty("Disabled", &GCSoundAreaEntityBase::GetDisabled, &GCSoundAreaEntityBase::SetDisabled)
        .addProperty("SoundAreaType", &GCSoundAreaEntityBase::GetSoundAreaType, &GCSoundAreaEntityBase::SetSoundAreaType)
        .addProperty("Pos", &GCSoundAreaEntityBase::GetPos, &GCSoundAreaEntityBase::SetPos)
        .endClass();
}