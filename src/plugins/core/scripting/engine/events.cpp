#include "../../scripting.h"

#include "../../../../memory/signatures/Signatures.h"

typedef IGameEventListener2* (*GetLegacyGameEventListener)(CPlayerSlot slot);

std::string FetchPluginName(EContext* state);

extern std::map<dyno::Hook*, std::vector<Hook>> hooksList;
extern std::map<std::string, std::string> gameEventsRegister;

PluginEvent::PluginEvent(std::string m_plugin_name, IGameEvent* m_gameEvent, dyno::Hook* m_hookPtr)
{
    this->plugin_name = m_plugin_name;
    this->gameEvent = m_gameEvent;
    this->hookPtr = m_hookPtr;
}

PluginEvent::PluginEvent(std::string gameEventName, EContext* state)
{
    this->plugin_name = FetchPluginName(state);

    for(auto it = gameEventsRegister.begin(); it != gameEventsRegister.end(); ++it)
        if(it->second == gameEventName) {
            this->gameEvent = g_gameEventManager->CreateEvent(it->first.c_str());
            this->shouldFree = true;
        }
    
    this->hookPtr = nullptr;
}

PluginEvent::~PluginEvent()
{
    if(this->shouldFree && this->gameEvent)
        g_gameEventManager->FreeEvent(this->gameEvent);
}

std::string PluginEvent::GetInvokingPlugin()
{
    return this->plugin_name;
}

bool PluginEvent::IsGameEvent()
{
    return (this->gameEvent != nullptr);
}

bool PluginEvent::IsHook()
{
    return (this->hookPtr != nullptr);
}

void PluginEvent::SetReturn(std::any value)
{
    this->returnValue = value;
}

std::any PluginEvent::GetReturnValue()
{
    return this->returnValue;
}

void PluginEvent::SetBool(std::string key, bool value)
{
    if (!this->gameEvent)
        return;

    this->gameEvent->SetBool(key.c_str(), value);
}

void PluginEvent::SetInt(std::string key, int value)
{
    if (!this->gameEvent)
        return;

    this->gameEvent->SetInt(key.c_str(), value);
}

void PluginEvent::SetUint64(std::string key, uint64_t value)
{
    if (!this->gameEvent)
        return;

    this->gameEvent->SetUint64(key.c_str(), value);
}

void PluginEvent::SetFloat(std::string key, float value)
{
    if (!this->gameEvent)
        return;

    this->gameEvent->SetFloat(key.c_str(), value);
}

void PluginEvent::SetString(std::string key, std::string value)
{
    if (!this->gameEvent)
        return;

    this->gameEvent->SetString(key.c_str(), value.c_str());
}

bool PluginEvent::GetBool(std::string key)
{
    if (!this->gameEvent)
        return false;

    if (!this->gameEvent->HasKey(key.c_str())) return false;

    return this->gameEvent->GetBool(key.c_str());
}

int PluginEvent::GetInt(std::string key)
{
    if (!this->gameEvent)
        return -1;

    if (!this->gameEvent->HasKey(key.c_str())) return -1;

    return this->gameEvent->GetInt(key.c_str());
}

uint64_t PluginEvent::GetUint64(std::string key)
{
    if (!this->gameEvent)
        return 0;

    if (!this->gameEvent->HasKey(key.c_str())) return 0;

    return this->gameEvent->GetUint64(key.c_str());
}

float PluginEvent::GetFloat(std::string key)
{
    if (!this->gameEvent)
        return 0.0f;

    if (!this->gameEvent->HasKey(key.c_str())) return 0.0f;

    return this->gameEvent->GetFloat(key.c_str());
}

std::string PluginEvent::GetString(std::string key)
{
    if (!this->gameEvent)
        return "";

    if (!this->gameEvent->HasKey(key.c_str())) return "";

    return this->gameEvent->GetString(key.c_str());
}

