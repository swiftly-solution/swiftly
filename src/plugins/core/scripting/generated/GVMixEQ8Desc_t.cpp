#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixEQ8Desc_t::GVMixEQ8Desc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixEQ8Desc_t::GVMixEQ8Desc_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GVMixFilterDesc_t> GVMixEQ8Desc_t::GetStages() const {
    GVMixFilterDesc_t* outValue = GetSchemaValue<GVMixFilterDesc_t*>(m_ptr, "VMixEQ8Desc_t", "m_stages"); std::vector<GVMixFilterDesc_t> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret;
}
void GVMixEQ8Desc_t::SetStages(std::vector<GVMixFilterDesc_t> value) {
    GVMixFilterDesc_t* outValue = GetSchemaValue<GVMixFilterDesc_t*>(m_ptr, "VMixEQ8Desc_t", "m_stages"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "VMixEQ8Desc_t", "m_stages", true, outValue);
}
std::string GVMixEQ8Desc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixEQ8Desc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixEQ8Desc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixEQ8Desc_t>("VMixEQ8Desc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Stages", &GVMixEQ8Desc_t::GetStages, &GVMixEQ8Desc_t::SetStages)
        .addFunction("ToPtr", &GVMixEQ8Desc_t::ToPtr)
        .addFunction("IsValid", &GVMixEQ8Desc_t::IsValid)
        .endClass();
}