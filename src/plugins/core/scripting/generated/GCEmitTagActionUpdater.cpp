#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEmitTagActionUpdater::GCEmitTagActionUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEmitTagActionUpdater::GCEmitTagActionUpdater(void *ptr) {
    m_ptr = ptr;
}
int32_t GCEmitTagActionUpdater::GetTagIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEmitTagActionUpdater", "m_nTagIndex");
}
void GCEmitTagActionUpdater::SetTagIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CEmitTagActionUpdater", "m_nTagIndex", false, value);
}
bool GCEmitTagActionUpdater::GetIsZeroDuration() const {
    return GetSchemaValue<bool>(m_ptr, "CEmitTagActionUpdater", "m_bIsZeroDuration");
}
void GCEmitTagActionUpdater::SetIsZeroDuration(bool value) {
    SetSchemaValue(m_ptr, "CEmitTagActionUpdater", "m_bIsZeroDuration", false, value);
}
std::string GCEmitTagActionUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEmitTagActionUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimActionUpdater GCEmitTagActionUpdater::GetParent() const {
    GCAnimActionUpdater value(m_ptr);
    return value;
}
void GCEmitTagActionUpdater::SetParent(GCAnimActionUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEmitTagActionUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEmitTagActionUpdater>("CEmitTagActionUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TagIndex", &GCEmitTagActionUpdater::GetTagIndex, &GCEmitTagActionUpdater::SetTagIndex)
        .addProperty("IsZeroDuration", &GCEmitTagActionUpdater::GetIsZeroDuration, &GCEmitTagActionUpdater::SetIsZeroDuration)
        .addProperty("Parent", &GCEmitTagActionUpdater::GetParent, &GCEmitTagActionUpdater::SetParent)
        .addFunction("ToPtr", &GCEmitTagActionUpdater::ToPtr)
        .addFunction("IsValid", &GCEmitTagActionUpdater::IsValid)
        .endClass();
}