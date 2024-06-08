#include "../../../core/scripting/generated/classes/GCFuncBrush.h"
#include "../core.h"

void SetupLuaClassGCFuncBrush(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncBrush>("CFuncBrush")
        .addProperty("Solidity", &GCFuncBrush::GetSolidity, &GCFuncBrush::SetSolidity)
        .addProperty("Disabled", &GCFuncBrush::GetDisabled, &GCFuncBrush::SetDisabled)
        .addProperty("SolidBsp", &GCFuncBrush::GetSolidBsp, &GCFuncBrush::SetSolidBsp)
        .addProperty("ExcludedClass", &GCFuncBrush::GetExcludedClass, &GCFuncBrush::SetExcludedClass)
        .addProperty("InvertExclusion", &GCFuncBrush::GetInvertExclusion, &GCFuncBrush::SetInvertExclusion)
        .addProperty("ScriptedMovement", &GCFuncBrush::GetScriptedMovement, &GCFuncBrush::SetScriptedMovement)
        .endClass();
}