#include "../../../core/scripting/generated/classes/GNmCompressionSettings_t__QuantizationRange_t.h"
#include "../core.h"

void SetupLuaClassGNmCompressionSettings_t__QuantizationRange_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNmCompressionSettings_t__QuantizationRange_t>("NmCompressionSettings_t__QuantizationRange_t")
        .addProperty("RangeStart", &GNmCompressionSettings_t__QuantizationRange_t::GetRangeStart, &GNmCompressionSettings_t__QuantizationRange_t::SetRangeStart)
        .addProperty("RangeLength", &GNmCompressionSettings_t__QuantizationRange_t::GetRangeLength, &GNmCompressionSettings_t__QuantizationRange_t::SetRangeLength)
        .endClass();
}