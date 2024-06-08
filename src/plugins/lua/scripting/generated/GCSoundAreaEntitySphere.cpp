#include "../../../core/scripting/generated/classes/GCSoundAreaEntitySphere.h"
#include "../core.h"

void SetupLuaClassGCSoundAreaEntitySphere(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundAreaEntitySphere>("CSoundAreaEntitySphere")
        .addProperty("Radius", &GCSoundAreaEntitySphere::GetRadius, &GCSoundAreaEntitySphere::SetRadius)
        .endClass();
}