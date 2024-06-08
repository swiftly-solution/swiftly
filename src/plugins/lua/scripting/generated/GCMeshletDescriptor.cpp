#include "../../../core/scripting/generated/classes/GCMeshletDescriptor.h"
#include "../core.h"

void SetupLuaClassGCMeshletDescriptor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMeshletDescriptor>("CMeshletDescriptor")
        .addProperty("CullingData", &GCMeshletDescriptor::GetCullingData, &GCMeshletDescriptor::SetCullingData)
        .endClass();
}