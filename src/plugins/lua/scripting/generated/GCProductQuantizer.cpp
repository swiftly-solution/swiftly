#include "../../../core/scripting/generated/classes/GCProductQuantizer.h"
#include "../core.h"

void SetupLuaClassGCProductQuantizer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCProductQuantizer>("CProductQuantizer")
        .addProperty("SubQuantizers", &GCProductQuantizer::GetSubQuantizers, &GCProductQuantizer::SetSubQuantizers)
        .addProperty("Dimensions", &GCProductQuantizer::GetDimensions, &GCProductQuantizer::SetDimensions)
        .endClass();
}