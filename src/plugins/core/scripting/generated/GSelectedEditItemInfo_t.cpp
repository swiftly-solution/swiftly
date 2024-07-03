#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSelectedEditItemInfo_t::GSelectedEditItemInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSelectedEditItemInfo_t::GSelectedEditItemInfo_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GSosEditItemInfo_t> GSelectedEditItemInfo_t::GetEditItems() const {
    CUtlVector<GSosEditItemInfo_t>* vec = GetSchemaValue<CUtlVector<GSosEditItemInfo_t>*>(m_ptr, "SelectedEditItemInfo_t", "m_EditItems"); std::vector<GSosEditItemInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GSelectedEditItemInfo_t::SetEditItems(std::vector<GSosEditItemInfo_t> value) {
    SetSchemaValueCUtlVector<GSosEditItemInfo_t>(m_ptr, "SelectedEditItemInfo_t", "m_EditItems", true, value);
}
std::string GSelectedEditItemInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSelectedEditItemInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSelectedEditItemInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSelectedEditItemInfo_t>("SelectedEditItemInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EditItems", &GSelectedEditItemInfo_t::GetEditItems, &GSelectedEditItemInfo_t::SetEditItems)
        .addFunction("ToPtr", &GSelectedEditItemInfo_t::ToPtr)
        .addFunction("IsValid", &GSelectedEditItemInfo_t::IsValid)
        .endClass();
}