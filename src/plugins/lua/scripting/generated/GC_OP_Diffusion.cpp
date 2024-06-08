#include "../../../core/scripting/generated/classes/GC_OP_Diffusion.h"
#include "../core.h"

void SetupLuaClassGC_OP_Diffusion(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_Diffusion>("C_OP_Diffusion")
        .addProperty("RadiusScale", &GC_OP_Diffusion::GetRadiusScale, &GC_OP_Diffusion::SetRadiusScale)
        .addProperty("FieldOutput", &GC_OP_Diffusion::GetFieldOutput, &GC_OP_Diffusion::SetFieldOutput)
        .addProperty("VoxelGridResolution", &GC_OP_Diffusion::GetVoxelGridResolution, &GC_OP_Diffusion::SetVoxelGridResolution)
        .endClass();
}