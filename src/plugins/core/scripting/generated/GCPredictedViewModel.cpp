#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPredictedViewModel::GCPredictedViewModel(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPredictedViewModel::GCPredictedViewModel(void *ptr) {
    m_ptr = ptr;
}
std::string GCPredictedViewModel::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPredictedViewModel::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseViewModel GCPredictedViewModel::GetParent() const {
    GCBaseViewModel value(m_ptr);
    return value;
}
void GCPredictedViewModel::SetParent(GCBaseViewModel value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPredictedViewModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPredictedViewModel>("CPredictedViewModel")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPredictedViewModel::GetParent, &GCPredictedViewModel::SetParent)
        .addFunction("ToPtr", &GCPredictedViewModel::ToPtr)
        .addFunction("IsValid", &GCPredictedViewModel::IsValid)
        .endClass();
}