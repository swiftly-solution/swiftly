#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnTriangle_t::GRnTriangle_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnTriangle_t::GRnTriangle_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<int32_t> GRnTriangle_t::GetIndex() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "RnTriangle_t", "m_nIndex"); std::vector<int32_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GRnTriangle_t::SetIndex(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "RnTriangle_t", "m_nIndex"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnTriangle_t", "m_nIndex", true, outValue);
}
std::string GRnTriangle_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnTriangle_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnTriangle_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnTriangle_t>("RnTriangle_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Index", &GRnTriangle_t::GetIndex, &GRnTriangle_t::SetIndex)
        .addFunction("ToPtr", &GRnTriangle_t::ToPtr)
        .addFunction("IsValid", &GRnTriangle_t::IsValid)
        .endClass();
}