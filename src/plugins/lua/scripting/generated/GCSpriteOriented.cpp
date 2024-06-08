#include "../../../core/scripting/generated/classes/GCSpriteOriented.h"
#include "../core.h"

void SetupLuaClassGCSpriteOriented(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSpriteOriented>("CSpriteOriented")

        .endClass();
}