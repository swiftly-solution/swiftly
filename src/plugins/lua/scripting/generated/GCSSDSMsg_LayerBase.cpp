#include "../../../core/scripting/generated/classes/GCSSDSMsg_LayerBase.h"
#include "../core.h"

void SetupLuaClassGCSSDSMsg_LayerBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_LayerBase>("CSSDSMsg_LayerBase")
        .addProperty("ViewId", &GCSSDSMsg_LayerBase::GetViewId, &GCSSDSMsg_LayerBase::SetViewId)
        .addProperty("ViewName", &GCSSDSMsg_LayerBase::GetViewName, &GCSSDSMsg_LayerBase::SetViewName)
        .addProperty("LayerIndex", &GCSSDSMsg_LayerBase::GetLayerIndex, &GCSSDSMsg_LayerBase::SetLayerIndex)
        .addProperty("LayerId", &GCSSDSMsg_LayerBase::GetLayerId, &GCSSDSMsg_LayerBase::SetLayerId)
        .addProperty("LayerName", &GCSSDSMsg_LayerBase::GetLayerName, &GCSSDSMsg_LayerBase::SetLayerName)
        .addProperty("DisplayText", &GCSSDSMsg_LayerBase::GetDisplayText, &GCSSDSMsg_LayerBase::SetDisplayText)
        .endClass();
}