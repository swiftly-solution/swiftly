#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVsInputSignature_t::GVsInputSignature_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVsInputSignature_t::GVsInputSignature_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GVsInputSignatureElement_t> GVsInputSignature_t::GetElems() const {
    CUtlVector<GVsInputSignatureElement_t>* vec = GetSchemaValue<CUtlVector<GVsInputSignatureElement_t>*>(m_ptr, "VsInputSignature_t", "m_elems"); std::vector<GVsInputSignatureElement_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVsInputSignature_t::SetElems(std::vector<GVsInputSignatureElement_t> value) {
    SetSchemaValueCUtlVector<GVsInputSignatureElement_t>(m_ptr, "VsInputSignature_t", "m_elems", true, value);
}
std::string GVsInputSignature_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVsInputSignature_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVsInputSignature_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVsInputSignature_t>("VsInputSignature_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Elems", &GVsInputSignature_t::GetElems, &GVsInputSignature_t::SetElems)
        .addFunction("ToPtr", &GVsInputSignature_t::ToPtr)
        .addFunction("IsValid", &GVsInputSignature_t::IsValid)
        .endClass();
}