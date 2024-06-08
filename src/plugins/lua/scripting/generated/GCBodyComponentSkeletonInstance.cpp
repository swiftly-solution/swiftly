#include "../../../core/scripting/generated/classes/GCBodyComponentSkeletonInstance.h"
#include "../core.h"

void SetupLuaClassGCBodyComponentSkeletonInstance(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyComponentSkeletonInstance>("CBodyComponentSkeletonInstance")
        .addProperty("SkeletonInstance", &GCBodyComponentSkeletonInstance::GetSkeletonInstance, &GCBodyComponentSkeletonInstance::SetSkeletonInstance)
        .endClass();
}