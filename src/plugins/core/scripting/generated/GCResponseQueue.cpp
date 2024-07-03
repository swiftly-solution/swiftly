#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCResponseQueue::GCResponseQueue(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCResponseQueue::GCResponseQueue(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCAI_Expresser*> GCResponseQueue::GetExpresserTargets() const {
    CUtlVector<GCAI_Expresser*>* vec = GetSchemaValue<CUtlVector<GCAI_Expresser*>*>(m_ptr, "CResponseQueue", "m_ExpresserTargets"); std::vector<GCAI_Expresser*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCResponseQueue::SetExpresserTargets(std::vector<GCAI_Expresser*> value) {
    SetSchemaValueCUtlVector<GCAI_Expresser*>(m_ptr, "CResponseQueue", "m_ExpresserTargets", false, value);
}
std::string GCResponseQueue::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCResponseQueue::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCResponseQueue(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCResponseQueue>("CResponseQueue")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ExpresserTargets", &GCResponseQueue::GetExpresserTargets, &GCResponseQueue::SetExpresserTargets)
        .addFunction("ToPtr", &GCResponseQueue::ToPtr)
        .addFunction("IsValid", &GCResponseQueue::IsValid)
        .endClass();
}