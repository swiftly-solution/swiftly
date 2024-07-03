#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLODComponentUpdater::GCLODComponentUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLODComponentUpdater::GCLODComponentUpdater(void *ptr) {
    m_ptr = ptr;
}
int32_t GCLODComponentUpdater::GetServerLOD() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLODComponentUpdater", "m_nServerLOD");
}
void GCLODComponentUpdater::SetServerLOD(int32_t value) {
    SetSchemaValue(m_ptr, "CLODComponentUpdater", "m_nServerLOD", false, value);
}
std::string GCLODComponentUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLODComponentUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimComponentUpdater GCLODComponentUpdater::GetParent() const {
    GCAnimComponentUpdater value(m_ptr);
    return value;
}
void GCLODComponentUpdater::SetParent(GCAnimComponentUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLODComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLODComponentUpdater>("CLODComponentUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ServerLOD", &GCLODComponentUpdater::GetServerLOD, &GCLODComponentUpdater::SetServerLOD)
        .addProperty("Parent", &GCLODComponentUpdater::GetParent, &GCLODComponentUpdater::SetParent)
        .addFunction("ToPtr", &GCLODComponentUpdater::ToPtr)
        .addFunction("IsValid", &GCLODComponentUpdater::IsValid)
        .endClass();
}