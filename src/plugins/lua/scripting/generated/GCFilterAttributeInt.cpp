#include "../../../core/scripting/generated/classes/GCFilterAttributeInt.h"
#include "../core.h"

void SetupLuaClassGCFilterAttributeInt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterAttributeInt>("CFilterAttributeInt")
        .addProperty("AttributeName", &GCFilterAttributeInt::GetAttributeName, &GCFilterAttributeInt::SetAttributeName)
        .endClass();
}