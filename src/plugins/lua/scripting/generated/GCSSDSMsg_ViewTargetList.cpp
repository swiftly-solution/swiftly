#include "../../../core/scripting/generated/classes/GCSSDSMsg_ViewTargetList.h"
#include "../core.h"

void SetupLuaClassGCSSDSMsg_ViewTargetList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_ViewTargetList>("CSSDSMsg_ViewTargetList")
        .addProperty("ViewId", &GCSSDSMsg_ViewTargetList::GetViewId, &GCSSDSMsg_ViewTargetList::SetViewId)
        .addProperty("ViewName", &GCSSDSMsg_ViewTargetList::GetViewName, &GCSSDSMsg_ViewTargetList::SetViewName)
        .addProperty("Targets", &GCSSDSMsg_ViewTargetList::GetTargets, &GCSSDSMsg_ViewTargetList::SetTargets)
        .endClass();
}