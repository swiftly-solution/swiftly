#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCompositeMaterialEditorDoc::GCCompositeMaterialEditorDoc(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCompositeMaterialEditorDoc::GCCompositeMaterialEditorDoc(void *ptr) {
    m_ptr = ptr;
}
int32_t GCCompositeMaterialEditorDoc::GetVersion() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCompositeMaterialEditorDoc", "m_nVersion");
}
void GCCompositeMaterialEditorDoc::SetVersion(int32_t value) {
    SetSchemaValue(m_ptr, "CCompositeMaterialEditorDoc", "m_nVersion", false, value);
}
std::vector<GCompositeMaterialEditorPoint_t> GCCompositeMaterialEditorDoc::GetPoints() const {
    CUtlVector<GCompositeMaterialEditorPoint_t>* vec = GetSchemaValue<CUtlVector<GCompositeMaterialEditorPoint_t>*>(m_ptr, "CCompositeMaterialEditorDoc", "m_Points"); std::vector<GCompositeMaterialEditorPoint_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCompositeMaterialEditorDoc::SetPoints(std::vector<GCompositeMaterialEditorPoint_t> value) {
    SetSchemaValueCUtlVector<GCompositeMaterialEditorPoint_t>(m_ptr, "CCompositeMaterialEditorDoc", "m_Points", false, value);
}
std::string GCCompositeMaterialEditorDoc::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCompositeMaterialEditorDoc::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCompositeMaterialEditorDoc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCompositeMaterialEditorDoc>("CCompositeMaterialEditorDoc")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Version", &GCCompositeMaterialEditorDoc::GetVersion, &GCCompositeMaterialEditorDoc::SetVersion)
        .addProperty("Points", &GCCompositeMaterialEditorDoc::GetPoints, &GCCompositeMaterialEditorDoc::SetPoints)
        .addFunction("ToPtr", &GCCompositeMaterialEditorDoc::ToPtr)
        .addFunction("IsValid", &GCCompositeMaterialEditorDoc::IsValid)
        .endClass();
}