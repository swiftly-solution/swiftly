#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAttributeList::GCAttributeList(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAttributeList::GCAttributeList(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCEconItemAttribute> GCAttributeList::GetAttributes() const {
    CUtlVector<GCEconItemAttribute>* vec = GetSchemaValue<CUtlVector<GCEconItemAttribute>*>(m_ptr, "CAttributeList", "m_Attributes"); std::vector<GCEconItemAttribute> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAttributeList::SetAttributes(std::vector<GCEconItemAttribute> value) {
    SetSchemaValueCUtlVector<GCEconItemAttribute>(m_ptr, "CAttributeList", "m_Attributes", false, value);
}
GCAttributeManager GCAttributeList::GetManager() const {
    GCAttributeManager value(*GetSchemaValuePtr<void*>(m_ptr, "CAttributeList", "m_pManager"));
    return value;
}
void GCAttributeList::SetManager(GCAttributeManager* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Manager' is not possible.\n");
}
std::string GCAttributeList::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAttributeList::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAttributeList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAttributeList>("CAttributeList")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Attributes", &GCAttributeList::GetAttributes, &GCAttributeList::SetAttributes)
        .addProperty("Manager", &GCAttributeList::GetManager, &GCAttributeList::SetManager)
        .addFunction("ToPtr", &GCAttributeList::ToPtr)
        .addFunction("IsValid", &GCAttributeList::IsValid)
        .endClass();
}