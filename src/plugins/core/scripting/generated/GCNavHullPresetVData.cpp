#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavHullPresetVData::GCNavHullPresetVData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavHullPresetVData::GCNavHullPresetVData(void *ptr) {
    m_ptr = ptr;
}
std::vector<CUtlString> GCNavHullPresetVData::GetNavHulls() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CNavHullPresetVData", "m_vecNavHulls"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCNavHullPresetVData::SetNavHulls(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CNavHullPresetVData", "m_vecNavHulls", false, value);
}
std::string GCNavHullPresetVData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavHullPresetVData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNavHullPresetVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavHullPresetVData>("CNavHullPresetVData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NavHulls", &GCNavHullPresetVData::GetNavHulls, &GCNavHullPresetVData::SetNavHulls)
        .addFunction("ToPtr", &GCNavHullPresetVData::ToPtr)
        .addFunction("IsValid", &GCNavHullPresetVData::IsValid)
        .endClass();
}