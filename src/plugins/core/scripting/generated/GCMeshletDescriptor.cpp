#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMeshletDescriptor::GCMeshletDescriptor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMeshletDescriptor::GCMeshletDescriptor(void *ptr) {
    m_ptr = ptr;
}
GCDrawCullingData GCMeshletDescriptor::GetCullingData() const {
    GCDrawCullingData value(GetSchemaPtr(m_ptr, "CMeshletDescriptor", "m_CullingData"));
    return value;
}
void GCMeshletDescriptor::SetCullingData(GCDrawCullingData value) {
    SetSchemaValue(m_ptr, "CMeshletDescriptor", "m_CullingData", false, value);
}
std::string GCMeshletDescriptor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMeshletDescriptor::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMeshletDescriptor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMeshletDescriptor>("CMeshletDescriptor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CullingData", &GCMeshletDescriptor::GetCullingData, &GCMeshletDescriptor::SetCullingData)
        .addFunction("ToPtr", &GCMeshletDescriptor::ToPtr)
        .addFunction("IsValid", &GCMeshletDescriptor::IsValid)
        .endClass();
}