#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStateNodeTransitionData::GCStateNodeTransitionData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStateNodeTransitionData::GCStateNodeTransitionData(void *ptr) {
    m_ptr = ptr;
}
GCBlendCurve GCStateNodeTransitionData::GetCurve() const {
    GCBlendCurve value(GetSchemaPtr(m_ptr, "CStateNodeTransitionData", "m_curve"));
    return value;
}
void GCStateNodeTransitionData::SetCurve(GCBlendCurve value) {
    SetSchemaValue(m_ptr, "CStateNodeTransitionData", "m_curve", false, value);
}
std::string GCStateNodeTransitionData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStateNodeTransitionData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCStateNodeTransitionData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStateNodeTransitionData>("CStateNodeTransitionData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Curve", &GCStateNodeTransitionData::GetCurve, &GCStateNodeTransitionData::SetCurve)
        .addFunction("ToPtr", &GCStateNodeTransitionData::ToPtr)
        .addFunction("IsValid", &GCStateNodeTransitionData::IsValid)
        .endClass();
}