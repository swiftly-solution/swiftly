#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncTrainControls::GCFuncTrainControls(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncTrainControls::GCFuncTrainControls(void *ptr) {
    m_ptr = ptr;
}
std::string GCFuncTrainControls::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncTrainControls::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncTrainControls::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncTrainControls::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncTrainControls(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTrainControls>("CFuncTrainControls")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCFuncTrainControls::GetParent, &GCFuncTrainControls::SetParent)
        .addFunction("ToPtr", &GCFuncTrainControls::ToPtr)
        .addFunction("IsValid", &GCFuncTrainControls::IsValid)
        .endClass();
}