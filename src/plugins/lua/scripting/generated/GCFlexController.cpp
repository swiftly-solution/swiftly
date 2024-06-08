#include "../../../core/scripting/generated/classes/GCFlexController.h"
#include "../core.h"

void SetupLuaClassGCFlexController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlexController>("CFlexController")
        .addProperty("Name", &GCFlexController::GetName, &GCFlexController::SetName)
        .addProperty("Type", &GCFlexController::GetType, &GCFlexController::SetType)
        .addProperty("Min", &GCFlexController::GetMin, &GCFlexController::SetMin)
        .addProperty("Max", &GCFlexController::GetMax, &GCFlexController::SetMax)
        .endClass();
}