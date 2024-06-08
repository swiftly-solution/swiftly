#include "../../../core/scripting/generated/classes/GC_OP_EnableChildrenFromParentParticleCount.h"
#include "../core.h"

void SetupLuaClassGC_OP_EnableChildrenFromParentParticleCount(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_EnableChildrenFromParentParticleCount>("C_OP_EnableChildrenFromParentParticleCount")
        .addProperty("ChildGroupID", &GC_OP_EnableChildrenFromParentParticleCount::GetChildGroupID, &GC_OP_EnableChildrenFromParentParticleCount::SetChildGroupID)
        .addProperty("FirstChild", &GC_OP_EnableChildrenFromParentParticleCount::GetFirstChild, &GC_OP_EnableChildrenFromParentParticleCount::SetFirstChild)
        .addProperty("NumChildrenToEnable", &GC_OP_EnableChildrenFromParentParticleCount::GetNumChildrenToEnable, &GC_OP_EnableChildrenFromParentParticleCount::SetNumChildrenToEnable)
        .addProperty("DisableChildren", &GC_OP_EnableChildrenFromParentParticleCount::GetDisableChildren, &GC_OP_EnableChildrenFromParentParticleCount::SetDisableChildren)
        .addProperty("PlayEndcapOnStop", &GC_OP_EnableChildrenFromParentParticleCount::GetPlayEndcapOnStop, &GC_OP_EnableChildrenFromParentParticleCount::SetPlayEndcapOnStop)
        .addProperty("DestroyImmediately", &GC_OP_EnableChildrenFromParentParticleCount::GetDestroyImmediately, &GC_OP_EnableChildrenFromParentParticleCount::SetDestroyImmediately)
        .endClass();
}