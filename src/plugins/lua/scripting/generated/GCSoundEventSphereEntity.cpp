#include "../../../core/scripting/generated/classes/GCSoundEventSphereEntity.h"
#include "../core.h"

void SetupLuaClassGCSoundEventSphereEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventSphereEntity>("CSoundEventSphereEntity")
        .addProperty("Radius", &GCSoundEventSphereEntity::GetRadius, &GCSoundEventSphereEntity::SetRadius)
        .endClass();
}