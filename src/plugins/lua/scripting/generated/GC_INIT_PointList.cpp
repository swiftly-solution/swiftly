#include "../../../core/scripting/generated/classes/GC_INIT_PointList.h"
#include "../core.h"

void SetupLuaClassGC_INIT_PointList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_PointList>("C_INIT_PointList")
        .addProperty("FieldOutput", &GC_INIT_PointList::GetFieldOutput, &GC_INIT_PointList::SetFieldOutput)
        .addProperty("PointList", &GC_INIT_PointList::GetPointList, &GC_INIT_PointList::SetPointList)
        .addProperty("PlaceAlongPath", &GC_INIT_PointList::GetPlaceAlongPath, &GC_INIT_PointList::SetPlaceAlongPath)
        .addProperty("ClosedLoop", &GC_INIT_PointList::GetClosedLoop, &GC_INIT_PointList::SetClosedLoop)
        .addProperty("NumPointsAlongPath", &GC_INIT_PointList::GetNumPointsAlongPath, &GC_INIT_PointList::SetNumPointsAlongPath)
        .endClass();
}