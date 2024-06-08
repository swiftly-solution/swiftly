#include "../../../core/scripting/generated/classes/GC_INIT_InitFromParentKilled.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InitFromParentKilled(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InitFromParentKilled>("C_INIT_InitFromParentKilled")
        .addProperty("AttributeToCopy", &GC_INIT_InitFromParentKilled::GetAttributeToCopy, &GC_INIT_InitFromParentKilled::SetAttributeToCopy)
        .addProperty("EventType", &GC_INIT_InitFromParentKilled::GetEventType, &GC_INIT_InitFromParentKilled::SetEventType)
        .endClass();
}