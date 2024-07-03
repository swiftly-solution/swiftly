#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimReplayFrame::GCAnimReplayFrame(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimReplayFrame::GCAnimReplayFrame(void *ptr) {
    m_ptr = ptr;
}
float GCAnimReplayFrame::GetTimeStamp() const {
    return GetSchemaValue<float>(m_ptr, "CAnimReplayFrame", "m_timeStamp");
}
void GCAnimReplayFrame::SetTimeStamp(float value) {
    SetSchemaValue(m_ptr, "CAnimReplayFrame", "m_timeStamp", false, value);
}
std::string GCAnimReplayFrame::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimReplayFrame::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimReplayFrame(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimReplayFrame>("CAnimReplayFrame")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TimeStamp", &GCAnimReplayFrame::GetTimeStamp, &GCAnimReplayFrame::SetTimeStamp)
        .addFunction("ToPtr", &GCAnimReplayFrame::ToPtr)
        .addFunction("IsValid", &GCAnimReplayFrame::IsValid)
        .endClass();
}