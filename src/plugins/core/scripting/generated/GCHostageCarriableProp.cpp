#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHostageCarriableProp::GCHostageCarriableProp(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHostageCarriableProp::GCHostageCarriableProp(void *ptr) {
    m_ptr = ptr;
}
std::string GCHostageCarriableProp::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHostageCarriableProp::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseAnimGraph GCHostageCarriableProp::GetParent() const {
    GCBaseAnimGraph value(m_ptr);
    return value;
}
void GCHostageCarriableProp::SetParent(GCBaseAnimGraph value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCHostageCarriableProp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHostageCarriableProp>("CHostageCarriableProp")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCHostageCarriableProp::GetParent, &GCHostageCarriableProp::SetParent)
        .addFunction("ToPtr", &GCHostageCarriableProp::ToPtr)
        .addFunction("IsValid", &GCHostageCarriableProp::IsValid)
        .endClass();
}