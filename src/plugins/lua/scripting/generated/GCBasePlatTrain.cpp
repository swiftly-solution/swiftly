#include "../../../core/scripting/generated/classes/GCBasePlatTrain.h"
#include "../core.h"

void SetupLuaClassGCBasePlatTrain(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlatTrain>("CBasePlatTrain")
        .addProperty("NoiseMoving", &GCBasePlatTrain::GetNoiseMoving, &GCBasePlatTrain::SetNoiseMoving)
        .addProperty("NoiseArrived", &GCBasePlatTrain::GetNoiseArrived, &GCBasePlatTrain::SetNoiseArrived)
        .addProperty("Volume", &GCBasePlatTrain::GetVolume, &GCBasePlatTrain::SetVolume)
        .addProperty("TWidth", &GCBasePlatTrain::GetTWidth, &GCBasePlatTrain::SetTWidth)
        .addProperty("TLength", &GCBasePlatTrain::GetTLength, &GCBasePlatTrain::SetTLength)
        .endClass();
}