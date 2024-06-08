#include "../../../core/scripting/generated/classes/GRnShapeDesc_t.h"
#include "../core.h"

void SetupLuaClassGRnShapeDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnShapeDesc_t>("RnShapeDesc_t")
        .addProperty("CollisionAttributeIndex", &GRnShapeDesc_t::GetCollisionAttributeIndex, &GRnShapeDesc_t::SetCollisionAttributeIndex)
        .addProperty("SurfacePropertyIndex", &GRnShapeDesc_t::GetSurfacePropertyIndex, &GRnShapeDesc_t::SetSurfacePropertyIndex)
        .addProperty("UserFriendlyName", &GRnShapeDesc_t::GetUserFriendlyName, &GRnShapeDesc_t::SetUserFriendlyName)
        .endClass();
}