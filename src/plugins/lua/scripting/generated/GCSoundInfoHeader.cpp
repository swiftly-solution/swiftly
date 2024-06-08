#include "../../../core/scripting/generated/classes/GCSoundInfoHeader.h"
#include "../core.h"

void SetupLuaClassGCSoundInfoHeader(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundInfoHeader>("CSoundInfoHeader")

        .endClass();
}