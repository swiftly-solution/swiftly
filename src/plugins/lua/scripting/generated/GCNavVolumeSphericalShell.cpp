#include "../../../core/scripting/generated/classes/GCNavVolumeSphericalShell.h"
#include "../core.h"

void SetupLuaClassGCNavVolumeSphericalShell(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeSphericalShell>("CNavVolumeSphericalShell")
        .addProperty("RadiusInner", &GCNavVolumeSphericalShell::GetRadiusInner, &GCNavVolumeSphericalShell::SetRadiusInner)
        .endClass();
}