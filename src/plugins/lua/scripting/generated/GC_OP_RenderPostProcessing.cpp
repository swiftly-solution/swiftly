#include "../../../core/scripting/generated/classes/GC_OP_RenderPostProcessing.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderPostProcessing(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderPostProcessing>("C_OP_RenderPostProcessing")
        .addProperty("PostProcessStrength", &GC_OP_RenderPostProcessing::GetPostProcessStrength, &GC_OP_RenderPostProcessing::SetPostProcessStrength)
        .addProperty("Priority", &GC_OP_RenderPostProcessing::GetPriority, &GC_OP_RenderPostProcessing::SetPriority)
        .endClass();
}