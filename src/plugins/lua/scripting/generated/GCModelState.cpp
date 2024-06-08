#include "../../../core/scripting/generated/classes/GCModelState.h"
#include "../core.h"

void SetupLuaClassGCModelState(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelState>("CModelState")
        .addProperty("ModelName", &GCModelState::GetModelName, &GCModelState::SetModelName)
        .addProperty("ClientClothCreationSuppressed", &GCModelState::GetClientClothCreationSuppressed, &GCModelState::SetClientClothCreationSuppressed)
        .addProperty("MeshGroupMask", &GCModelState::GetMeshGroupMask, &GCModelState::SetMeshGroupMask)
        .addProperty("IdealMotionType", &GCModelState::GetIdealMotionType, &GCModelState::SetIdealMotionType)
        .addProperty("ForceLOD", &GCModelState::GetForceLOD, &GCModelState::SetForceLOD)
        .addProperty("ClothUpdateFlags", &GCModelState::GetClothUpdateFlags, &GCModelState::SetClothUpdateFlags)
        .endClass();
}