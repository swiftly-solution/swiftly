#include "../../../core/scripting/generated/classes/GCFlexOp.h"
#include "../core.h"

void SetupLuaClassGCFlexOp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlexOp>("CFlexOp")
        .addProperty("OpCode", &GCFlexOp::GetOpCode, &GCFlexOp::SetOpCode)
        .addProperty("Data", &GCFlexOp::GetData, &GCFlexOp::SetData)
        .endClass();
}