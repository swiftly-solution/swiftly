#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavVolumeMarkupVolume::GCNavVolumeMarkupVolume(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavVolumeMarkupVolume::GCNavVolumeMarkupVolume(void *ptr) {
    m_ptr = ptr;
}
std::string GCNavVolumeMarkupVolume::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavVolumeMarkupVolume::IsValid() {
    return (m_ptr != nullptr);
}
GCNavVolume GCNavVolumeMarkupVolume::GetParent() const {
    GCNavVolume value(m_ptr);
    return value;
}
void GCNavVolumeMarkupVolume::SetParent(GCNavVolume value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNavVolumeMarkupVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeMarkupVolume>("CNavVolumeMarkupVolume")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNavVolumeMarkupVolume::GetParent, &GCNavVolumeMarkupVolume::SetParent)
        .addFunction("ToPtr", &GCNavVolumeMarkupVolume::ToPtr)
        .addFunction("IsValid", &GCNavVolumeMarkupVolume::IsValid)
        .endClass();
}