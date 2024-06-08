#include "../../../core/scripting/generated/classes/GVsInputSignature_t.h"
#include "../core.h"

void SetupLuaClassGVsInputSignature_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVsInputSignature_t>("VsInputSignature_t")
        .addProperty("Elems", &GVsInputSignature_t::GetElems, &GVsInputSignature_t::SetElems)
        .endClass();
}