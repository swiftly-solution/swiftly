#include "../../../core/scripting/generated/classes/GC_OP_RenderMaterialProxy.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderMaterialProxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderMaterialProxy>("C_OP_RenderMaterialProxy")
        .addProperty("MaterialControlPoint", &GC_OP_RenderMaterialProxy::GetMaterialControlPoint, &GC_OP_RenderMaterialProxy::SetMaterialControlPoint)
        .addProperty("ProxyType", &GC_OP_RenderMaterialProxy::GetProxyType, &GC_OP_RenderMaterialProxy::SetProxyType)
        .addProperty("MaterialVars", &GC_OP_RenderMaterialProxy::GetMaterialVars, &GC_OP_RenderMaterialProxy::SetMaterialVars)
        .addProperty("MaterialOverrideEnabled", &GC_OP_RenderMaterialProxy::GetMaterialOverrideEnabled, &GC_OP_RenderMaterialProxy::SetMaterialOverrideEnabled)
        .addProperty("Alpha", &GC_OP_RenderMaterialProxy::GetAlpha, &GC_OP_RenderMaterialProxy::SetAlpha)
        .addProperty("ColorBlendType", &GC_OP_RenderMaterialProxy::GetColorBlendType, &GC_OP_RenderMaterialProxy::SetColorBlendType)
        .endClass();
}