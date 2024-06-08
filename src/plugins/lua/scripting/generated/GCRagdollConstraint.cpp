#include "../../../core/scripting/generated/classes/GCRagdollConstraint.h"
#include "../core.h"

void SetupLuaClassGCRagdollConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollConstraint>("CRagdollConstraint")
        .addProperty("Xmin", &GCRagdollConstraint::GetXmin, &GCRagdollConstraint::SetXmin)
        .addProperty("Xmax", &GCRagdollConstraint::GetXmax, &GCRagdollConstraint::SetXmax)
        .addProperty("Ymin", &GCRagdollConstraint::GetYmin, &GCRagdollConstraint::SetYmin)
        .addProperty("Ymax", &GCRagdollConstraint::GetYmax, &GCRagdollConstraint::SetYmax)
        .addProperty("Zmin", &GCRagdollConstraint::GetZmin, &GCRagdollConstraint::SetZmin)
        .addProperty("Zmax", &GCRagdollConstraint::GetZmax, &GCRagdollConstraint::SetZmax)
        .addProperty("Xfriction", &GCRagdollConstraint::GetXfriction, &GCRagdollConstraint::SetXfriction)
        .addProperty("Yfriction", &GCRagdollConstraint::GetYfriction, &GCRagdollConstraint::SetYfriction)
        .addProperty("Zfriction", &GCRagdollConstraint::GetZfriction, &GCRagdollConstraint::SetZfriction)
        .endClass();
}