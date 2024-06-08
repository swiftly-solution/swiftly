#include "../../../core/scripting/generated/classes/GC_CommandContext.h"
#include "../core.h"

void SetupLuaClassGC_CommandContext(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_CommandContext>("C_CommandContext")
        .addProperty("Needsprocessing", &GC_CommandContext::GetNeedsprocessing, &GC_CommandContext::SetNeedsprocessing)
        .addProperty("Command_number", &GC_CommandContext::GetCommand_number, &GC_CommandContext::SetCommand_number)
        .endClass();
}