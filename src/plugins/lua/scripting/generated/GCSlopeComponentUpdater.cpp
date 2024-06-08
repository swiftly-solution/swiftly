#include "../../../core/scripting/generated/classes/GCSlopeComponentUpdater.h"
#include "../core.h"

void SetupLuaClassGCSlopeComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSlopeComponentUpdater>("CSlopeComponentUpdater")
        .addProperty("TraceDistance", &GCSlopeComponentUpdater::GetTraceDistance, &GCSlopeComponentUpdater::SetTraceDistance)
        .addProperty("SlopeAngle", &GCSlopeComponentUpdater::GetSlopeAngle, &GCSlopeComponentUpdater::SetSlopeAngle)
        .addProperty("SlopeAngleFront", &GCSlopeComponentUpdater::GetSlopeAngleFront, &GCSlopeComponentUpdater::SetSlopeAngleFront)
        .addProperty("SlopeAngleSide", &GCSlopeComponentUpdater::GetSlopeAngleSide, &GCSlopeComponentUpdater::SetSlopeAngleSide)
        .addProperty("SlopeHeading", &GCSlopeComponentUpdater::GetSlopeHeading, &GCSlopeComponentUpdater::SetSlopeHeading)
        .addProperty("SlopeNormal", &GCSlopeComponentUpdater::GetSlopeNormal, &GCSlopeComponentUpdater::SetSlopeNormal)
        .addProperty("SlopeNormal_WorldSpace", &GCSlopeComponentUpdater::GetSlopeNormal_WorldSpace, &GCSlopeComponentUpdater::SetSlopeNormal_WorldSpace)
        .endClass();
}