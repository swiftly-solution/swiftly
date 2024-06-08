#include "../../../core/scripting/generated/classes/GCMessage.h"
#include "../core.h"

void SetupLuaClassGCMessage(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMessage>("CMessage")
        .addProperty("Message", &GCMessage::GetMessage, &GCMessage::SetMessage)
        .addProperty("MessageVolume", &GCMessage::GetMessageVolume, &GCMessage::SetMessageVolume)
        .addProperty("MessageAttenuation", &GCMessage::GetMessageAttenuation, &GCMessage::SetMessageAttenuation)
        .addProperty("Radius", &GCMessage::GetRadius, &GCMessage::SetRadius)
        .addProperty("Noise", &GCMessage::GetNoise, &GCMessage::SetNoise)
        .addProperty("OnShowMessage", &GCMessage::GetOnShowMessage, &GCMessage::SetOnShowMessage)
        .endClass();
}