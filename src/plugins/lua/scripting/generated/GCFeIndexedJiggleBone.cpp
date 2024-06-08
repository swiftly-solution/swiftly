#include "../../../core/scripting/generated/classes/GCFeIndexedJiggleBone.h"
#include "../core.h"

void SetupLuaClassGCFeIndexedJiggleBone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFeIndexedJiggleBone>("CFeIndexedJiggleBone")
        .addProperty("Node", &GCFeIndexedJiggleBone::GetNode, &GCFeIndexedJiggleBone::SetNode)
        .addProperty("JiggleParent", &GCFeIndexedJiggleBone::GetJiggleParent, &GCFeIndexedJiggleBone::SetJiggleParent)
        .addProperty("JiggleBone", &GCFeIndexedJiggleBone::GetJiggleBone, &GCFeIndexedJiggleBone::SetJiggleBone)
        .endClass();
}