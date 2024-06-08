#include "../../../core/scripting/generated/classes/GCSSDSMsg_ViewRender.h"
#include "../core.h"

void SetupLuaClassGCSSDSMsg_ViewRender(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_ViewRender>("CSSDSMsg_ViewRender")
        .addProperty("ViewId", &GCSSDSMsg_ViewRender::GetViewId, &GCSSDSMsg_ViewRender::SetViewId)
        .addProperty("ViewName", &GCSSDSMsg_ViewRender::GetViewName, &GCSSDSMsg_ViewRender::SetViewName)
        .endClass();
}