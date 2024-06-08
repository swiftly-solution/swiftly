#include "../../../core/scripting/generated/classes/GC_OP_RenderFlattenGrass.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderFlattenGrass(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderFlattenGrass>("C_OP_RenderFlattenGrass")
        .addProperty("FlattenStrength", &GC_OP_RenderFlattenGrass::GetFlattenStrength, &GC_OP_RenderFlattenGrass::SetFlattenStrength)
        .addProperty("StrengthFieldOverride", &GC_OP_RenderFlattenGrass::GetStrengthFieldOverride, &GC_OP_RenderFlattenGrass::SetStrengthFieldOverride)
        .addProperty("RadiusScale", &GC_OP_RenderFlattenGrass::GetRadiusScale, &GC_OP_RenderFlattenGrass::SetRadiusScale)
        .endClass();
}