#include "../../../core/scripting/generated/classes/GCMotionNodeBlend1D.h"
#include "../core.h"

void SetupLuaClassGCMotionNodeBlend1D(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionNodeBlend1D>("CMotionNodeBlend1D")
        .addProperty("BlendItems", &GCMotionNodeBlend1D::GetBlendItems, &GCMotionNodeBlend1D::SetBlendItems)
        .addProperty("ParamIndex", &GCMotionNodeBlend1D::GetParamIndex, &GCMotionNodeBlend1D::SetParamIndex)
        .endClass();
}