#include "../../../core/scripting/generated/classes/GCItemDogtags.h"
#include "../core.h"

void SetupLuaClassGCItemDogtags(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemDogtags>("CItemDogtags")
        .addProperty("OwningPlayer", &GCItemDogtags::GetOwningPlayer, &GCItemDogtags::SetOwningPlayer)
        .addProperty("KillingPlayer", &GCItemDogtags::GetKillingPlayer, &GCItemDogtags::SetKillingPlayer)
        .endClass();
}