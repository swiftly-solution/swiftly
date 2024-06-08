#include "../../../core/scripting/generated/classes/GCVPhysXSurfacePropertiesList.h"
#include "../core.h"

void SetupLuaClassGCVPhysXSurfacePropertiesList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVPhysXSurfacePropertiesList>("CVPhysXSurfacePropertiesList")
        .addProperty("SurfacePropertiesList", &GCVPhysXSurfacePropertiesList::GetSurfacePropertiesList, &GCVPhysXSurfacePropertiesList::SetSurfacePropertiesList)
        .endClass();
}