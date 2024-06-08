#include "../../../core/scripting/generated/classes/GCSoundAreaEntityOrientedBox.h"
#include "../core.h"

void SetupLuaClassGCSoundAreaEntityOrientedBox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundAreaEntityOrientedBox>("CSoundAreaEntityOrientedBox")
        .addProperty("Min", &GCSoundAreaEntityOrientedBox::GetMin, &GCSoundAreaEntityOrientedBox::SetMin)
        .addProperty("Max", &GCSoundAreaEntityOrientedBox::GetMax, &GCSoundAreaEntityOrientedBox::SetMax)
        .endClass();
}