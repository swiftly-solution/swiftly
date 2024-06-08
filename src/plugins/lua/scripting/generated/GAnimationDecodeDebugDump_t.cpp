#include "../../../core/scripting/generated/classes/GAnimationDecodeDebugDump_t.h"
#include "../core.h"

void SetupLuaClassGAnimationDecodeDebugDump_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimationDecodeDebugDump_t>("AnimationDecodeDebugDump_t")
        .addProperty("ProcessingType", &GAnimationDecodeDebugDump_t::GetProcessingType, &GAnimationDecodeDebugDump_t::SetProcessingType)
        .addProperty("Elems", &GAnimationDecodeDebugDump_t::GetElems, &GAnimationDecodeDebugDump_t::SetElems)
        .endClass();
}