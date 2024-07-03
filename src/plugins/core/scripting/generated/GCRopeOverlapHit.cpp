#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRopeOverlapHit::GCRopeOverlapHit(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRopeOverlapHit::GCRopeOverlapHit(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCRopeOverlapHit::GetEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CRopeOverlapHit", "m_hEntity"));
    return value;
}
void GCRopeOverlapHit::SetEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Entity' is not possible.\n");
}
std::vector<int32> GCRopeOverlapHit::GetOverlappingLinks() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CRopeOverlapHit", "m_vecOverlappingLinks"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRopeOverlapHit::SetOverlappingLinks(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CRopeOverlapHit", "m_vecOverlappingLinks", false, value);
}
std::string GCRopeOverlapHit::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRopeOverlapHit::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCRopeOverlapHit(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRopeOverlapHit>("CRopeOverlapHit")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Entity", &GCRopeOverlapHit::GetEntity, &GCRopeOverlapHit::SetEntity)
        .addProperty("OverlappingLinks", &GCRopeOverlapHit::GetOverlappingLinks, &GCRopeOverlapHit::SetOverlappingLinks)
        .addFunction("ToPtr", &GCRopeOverlapHit::ToPtr)
        .addFunction("IsValid", &GCRopeOverlapHit::IsValid)
        .endClass();
}