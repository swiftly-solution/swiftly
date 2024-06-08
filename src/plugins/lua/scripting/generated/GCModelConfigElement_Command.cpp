#include "../../../core/scripting/generated/classes/GCModelConfigElement_Command.h"
#include "../core.h"

void SetupLuaClassGCModelConfigElement_Command(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_Command>("CModelConfigElement_Command")
        .addProperty("Command", &GCModelConfigElement_Command::GetCommand, &GCModelConfigElement_Command::SetCommand)
        .endClass();
}