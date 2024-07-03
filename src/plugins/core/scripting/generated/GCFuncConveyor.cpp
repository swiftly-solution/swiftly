#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncConveyor::GCFuncConveyor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncConveyor::GCFuncConveyor(void *ptr) {
    m_ptr = ptr;
}
std::string GCFuncConveyor::GetConveyorModels() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncConveyor", "m_szConveyorModels").String();
}
void GCFuncConveyor::SetConveyorModels(std::string value) {
    SetSchemaValue(m_ptr, "CFuncConveyor", "m_szConveyorModels", false, CUtlSymbolLarge(value.c_str()));
}
float GCFuncConveyor::GetTransitionDurationSeconds() const {
    return GetSchemaValue<float>(m_ptr, "CFuncConveyor", "m_flTransitionDurationSeconds");
}
void GCFuncConveyor::SetTransitionDurationSeconds(float value) {
    SetSchemaValue(m_ptr, "CFuncConveyor", "m_flTransitionDurationSeconds", false, value);
}
QAngle GCFuncConveyor::GetMoveEntitySpace() const {
    return GetSchemaValue<QAngle>(m_ptr, "CFuncConveyor", "m_angMoveEntitySpace");
}
void GCFuncConveyor::SetMoveEntitySpace(QAngle value) {
    SetSchemaValue(m_ptr, "CFuncConveyor", "m_angMoveEntitySpace", false, value);
}
Vector GCFuncConveyor::GetMoveDirEntitySpace() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncConveyor", "m_vecMoveDirEntitySpace");
}
void GCFuncConveyor::SetMoveDirEntitySpace(Vector value) {
    SetSchemaValue(m_ptr, "CFuncConveyor", "m_vecMoveDirEntitySpace", false, value);
}
float GCFuncConveyor::GetTargetSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFuncConveyor", "m_flTargetSpeed");
}
void GCFuncConveyor::SetTargetSpeed(float value) {
    SetSchemaValue(m_ptr, "CFuncConveyor", "m_flTargetSpeed", false, value);
}
int32 GCFuncConveyor::GetTransitionStartTick() const {
    return GetSchemaValue<int32>(m_ptr, "CFuncConveyor", "m_nTransitionStartTick");
}
void GCFuncConveyor::SetTransitionStartTick(int32 value) {
    SetSchemaValue(m_ptr, "CFuncConveyor", "m_nTransitionStartTick", false, value);
}
int32_t GCFuncConveyor::GetTransitionDurationTicks() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFuncConveyor", "m_nTransitionDurationTicks");
}
void GCFuncConveyor::SetTransitionDurationTicks(int32_t value) {
    SetSchemaValue(m_ptr, "CFuncConveyor", "m_nTransitionDurationTicks", false, value);
}
float GCFuncConveyor::GetTransitionStartSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFuncConveyor", "m_flTransitionStartSpeed");
}
void GCFuncConveyor::SetTransitionStartSpeed(float value) {
    SetSchemaValue(m_ptr, "CFuncConveyor", "m_flTransitionStartSpeed", false, value);
}
std::vector<GCBaseEntity*> GCFuncConveyor::GetConveyorModels1() const {
    CUtlVector<GCBaseEntity*>* vec = GetSchemaValue<CUtlVector<GCBaseEntity*>*>(m_ptr, "CFuncConveyor", "m_hConveyorModels"); std::vector<GCBaseEntity*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFuncConveyor::SetConveyorModels1(std::vector<GCBaseEntity*> value) {
    SetSchemaValueCUtlVector<GCBaseEntity*>(m_ptr, "CFuncConveyor", "m_hConveyorModels", false, value);
}
std::string GCFuncConveyor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncConveyor::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncConveyor::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncConveyor::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncConveyor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncConveyor>("CFuncConveyor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ConveyorModels", &GCFuncConveyor::GetConveyorModels, &GCFuncConveyor::SetConveyorModels)
        .addProperty("TransitionDurationSeconds", &GCFuncConveyor::GetTransitionDurationSeconds, &GCFuncConveyor::SetTransitionDurationSeconds)
        .addProperty("MoveEntitySpace", &GCFuncConveyor::GetMoveEntitySpace, &GCFuncConveyor::SetMoveEntitySpace)
        .addProperty("MoveDirEntitySpace", &GCFuncConveyor::GetMoveDirEntitySpace, &GCFuncConveyor::SetMoveDirEntitySpace)
        .addProperty("TargetSpeed", &GCFuncConveyor::GetTargetSpeed, &GCFuncConveyor::SetTargetSpeed)
        .addProperty("TransitionStartTick", &GCFuncConveyor::GetTransitionStartTick, &GCFuncConveyor::SetTransitionStartTick)
        .addProperty("TransitionDurationTicks", &GCFuncConveyor::GetTransitionDurationTicks, &GCFuncConveyor::SetTransitionDurationTicks)
        .addProperty("TransitionStartSpeed", &GCFuncConveyor::GetTransitionStartSpeed, &GCFuncConveyor::SetTransitionStartSpeed)
        .addProperty("ConveyorModels1", &GCFuncConveyor::GetConveyorModels1, &GCFuncConveyor::SetConveyorModels1)
        .addProperty("Parent", &GCFuncConveyor::GetParent, &GCFuncConveyor::SetParent)
        .addFunction("ToPtr", &GCFuncConveyor::ToPtr)
        .addFunction("IsValid", &GCFuncConveyor::IsValid)
        .endClass();
}