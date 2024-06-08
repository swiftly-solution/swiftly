#include "../../../core/scripting/generated/classes/GCEntityComponentHelper.h"
#include "../core.h"

void SetupLuaClassGCEntityComponentHelper(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityComponentHelper>("CEntityComponentHelper")
        .addProperty("Flags", &GCEntityComponentHelper::GetFlags, &GCEntityComponentHelper::SetFlags)
        .addProperty("Info", &GCEntityComponentHelper::GetInfo, &GCEntityComponentHelper::SetInfo)
        .addProperty("Priority", &GCEntityComponentHelper::GetPriority, &GCEntityComponentHelper::SetPriority)
        .addProperty("Next", &GCEntityComponentHelper::GetNext, &GCEntityComponentHelper::SetNext)
        .endClass();
}