#include "../../../core/scripting/generated/classes/GCRectLight.h"
#include "../core.h"

void SetupLuaClassGCRectLight(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRectLight>("CRectLight")
        .addProperty("ShowLight", &GCRectLight::GetShowLight, &GCRectLight::SetShowLight)
        .endClass();
}