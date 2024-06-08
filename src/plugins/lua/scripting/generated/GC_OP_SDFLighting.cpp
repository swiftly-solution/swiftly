#include "../../../core/scripting/generated/classes/GC_OP_SDFLighting.h"
#include "../core.h"

void SetupLuaClassGC_OP_SDFLighting(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SDFLighting>("C_OP_SDFLighting")
        .addProperty("LightingDir", &GC_OP_SDFLighting::GetLightingDir, &GC_OP_SDFLighting::SetLightingDir)
        .addProperty("Tint_0", &GC_OP_SDFLighting::GetTint_0, &GC_OP_SDFLighting::SetTint_0)
        .addProperty("Tint_1", &GC_OP_SDFLighting::GetTint_1, &GC_OP_SDFLighting::SetTint_1)
        .endClass();
}