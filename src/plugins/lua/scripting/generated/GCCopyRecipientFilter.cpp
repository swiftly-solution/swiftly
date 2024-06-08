#include "../../../core/scripting/generated/classes/GCCopyRecipientFilter.h"
#include "../core.h"

void SetupLuaClassGCCopyRecipientFilter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCopyRecipientFilter>("CCopyRecipientFilter")
        .addProperty("Flags", &GCCopyRecipientFilter::GetFlags, &GCCopyRecipientFilter::SetFlags)
        .addProperty("Recipients", &GCCopyRecipientFilter::GetRecipients, &GCCopyRecipientFilter::SetRecipients)
        .endClass();
}