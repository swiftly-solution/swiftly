#include "../../../core/scripting/generated/classes/GCMorphConstraint.h"
#include "../core.h"

void SetupLuaClassGCMorphConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMorphConstraint>("CMorphConstraint")
        .addProperty("TargetMorph", &GCMorphConstraint::GetTargetMorph, &GCMorphConstraint::SetTargetMorph)
        .addProperty("SlaveChannel", &GCMorphConstraint::GetSlaveChannel, &GCMorphConstraint::SetSlaveChannel)
        .addProperty("Min", &GCMorphConstraint::GetMin, &GCMorphConstraint::SetMin)
        .addProperty("Max", &GCMorphConstraint::GetMax, &GCMorphConstraint::SetMax)
        .endClass();
}