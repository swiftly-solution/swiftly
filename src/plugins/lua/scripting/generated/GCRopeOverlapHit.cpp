#include "../../../core/scripting/generated/classes/GCRopeOverlapHit.h"
#include "../core.h"

void SetupLuaClassGCRopeOverlapHit(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRopeOverlapHit>("CRopeOverlapHit")
        .addProperty("Entity", &GCRopeOverlapHit::GetEntity, &GCRopeOverlapHit::SetEntity)
        .addProperty("OverlappingLinks", &GCRopeOverlapHit::GetOverlappingLinks, &GCRopeOverlapHit::SetOverlappingLinks)
        .endClass();
}