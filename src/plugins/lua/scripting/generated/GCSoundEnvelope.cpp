#include "../../../core/scripting/generated/classes/GCSoundEnvelope.h"
#include "../core.h"

void SetupLuaClassGCSoundEnvelope(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEnvelope>("CSoundEnvelope")
        .addProperty("Current", &GCSoundEnvelope::GetCurrent, &GCSoundEnvelope::SetCurrent)
        .addProperty("Target", &GCSoundEnvelope::GetTarget, &GCSoundEnvelope::SetTarget)
        .addProperty("Rate", &GCSoundEnvelope::GetRate, &GCSoundEnvelope::SetRate)
        .addProperty("Forceupdate", &GCSoundEnvelope::GetForceupdate, &GCSoundEnvelope::SetForceupdate)
        .endClass();
}