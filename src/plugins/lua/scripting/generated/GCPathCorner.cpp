#include "../../../core/scripting/generated/classes/GCPathCorner.h"
#include "../core.h"

void SetupLuaClassGCPathCorner(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathCorner>("CPathCorner")
        .addProperty("Wait", &GCPathCorner::GetWait, &GCPathCorner::SetWait)
        .addProperty("Radius", &GCPathCorner::GetRadius, &GCPathCorner::SetRadius)
        .addProperty("OnPass", &GCPathCorner::GetOnPass, &GCPathCorner::SetOnPass)
        .endClass();
}