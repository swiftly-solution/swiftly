#include "../scripting.h"

#include <dynohook/core.h>
#include <dynohook/manager.h>
#include <dynohook/conventions/x64_systemV_call.h>

#include <msgpack.hpp>
#include <sstream>

std::map<dyno::IHook *, std::vector<Hook>> hooksList;

PluginHooks::PluginHooks(std::string plugin_name)
{
    m_plugin_name = plugin_name;
}

std::string emptyPayload;
bool setEmptyPayload = false;

std::vector<DataType_t> ParseArgsList(std::string args_list)
{
    std::vector<DataType_t> argsList;

    for (size_t i = 0; i < args_list.size(); i++)
    {
        if (args_list.at(0) == 'p')
            argsList.push_back(DataType_t::POINTER);
        else if (args_list.at(0) == 'f')
            argsList.push_back(DataType_t::FLOAT);
        else if (args_list.at(0) == 'b')
            argsList.push_back(DataType_t::BOOL);
        else if (args_list.at(0) == 'd')
            argsList.push_back(DataType_t::DOUBLE);
        else if (args_list.at(0) == 'i')
            argsList.push_back(DataType_t::INT);
        else if (args_list.at(0) == 'u')
            argsList.push_back(DataType_t::UINT);
        else if (args_list.at(0) == 's')
            argsList.push_back(DataType_t::STRING);
        else if (args_list.at(0) == 'I')
            argsList.push_back(DataType_t::LONG_LONG);
        else if (args_list.at(0) == 'U')
            argsList.push_back(DataType_t::ULONG_LONG);
        else if (args_list.at(0) == 'v')
            argsList.push_back(DataType_t::VOID);
        else
            PRINTF("Invalid argument in list: '%c'.\n", args_list.at(0));
    }

    return argsList;
}

std::vector<dyno::DataObject> ConvertDT(const std::vector<DataType_t> dataTypes)
{
    std::vector<dyno::DataObject> converted;

    for (DataType_t dt : dataTypes)
        converted.push_back(dyno::DataObject(static_cast<dyno::DataType>(dt)));

    return converted;
}

dyno::ReturnAction DynHookHandler(dyno::CallbackType hookType, dyno::IHook &hook)
{
    dyno::IHook *hookPtr = &hook;
    std::string callbackType = (hookType == dyno::CallbackType::Pre ? "Pre" : "Post");
    if (hooksList.find(hookPtr) == hooksList.end())
        return dyno::ReturnAction::Ignored;

    if (!setEmptyPayload)
    {
        std::stringstream ss;
        std::vector<msgpack::object> eventData;

        msgpack::pack(ss, eventData);
        emptyPayload = ss.str();
        setEmptyPayload = true;
    }

    PluginEvent *event = new PluginEvent("core", nullptr, hookPtr);
    for (auto hk : hooksList[hookPtr])
    {
        auto res = g_pluginManager->ExecuteEvent("core", "hook:" + callbackType + ":" + hk.id, emptyPayload, event);
        if (res != EventResult::Continue)
        {
            delete event;
            return dyno::ReturnAction::Supercede;
        }
    }
    delete event;

    return dyno::ReturnAction::Ignored;
}

std::string PluginHooks::AddHook(PluginMemory mem, std::string args_list, std::string ret_type)
{
    if (!mem.IsValid())
    {
        PRINT("ERROR: Tried to add a hook with invalid memory.\n");
        return "00000000-0000-0000-0000-000000000000";
    }

    void *funcPtr = mem.GetRawPtr();

    std::string id = get_uuid();
    Hook hk = {
        funcPtr,
        args_list,
        ret_type,
        id,
    };

    std::vector<DataType_t> argTypes = ParseArgsList(args_list);

    dyno::IHookManager &manager = dyno::HookManager::Get();
    dyno::IHook *hook = manager.hookDetour(funcPtr, [argTypes, ret_type]
                                           { return new dyno::x64SystemVcall(ConvertDT(argTypes), static_cast<dyno::DataType>(ParseArgsList(ret_type)[0])); })
                            .get();

    if (hooksList.find(hook) == hooksList.end())
        hooksList.insert({hook, {}});

    hooksList[hook].push_back(hk);

    hook->addCallback(dyno::CallbackType::Pre, DynHookHandler);
    hook->addCallback(dyno::CallbackType::Post, DynHookHandler);
    return id;
}