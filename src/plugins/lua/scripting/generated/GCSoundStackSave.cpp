#include "../../../core/scripting/generated/classes/GCSoundStackSave.h"
#include "../core.h"

void SetupLuaClassGCSoundStackSave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundStackSave>("CSoundStackSave")
        .addProperty("StackName", &GCSoundStackSave::GetStackName, &GCSoundStackSave::SetStackName)
        .endClass();
}