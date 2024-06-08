#include "../../../core/scripting/generated/classes/GC_OP_PlayEndCapWhenFinished.h"
#include "../core.h"

void SetupLuaClassGC_OP_PlayEndCapWhenFinished(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_PlayEndCapWhenFinished>("C_OP_PlayEndCapWhenFinished")
        .addProperty("FireOnEmissionEnd", &GC_OP_PlayEndCapWhenFinished::GetFireOnEmissionEnd, &GC_OP_PlayEndCapWhenFinished::SetFireOnEmissionEnd)
        .addProperty("IncludeChildren", &GC_OP_PlayEndCapWhenFinished::GetIncludeChildren, &GC_OP_PlayEndCapWhenFinished::SetIncludeChildren)
        .endClass();
}