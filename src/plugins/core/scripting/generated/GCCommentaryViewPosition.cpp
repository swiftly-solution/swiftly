#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCommentaryViewPosition::GCCommentaryViewPosition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCommentaryViewPosition::GCCommentaryViewPosition(void *ptr) {
    m_ptr = ptr;
}
std::string GCCommentaryViewPosition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCommentaryViewPosition::IsValid() {
    return (m_ptr != nullptr);
}
GCSprite GCCommentaryViewPosition::GetParent() const {
    GCSprite value(m_ptr);
    return value;
}
void GCCommentaryViewPosition::SetParent(GCSprite value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCommentaryViewPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCommentaryViewPosition>("CCommentaryViewPosition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCommentaryViewPosition::GetParent, &GCCommentaryViewPosition::SetParent)
        .addFunction("ToPtr", &GCCommentaryViewPosition::ToPtr)
        .addFunction("IsValid", &GCCommentaryViewPosition::IsValid)
        .endClass();
}