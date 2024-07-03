#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMoodVData::GCMoodVData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMoodVData::GCMoodVData(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCMoodVData::GetMoodType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CMoodVData", "m_nMoodType");
}
void GCMoodVData::SetMoodType(uint64_t value) {
    SetSchemaValue(m_ptr, "CMoodVData", "m_nMoodType", false, value);
}
std::string GCMoodVData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMoodVData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMoodVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMoodVData>("CMoodVData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MoodType", &GCMoodVData::GetMoodType, &GCMoodVData::SetMoodType)
        .addFunction("ToPtr", &GCMoodVData::ToPtr)
        .addFunction("IsValid", &GCMoodVData::IsValid)
        .endClass();
}