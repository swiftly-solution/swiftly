#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTestDomainDerived_Cursor::GCTestDomainDerived_Cursor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTestDomainDerived_Cursor::GCTestDomainDerived_Cursor(void *ptr) {
    m_ptr = ptr;
}
int32_t GCTestDomainDerived_Cursor::GetCursorValueA() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTestDomainDerived_Cursor", "m_nCursorValueA");
}
void GCTestDomainDerived_Cursor::SetCursorValueA(int32_t value) {
    SetSchemaValue(m_ptr, "CTestDomainDerived_Cursor", "m_nCursorValueA", false, value);
}
int32_t GCTestDomainDerived_Cursor::GetCursorValueB() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTestDomainDerived_Cursor", "m_nCursorValueB");
}
void GCTestDomainDerived_Cursor::SetCursorValueB(int32_t value) {
    SetSchemaValue(m_ptr, "CTestDomainDerived_Cursor", "m_nCursorValueB", false, value);
}
std::string GCTestDomainDerived_Cursor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTestDomainDerived_Cursor::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCTestDomainDerived_Cursor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTestDomainDerived_Cursor>("CTestDomainDerived_Cursor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CursorValueA", &GCTestDomainDerived_Cursor::GetCursorValueA, &GCTestDomainDerived_Cursor::SetCursorValueA)
        .addProperty("CursorValueB", &GCTestDomainDerived_Cursor::GetCursorValueB, &GCTestDomainDerived_Cursor::SetCursorValueB)
        .addFunction("ToPtr", &GCTestDomainDerived_Cursor::ToPtr)
        .addFunction("IsValid", &GCTestDomainDerived_Cursor::IsValid)
        .endClass();
}