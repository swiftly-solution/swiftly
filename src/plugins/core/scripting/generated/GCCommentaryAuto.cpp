#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCommentaryAuto::GCCommentaryAuto(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCommentaryAuto::GCCommentaryAuto(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCCommentaryAuto::GetOnCommentaryNewGame() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CCommentaryAuto", "m_OnCommentaryNewGame"));
    return value;
}
void GCCommentaryAuto::SetOnCommentaryNewGame(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CCommentaryAuto", "m_OnCommentaryNewGame", false, value);
}
GCEntityIOOutput GCCommentaryAuto::GetOnCommentaryMidGame() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CCommentaryAuto", "m_OnCommentaryMidGame"));
    return value;
}
void GCCommentaryAuto::SetOnCommentaryMidGame(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CCommentaryAuto", "m_OnCommentaryMidGame", false, value);
}
GCEntityIOOutput GCCommentaryAuto::GetOnCommentaryMultiplayerSpawn() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CCommentaryAuto", "m_OnCommentaryMultiplayerSpawn"));
    return value;
}
void GCCommentaryAuto::SetOnCommentaryMultiplayerSpawn(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CCommentaryAuto", "m_OnCommentaryMultiplayerSpawn", false, value);
}
std::string GCCommentaryAuto::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCommentaryAuto::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCCommentaryAuto::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCCommentaryAuto::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCommentaryAuto(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCommentaryAuto>("CCommentaryAuto")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnCommentaryNewGame", &GCCommentaryAuto::GetOnCommentaryNewGame, &GCCommentaryAuto::SetOnCommentaryNewGame)
        .addProperty("OnCommentaryMidGame", &GCCommentaryAuto::GetOnCommentaryMidGame, &GCCommentaryAuto::SetOnCommentaryMidGame)
        .addProperty("OnCommentaryMultiplayerSpawn", &GCCommentaryAuto::GetOnCommentaryMultiplayerSpawn, &GCCommentaryAuto::SetOnCommentaryMultiplayerSpawn)
        .addProperty("Parent", &GCCommentaryAuto::GetParent, &GCCommentaryAuto::SetParent)
        .addFunction("ToPtr", &GCCommentaryAuto::ToPtr)
        .addFunction("IsValid", &GCCommentaryAuto::IsValid)
        .endClass();
}