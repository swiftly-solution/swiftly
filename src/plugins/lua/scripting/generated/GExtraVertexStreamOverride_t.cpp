#include "../../../core/scripting/generated/classes/GExtraVertexStreamOverride_t.h"
#include "../core.h"

void SetupLuaClassGExtraVertexStreamOverride_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GExtraVertexStreamOverride_t>("ExtraVertexStreamOverride_t")
        .addProperty("SubSceneObject", &GExtraVertexStreamOverride_t::GetSubSceneObject, &GExtraVertexStreamOverride_t::SetSubSceneObject)
        .addProperty("DrawCallIndex", &GExtraVertexStreamOverride_t::GetDrawCallIndex, &GExtraVertexStreamOverride_t::SetDrawCallIndex)
        .addProperty("AdditionalMeshDrawPrimitiveFlags", &GExtraVertexStreamOverride_t::GetAdditionalMeshDrawPrimitiveFlags, &GExtraVertexStreamOverride_t::SetAdditionalMeshDrawPrimitiveFlags)
        .addProperty("ExtraBufferBinding", &GExtraVertexStreamOverride_t::GetExtraBufferBinding, &GExtraVertexStreamOverride_t::SetExtraBufferBinding)
        .endClass();
}