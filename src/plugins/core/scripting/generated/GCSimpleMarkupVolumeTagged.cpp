#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSimpleMarkupVolumeTagged::GCSimpleMarkupVolumeTagged(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSimpleMarkupVolumeTagged::GCSimpleMarkupVolumeTagged(void *ptr) {
    m_ptr = ptr;
}
std::string GCSimpleMarkupVolumeTagged::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSimpleMarkupVolumeTagged::IsValid() {
    return (m_ptr != nullptr);
}
GCMarkupVolumeTagged GCSimpleMarkupVolumeTagged::GetParent() const {
    GCMarkupVolumeTagged value(m_ptr);
    return value;
}
void GCSimpleMarkupVolumeTagged::SetParent(GCMarkupVolumeTagged value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSimpleMarkupVolumeTagged(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSimpleMarkupVolumeTagged>("CSimpleMarkupVolumeTagged")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCSimpleMarkupVolumeTagged::GetParent, &GCSimpleMarkupVolumeTagged::SetParent)
        .addFunction("ToPtr", &GCSimpleMarkupVolumeTagged::ToPtr)
        .addFunction("IsValid", &GCSimpleMarkupVolumeTagged::IsValid)
        .endClass();
}