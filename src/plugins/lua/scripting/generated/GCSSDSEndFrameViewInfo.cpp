#include "../../../core/scripting/generated/classes/GCSSDSEndFrameViewInfo.h"
#include "../core.h"

void SetupLuaClassGCSSDSEndFrameViewInfo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSEndFrameViewInfo>("CSSDSEndFrameViewInfo")
        .addProperty("ViewId", &GCSSDSEndFrameViewInfo::GetViewId, &GCSSDSEndFrameViewInfo::SetViewId)
        .addProperty("ViewName", &GCSSDSEndFrameViewInfo::GetViewName, &GCSSDSEndFrameViewInfo::SetViewName)
        .endClass();
}