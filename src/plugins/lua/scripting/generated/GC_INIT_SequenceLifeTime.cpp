#include "../../../core/scripting/generated/classes/GC_INIT_SequenceLifeTime.h"
#include "../core.h"

void SetupLuaClassGC_INIT_SequenceLifeTime(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_SequenceLifeTime>("C_INIT_SequenceLifeTime")
        .addProperty("Framerate", &GC_INIT_SequenceLifeTime::GetFramerate, &GC_INIT_SequenceLifeTime::SetFramerate)
        .endClass();
}