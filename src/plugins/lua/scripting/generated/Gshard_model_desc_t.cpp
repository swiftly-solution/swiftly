#include "../../../core/scripting/generated/classes/Gshard_model_desc_t.h"
#include "../core.h"

void SetupLuaClassGshard_model_desc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gshard_model_desc_t>("shard_model_desc_t")
        .addProperty("ModelID", &Gshard_model_desc_t::GetModelID, &Gshard_model_desc_t::SetModelID)
        .addProperty("Solid", &Gshard_model_desc_t::GetSolid, &Gshard_model_desc_t::SetSolid)
        .addProperty("ShatterPanelMode", &Gshard_model_desc_t::GetShatterPanelMode, &Gshard_model_desc_t::SetShatterPanelMode)
        .addProperty("PanelSize", &Gshard_model_desc_t::GetPanelSize, &Gshard_model_desc_t::SetPanelSize)
        .addProperty("StressPositionA", &Gshard_model_desc_t::GetStressPositionA, &Gshard_model_desc_t::SetStressPositionA)
        .addProperty("StressPositionB", &Gshard_model_desc_t::GetStressPositionB, &Gshard_model_desc_t::SetStressPositionB)
        .addProperty("PanelVertices", &Gshard_model_desc_t::GetPanelVertices, &Gshard_model_desc_t::SetPanelVertices)
        .addProperty("GlassHalfThickness", &Gshard_model_desc_t::GetGlassHalfThickness, &Gshard_model_desc_t::SetGlassHalfThickness)
        .addProperty("HasParent", &Gshard_model_desc_t::GetHasParent, &Gshard_model_desc_t::SetHasParent)
        .addProperty("ParentFrozen", &Gshard_model_desc_t::GetParentFrozen, &Gshard_model_desc_t::SetParentFrozen)
        .addProperty("SurfacePropStringToken", &Gshard_model_desc_t::GetSurfacePropStringToken, &Gshard_model_desc_t::SetSurfacePropStringToken)
        .endClass();
}