#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeTwistConstraint_t::GFeTwistConstraint_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeTwistConstraint_t::GFeTwistConstraint_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GFeTwistConstraint_t::GetNodeOrient() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeTwistConstraint_t", "nNodeOrient");
}
void GFeTwistConstraint_t::SetNodeOrient(uint16_t value) {
    SetSchemaValue(m_ptr, "FeTwistConstraint_t", "nNodeOrient", true, value);
}
uint16_t GFeTwistConstraint_t::GetNodeEnd() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeTwistConstraint_t", "nNodeEnd");
}
void GFeTwistConstraint_t::SetNodeEnd(uint16_t value) {
    SetSchemaValue(m_ptr, "FeTwistConstraint_t", "nNodeEnd", true, value);
}
float GFeTwistConstraint_t::GetTwistRelax() const {
    return GetSchemaValue<float>(m_ptr, "FeTwistConstraint_t", "flTwistRelax");
}
void GFeTwistConstraint_t::SetTwistRelax(float value) {
    SetSchemaValue(m_ptr, "FeTwistConstraint_t", "flTwistRelax", true, value);
}
float GFeTwistConstraint_t::GetSwingRelax() const {
    return GetSchemaValue<float>(m_ptr, "FeTwistConstraint_t", "flSwingRelax");
}
void GFeTwistConstraint_t::SetSwingRelax(float value) {
    SetSchemaValue(m_ptr, "FeTwistConstraint_t", "flSwingRelax", true, value);
}
std::string GFeTwistConstraint_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeTwistConstraint_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeTwistConstraint_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeTwistConstraint_t>("FeTwistConstraint_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NodeOrient", &GFeTwistConstraint_t::GetNodeOrient, &GFeTwistConstraint_t::SetNodeOrient)
        .addProperty("NodeEnd", &GFeTwistConstraint_t::GetNodeEnd, &GFeTwistConstraint_t::SetNodeEnd)
        .addProperty("TwistRelax", &GFeTwistConstraint_t::GetTwistRelax, &GFeTwistConstraint_t::SetTwistRelax)
        .addProperty("SwingRelax", &GFeTwistConstraint_t::GetSwingRelax, &GFeTwistConstraint_t::SetSwingRelax)
        .addFunction("ToPtr", &GFeTwistConstraint_t::ToPtr)
        .addFunction("IsValid", &GFeTwistConstraint_t::IsValid)
        .endClass();
}