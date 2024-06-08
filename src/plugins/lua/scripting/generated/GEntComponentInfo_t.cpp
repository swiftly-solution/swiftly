#include "../../../core/scripting/generated/classes/GEntComponentInfo_t.h"
#include "../core.h"

void SetupLuaClassGEntComponentInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntComponentInfo_t>("EntComponentInfo_t")
        .addProperty("Name", &GEntComponentInfo_t::GetName, &GEntComponentInfo_t::SetName)
        .addProperty("CPPClassname", &GEntComponentInfo_t::GetCPPClassname, &GEntComponentInfo_t::SetCPPClassname)
        .addProperty("NetworkDataReferencedDescription", &GEntComponentInfo_t::GetNetworkDataReferencedDescription, &GEntComponentInfo_t::SetNetworkDataReferencedDescription)
        .addProperty("NetworkDataReferencedPtrPropDescription", &GEntComponentInfo_t::GetNetworkDataReferencedPtrPropDescription, &GEntComponentInfo_t::SetNetworkDataReferencedPtrPropDescription)
        .addProperty("RuntimeIndex", &GEntComponentInfo_t::GetRuntimeIndex, &GEntComponentInfo_t::SetRuntimeIndex)
        .addProperty("Flags", &GEntComponentInfo_t::GetFlags, &GEntComponentInfo_t::SetFlags)
        .addProperty("BaseClassComponentHelper", &GEntComponentInfo_t::GetBaseClassComponentHelper, &GEntComponentInfo_t::SetBaseClassComponentHelper)
        .endClass();
}