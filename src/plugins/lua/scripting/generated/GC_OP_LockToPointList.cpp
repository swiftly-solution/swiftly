#include "../../../core/scripting/generated/classes/GC_OP_LockToPointList.h"
#include "../core.h"

void SetupLuaClassGC_OP_LockToPointList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LockToPointList>("C_OP_LockToPointList")
        .addProperty("FieldOutput", &GC_OP_LockToPointList::GetFieldOutput, &GC_OP_LockToPointList::SetFieldOutput)
        .addProperty("PointList", &GC_OP_LockToPointList::GetPointList, &GC_OP_LockToPointList::SetPointList)
        .addProperty("PlaceAlongPath", &GC_OP_LockToPointList::GetPlaceAlongPath, &GC_OP_LockToPointList::SetPlaceAlongPath)
        .addProperty("ClosedLoop", &GC_OP_LockToPointList::GetClosedLoop, &GC_OP_LockToPointList::SetClosedLoop)
        .addProperty("NumPointsAlongPath", &GC_OP_LockToPointList::GetNumPointsAlongPath, &GC_OP_LockToPointList::SetNumPointsAlongPath)
        .endClass();
}