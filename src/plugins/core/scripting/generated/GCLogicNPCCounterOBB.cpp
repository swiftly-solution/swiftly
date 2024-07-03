#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicNPCCounterOBB::GCLogicNPCCounterOBB(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicNPCCounterOBB::GCLogicNPCCounterOBB(void *ptr) {
    m_ptr = ptr;
}
std::string GCLogicNPCCounterOBB::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicNPCCounterOBB::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicNPCCounterAABB GCLogicNPCCounterOBB::GetParent() const {
    GCLogicNPCCounterAABB value(m_ptr);
    return value;
}
void GCLogicNPCCounterOBB::SetParent(GCLogicNPCCounterAABB value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicNPCCounterOBB(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicNPCCounterOBB>("CLogicNPCCounterOBB")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCLogicNPCCounterOBB::GetParent, &GCLogicNPCCounterOBB::SetParent)
        .addFunction("ToPtr", &GCLogicNPCCounterOBB::ToPtr)
        .addFunction("IsValid", &GCLogicNPCCounterOBB::IsValid)
        .endClass();
}