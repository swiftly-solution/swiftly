#include "../../../core/scripting/generated/classes/GCSkyboxReference.h"
#include "../core.h"

void SetupLuaClassGCSkyboxReference(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkyboxReference>("CSkyboxReference")
        .addProperty("WorldGroupId", &GCSkyboxReference::GetWorldGroupId, &GCSkyboxReference::SetWorldGroupId)
        .addProperty("SkyCamera", &GCSkyboxReference::GetSkyCamera, &GCSkyboxReference::SetSkyCamera)
        .endClass();
}