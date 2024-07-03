#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeTreeChildren_t::GFeTreeChildren_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeTreeChildren_t::GFeTreeChildren_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint16_t> GFeTreeChildren_t::GetChild() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeTreeChildren_t", "nChild"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeTreeChildren_t::SetChild(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeTreeChildren_t", "nChild"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeTreeChildren_t", "nChild", true, outValue);
}
std::string GFeTreeChildren_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeTreeChildren_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeTreeChildren_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeTreeChildren_t>("FeTreeChildren_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Child", &GFeTreeChildren_t::GetChild, &GFeTreeChildren_t::SetChild)
        .addFunction("ToPtr", &GFeTreeChildren_t::ToPtr)
        .addFunction("IsValid", &GFeTreeChildren_t::IsValid)
        .endClass();
}