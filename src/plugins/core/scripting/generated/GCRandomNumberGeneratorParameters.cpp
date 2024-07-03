#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRandomNumberGeneratorParameters::GCRandomNumberGeneratorParameters(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRandomNumberGeneratorParameters::GCRandomNumberGeneratorParameters(void *ptr) {
    m_ptr = ptr;
}
bool GCRandomNumberGeneratorParameters::GetDistributeEvenly() const {
    return GetSchemaValue<bool>(m_ptr, "CRandomNumberGeneratorParameters", "m_bDistributeEvenly");
}
void GCRandomNumberGeneratorParameters::SetDistributeEvenly(bool value) {
    SetSchemaValue(m_ptr, "CRandomNumberGeneratorParameters", "m_bDistributeEvenly", false, value);
}
int32_t GCRandomNumberGeneratorParameters::GetSeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRandomNumberGeneratorParameters", "m_nSeed");
}
void GCRandomNumberGeneratorParameters::SetSeed(int32_t value) {
    SetSchemaValue(m_ptr, "CRandomNumberGeneratorParameters", "m_nSeed", false, value);
}
std::string GCRandomNumberGeneratorParameters::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRandomNumberGeneratorParameters::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCRandomNumberGeneratorParameters(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRandomNumberGeneratorParameters>("CRandomNumberGeneratorParameters")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DistributeEvenly", &GCRandomNumberGeneratorParameters::GetDistributeEvenly, &GCRandomNumberGeneratorParameters::SetDistributeEvenly)
        .addProperty("Seed", &GCRandomNumberGeneratorParameters::GetSeed, &GCRandomNumberGeneratorParameters::SetSeed)
        .addFunction("ToPtr", &GCRandomNumberGeneratorParameters::ToPtr)
        .addFunction("IsValid", &GCRandomNumberGeneratorParameters::IsValid)
        .endClass();
}