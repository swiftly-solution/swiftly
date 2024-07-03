#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFlexOp::GCFlexOp(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFlexOp::GCFlexOp(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCFlexOp::GetOpCode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFlexOp", "m_OpCode");
}
void GCFlexOp::SetOpCode(uint64_t value) {
    SetSchemaValue(m_ptr, "CFlexOp", "m_OpCode", false, value);
}
int32_t GCFlexOp::GetData() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFlexOp", "m_Data");
}
void GCFlexOp::SetData(int32_t value) {
    SetSchemaValue(m_ptr, "CFlexOp", "m_Data", false, value);
}
std::string GCFlexOp::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFlexOp::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFlexOp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlexOp>("CFlexOp")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OpCode", &GCFlexOp::GetOpCode, &GCFlexOp::SetOpCode)
        .addProperty("Data", &GCFlexOp::GetData, &GCFlexOp::SetData)
        .addFunction("ToPtr", &GCFlexOp::ToPtr)
        .addFunction("IsValid", &GCFlexOp::IsValid)
        .endClass();
}