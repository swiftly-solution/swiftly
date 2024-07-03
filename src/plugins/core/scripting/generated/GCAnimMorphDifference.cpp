#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimMorphDifference::GCAnimMorphDifference(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimMorphDifference::GCAnimMorphDifference(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCAnimMorphDifference::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimMorphDifference", "m_name");
}
void GCAnimMorphDifference::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimMorphDifference", "m_name", false, value);
}
std::string GCAnimMorphDifference::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimMorphDifference::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimMorphDifference(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimMorphDifference>("CAnimMorphDifference")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAnimMorphDifference::GetName, &GCAnimMorphDifference::SetName)
        .addFunction("ToPtr", &GCAnimMorphDifference::ToPtr)
        .addFunction("IsValid", &GCAnimMorphDifference::IsValid)
        .endClass();
}