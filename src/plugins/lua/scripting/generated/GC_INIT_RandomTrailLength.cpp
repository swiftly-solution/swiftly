#include "../../../core/scripting/generated/classes/GC_INIT_RandomTrailLength.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomTrailLength(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomTrailLength>("C_INIT_RandomTrailLength")
        .addProperty("MinLength", &GC_INIT_RandomTrailLength::GetMinLength, &GC_INIT_RandomTrailLength::SetMinLength)
        .addProperty("MaxLength", &GC_INIT_RandomTrailLength::GetMaxLength, &GC_INIT_RandomTrailLength::SetMaxLength)
        .addProperty("LengthRandExponent", &GC_INIT_RandomTrailLength::GetLengthRandExponent, &GC_INIT_RandomTrailLength::SetLengthRandExponent)
        .endClass();
}