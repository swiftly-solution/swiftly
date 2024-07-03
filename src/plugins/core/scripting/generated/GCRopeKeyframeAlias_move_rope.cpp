#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRopeKeyframeAlias_move_rope::GCRopeKeyframeAlias_move_rope(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRopeKeyframeAlias_move_rope::GCRopeKeyframeAlias_move_rope(void *ptr) {
    m_ptr = ptr;
}
std::string GCRopeKeyframeAlias_move_rope::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRopeKeyframeAlias_move_rope::IsValid() {
    return (m_ptr != nullptr);
}
GCRopeKeyframe GCRopeKeyframeAlias_move_rope::GetParent() const {
    GCRopeKeyframe value(m_ptr);
    return value;
}
void GCRopeKeyframeAlias_move_rope::SetParent(GCRopeKeyframe value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRopeKeyframeAlias_move_rope(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRopeKeyframeAlias_move_rope>("CRopeKeyframeAlias_move_rope")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCRopeKeyframeAlias_move_rope::GetParent, &GCRopeKeyframeAlias_move_rope::SetParent)
        .addFunction("ToPtr", &GCRopeKeyframeAlias_move_rope::ToPtr)
        .addFunction("IsValid", &GCRopeKeyframeAlias_move_rope::IsValid)
        .endClass();
}