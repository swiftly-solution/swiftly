#include "../../../core/scripting/generated/classes/GCSeqCmdLayer.h"
#include "../core.h"

void SetupLuaClassGCSeqCmdLayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqCmdLayer>("CSeqCmdLayer")
        .addProperty("Cmd", &GCSeqCmdLayer::GetCmd, &GCSeqCmdLayer::SetCmd)
        .addProperty("LocalReference", &GCSeqCmdLayer::GetLocalReference, &GCSeqCmdLayer::SetLocalReference)
        .addProperty("LocalBonemask", &GCSeqCmdLayer::GetLocalBonemask, &GCSeqCmdLayer::SetLocalBonemask)
        .addProperty("DstResult", &GCSeqCmdLayer::GetDstResult, &GCSeqCmdLayer::SetDstResult)
        .addProperty("SrcResult", &GCSeqCmdLayer::GetSrcResult, &GCSeqCmdLayer::SetSrcResult)
        .addProperty("Spline", &GCSeqCmdLayer::GetSpline, &GCSeqCmdLayer::SetSpline)
        .addProperty("Var1", &GCSeqCmdLayer::GetVar1, &GCSeqCmdLayer::SetVar1)
        .addProperty("Var2", &GCSeqCmdLayer::GetVar2, &GCSeqCmdLayer::SetVar2)
        .addProperty("LineNumber", &GCSeqCmdLayer::GetLineNumber, &GCSeqCmdLayer::SetLineNumber)
        .endClass();
}