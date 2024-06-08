#include "../../../core/scripting/generated/classes/GCBodyComponentPoint.h"
#include "../core.h"

void SetupLuaClassGCBodyComponentPoint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyComponentPoint>("CBodyComponentPoint")
        .addProperty("SceneNode", &GCBodyComponentPoint::GetSceneNode, &GCBodyComponentPoint::SetSceneNode)
        .endClass();
}