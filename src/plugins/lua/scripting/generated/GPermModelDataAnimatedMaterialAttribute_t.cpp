#include "../../../core/scripting/generated/classes/GPermModelDataAnimatedMaterialAttribute_t.h"
#include "../core.h"

void SetupLuaClassGPermModelDataAnimatedMaterialAttribute_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPermModelDataAnimatedMaterialAttribute_t>("PermModelDataAnimatedMaterialAttribute_t")
        .addProperty("AttributeName", &GPermModelDataAnimatedMaterialAttribute_t::GetAttributeName, &GPermModelDataAnimatedMaterialAttribute_t::SetAttributeName)
        .addProperty("NumChannels", &GPermModelDataAnimatedMaterialAttribute_t::GetNumChannels, &GPermModelDataAnimatedMaterialAttribute_t::SetNumChannels)
        .endClass();
}