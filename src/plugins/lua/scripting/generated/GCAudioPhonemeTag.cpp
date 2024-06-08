#include "../../../core/scripting/generated/classes/GCAudioPhonemeTag.h"
#include "../core.h"

void SetupLuaClassGCAudioPhonemeTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAudioPhonemeTag>("CAudioPhonemeTag")
        .addProperty("StartTime", &GCAudioPhonemeTag::GetStartTime, &GCAudioPhonemeTag::SetStartTime)
        .addProperty("EndTime", &GCAudioPhonemeTag::GetEndTime, &GCAudioPhonemeTag::SetEndTime)
        .addProperty("PhonemeCode", &GCAudioPhonemeTag::GetPhonemeCode, &GCAudioPhonemeTag::SetPhonemeCode)
        .endClass();
}