void PluginEvent::FireEvent(bool dontBroadcast)
{
    if (!this->gameEvent)
        return;

    g_gameEventManager->FireEvent(this->gameEvent, dontBroadcast);
}

void PluginEvent::FireEventToClient(int slot)
{
    if (!this->gameEvent)
        return;

    IGameEventListener2* playerListener = g_Signatures->FetchSignature<GetLegacyGameEventListener>("LegacyGameEventListener")(slot);
    playerListener->FireGameEvent(this->gameEvent);
}

bool PluginEvent::GetHookBool(int index)
{
    if (!this->hookPtr)
        return false;

    return this->hookPtr->getArgument<bool>(index);
}

int PluginEvent::GetHookInt(int index)
{
    if (!this->hookPtr)
        return 0;

    return this->hookPtr->getArgument<int>(index);
}

uint64_t PluginEvent::GetHookUint64(int index)
{
    if (!this->hookPtr)
        return 0;

    return this->hookPtr->getArgument<uint64_t>(index);
}

float PluginEvent::GetHookFloat(int index)
{
    if (!this->hookPtr)
        return 0.0f;

    return this->hookPtr->getArgument<float>(index);
}

std::string PluginEvent::GetHookString(int index)
{
    if (!this->hookPtr)
        return "";

    return this->hookPtr->getArgument<const char*>(index);
}

PluginMemory PluginEvent::GetHookPointer(int index)
{
    PluginMemory mem;
    if (!this->hookPtr)
        return mem;

    mem.LoadFromPtr(this->hookPtr->getArgument<void*>(index));
    return mem;
}

double PluginEvent::GetHookDouble(int index)
{
    if (!this->hookPtr)
        return 0.0f;

    return this->hookPtr->getArgument<double>(index);
}

uint32_t PluginEvent::GetHookUInt(int index)
{
    if (!this->hookPtr)
        return 0;

    return this->hookPtr->getArgument<uint32_t>(index);
}

int64_t PluginEvent::GetHookInt64(int index)
{
    if (!this->hookPtr)
        return 0;

    return this->hookPtr->getArgument<int64_t>(index);
}

void PluginEvent::SetHookBool(int index, bool value)
{
    if (!this->hookPtr)
        return;

    this->hookPtr->setArgument(index, value);
}

void PluginEvent::SetHookInt(int index, int value)
{
    if (!this->hookPtr)
        return;

    this->hookPtr->setArgument(index, value);
}

void PluginEvent::SetHookUint64(int index, uint64_t value)
{
    if (!this->hookPtr)
        return;

    this->hookPtr->setArgument(index, value);
}

void PluginEvent::SetHookFloat(int index, float value)
{
    if (!this->hookPtr)
        return;

    this->hookPtr->setArgument(index, value);
}

void PluginEvent::SetHookString(int index, std::string value)
{
    if (!this->hookPtr)
        return;

    this->hookPtr->setArgument(index, value.c_str());
}

void PluginEvent::SetHookPointer(int index, PluginMemory value)
{
    if (!this->hookPtr)
        return;

    this->hookPtr->setArgument(index, value.GetRawPtr());
}

void PluginEvent::SetHookDouble(int index, double value)
{
    if (!this->hookPtr)
        return;

    this->hookPtr->setArgument(index, value);
}

void PluginEvent::SetHookUInt(int index, uint32_t value)
{
    if (!this->hookPtr)
        return;

    this->hookPtr->setArgument(index, value);
}

void PluginEvent::SetHookInt64(int index, int64_t value)
{
    if (!this->hookPtr)
        return;

    this->hookPtr->setArgument(index, value);
}

