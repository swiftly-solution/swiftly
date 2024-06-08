#include "../../../core/scripting/generated/classes/GCVariantDefaultAllocator.h"
#include "../core.h"

void SetupLuaClassGCVariantDefaultAllocator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVariantDefaultAllocator>("CVariantDefaultAllocator")

        .endClass();
}