#include "../../../core/scripting/generated/classes/GCFeVertexMapBuildArray.h"
#include "../core.h"

void SetupLuaClassGCFeVertexMapBuildArray(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFeVertexMapBuildArray>("CFeVertexMapBuildArray")
        .addProperty("Array", &GCFeVertexMapBuildArray::GetArray, &GCFeVertexMapBuildArray::SetArray)
        .endClass();
}