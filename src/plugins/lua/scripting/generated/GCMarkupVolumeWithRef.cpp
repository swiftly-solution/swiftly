#include "../../../core/scripting/generated/classes/GCMarkupVolumeWithRef.h"
#include "../core.h"

void SetupLuaClassGCMarkupVolumeWithRef(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMarkupVolumeWithRef>("CMarkupVolumeWithRef")
        .addProperty("UseRef", &GCMarkupVolumeWithRef::GetUseRef, &GCMarkupVolumeWithRef::SetUseRef)
        .addProperty("RefPos", &GCMarkupVolumeWithRef::GetRefPos, &GCMarkupVolumeWithRef::SetRefPos)
        .addProperty("RefDot", &GCMarkupVolumeWithRef::GetRefDot, &GCMarkupVolumeWithRef::SetRefDot)
        .endClass();
}