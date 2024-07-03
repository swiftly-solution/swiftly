#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelConfigList::GCModelConfigList(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelConfigList::GCModelConfigList(void *ptr) {
    m_ptr = ptr;
}
bool GCModelConfigList::GetHideMaterialGroupInTools() const {
    return GetSchemaValue<bool>(m_ptr, "CModelConfigList", "m_bHideMaterialGroupInTools");
}
void GCModelConfigList::SetHideMaterialGroupInTools(bool value) {
    SetSchemaValue(m_ptr, "CModelConfigList", "m_bHideMaterialGroupInTools", false, value);
}
bool GCModelConfigList::GetHideRenderColorInTools() const {
    return GetSchemaValue<bool>(m_ptr, "CModelConfigList", "m_bHideRenderColorInTools");
}
void GCModelConfigList::SetHideRenderColorInTools(bool value) {
    SetSchemaValue(m_ptr, "CModelConfigList", "m_bHideRenderColorInTools", false, value);
}
std::vector<GCModelConfig*> GCModelConfigList::GetConfigs() const {
    CUtlVector<GCModelConfig*>* vec = GetSchemaValue<CUtlVector<GCModelConfig*>*>(m_ptr, "CModelConfigList", "m_Configs"); std::vector<GCModelConfig*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCModelConfigList::SetConfigs(std::vector<GCModelConfig*> value) {
    SetSchemaValueCUtlVector<GCModelConfig*>(m_ptr, "CModelConfigList", "m_Configs", false, value);
}
std::string GCModelConfigList::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelConfigList::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCModelConfigList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigList>("CModelConfigList")
        .addConstructor<void (*)(std::string)>()
        .addProperty("HideMaterialGroupInTools", &GCModelConfigList::GetHideMaterialGroupInTools, &GCModelConfigList::SetHideMaterialGroupInTools)
        .addProperty("HideRenderColorInTools", &GCModelConfigList::GetHideRenderColorInTools, &GCModelConfigList::SetHideRenderColorInTools)
        .addProperty("Configs", &GCModelConfigList::GetConfigs, &GCModelConfigList::SetConfigs)
        .addFunction("ToPtr", &GCModelConfigList::ToPtr)
        .addFunction("IsValid", &GCModelConfigList::IsValid)
        .endClass();
}