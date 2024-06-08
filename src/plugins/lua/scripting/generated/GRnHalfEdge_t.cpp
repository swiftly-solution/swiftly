#include "../../../core/scripting/generated/classes/GRnHalfEdge_t.h"
#include "../core.h"

void SetupLuaClassGRnHalfEdge_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnHalfEdge_t>("RnHalfEdge_t")
        .addProperty("Next", &GRnHalfEdge_t::GetNext, &GRnHalfEdge_t::SetNext)
        .addProperty("Twin", &GRnHalfEdge_t::GetTwin, &GRnHalfEdge_t::SetTwin)
        .addProperty("Origin", &GRnHalfEdge_t::GetOrigin, &GRnHalfEdge_t::SetOrigin)
        .addProperty("Face", &GRnHalfEdge_t::GetFace, &GRnHalfEdge_t::SetFace)
        .endClass();
}