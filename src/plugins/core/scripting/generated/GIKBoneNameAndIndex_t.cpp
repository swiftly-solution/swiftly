#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIKBoneNameAndIndex_t::GIKBoneNameAndIndex_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIKBoneNameAndIndex_t::GIKBoneNameAndIndex_t(void *ptr) {
    m_ptr = ptr;
}
std::string GIKBoneNameAndIndex_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "IKBoneNameAndIndex_t", "m_Name").Get();
}
void GIKBoneNameAndIndex_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "IKBoneNameAndIndex_t", "m_Name", true, CUtlString(value.c_str()));
}
std::string GIKBoneNameAndIndex_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIKBoneNameAndIndex_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIKBoneNameAndIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIKBoneNameAndIndex_t>("IKBoneNameAndIndex_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GIKBoneNameAndIndex_t::GetName, &GIKBoneNameAndIndex_t::SetName)
        .addFunction("ToPtr", &GIKBoneNameAndIndex_t::ToPtr)
        .addFunction("IsValid", &GIKBoneNameAndIndex_t::IsValid)
        .endClass();
}