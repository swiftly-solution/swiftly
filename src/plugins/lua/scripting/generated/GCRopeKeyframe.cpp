#include "../../../core/scripting/generated/classes/GCRopeKeyframe.h"
#include "../core.h"

void SetupLuaClassGCRopeKeyframe(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRopeKeyframe>("CRopeKeyframe")
        .addProperty("RopeFlags", &GCRopeKeyframe::GetRopeFlags, &GCRopeKeyframe::SetRopeFlags)
        .addProperty("NextLinkName", &GCRopeKeyframe::GetNextLinkName, &GCRopeKeyframe::SetNextLinkName)
        .addProperty("Slack", &GCRopeKeyframe::GetSlack, &GCRopeKeyframe::SetSlack)
        .addProperty("Width", &GCRopeKeyframe::GetWidth, &GCRopeKeyframe::SetWidth)
        .addProperty("TextureScale", &GCRopeKeyframe::GetTextureScale, &GCRopeKeyframe::SetTextureScale)
        .addProperty("Segments", &GCRopeKeyframe::GetSegments, &GCRopeKeyframe::SetSegments)
        .addProperty("ConstrainBetweenEndpoints", &GCRopeKeyframe::GetConstrainBetweenEndpoints, &GCRopeKeyframe::SetConstrainBetweenEndpoints)
        .addProperty("StrRopeMaterialModel", &GCRopeKeyframe::GetStrRopeMaterialModel, &GCRopeKeyframe::SetStrRopeMaterialModel)
        .addProperty("Subdiv", &GCRopeKeyframe::GetSubdiv, &GCRopeKeyframe::SetSubdiv)
        .addProperty("ChangeCount", &GCRopeKeyframe::GetChangeCount, &GCRopeKeyframe::SetChangeCount)
        .addProperty("RopeLength", &GCRopeKeyframe::GetRopeLength, &GCRopeKeyframe::SetRopeLength)
        .addProperty("LockedPoints", &GCRopeKeyframe::GetLockedPoints, &GCRopeKeyframe::SetLockedPoints)
        .addProperty("CreatedFromMapFile", &GCRopeKeyframe::GetCreatedFromMapFile, &GCRopeKeyframe::SetCreatedFromMapFile)
        .addProperty("ScrollSpeed", &GCRopeKeyframe::GetScrollSpeed, &GCRopeKeyframe::SetScrollSpeed)
        .addProperty("StartPointValid", &GCRopeKeyframe::GetStartPointValid, &GCRopeKeyframe::SetStartPointValid)
        .addProperty("EndPointValid", &GCRopeKeyframe::GetEndPointValid, &GCRopeKeyframe::SetEndPointValid)
        .addProperty("StartPoint", &GCRopeKeyframe::GetStartPoint, &GCRopeKeyframe::SetStartPoint)
        .addProperty("EndPoint", &GCRopeKeyframe::GetEndPoint, &GCRopeKeyframe::SetEndPoint)
        .endClass();
}