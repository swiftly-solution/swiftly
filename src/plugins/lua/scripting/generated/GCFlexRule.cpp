#include "../../../core/scripting/generated/classes/GCFlexRule.h"
#include "../core.h"

void SetupLuaClassGCFlexRule(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlexRule>("CFlexRule")
        .addProperty("Flex", &GCFlexRule::GetFlex, &GCFlexRule::SetFlex)
        .addProperty("FlexOps", &GCFlexRule::GetFlexOps, &GCFlexRule::SetFlexOps)
        .endClass();
}