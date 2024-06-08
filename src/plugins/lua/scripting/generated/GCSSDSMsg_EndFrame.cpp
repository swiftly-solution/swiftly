#include "../../../core/scripting/generated/classes/GCSSDSMsg_EndFrame.h"
#include "../core.h"

void SetupLuaClassGCSSDSMsg_EndFrame(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_EndFrame>("CSSDSMsg_EndFrame")
        .addProperty("Views", &GCSSDSMsg_EndFrame::GetViews, &GCSSDSMsg_EndFrame::SetViews)
        .endClass();
}