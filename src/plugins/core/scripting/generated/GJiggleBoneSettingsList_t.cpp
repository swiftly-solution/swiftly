#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GJiggleBoneSettingsList_t::GJiggleBoneSettingsList_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GJiggleBoneSettingsList_t::GJiggleBoneSettingsList_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GJiggleBoneSettings_t> GJiggleBoneSettingsList_t::GetBoneSettings() const {
    CUtlVector<GJiggleBoneSettings_t>* vec = GetSchemaValue<CUtlVector<GJiggleBoneSettings_t>*>(m_ptr, "JiggleBoneSettingsList_t", "m_boneSettings"); std::vector<GJiggleBoneSettings_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GJiggleBoneSettingsList_t::SetBoneSettings(std::vector<GJiggleBoneSettings_t> value) {
    SetSchemaValueCUtlVector<GJiggleBoneSettings_t>(m_ptr, "JiggleBoneSettingsList_t", "m_boneSettings", true, value);
}
std::string GJiggleBoneSettingsList_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GJiggleBoneSettingsList_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassJiggleBoneSettingsList_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GJiggleBoneSettingsList_t>("JiggleBoneSettingsList_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneSettings", &GJiggleBoneSettingsList_t::GetBoneSettings, &GJiggleBoneSettingsList_t::SetBoneSettings)
        .addFunction("ToPtr", &GJiggleBoneSettingsList_t::ToPtr)
        .addFunction("IsValid", &GJiggleBoneSettingsList_t::IsValid)
        .endClass();
}