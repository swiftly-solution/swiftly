#include "../../../core/scripting/generated/classes/GCAttributeManager__cached_attribute_float_t.h"
#include "../core.h"

void SetupLuaClassGCAttributeManager__cached_attribute_float_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAttributeManager__cached_attribute_float_t>("CAttributeManager__cached_attribute_float_t")
        .addProperty("In", &GCAttributeManager__cached_attribute_float_t::GetIn, &GCAttributeManager__cached_attribute_float_t::SetIn)
        .addProperty("AttribHook", &GCAttributeManager__cached_attribute_float_t::GetAttribHook, &GCAttributeManager__cached_attribute_float_t::SetAttribHook)
        .addProperty("Out", &GCAttributeManager__cached_attribute_float_t::GetOut, &GCAttributeManager__cached_attribute_float_t::SetOut)
        .endClass();
}