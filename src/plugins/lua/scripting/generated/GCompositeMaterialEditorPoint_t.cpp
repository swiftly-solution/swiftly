#include "../../../core/scripting/generated/classes/GCompositeMaterialEditorPoint_t.h"
#include "../core.h"

void SetupLuaClassGCompositeMaterialEditorPoint_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompositeMaterialEditorPoint_t>("CompositeMaterialEditorPoint_t")
        .addProperty("SequenceIndex", &GCompositeMaterialEditorPoint_t::GetSequenceIndex, &GCompositeMaterialEditorPoint_t::SetSequenceIndex)
        .addProperty("Cycle", &GCompositeMaterialEditorPoint_t::GetCycle, &GCompositeMaterialEditorPoint_t::SetCycle)
        .addProperty("EnableChildModel", &GCompositeMaterialEditorPoint_t::GetEnableChildModel, &GCompositeMaterialEditorPoint_t::SetEnableChildModel)
        .addProperty("CompositeMaterialAssemblyProcedures", &GCompositeMaterialEditorPoint_t::GetCompositeMaterialAssemblyProcedures, &GCompositeMaterialEditorPoint_t::SetCompositeMaterialAssemblyProcedures)
        .addProperty("CompositeMaterials", &GCompositeMaterialEditorPoint_t::GetCompositeMaterials, &GCompositeMaterialEditorPoint_t::SetCompositeMaterials)
        .endClass();
}