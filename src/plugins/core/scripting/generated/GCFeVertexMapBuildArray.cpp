#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFeVertexMapBuildArray::GCFeVertexMapBuildArray(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFeVertexMapBuildArray::GCFeVertexMapBuildArray(void *ptr) {
    m_ptr = ptr;
}
std::vector<GFeVertexMapBuild_t*> GCFeVertexMapBuildArray::GetArray() const {
    CUtlVector<GFeVertexMapBuild_t*>* vec = GetSchemaValue<CUtlVector<GFeVertexMapBuild_t*>*>(m_ptr, "CFeVertexMapBuildArray", "m_Array"); std::vector<GFeVertexMapBuild_t*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFeVertexMapBuildArray::SetArray(std::vector<GFeVertexMapBuild_t*> value) {
    SetSchemaValueCUtlVector<GFeVertexMapBuild_t*>(m_ptr, "CFeVertexMapBuildArray", "m_Array", false, value);
}
std::string GCFeVertexMapBuildArray::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFeVertexMapBuildArray::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFeVertexMapBuildArray(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFeVertexMapBuildArray>("CFeVertexMapBuildArray")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Array", &GCFeVertexMapBuildArray::GetArray, &GCFeVertexMapBuildArray::SetArray)
        .addFunction("ToPtr", &GCFeVertexMapBuildArray::ToPtr)
        .addFunction("IsValid", &GCFeVertexMapBuildArray::IsValid)
        .endClass();
}