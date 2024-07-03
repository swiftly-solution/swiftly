#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_ViewModelServices::GCCSPlayer_ViewModelServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_ViewModelServices::GCCSPlayer_ViewModelServices(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCBaseViewModel*> GCCSPlayer_ViewModelServices::GetViewModel() const {
    GCBaseViewModel** outValue = GetSchemaValue<GCBaseViewModel**>(m_ptr, "CCSPlayer_ViewModelServices", "m_hViewModel"); std::vector<GCBaseViewModel*> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayer_ViewModelServices::SetViewModel(std::vector<GCBaseViewModel*> value) {
    GCBaseViewModel** outValue = GetSchemaValue<GCBaseViewModel**>(m_ptr, "CCSPlayer_ViewModelServices", "m_hViewModel"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayer_ViewModelServices", "m_hViewModel", false, outValue);
}
std::string GCCSPlayer_ViewModelServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_ViewModelServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayer_ViewModelServices GCCSPlayer_ViewModelServices::GetParent() const {
    GCPlayer_ViewModelServices value(m_ptr);
    return value;
}
void GCCSPlayer_ViewModelServices::SetParent(GCPlayer_ViewModelServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_ViewModelServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_ViewModelServices>("CCSPlayer_ViewModelServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ViewModel", &GCCSPlayer_ViewModelServices::GetViewModel, &GCCSPlayer_ViewModelServices::SetViewModel)
        .addProperty("Parent", &GCCSPlayer_ViewModelServices::GetParent, &GCCSPlayer_ViewModelServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_ViewModelServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_ViewModelServices::IsValid)
        .endClass();
}