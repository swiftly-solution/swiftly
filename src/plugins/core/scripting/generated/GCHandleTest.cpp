#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHandleTest::GCHandleTest(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHandleTest::GCHandleTest(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCHandleTest::GetHandle() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CHandleTest", "m_Handle"));
    return value;
}
void GCHandleTest::SetHandle(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Handle' is not possible.\n");
}
bool GCHandleTest::GetSendHandle() const {
    return GetSchemaValue<bool>(m_ptr, "CHandleTest", "m_bSendHandle");
}
void GCHandleTest::SetSendHandle(bool value) {
    SetSchemaValue(m_ptr, "CHandleTest", "m_bSendHandle", false, value);
}
std::string GCHandleTest::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHandleTest::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCHandleTest::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCHandleTest::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCHandleTest(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHandleTest>("CHandleTest")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Handle", &GCHandleTest::GetHandle, &GCHandleTest::SetHandle)
        .addProperty("SendHandle", &GCHandleTest::GetSendHandle, &GCHandleTest::SetSendHandle)
        .addProperty("Parent", &GCHandleTest::GetParent, &GCHandleTest::SetParent)
        .addFunction("ToPtr", &GCHandleTest::ToPtr)
        .addFunction("IsValid", &GCHandleTest::IsValid)
        .endClass();
}