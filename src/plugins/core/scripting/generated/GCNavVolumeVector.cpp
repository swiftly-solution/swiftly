#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavVolumeVector::GCNavVolumeVector(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavVolumeVector::GCNavVolumeVector(void *ptr) {
    m_ptr = ptr;
}
bool GCNavVolumeVector::GetHasBeenPreFiltered() const {
    return GetSchemaValue<bool>(m_ptr, "CNavVolumeVector", "m_bHasBeenPreFiltered");
}
void GCNavVolumeVector::SetHasBeenPreFiltered(bool value) {
    SetSchemaValue(m_ptr, "CNavVolumeVector", "m_bHasBeenPreFiltered", false, value);
}
std::string GCNavVolumeVector::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavVolumeVector::IsValid() {
    return (m_ptr != nullptr);
}
GCNavVolume GCNavVolumeVector::GetParent() const {
    GCNavVolume value(m_ptr);
    return value;
}
void GCNavVolumeVector::SetParent(GCNavVolume value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNavVolumeVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeVector>("CNavVolumeVector")
        .addConstructor<void (*)(std::string)>()
        .addProperty("HasBeenPreFiltered", &GCNavVolumeVector::GetHasBeenPreFiltered, &GCNavVolumeVector::SetHasBeenPreFiltered)
        .addProperty("Parent", &GCNavVolumeVector::GetParent, &GCNavVolumeVector::SetParent)
        .addFunction("ToPtr", &GCNavVolumeVector::ToPtr)
        .addFunction("IsValid", &GCNavVolumeVector::IsValid)
        .endClass();
}