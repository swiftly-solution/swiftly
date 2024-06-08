#include "../../../core/scripting/generated/classes/GCNavLinkAreaEntity.h"
#include "../core.h"

void SetupLuaClassGCNavLinkAreaEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavLinkAreaEntity>("CNavLinkAreaEntity")
        .addProperty("Width", &GCNavLinkAreaEntity::GetWidth, &GCNavLinkAreaEntity::SetWidth)
        .addProperty("LocatorOffset", &GCNavLinkAreaEntity::GetLocatorOffset, &GCNavLinkAreaEntity::SetLocatorOffset)
        .addProperty("LocatorAnglesOffset", &GCNavLinkAreaEntity::GetLocatorAnglesOffset, &GCNavLinkAreaEntity::SetLocatorAnglesOffset)
        .addProperty("StrMovementForward", &GCNavLinkAreaEntity::GetStrMovementForward, &GCNavLinkAreaEntity::SetStrMovementForward)
        .addProperty("StrMovementReverse", &GCNavLinkAreaEntity::GetStrMovementReverse, &GCNavLinkAreaEntity::SetStrMovementReverse)
        .addProperty("NavLinkIdForward", &GCNavLinkAreaEntity::GetNavLinkIdForward, &GCNavLinkAreaEntity::SetNavLinkIdForward)
        .addProperty("NavLinkIdReverse", &GCNavLinkAreaEntity::GetNavLinkIdReverse, &GCNavLinkAreaEntity::SetNavLinkIdReverse)
        .addProperty("Enabled", &GCNavLinkAreaEntity::GetEnabled, &GCNavLinkAreaEntity::SetEnabled)
        .addProperty("StrFilterName", &GCNavLinkAreaEntity::GetStrFilterName, &GCNavLinkAreaEntity::SetStrFilterName)
        .addProperty("Filter", &GCNavLinkAreaEntity::GetFilter, &GCNavLinkAreaEntity::SetFilter)
        .addProperty("OnNavLinkStart", &GCNavLinkAreaEntity::GetOnNavLinkStart, &GCNavLinkAreaEntity::SetOnNavLinkStart)
        .addProperty("OnNavLinkFinish", &GCNavLinkAreaEntity::GetOnNavLinkFinish, &GCNavLinkAreaEntity::SetOnNavLinkFinish)
        .addProperty("IsTerminus", &GCNavLinkAreaEntity::GetIsTerminus, &GCNavLinkAreaEntity::SetIsTerminus)
        .endClass();
}