#include "../../../core/scripting/generated/classes/GCAttributeContainer.h"
#include "../core.h"

void SetupLuaClassGCAttributeContainer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAttributeContainer>("CAttributeContainer")
        .addProperty("Item", &GCAttributeContainer::GetItem, &GCAttributeContainer::SetItem)
        .endClass();
}