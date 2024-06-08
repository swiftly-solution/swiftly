#include "../../../core/scripting/generated/classes/GC_INIT_InitFromCPSnapshot.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InitFromCPSnapshot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InitFromCPSnapshot>("C_INIT_InitFromCPSnapshot")
        .addProperty("ControlPointNumber", &GC_INIT_InitFromCPSnapshot::GetControlPointNumber, &GC_INIT_InitFromCPSnapshot::SetControlPointNumber)
        .addProperty("AttributeToRead", &GC_INIT_InitFromCPSnapshot::GetAttributeToRead, &GC_INIT_InitFromCPSnapshot::SetAttributeToRead)
        .addProperty("AttributeToWrite", &GC_INIT_InitFromCPSnapshot::GetAttributeToWrite, &GC_INIT_InitFromCPSnapshot::SetAttributeToWrite)
        .addProperty("LocalSpaceCP", &GC_INIT_InitFromCPSnapshot::GetLocalSpaceCP, &GC_INIT_InitFromCPSnapshot::SetLocalSpaceCP)
        .addProperty("Random", &GC_INIT_InitFromCPSnapshot::GetRandom, &GC_INIT_InitFromCPSnapshot::SetRandom)
        .addProperty("Reverse", &GC_INIT_InitFromCPSnapshot::GetReverse, &GC_INIT_InitFromCPSnapshot::SetReverse)
        .addProperty("SnapShotIncrement", &GC_INIT_InitFromCPSnapshot::GetSnapShotIncrement, &GC_INIT_InitFromCPSnapshot::SetSnapShotIncrement)
        .addProperty("ManualSnapshotIndex", &GC_INIT_InitFromCPSnapshot::GetManualSnapshotIndex, &GC_INIT_InitFromCPSnapshot::SetManualSnapshotIndex)
        .addProperty("RandomSeed", &GC_INIT_InitFromCPSnapshot::GetRandomSeed, &GC_INIT_InitFromCPSnapshot::SetRandomSeed)
        .addProperty("LocalSpaceAngles", &GC_INIT_InitFromCPSnapshot::GetLocalSpaceAngles, &GC_INIT_InitFromCPSnapshot::SetLocalSpaceAngles)
        .endClass();
}