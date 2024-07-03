#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHintMessageQueue::GCHintMessageQueue(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHintMessageQueue::GCHintMessageQueue(void *ptr) {
    m_ptr = ptr;
}
float GCHintMessageQueue::GetTmMessageEnd() const {
    return GetSchemaValue<float>(m_ptr, "CHintMessageQueue", "m_tmMessageEnd");
}
void GCHintMessageQueue::SetTmMessageEnd(float value) {
    SetSchemaValue(m_ptr, "CHintMessageQueue", "m_tmMessageEnd", false, value);
}
GCBasePlayerController GCHintMessageQueue::GetPlayerController() const {
    GCBasePlayerController value(*GetSchemaValuePtr<void*>(m_ptr, "CHintMessageQueue", "m_pPlayerController"));
    return value;
}
void GCHintMessageQueue::SetPlayerController(GCBasePlayerController* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerController' is not possible.\n");
}
std::string GCHintMessageQueue::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHintMessageQueue::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCHintMessageQueue(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHintMessageQueue>("CHintMessageQueue")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TmMessageEnd", &GCHintMessageQueue::GetTmMessageEnd, &GCHintMessageQueue::SetTmMessageEnd)
        .addProperty("PlayerController", &GCHintMessageQueue::GetPlayerController, &GCHintMessageQueue::SetPlayerController)
        .addFunction("ToPtr", &GCHintMessageQueue::ToPtr)
        .addFunction("IsValid", &GCHintMessageQueue::IsValid)
        .endClass();
}