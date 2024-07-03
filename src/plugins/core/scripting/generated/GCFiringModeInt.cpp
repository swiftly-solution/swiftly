#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFiringModeInt::GCFiringModeInt(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFiringModeInt::GCFiringModeInt(void *ptr) {
    m_ptr = ptr;
}
std::vector<int32_t> GCFiringModeInt::GetValues() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CFiringModeInt", "m_nValues"); std::vector<int32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCFiringModeInt::SetValues(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CFiringModeInt", "m_nValues"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CFiringModeInt", "m_nValues", false, outValue);
}
std::string GCFiringModeInt::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFiringModeInt::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFiringModeInt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFiringModeInt>("CFiringModeInt")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Values", &GCFiringModeInt::GetValues, &GCFiringModeInt::SetValues)
        .addFunction("ToPtr", &GCFiringModeInt::ToPtr)
        .addFunction("IsValid", &GCFiringModeInt::IsValid)
        .endClass();
}