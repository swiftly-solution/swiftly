#include "../../../core/scripting/generated/classes/GCNavVolumeSphere.h"
#include "../core.h"

void SetupLuaClassGCNavVolumeSphere(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeSphere>("CNavVolumeSphere")
        .addProperty("Center", &GCNavVolumeSphere::GetCenter, &GCNavVolumeSphere::SetCenter)
        .addProperty("Radius", &GCNavVolumeSphere::GetRadius, &GCNavVolumeSphere::SetRadius)
        .endClass();
}