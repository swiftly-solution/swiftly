#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFilterLOS::GCFilterLOS(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFilterLOS::GCFilterLOS(void *ptr) {
    m_ptr = ptr;
}
std::string GCFilterLOS::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFilterLOS::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFilter GCFilterLOS::GetParent() const {
    GCBaseFilter value(m_ptr);
    return value;
}
void GCFilterLOS::SetParent(GCBaseFilter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFilterLOS(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterLOS>("CFilterLOS")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCFilterLOS::GetParent, &GCFilterLOS::SetParent)
        .addFunction("ToPtr", &GCFilterLOS::ToPtr)
        .addFunction("IsValid", &GCFilterLOS::IsValid)
        .endClass();
}