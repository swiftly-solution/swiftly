#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSequenceWeightedList_t::GSequenceWeightedList_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSequenceWeightedList_t::GSequenceWeightedList_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GSequenceWeightedList_t::GetSequence() const {
    return GetSchemaValue<int32_t>(m_ptr, "SequenceWeightedList_t", "m_nSequence");
}
void GSequenceWeightedList_t::SetSequence(int32_t value) {
    SetSchemaValue(m_ptr, "SequenceWeightedList_t", "m_nSequence", true, value);
}
float GSequenceWeightedList_t::GetRelativeWeight() const {
    return GetSchemaValue<float>(m_ptr, "SequenceWeightedList_t", "m_flRelativeWeight");
}
void GSequenceWeightedList_t::SetRelativeWeight(float value) {
    SetSchemaValue(m_ptr, "SequenceWeightedList_t", "m_flRelativeWeight", true, value);
}
std::string GSequenceWeightedList_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSequenceWeightedList_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSequenceWeightedList_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSequenceWeightedList_t>("SequenceWeightedList_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Sequence", &GSequenceWeightedList_t::GetSequence, &GSequenceWeightedList_t::SetSequence)
        .addProperty("RelativeWeight", &GSequenceWeightedList_t::GetRelativeWeight, &GSequenceWeightedList_t::SetRelativeWeight)
        .addFunction("ToPtr", &GSequenceWeightedList_t::ToPtr)
        .addFunction("IsValid", &GSequenceWeightedList_t::IsValid)
        .endClass();
}