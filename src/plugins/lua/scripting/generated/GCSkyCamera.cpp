#include "../../../core/scripting/generated/classes/GCSkyCamera.h"
#include "../core.h"

void SetupLuaClassGCSkyCamera(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkyCamera>("CSkyCamera")
        .addProperty("SkyboxData", &GCSkyCamera::GetSkyboxData, &GCSkyCamera::SetSkyboxData)
        .addProperty("SkyboxSlotToken", &GCSkyCamera::GetSkyboxSlotToken, &GCSkyCamera::SetSkyboxSlotToken)
        .addProperty("UseAngles", &GCSkyCamera::GetUseAngles, &GCSkyCamera::SetUseAngles)
        .addProperty("Next", &GCSkyCamera::GetNext, &GCSkyCamera::SetNext)
        .endClass();
}