#include "../../../core/scripting/generated/classes/GCAnimMorphDifference.h"
#include "../core.h"

void SetupLuaClassGCAnimMorphDifference(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimMorphDifference>("CAnimMorphDifference")
        .addProperty("Name", &GCAnimMorphDifference::GetName, &GCAnimMorphDifference::SetName)
        .endClass();
}