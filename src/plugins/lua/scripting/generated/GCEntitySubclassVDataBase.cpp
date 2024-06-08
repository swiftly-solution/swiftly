#include "../../../core/scripting/generated/classes/GCEntitySubclassVDataBase.h"
#include "../core.h"

void SetupLuaClassGCEntitySubclassVDataBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntitySubclassVDataBase>("CEntitySubclassVDataBase")

        .endClass();
}