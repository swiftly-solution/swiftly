#include "../../../core/scripting/generated/classes/GAnimationDecodeDebugDumpElement_t.h"
#include "../core.h"

void SetupLuaClassGAnimationDecodeDebugDumpElement_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimationDecodeDebugDumpElement_t>("AnimationDecodeDebugDumpElement_t")
        .addProperty("EntityIndex", &GAnimationDecodeDebugDumpElement_t::GetEntityIndex, &GAnimationDecodeDebugDumpElement_t::SetEntityIndex)
        .addProperty("ModelName", &GAnimationDecodeDebugDumpElement_t::GetModelName, &GAnimationDecodeDebugDumpElement_t::SetModelName)
        .addProperty("PoseParams", &GAnimationDecodeDebugDumpElement_t::GetPoseParams, &GAnimationDecodeDebugDumpElement_t::SetPoseParams)
        .addProperty("DecodeOps", &GAnimationDecodeDebugDumpElement_t::GetDecodeOps, &GAnimationDecodeDebugDumpElement_t::SetDecodeOps)
        .addProperty("InternalOps", &GAnimationDecodeDebugDumpElement_t::GetInternalOps, &GAnimationDecodeDebugDumpElement_t::SetInternalOps)
        .addProperty("DecodedAnims", &GAnimationDecodeDebugDumpElement_t::GetDecodedAnims, &GAnimationDecodeDebugDumpElement_t::SetDecodedAnims)
        .endClass();
}