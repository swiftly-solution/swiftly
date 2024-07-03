#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixEffectChainDesc_t::GVMixEffectChainDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixEffectChainDesc_t::GVMixEffectChainDesc_t(void *ptr) {
    m_ptr = ptr;
}
float GVMixEffectChainDesc_t::GetCrossfadeTime() const {
    return GetSchemaValue<float>(m_ptr, "VMixEffectChainDesc_t", "m_flCrossfadeTime");
}
void GVMixEffectChainDesc_t::SetCrossfadeTime(float value) {
    SetSchemaValue(m_ptr, "VMixEffectChainDesc_t", "m_flCrossfadeTime", true, value);
}
std::string GVMixEffectChainDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixEffectChainDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixEffectChainDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixEffectChainDesc_t>("VMixEffectChainDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CrossfadeTime", &GVMixEffectChainDesc_t::GetCrossfadeTime, &GVMixEffectChainDesc_t::SetCrossfadeTime)
        .addFunction("ToPtr", &GVMixEffectChainDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixEffectChainDesc_t::IsValid)
        .endClass();
}