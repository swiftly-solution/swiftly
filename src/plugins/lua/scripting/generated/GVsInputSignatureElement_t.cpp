#include "../../../core/scripting/generated/classes/GVsInputSignatureElement_t.h"
#include "../core.h"

void SetupLuaClassGVsInputSignatureElement_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVsInputSignatureElement_t>("VsInputSignatureElement_t")
        .addProperty("Name", &GVsInputSignatureElement_t::GetName, &GVsInputSignatureElement_t::SetName)
        .addProperty("Semantic", &GVsInputSignatureElement_t::GetSemantic, &GVsInputSignatureElement_t::SetSemantic)
        .addProperty("D3DSemanticName", &GVsInputSignatureElement_t::GetD3DSemanticName, &GVsInputSignatureElement_t::SetD3DSemanticName)
        .addProperty("D3DSemanticIndex", &GVsInputSignatureElement_t::GetD3DSemanticIndex, &GVsInputSignatureElement_t::SetD3DSemanticIndex)
        .endClass();
}