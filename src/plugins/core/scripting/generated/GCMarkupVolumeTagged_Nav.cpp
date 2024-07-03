#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMarkupVolumeTagged_Nav::GCMarkupVolumeTagged_Nav(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMarkupVolumeTagged_Nav::GCMarkupVolumeTagged_Nav(void *ptr) {
    m_ptr = ptr;
}
std::string GCMarkupVolumeTagged_Nav::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMarkupVolumeTagged_Nav::IsValid() {
    return (m_ptr != nullptr);
}
GCMarkupVolumeTagged GCMarkupVolumeTagged_Nav::GetParent() const {
    GCMarkupVolumeTagged value(m_ptr);
    return value;
}
void GCMarkupVolumeTagged_Nav::SetParent(GCMarkupVolumeTagged value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMarkupVolumeTagged_Nav(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMarkupVolumeTagged_Nav>("CMarkupVolumeTagged_Nav")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCMarkupVolumeTagged_Nav::GetParent, &GCMarkupVolumeTagged_Nav::SetParent)
        .addFunction("ToPtr", &GCMarkupVolumeTagged_Nav::ToPtr)
        .addFunction("IsValid", &GCMarkupVolumeTagged_Nav::IsValid)
        .endClass();
}