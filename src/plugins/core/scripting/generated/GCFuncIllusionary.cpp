#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncIllusionary::GCFuncIllusionary(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncIllusionary::GCFuncIllusionary(void *ptr) {
    m_ptr = ptr;
}
std::string GCFuncIllusionary::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncIllusionary::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncIllusionary::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncIllusionary::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncIllusionary(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncIllusionary>("CFuncIllusionary")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCFuncIllusionary::GetParent, &GCFuncIllusionary::SetParent)
        .addFunction("ToPtr", &GCFuncIllusionary::ToPtr)
        .addFunction("IsValid", &GCFuncIllusionary::IsValid)
        .endClass();
}