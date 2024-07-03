#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootTrajectories::GCFootTrajectories(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootTrajectories::GCFootTrajectories(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCFootTrajectory> GCFootTrajectories::GetTrajectories() const {
    CUtlVector<GCFootTrajectory>* vec = GetSchemaValue<CUtlVector<GCFootTrajectory>*>(m_ptr, "CFootTrajectories", "m_trajectories"); std::vector<GCFootTrajectory> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFootTrajectories::SetTrajectories(std::vector<GCFootTrajectory> value) {
    SetSchemaValueCUtlVector<GCFootTrajectory>(m_ptr, "CFootTrajectories", "m_trajectories", false, value);
}
std::string GCFootTrajectories::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootTrajectories::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFootTrajectories(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootTrajectories>("CFootTrajectories")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Trajectories", &GCFootTrajectories::GetTrajectories, &GCFootTrajectories::SetTrajectories)
        .addFunction("ToPtr", &GCFootTrajectories::ToPtr)
        .addFunction("IsValid", &GCFootTrajectories::IsValid)
        .endClass();
}