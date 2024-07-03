#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBreakableStageHelper::GCBreakableStageHelper(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBreakableStageHelper::GCBreakableStageHelper(void *ptr) {
    m_ptr = ptr;
}
int32_t GCBreakableStageHelper::GetCurrentStage() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBreakableStageHelper", "m_nCurrentStage");
}
void GCBreakableStageHelper::SetCurrentStage(int32_t value) {
    SetSchemaValue(m_ptr, "CBreakableStageHelper", "m_nCurrentStage", false, value);
}
int32_t GCBreakableStageHelper::GetStageCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBreakableStageHelper", "m_nStageCount");
}
void GCBreakableStageHelper::SetStageCount(int32_t value) {
    SetSchemaValue(m_ptr, "CBreakableStageHelper", "m_nStageCount", false, value);
}
std::string GCBreakableStageHelper::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBreakableStageHelper::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCBreakableStageHelper(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBreakableStageHelper>("CBreakableStageHelper")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CurrentStage", &GCBreakableStageHelper::GetCurrentStage, &GCBreakableStageHelper::SetCurrentStage)
        .addProperty("StageCount", &GCBreakableStageHelper::GetStageCount, &GCBreakableStageHelper::SetStageCount)
        .addFunction("ToPtr", &GCBreakableStageHelper::ToPtr)
        .addFunction("IsValid", &GCBreakableStageHelper::IsValid)
        .endClass();
}