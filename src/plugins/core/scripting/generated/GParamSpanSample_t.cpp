#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GParamSpanSample_t::GParamSpanSample_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GParamSpanSample_t::GParamSpanSample_t(void *ptr) {
    m_ptr = ptr;
}
float GParamSpanSample_t::GetCycle() const {
    return GetSchemaValue<float>(m_ptr, "ParamSpanSample_t", "m_flCycle");
}
void GParamSpanSample_t::SetCycle(float value) {
    SetSchemaValue(m_ptr, "ParamSpanSample_t", "m_flCycle", true, value);
}
std::string GParamSpanSample_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GParamSpanSample_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassParamSpanSample_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParamSpanSample_t>("ParamSpanSample_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Cycle", &GParamSpanSample_t::GetCycle, &GParamSpanSample_t::SetCycle)
        .addFunction("ToPtr", &GParamSpanSample_t::ToPtr)
        .addFunction("IsValid", &GParamSpanSample_t::IsValid)
        .endClass();
}