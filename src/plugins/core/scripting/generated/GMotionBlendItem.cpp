#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMotionBlendItem::GMotionBlendItem(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMotionBlendItem::GMotionBlendItem(void *ptr) {
    m_ptr = ptr;
}
float GMotionBlendItem::GetKeyValue() const {
    return GetSchemaValue<float>(m_ptr, "MotionBlendItem", "m_flKeyValue");
}
void GMotionBlendItem::SetKeyValue(float value) {
    SetSchemaValue(m_ptr, "MotionBlendItem", "m_flKeyValue", false, value);
}
std::string GMotionBlendItem::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMotionBlendItem::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassMotionBlendItem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMotionBlendItem>("MotionBlendItem")
        .addConstructor<void (*)(std::string)>()
        .addProperty("KeyValue", &GMotionBlendItem::GetKeyValue, &GMotionBlendItem::SetKeyValue)
        .addFunction("ToPtr", &GMotionBlendItem::ToPtr)
        .addFunction("IsValid", &GMotionBlendItem::IsValid)
        .endClass();
}