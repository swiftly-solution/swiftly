#include "../../../core/scripting/generated/classes/GCSSDSMsg_ViewTarget.h"
#include "../core.h"

void SetupLuaClassGCSSDSMsg_ViewTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_ViewTarget>("CSSDSMsg_ViewTarget")
        .addProperty("Name", &GCSSDSMsg_ViewTarget::GetName, &GCSSDSMsg_ViewTarget::SetName)
        .addProperty("TextureId", &GCSSDSMsg_ViewTarget::GetTextureId, &GCSSDSMsg_ViewTarget::SetTextureId)
        .addProperty("Width", &GCSSDSMsg_ViewTarget::GetWidth, &GCSSDSMsg_ViewTarget::SetWidth)
        .addProperty("Height", &GCSSDSMsg_ViewTarget::GetHeight, &GCSSDSMsg_ViewTarget::SetHeight)
        .addProperty("RequestedWidth", &GCSSDSMsg_ViewTarget::GetRequestedWidth, &GCSSDSMsg_ViewTarget::SetRequestedWidth)
        .addProperty("RequestedHeight", &GCSSDSMsg_ViewTarget::GetRequestedHeight, &GCSSDSMsg_ViewTarget::SetRequestedHeight)
        .addProperty("NumMipLevels", &GCSSDSMsg_ViewTarget::GetNumMipLevels, &GCSSDSMsg_ViewTarget::SetNumMipLevels)
        .addProperty("Depth", &GCSSDSMsg_ViewTarget::GetDepth, &GCSSDSMsg_ViewTarget::SetDepth)
        .addProperty("MultisampleNumSamples", &GCSSDSMsg_ViewTarget::GetMultisampleNumSamples, &GCSSDSMsg_ViewTarget::SetMultisampleNumSamples)
        .addProperty("Format", &GCSSDSMsg_ViewTarget::GetFormat, &GCSSDSMsg_ViewTarget::SetFormat)
        .endClass();
}