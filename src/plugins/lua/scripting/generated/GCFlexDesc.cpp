#include "../../../core/scripting/generated/classes/GCFlexDesc.h"
#include "../core.h"

void SetupLuaClassGCFlexDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlexDesc>("CFlexDesc")
        .addProperty("Facs", &GCFlexDesc::GetFacs, &GCFlexDesc::SetFacs)
        .endClass();
}