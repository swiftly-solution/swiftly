#include "../../../core/scripting/generated/classes/GCProjectedDecal.h"
#include "../core.h"

void SetupLuaClassGCProjectedDecal(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCProjectedDecal>("CProjectedDecal")
        .addProperty("Texture", &GCProjectedDecal::GetTexture, &GCProjectedDecal::SetTexture)
        .addProperty("Distance", &GCProjectedDecal::GetDistance, &GCProjectedDecal::SetDistance)
        .endClass();
}