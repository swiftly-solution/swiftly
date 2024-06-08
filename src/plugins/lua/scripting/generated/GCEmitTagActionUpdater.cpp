#include "../../../core/scripting/generated/classes/GCEmitTagActionUpdater.h"
#include "../core.h"

void SetupLuaClassGCEmitTagActionUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEmitTagActionUpdater>("CEmitTagActionUpdater")
        .addProperty("TagIndex", &GCEmitTagActionUpdater::GetTagIndex, &GCEmitTagActionUpdater::SetTagIndex)
        .addProperty("IsZeroDuration", &GCEmitTagActionUpdater::GetIsZeroDuration, &GCEmitTagActionUpdater::SetIsZeroDuration)
        .endClass();
}