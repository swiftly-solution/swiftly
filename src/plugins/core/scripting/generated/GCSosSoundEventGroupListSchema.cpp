#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSosSoundEventGroupListSchema::GCSosSoundEventGroupListSchema(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSosSoundEventGroupListSchema::GCSosSoundEventGroupListSchema(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCSosSoundEventGroupSchema> GCSosSoundEventGroupListSchema::GetGroupList() const {
    CUtlVector<GCSosSoundEventGroupSchema>* vec = GetSchemaValue<CUtlVector<GCSosSoundEventGroupSchema>*>(m_ptr, "CSosSoundEventGroupListSchema", "m_groupList"); std::vector<GCSosSoundEventGroupSchema> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSosSoundEventGroupListSchema::SetGroupList(std::vector<GCSosSoundEventGroupSchema> value) {
    SetSchemaValueCUtlVector<GCSosSoundEventGroupSchema>(m_ptr, "CSosSoundEventGroupListSchema", "m_groupList", false, value);
}
std::string GCSosSoundEventGroupListSchema::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSosSoundEventGroupListSchema::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSosSoundEventGroupListSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosSoundEventGroupListSchema>("CSosSoundEventGroupListSchema")
        .addConstructor<void (*)(std::string)>()
        .addProperty("GroupList", &GCSosSoundEventGroupListSchema::GetGroupList, &GCSosSoundEventGroupListSchema::SetGroupList)
        .addFunction("ToPtr", &GCSosSoundEventGroupListSchema::ToPtr)
        .addFunction("IsValid", &GCSosSoundEventGroupListSchema::IsValid)
        .endClass();
}