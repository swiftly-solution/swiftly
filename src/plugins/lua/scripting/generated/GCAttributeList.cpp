#include "../../../core/scripting/generated/classes/GCAttributeList.h"
#include "../core.h"

void SetupLuaClassGCAttributeList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAttributeList>("CAttributeList")
        .addProperty("Attributes", &GCAttributeList::GetAttributes, &GCAttributeList::SetAttributes)
        .addProperty("Manager", &GCAttributeList::GetManager, &GCAttributeList::SetManager)
        .endClass();
}