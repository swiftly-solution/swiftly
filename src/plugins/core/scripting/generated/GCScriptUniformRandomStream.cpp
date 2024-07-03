#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCScriptUniformRandomStream::GCScriptUniformRandomStream(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCScriptUniformRandomStream::GCScriptUniformRandomStream(void *ptr) {
    m_ptr = ptr;
}
int32_t GCScriptUniformRandomStream::GetInitialSeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CScriptUniformRandomStream", "m_nInitialSeed");
}
void GCScriptUniformRandomStream::SetInitialSeed(int32_t value) {
    SetSchemaValue(m_ptr, "CScriptUniformRandomStream", "m_nInitialSeed", false, value);
}
std::string GCScriptUniformRandomStream::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCScriptUniformRandomStream::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCScriptUniformRandomStream(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptUniformRandomStream>("CScriptUniformRandomStream")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InitialSeed", &GCScriptUniformRandomStream::GetInitialSeed, &GCScriptUniformRandomStream::SetInitialSeed)
        .addFunction("ToPtr", &GCScriptUniformRandomStream::ToPtr)
        .addFunction("IsValid", &GCScriptUniformRandomStream::IsValid)
        .endClass();
}