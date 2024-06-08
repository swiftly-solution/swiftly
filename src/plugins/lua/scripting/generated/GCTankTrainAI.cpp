#include "../../../core/scripting/generated/classes/GCTankTrainAI.h"
#include "../core.h"

void SetupLuaClassGCTankTrainAI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTankTrainAI>("CTankTrainAI")
        .addProperty("Train", &GCTankTrainAI::GetTrain, &GCTankTrainAI::SetTrain)
        .addProperty("TargetEntity", &GCTankTrainAI::GetTargetEntity, &GCTankTrainAI::SetTargetEntity)
        .addProperty("SoundPlaying", &GCTankTrainAI::GetSoundPlaying, &GCTankTrainAI::SetSoundPlaying)
        .addProperty("StartSoundName", &GCTankTrainAI::GetStartSoundName, &GCTankTrainAI::SetStartSoundName)
        .addProperty("EngineSoundName", &GCTankTrainAI::GetEngineSoundName, &GCTankTrainAI::SetEngineSoundName)
        .addProperty("MovementSoundName", &GCTankTrainAI::GetMovementSoundName, &GCTankTrainAI::SetMovementSoundName)
        .addProperty("TargetEntityName", &GCTankTrainAI::GetTargetEntityName, &GCTankTrainAI::SetTargetEntityName)
        .endClass();
}