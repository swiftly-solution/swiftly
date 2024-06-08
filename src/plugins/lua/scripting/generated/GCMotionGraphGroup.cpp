#include "../../../core/scripting/generated/classes/GCMotionGraphGroup.h"
#include "../core.h"

void SetupLuaClassGCMotionGraphGroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionGraphGroup>("CMotionGraphGroup")
        .addProperty("SearchDB", &GCMotionGraphGroup::GetSearchDB, &GCMotionGraphGroup::SetSearchDB)
        .addProperty("MotionGraphConfigs", &GCMotionGraphGroup::GetMotionGraphConfigs, &GCMotionGraphGroup::SetMotionGraphConfigs)
        .addProperty("SampleToConfig", &GCMotionGraphGroup::GetSampleToConfig, &GCMotionGraphGroup::SetSampleToConfig)
        .addProperty("IsActiveScript", &GCMotionGraphGroup::GetIsActiveScript, &GCMotionGraphGroup::SetIsActiveScript)
        .endClass();
}