#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavVolumeCalculatedVector::GCNavVolumeCalculatedVector(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavVolumeCalculatedVector::GCNavVolumeCalculatedVector(void *ptr) {
    m_ptr = ptr;
}
std::string GCNavVolumeCalculatedVector::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavVolumeCalculatedVector::IsValid() {
    return (m_ptr != nullptr);
}
GCNavVolume GCNavVolumeCalculatedVector::GetParent() const {
    GCNavVolume value(m_ptr);
    return value;
}
void GCNavVolumeCalculatedVector::SetParent(GCNavVolume value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNavVolumeCalculatedVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeCalculatedVector>("CNavVolumeCalculatedVector")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNavVolumeCalculatedVector::GetParent, &GCNavVolumeCalculatedVector::SetParent)
        .addFunction("ToPtr", &GCNavVolumeCalculatedVector::ToPtr)
        .addFunction("IsValid", &GCNavVolumeCalculatedVector::IsValid)
        .endClass();
}