#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimActivity::GCAnimActivity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimActivity::GCAnimActivity(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCAnimActivity::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimActivity", "m_name");
}
void GCAnimActivity::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimActivity", "m_name", false, value);
}
int32_t GCAnimActivity::GetActivity() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimActivity", "m_nActivity");
}
void GCAnimActivity::SetActivity(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimActivity", "m_nActivity", false, value);
}
int32_t GCAnimActivity::GetFlags() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimActivity", "m_nFlags");
}
void GCAnimActivity::SetFlags(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimActivity", "m_nFlags", false, value);
}
int32_t GCAnimActivity::GetWeight() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimActivity", "m_nWeight");
}
void GCAnimActivity::SetWeight(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimActivity", "m_nWeight", false, value);
}
std::string GCAnimActivity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimActivity::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimActivity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimActivity>("CAnimActivity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAnimActivity::GetName, &GCAnimActivity::SetName)
        .addProperty("Activity", &GCAnimActivity::GetActivity, &GCAnimActivity::SetActivity)
        .addProperty("Flags", &GCAnimActivity::GetFlags, &GCAnimActivity::SetFlags)
        .addProperty("Weight", &GCAnimActivity::GetWeight, &GCAnimActivity::SetWeight)
        .addFunction("ToPtr", &GCAnimActivity::ToPtr)
        .addFunction("IsValid", &GCAnimActivity::IsValid)
        .endClass();
}