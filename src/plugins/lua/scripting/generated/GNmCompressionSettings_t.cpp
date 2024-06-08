#include "../../../core/scripting/generated/classes/GNmCompressionSettings_t.h"
#include "../core.h"

void SetupLuaClassGNmCompressionSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNmCompressionSettings_t>("NmCompressionSettings_t")
        .addProperty("TranslationRangeX", &GNmCompressionSettings_t::GetTranslationRangeX, &GNmCompressionSettings_t::SetTranslationRangeX)
        .addProperty("TranslationRangeY", &GNmCompressionSettings_t::GetTranslationRangeY, &GNmCompressionSettings_t::SetTranslationRangeY)
        .addProperty("TranslationRangeZ", &GNmCompressionSettings_t::GetTranslationRangeZ, &GNmCompressionSettings_t::SetTranslationRangeZ)
        .addProperty("ScaleRange", &GNmCompressionSettings_t::GetScaleRange, &GNmCompressionSettings_t::SetScaleRange)
        .addProperty("ConstantRotation", &GNmCompressionSettings_t::GetConstantRotation, &GNmCompressionSettings_t::SetConstantRotation)
        .addProperty("IsRotationStatic", &GNmCompressionSettings_t::GetIsRotationStatic, &GNmCompressionSettings_t::SetIsRotationStatic)
        .addProperty("IsTranslationStatic", &GNmCompressionSettings_t::GetIsTranslationStatic, &GNmCompressionSettings_t::SetIsTranslationStatic)
        .addProperty("IsScaleStatic", &GNmCompressionSettings_t::GetIsScaleStatic, &GNmCompressionSettings_t::SetIsScaleStatic)
        .endClass();
}