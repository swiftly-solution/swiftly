#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHitBoxSetList::GCHitBoxSetList(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHitBoxSetList::GCHitBoxSetList(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCHitBoxSet> GCHitBoxSetList::GetHitBoxSets() const {
    CUtlVector<GCHitBoxSet>* vec = GetSchemaValue<CUtlVector<GCHitBoxSet>*>(m_ptr, "CHitBoxSetList", "m_HitBoxSets"); std::vector<GCHitBoxSet> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCHitBoxSetList::SetHitBoxSets(std::vector<GCHitBoxSet> value) {
    SetSchemaValueCUtlVector<GCHitBoxSet>(m_ptr, "CHitBoxSetList", "m_HitBoxSets", false, value);
}
std::string GCHitBoxSetList::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHitBoxSetList::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCHitBoxSetList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHitBoxSetList>("CHitBoxSetList")
        .addConstructor<void (*)(std::string)>()
        .addProperty("HitBoxSets", &GCHitBoxSetList::GetHitBoxSets, &GCHitBoxSetList::SetHitBoxSets)
        .addFunction("ToPtr", &GCHitBoxSetList::ToPtr)
        .addFunction("IsValid", &GCHitBoxSetList::IsValid)
        .endClass();
}