#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFlexController::GCFlexController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFlexController::GCFlexController(void *ptr) {
    m_ptr = ptr;
}
std::string GCFlexController::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFlexController", "m_szName").Get();
}
void GCFlexController::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CFlexController", "m_szName", false, CUtlString(value.c_str()));
}
std::string GCFlexController::GetType() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFlexController", "m_szType").Get();
}
void GCFlexController::SetType(std::string value) {
    SetSchemaValue(m_ptr, "CFlexController", "m_szType", false, CUtlString(value.c_str()));
}
float GCFlexController::GetMin() const {
    return GetSchemaValue<float>(m_ptr, "CFlexController", "min");
}
void GCFlexController::SetMin(float value) {
    SetSchemaValue(m_ptr, "CFlexController", "min", false, value);
}
float GCFlexController::GetMax() const {
    return GetSchemaValue<float>(m_ptr, "CFlexController", "max");
}
void GCFlexController::SetMax(float value) {
    SetSchemaValue(m_ptr, "CFlexController", "max", false, value);
}
std::string GCFlexController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFlexController::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFlexController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlexController>("CFlexController")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCFlexController::GetName, &GCFlexController::SetName)
        .addProperty("Type", &GCFlexController::GetType, &GCFlexController::SetType)
        .addProperty("Min", &GCFlexController::GetMin, &GCFlexController::SetMin)
        .addProperty("Max", &GCFlexController::GetMax, &GCFlexController::SetMax)
        .addFunction("ToPtr", &GCFlexController::ToPtr)
        .addFunction("IsValid", &GCFlexController::IsValid)
        .endClass();
}