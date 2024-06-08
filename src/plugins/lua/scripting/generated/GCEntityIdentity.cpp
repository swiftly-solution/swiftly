#include "../../../core/scripting/generated/classes/GCEntityIdentity.h"
#include "../core.h"

void SetupLuaClassGCEntityIdentity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityIdentity>("CEntityIdentity")
        .addProperty("NameStringableIndex", &GCEntityIdentity::GetNameStringableIndex, &GCEntityIdentity::SetNameStringableIndex)
        .addProperty("Name", &GCEntityIdentity::GetName, &GCEntityIdentity::SetName)
        .addProperty("DesignerName", &GCEntityIdentity::GetDesignerName, &GCEntityIdentity::SetDesignerName)
        .addProperty("Flags", &GCEntityIdentity::GetFlags, &GCEntityIdentity::SetFlags)
        .addProperty("WorldGroupId", &GCEntityIdentity::GetWorldGroupId, &GCEntityIdentity::SetWorldGroupId)
        .addProperty("DataObjectTypes", &GCEntityIdentity::GetDataObjectTypes, &GCEntityIdentity::SetDataObjectTypes)
        .addProperty("PathIndex", &GCEntityIdentity::GetPathIndex, &GCEntityIdentity::SetPathIndex)
        .addProperty("Prev", &GCEntityIdentity::GetPrev, &GCEntityIdentity::SetPrev)
        .addProperty("Next", &GCEntityIdentity::GetNext, &GCEntityIdentity::SetNext)
        .addProperty("PrevByClass", &GCEntityIdentity::GetPrevByClass, &GCEntityIdentity::SetPrevByClass)
        .addProperty("NextByClass", &GCEntityIdentity::GetNextByClass, &GCEntityIdentity::SetNextByClass)
        .endClass();
}