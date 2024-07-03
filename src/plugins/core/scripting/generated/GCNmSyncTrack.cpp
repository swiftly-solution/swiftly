#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmSyncTrack::GCNmSyncTrack(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmSyncTrack::GCNmSyncTrack(void *ptr) {
    m_ptr = ptr;
}
int32_t GCNmSyncTrack::GetStartEventOffset() const {
    return GetSchemaValue<int32_t>(m_ptr, "CNmSyncTrack", "m_nStartEventOffset");
}
void GCNmSyncTrack::SetStartEventOffset(int32_t value) {
    SetSchemaValue(m_ptr, "CNmSyncTrack", "m_nStartEventOffset", false, value);
}
std::string GCNmSyncTrack::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmSyncTrack::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmSyncTrack(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmSyncTrack>("CNmSyncTrack")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartEventOffset", &GCNmSyncTrack::GetStartEventOffset, &GCNmSyncTrack::SetStartEventOffset)
        .addFunction("ToPtr", &GCNmSyncTrack::ToPtr)
        .addFunction("IsValid", &GCNmSyncTrack::IsValid)
        .endClass();
}