#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSimpleStopwatch::GCSimpleStopwatch(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSimpleStopwatch::GCSimpleStopwatch(void *ptr) {
    m_ptr = ptr;
}
std::string GCSimpleStopwatch::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSimpleStopwatch::IsValid() {
    return (m_ptr != nullptr);
}
GCStopwatchBase GCSimpleStopwatch::GetParent() const {
    GCStopwatchBase value(m_ptr);
    return value;
}
void GCSimpleStopwatch::SetParent(GCStopwatchBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSimpleStopwatch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSimpleStopwatch>("CSimpleStopwatch")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCSimpleStopwatch::GetParent, &GCSimpleStopwatch::SetParent)
        .addFunction("ToPtr", &GCSimpleStopwatch::ToPtr)
        .addFunction("IsValid", &GCSimpleStopwatch::IsValid)
        .endClass();
}