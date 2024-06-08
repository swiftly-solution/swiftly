#include "../../../core/scripting/generated/classes/GCRenderBufferBinding.h"
#include "../core.h"

void SetupLuaClassGCRenderBufferBinding(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRenderBufferBinding>("CRenderBufferBinding")
        .addProperty("Buffer", &GCRenderBufferBinding::GetBuffer, &GCRenderBufferBinding::SetBuffer)
        .addProperty("BindOffsetBytes", &GCRenderBufferBinding::GetBindOffsetBytes, &GCRenderBufferBinding::SetBindOffsetBytes)
        .endClass();
}