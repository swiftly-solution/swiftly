#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GDop26_t::GDop26_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GDop26_t::GDop26_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<float> GDop26_t::GetSupport() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "Dop26_t", "m_flSupport"); std::vector<float> ret; for(int i = 0; i < 26; i++) { ret.push_back(outValue[i]); } return ret;
}
void GDop26_t::SetSupport(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "Dop26_t", "m_flSupport"); for(int i = 0; i < 26; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "Dop26_t", "m_flSupport", true, outValue);
}
std::string GDop26_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GDop26_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassDop26_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GDop26_t>("Dop26_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Support", &GDop26_t::GetSupport, &GDop26_t::SetSupport)
        .addFunction("ToPtr", &GDop26_t::ToPtr)
        .addFunction("IsValid", &GDop26_t::IsValid)
        .endClass();
}