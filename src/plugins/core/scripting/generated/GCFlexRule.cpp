#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFlexRule::GCFlexRule(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFlexRule::GCFlexRule(void *ptr) {
    m_ptr = ptr;
}
int32_t GCFlexRule::GetFlex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFlexRule", "m_nFlex");
}
void GCFlexRule::SetFlex(int32_t value) {
    SetSchemaValue(m_ptr, "CFlexRule", "m_nFlex", false, value);
}
std::vector<GCFlexOp> GCFlexRule::GetFlexOps() const {
    CUtlVector<GCFlexOp>* vec = GetSchemaValue<CUtlVector<GCFlexOp>*>(m_ptr, "CFlexRule", "m_FlexOps"); std::vector<GCFlexOp> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFlexRule::SetFlexOps(std::vector<GCFlexOp> value) {
    SetSchemaValueCUtlVector<GCFlexOp>(m_ptr, "CFlexRule", "m_FlexOps", false, value);
}
std::string GCFlexRule::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFlexRule::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFlexRule(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlexRule>("CFlexRule")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Flex", &GCFlexRule::GetFlex, &GCFlexRule::SetFlex)
        .addProperty("FlexOps", &GCFlexRule::GetFlexOps, &GCFlexRule::SetFlexOps)
        .addFunction("ToPtr", &GCFlexRule::ToPtr)
        .addFunction("IsValid", &GCFlexRule::IsValid)
        .endClass();
}