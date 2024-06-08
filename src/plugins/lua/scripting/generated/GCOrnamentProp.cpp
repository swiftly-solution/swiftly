#include "../../../core/scripting/generated/classes/GCOrnamentProp.h"
#include "../core.h"

void SetupLuaClassGCOrnamentProp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCOrnamentProp>("COrnamentProp")
        .addProperty("InitialOwner", &GCOrnamentProp::GetInitialOwner, &GCOrnamentProp::SetInitialOwner)
        .endClass();
}