#include "../../../core/scripting/generated/classes/GC_Chicken_GraphController.h"
#include "../core.h"

void SetupLuaClassGC_Chicken_GraphController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_Chicken_GraphController>("C_Chicken_GraphController")
        .addProperty("SquatProbability", &GC_Chicken_GraphController::GetSquatProbability, &GC_Chicken_GraphController::SetSquatProbability)
        .endClass();
}