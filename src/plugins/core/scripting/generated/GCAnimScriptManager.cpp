#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimScriptManager::GCAnimScriptManager(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimScriptManager::GCAnimScriptManager(void *ptr) {
    m_ptr = ptr;
}
std::vector<GScriptInfo_t> GCAnimScriptManager::GetScriptInfo() const {
    CUtlVector<GScriptInfo_t>* vec = GetSchemaValue<CUtlVector<GScriptInfo_t>*>(m_ptr, "CAnimScriptManager", "m_scriptInfo"); std::vector<GScriptInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimScriptManager::SetScriptInfo(std::vector<GScriptInfo_t> value) {
    SetSchemaValueCUtlVector<GScriptInfo_t>(m_ptr, "CAnimScriptManager", "m_scriptInfo", false, value);
}
std::string GCAnimScriptManager::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimScriptManager::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimScriptManager(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimScriptManager>("CAnimScriptManager")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ScriptInfo", &GCAnimScriptManager::GetScriptInfo, &GCAnimScriptManager::SetScriptInfo)
        .addFunction("ToPtr", &GCAnimScriptManager::ToPtr)
        .addFunction("IsValid", &GCAnimScriptManager::IsValid)
        .endClass();
}