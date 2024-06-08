#include "../../../core/scripting/generated/classes/GCCompositeMaterialEditorDoc.h"
#include "../core.h"

void SetupLuaClassGCCompositeMaterialEditorDoc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCompositeMaterialEditorDoc>("CCompositeMaterialEditorDoc")
        .addProperty("Version", &GCCompositeMaterialEditorDoc::GetVersion, &GCCompositeMaterialEditorDoc::SetVersion)
        .addProperty("Points", &GCCompositeMaterialEditorDoc::GetPoints, &GCCompositeMaterialEditorDoc::SetPoints)
        .endClass();
}