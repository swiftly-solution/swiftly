#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRangeInt::GCRangeInt(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRangeInt::GCRangeInt(void *ptr) {
    m_ptr = ptr;
}
std::vector<int32_t> GCRangeInt::GetValue() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CRangeInt", "m_pValue"); std::vector<int32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCRangeInt::SetValue(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CRangeInt", "m_pValue"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CRangeInt", "m_pValue", false, outValue);
}
std::string GCRangeInt::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRangeInt::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCRangeInt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRangeInt>("CRangeInt")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GCRangeInt::GetValue, &GCRangeInt::SetValue)
        .addFunction("ToPtr", &GCRangeInt::ToPtr)
        .addFunction("IsValid", &GCRangeInt::IsValid)
        .endClass();
}