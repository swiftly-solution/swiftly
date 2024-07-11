#include "../scripting.h"

#include "../../../signatures/Signatures.h"

typedef IGameEventListener2 *(*GetLegacyGameEventListener)(CPlayerSlot slot);

extern std::map<dyno::IHook *, std::vector<Hook>> hooksList;

PluginEvent::PluginEvent(std::string m_plugin_name, IGameEvent *m_gameEvent, dyno::IHook *m_hookPtr)
{
    this->plugin_name = m_plugin_name;
    this->gameEvent = m_gameEvent;
    this->hookPtr = m_hookPtr;
}

PluginEvent::~PluginEvent()
{
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

void PluginEvent::SetReturnLua(luabridge::LuaRef value)
{
    std::any returnValue;

    if (value.isBool())
        returnValue = value.cast<bool>();
    else if (value.isNil())
        returnValue = nullptr;
    else if (value.isNumber())
        returnValue = value.cast<int64_t>();
    else if (value.isString())
        returnValue = value.cast<std::string>();
    else
        returnValue = nullptr;

    SetReturn(returnValue);
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

    return this->gameEvent->GetBool(key.c_str());
}

int PluginEvent::GetInt(std::string key)
{
    if (!this->gameEvent)
        return 0;

    return this->gameEvent->GetInt(key.c_str());
}

uint64_t PluginEvent::GetUint64(std::string key)
{
    if (!this->gameEvent)
        return 0;

    return this->gameEvent->GetUint64(key.c_str());
}

float PluginEvent::GetFloat(std::string key)
{
    if (!this->gameEvent)
        return 0.0f;

    return this->gameEvent->GetFloat(key.c_str());
}

std::string PluginEvent::GetString(std::string key)
{
    if (!this->gameEvent)
        return "";

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

    IGameEventListener2 *playerListener = g_Signatures->FetchSignature<GetLegacyGameEventListener>("LegacyGameEventListener")(slot);
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

    return this->hookPtr->getArgument<const char *>(index);
}

PluginMemory PluginEvent::GetHookPointer(int index)
{
    PluginMemory mem;
    if (!this->hookPtr)
        return mem;

    mem.LoadFromPtr(this->hookPtr->getArgument<void *>(index));
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
        if (value.type() == typeid(const char *))
            return this->hookPtr->setReturn(std::any_cast<const char *>(value));
        else if (value.type() == typeid(std::string))
            return this->hookPtr->setReturn(std::any_cast<std::string>(value).c_str());
        else if (value.type() == typeid(uint64))
            return this->hookPtr->setReturn(std::any_cast<uint64>(value));
        else if (value.type() == typeid(uint32))
            return this->hookPtr->setReturn(std::any_cast<uint32>(value));
        else if (value.type() == typeid(unsigned long))
            return this->hookPtr->setReturn(std::any_cast<unsigned long>(value));
        else if (value.type() == typeid(uint16))
            return this->hookPtr->setReturn(std::any_cast<uint16>(value));
        else if (value.type() == typeid(uint8))
            return this->hookPtr->setReturn(std::any_cast<uint8>(value));
        else if (value.type() == typeid(int64))
            return this->hookPtr->setReturn(std::any_cast<int64>(value));
        else if (value.type() == typeid(int32))
            return this->hookPtr->setReturn(std::any_cast<int32>(value));
        else if (value.type() == typeid(long))
            return this->hookPtr->setReturn(std::any_cast<long>(value));
        else if (value.type() == typeid(int16))
            return this->hookPtr->setReturn(std::any_cast<int16>(value));
        else if (value.type() == typeid(int8))
            return this->hookPtr->setReturn(std::any_cast<int8>(value));
        else if (value.type() == typeid(bool))
            return this->hookPtr->setReturn(std::any_cast<bool>(value));
        else if (value.type() == typeid(float))
            return this->hookPtr->setReturn(std::any_cast<float>(value));
        else if (value.type() == typeid(void *))
            return this->hookPtr->setReturn(std::any_cast<void *>(value));
        else if (value.type() == typeid(double))
            return this->hookPtr->setReturn(std::any_cast<double>(value));
        else if (value.type() == typeid(std::nullptr_t))
            return this->hookPtr->setReturn(0);
        else
            PRINTF("Unknown Data Type: %s\n", value.type().name());
    }
    catch (std::bad_any_cast &err)
    {
        PRINTF("Invalid casting: %s\n", err.what());
    }
}

void PluginEvent::SetHookReturnLua(luabridge::LuaRef value)
{
    if (!this->hookPtr)
        return;

    std::any val;

    if (value.isBool())
        val = value.cast<bool>();
    else if (value.isNil())
        val = nullptr;
    else if (value.isNumber())
        val = value.cast<int64_t>();
    else if (value.isString())
    {
        std::string str = value.cast<std::string>();
        if (str.find("0x") != std::string::npos)
            val = (void *)(strtol(str.c_str(), nullptr, 16));
        else
            val = str;
    }

    SetHookReturn(val);
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
        mem.LoadFromPtr(this->hookPtr->getReturn<void *>());
        return mem.GetPtr();
    }
    else if (hk.retType.at(0) == 'f')
        return this->hookPtr->getReturn<float>();
    else if (hk.retType.at(0) == 'b')
        return this->hookPtr->getReturn<bool>();
    else if (hk.retType.at(0) == 'd')
        return this->hookPtr->getReturn<double>();
    else if (hk.retType.at(0) == 'i')
        return this->hookPtr->getReturn<int32_t>();
    else if (hk.retType.at(0) == 'u')
        return this->hookPtr->getReturn<uint32_t>();
    else if (hk.retType.at(0) == 's')
        return this->hookPtr->getReturn<const char *>();
    else if (hk.retType.at(0) == 'I')
        return this->hookPtr->getReturn<int64_t>();
    else if (hk.retType.at(0) == 'U')
        return this->hookPtr->getReturn<uint64_t>();
    else
    {
        PRINTF("Invalid argument in return value: '%c'.\n", hk.retType.at(0));
        return nullptr;
    }
}