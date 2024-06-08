#include "../../../core/scripting/generated/classes/GGeneratedTextureHandle_t.h"
#include "../core.h"

void SetupLuaClassGGeneratedTextureHandle_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GGeneratedTextureHandle_t>("GeneratedTextureHandle_t")
        .addProperty("StrBitmapName", &GGeneratedTextureHandle_t::GetStrBitmapName, &GGeneratedTextureHandle_t::SetStrBitmapName)
        .endClass();
}