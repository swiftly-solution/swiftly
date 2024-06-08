#include "../../../core/scripting/generated/classes/GCommandToolCommand_t.h"
#include "../core.h"

void SetupLuaClassGCommandToolCommand_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCommandToolCommand_t>("CommandToolCommand_t")
        .addProperty("Enabled", &GCommandToolCommand_t::GetEnabled, &GCommandToolCommand_t::SetEnabled)
        .addProperty("Opened", &GCommandToolCommand_t::GetOpened, &GCommandToolCommand_t::SetOpened)
        .addProperty("InternalId", &GCommandToolCommand_t::GetInternalId, &GCommandToolCommand_t::SetInternalId)
        .addProperty("ShortName", &GCommandToolCommand_t::GetShortName, &GCommandToolCommand_t::SetShortName)
        .addProperty("ExecMode", &GCommandToolCommand_t::GetExecMode, &GCommandToolCommand_t::SetExecMode)
        .addProperty("SpawnGroup", &GCommandToolCommand_t::GetSpawnGroup, &GCommandToolCommand_t::SetSpawnGroup)
        .addProperty("PeriodicExecDelay", &GCommandToolCommand_t::GetPeriodicExecDelay, &GCommandToolCommand_t::SetPeriodicExecDelay)
        .addProperty("SpecType", &GCommandToolCommand_t::GetSpecType, &GCommandToolCommand_t::SetSpecType)
        .addProperty("EntitySpec", &GCommandToolCommand_t::GetEntitySpec, &GCommandToolCommand_t::SetEntitySpec)
        .addProperty("Commands", &GCommandToolCommand_t::GetCommands, &GCommandToolCommand_t::SetCommands)
        .addProperty("SetDebugBits", &GCommandToolCommand_t::GetSetDebugBits, &GCommandToolCommand_t::SetSetDebugBits)
        .addProperty("ClearDebugBits", &GCommandToolCommand_t::GetClearDebugBits, &GCommandToolCommand_t::SetClearDebugBits)
        .endClass();
}