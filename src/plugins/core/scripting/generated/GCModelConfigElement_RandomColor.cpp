#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelConfigElement_RandomColor::GCModelConfigElement_RandomColor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelConfigElement_RandomColor::GCModelConfigElement_RandomColor(void *ptr) {
    m_ptr = ptr;
}
std::string GCModelConfigElement_RandomColor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelConfigElement_RandomColor::IsValid() {
    return (m_ptr != nullptr);
}
GCModelConfigElement GCModelConfigElement_RandomColor::GetParent() const {
    GCModelConfigElement value(m_ptr);
    return value;
}
void GCModelConfigElement_RandomColor::SetParent(GCModelConfigElement value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCModelConfigElement_RandomColor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_RandomColor>("CModelConfigElement_RandomColor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCModelConfigElement_RandomColor::GetParent, &GCModelConfigElement_RandomColor::SetParent)
        .addFunction("ToPtr", &GCModelConfigElement_RandomColor::ToPtr)
        .addFunction("IsValid", &GCModelConfigElement_RandomColor::IsValid)
        .endClass();
}