void PluginEvent::SetHookReturn(std::any value)
{

    if (!this->hookPtr)
        return;

    if (!value.has_value())
        return;

    try
    {
        if (value.type() == typeid(const char*))
            return this->hookPtr->setReturnValue(std::any_cast<const char*>(value));
        else if (value.type() == typeid(std::string))
            return this->hookPtr->setReturnValue(std::any_cast<std::string>(value).c_str());
        else if (value.type() == typeid(uint64))
            return this->hookPtr->setReturnValue(std::any_cast<uint64>(value));
        else if (value.type() == typeid(uint32))
            return this->hookPtr->setReturnValue(std::any_cast<uint32>(value));
        else if (value.type() == typeid(unsigned long))
            return this->hookPtr->setReturnValue(std::any_cast<unsigned long>(value));
        else if (value.type() == typeid(uint16))
            return this->hookPtr->setReturnValue(std::any_cast<uint16>(value));
        else if (value.type() == typeid(uint8))
            return this->hookPtr->setReturnValue(std::any_cast<uint8>(value));
        else if (value.type() == typeid(int64))
            return this->hookPtr->setReturnValue(std::any_cast<int64>(value));
        else if (value.type() == typeid(int32))
            return this->hookPtr->setReturnValue(std::any_cast<int32>(value));
        else if (value.type() == typeid(long))
            return this->hookPtr->setReturnValue(std::any_cast<long>(value));
        else if (value.type() == typeid(int16))
            return this->hookPtr->setReturnValue(std::any_cast<int16>(value));
        else if (value.type() == typeid(int8))
            return this->hookPtr->setReturnValue(std::any_cast<int8>(value));
        else if (value.type() == typeid(bool))
            return this->hookPtr->setReturnValue(std::any_cast<bool>(value));
        else if (value.type() == typeid(float))
            return this->hookPtr->setReturnValue(std::any_cast<float>(value));
        else if (value.type() == typeid(void*))
            return this->hookPtr->setReturnValue(std::any_cast<void*>(value));
        else if (value.type() == typeid(double))
            return this->hookPtr->setReturnValue(std::any_cast<double>(value));
        else if (value.type() == typeid(std::nullptr_t))
            return this->hookPtr->setReturnValue(0);
        else
            PRINTF("Unknown Data Type: %s\n", value.type().name());
    }
    catch (std::bad_any_cast& err)
    {
        PRINTF("Invalid casting: %s\n", err.what());
    }
}

std::any PluginEvent::GetHookReturn()
{
    if (!this->hookPtr)
        return nullptr;

    if (hooksList.find(this->hookPtr) == hooksList.end())
        return nullptr;

    if (hooksList[this->hookPtr].size() <= 0)
        return nullptr;

    Hook hk = hooksList[this->hookPtr][0];
    if (hk.retType.size() <= 0)
        return nullptr;

    if (hk.retType.at(0) == 'p')
    {
        PluginMemory mem;
        mem.LoadFromPtr(this->hookPtr->getReturnValue<void*>());
        return mem.GetPtr();
    }
    else if (hk.retType.at(0) == 'f')
        return this->hookPtr->getReturnValue<float>();
    else if (hk.retType.at(0) == 'b')
        return this->hookPtr->getReturnValue<bool>();
    else if (hk.retType.at(0) == 'd')
        return this->hookPtr->getReturnValue<double>();
    else if (hk.retType.at(0) == 'i')
        return this->hookPtr->getReturnValue<int32_t>();
    else if (hk.retType.at(0) == 'u')
        return this->hookPtr->getReturnValue<uint32_t>();
    else if (hk.retType.at(0) == 's')
        return this->hookPtr->getReturnValue<const char*>();
    else if (hk.retType.at(0) == 'I')
        return this->hookPtr->getReturnValue<int64_t>();
    else if (hk.retType.at(0) == 'U')
        return this->hookPtr->getReturnValue<uint64_t>();
    else
    {
        PRINTF("Invalid argument in return value: '%c'.\n", hk.retType.at(0));
        return nullptr;
    }
}

void PluginEvent::SetNoBroadcast(bool status)
{
    noBroadcastStatus = status;
}

bool PluginEvent::GetNoBroadcast()
{
    return noBroadcastStatus;
}
