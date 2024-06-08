#include "../../../core/scripting/generated/classes/GCRegionSVM.h"
#include "../core.h"

void SetupLuaClassGCRegionSVM(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRegionSVM>("CRegionSVM")
        .addProperty("Planes", &GCRegionSVM::GetPlanes, &GCRegionSVM::SetPlanes)
        .addProperty("Nodes", &GCRegionSVM::GetNodes, &GCRegionSVM::SetNodes)
        .endClass();
}