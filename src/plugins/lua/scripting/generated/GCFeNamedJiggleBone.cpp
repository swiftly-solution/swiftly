#include "../../../core/scripting/generated/classes/GCFeNamedJiggleBone.h"
#include "../core.h"

void SetupLuaClassGCFeNamedJiggleBone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFeNamedJiggleBone>("CFeNamedJiggleBone")
        .addProperty("StrParentBone", &GCFeNamedJiggleBone::GetStrParentBone, &GCFeNamedJiggleBone::SetStrParentBone)
        .addProperty("JiggleParent", &GCFeNamedJiggleBone::GetJiggleParent, &GCFeNamedJiggleBone::SetJiggleParent)
        .addProperty("JiggleBone", &GCFeNamedJiggleBone::GetJiggleBone, &GCFeNamedJiggleBone::SetJiggleBone)
        .endClass();
}