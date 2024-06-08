#include "../../../core/scripting/generated/classes/GCAnimActivity.h"
#include "../core.h"

void SetupLuaClassGCAnimActivity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimActivity>("CAnimActivity")
        .addProperty("Name", &GCAnimActivity::GetName, &GCAnimActivity::SetName)
        .addProperty("Activity", &GCAnimActivity::GetActivity, &GCAnimActivity::SetActivity)
        .addProperty("Flags", &GCAnimActivity::GetFlags, &GCAnimActivity::SetFlags)
        .addProperty("Weight", &GCAnimActivity::GetWeight, &GCAnimActivity::SetWeight)
        .endClass();
}