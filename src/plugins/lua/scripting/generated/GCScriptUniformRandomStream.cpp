#include "../../../core/scripting/generated/classes/GCScriptUniformRandomStream.h"
#include "../core.h"

void SetupLuaClassGCScriptUniformRandomStream(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptUniformRandomStream>("CScriptUniformRandomStream")
        .addProperty("InitialSeed", &GCScriptUniformRandomStream::GetInitialSeed, &GCScriptUniformRandomStream::SetInitialSeed)
        .endClass();
}