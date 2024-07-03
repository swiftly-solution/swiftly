#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVPhysXSurfacePropertiesList::GCVPhysXSurfacePropertiesList(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVPhysXSurfacePropertiesList::GCVPhysXSurfacePropertiesList(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCPhysSurfaceProperties*> GCVPhysXSurfacePropertiesList::GetSurfacePropertiesList() const {
    CUtlVector<GCPhysSurfaceProperties*>* vec = GetSchemaValue<CUtlVector<GCPhysSurfaceProperties*>*>(m_ptr, "CVPhysXSurfacePropertiesList", "m_surfacePropertiesList"); std::vector<GCPhysSurfaceProperties*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCVPhysXSurfacePropertiesList::SetSurfacePropertiesList(std::vector<GCPhysSurfaceProperties*> value) {
    SetSchemaValueCUtlVector<GCPhysSurfaceProperties*>(m_ptr, "CVPhysXSurfacePropertiesList", "m_surfacePropertiesList", false, value);
}
std::string GCVPhysXSurfacePropertiesList::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVPhysXSurfacePropertiesList::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCVPhysXSurfacePropertiesList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVPhysXSurfacePropertiesList>("CVPhysXSurfacePropertiesList")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SurfacePropertiesList", &GCVPhysXSurfacePropertiesList::GetSurfacePropertiesList, &GCVPhysXSurfacePropertiesList::SetSurfacePropertiesList)
        .addFunction("ToPtr", &GCVPhysXSurfacePropertiesList::ToPtr)
        .addFunction("IsValid", &GCVPhysXSurfacePropertiesList::IsValid)
        .endClass();
}