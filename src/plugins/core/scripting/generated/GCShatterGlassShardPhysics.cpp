#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCShatterGlassShardPhysics::GCShatterGlassShardPhysics(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCShatterGlassShardPhysics::GCShatterGlassShardPhysics(void *ptr) {
    m_ptr = ptr;
}
bool GCShatterGlassShardPhysics::GetDebris() const {
    return GetSchemaValue<bool>(m_ptr, "CShatterGlassShardPhysics", "m_bDebris");
}
void GCShatterGlassShardPhysics::SetDebris(bool value) {
    SetSchemaValue(m_ptr, "CShatterGlassShardPhysics", "m_bDebris", false, value);
}
uint32_t GCShatterGlassShardPhysics::GetParentShard() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CShatterGlassShardPhysics", "m_hParentShard");
}
void GCShatterGlassShardPhysics::SetParentShard(uint32_t value) {
    SetSchemaValue(m_ptr, "CShatterGlassShardPhysics", "m_hParentShard", false, value);
}
Gshard_model_desc_t GCShatterGlassShardPhysics::GetShardDesc() const {
    Gshard_model_desc_t value(GetSchemaPtr(m_ptr, "CShatterGlassShardPhysics", "m_ShardDesc"));
    return value;
}
void GCShatterGlassShardPhysics::SetShardDesc(Gshard_model_desc_t value) {
    SetSchemaValue(m_ptr, "CShatterGlassShardPhysics", "m_ShardDesc", false, value);
}
std::string GCShatterGlassShardPhysics::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCShatterGlassShardPhysics::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysicsProp GCShatterGlassShardPhysics::GetParent() const {
    GCPhysicsProp value(m_ptr);
    return value;
}
void GCShatterGlassShardPhysics::SetParent(GCPhysicsProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCShatterGlassShardPhysics(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCShatterGlassShardPhysics>("CShatterGlassShardPhysics")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Debris", &GCShatterGlassShardPhysics::GetDebris, &GCShatterGlassShardPhysics::SetDebris)
        .addProperty("ParentShard", &GCShatterGlassShardPhysics::GetParentShard, &GCShatterGlassShardPhysics::SetParentShard)
        .addProperty("ShardDesc", &GCShatterGlassShardPhysics::GetShardDesc, &GCShatterGlassShardPhysics::SetShardDesc)
        .addProperty("Parent", &GCShatterGlassShardPhysics::GetParent, &GCShatterGlassShardPhysics::SetParent)
        .addFunction("ToPtr", &GCShatterGlassShardPhysics::ToPtr)
        .addFunction("IsValid", &GCShatterGlassShardPhysics::IsValid)
        .endClass();
}