#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCProductQuantizer::GCProductQuantizer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCProductQuantizer::GCProductQuantizer(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCVectorQuantizer> GCProductQuantizer::GetSubQuantizers() const {
    CUtlVector<GCVectorQuantizer>* vec = GetSchemaValue<CUtlVector<GCVectorQuantizer>*>(m_ptr, "CProductQuantizer", "m_subQuantizers"); std::vector<GCVectorQuantizer> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCProductQuantizer::SetSubQuantizers(std::vector<GCVectorQuantizer> value) {
    SetSchemaValueCUtlVector<GCVectorQuantizer>(m_ptr, "CProductQuantizer", "m_subQuantizers", false, value);
}
int32_t GCProductQuantizer::GetDimensions() const {
    return GetSchemaValue<int32_t>(m_ptr, "CProductQuantizer", "m_nDimensions");
}
void GCProductQuantizer::SetDimensions(int32_t value) {
    SetSchemaValue(m_ptr, "CProductQuantizer", "m_nDimensions", false, value);
}
std::string GCProductQuantizer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCProductQuantizer::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCProductQuantizer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCProductQuantizer>("CProductQuantizer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SubQuantizers", &GCProductQuantizer::GetSubQuantizers, &GCProductQuantizer::SetSubQuantizers)
        .addProperty("Dimensions", &GCProductQuantizer::GetDimensions, &GCProductQuantizer::SetDimensions)
        .addFunction("ToPtr", &GCProductQuantizer::ToPtr)
        .addFunction("IsValid", &GCProductQuantizer::IsValid)
        .endClass();
}