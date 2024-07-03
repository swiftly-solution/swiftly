#include "../scripting.h"
#include "../../../hooks/FuncHook.h"

#include <dynohook/core.h>
#include <dynohook/manager.h>
#include <dynohook/conventions/x64_systemV_call.h>

#include <dyncall/dyncall.h>

#include <msgpack.hpp>
#include <sstream>

typedef std::pair<std::string, std::string> OutputPair_t;
std::map<OutputPair_t, std::vector<std::string>> outputHooksList;
// void Hook_FireOutputInternal(CEntityIOOutput *const pThis, CEntityInstance *pActivator, CEntityInstance *pCaller, const CVariant *const value, float flDelay);
// FuncHook<decltype(Hook_FireOutputInternal)> TFireOutputInternal(Hook_FireOutputInternal, "FireOutputInternal");

std::map<dyno::IHook *, std::vector<Hook>> hooksList;
std::map<std::string, dyno::IHook *> hooksMap;
DCCallVM *g_pCallVM = dcNewCallVM(4096);

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
        if (args_list.at(i) == 'p')
            argsList.push_back(DataType_t::POINTER);
        else if (args_list.at(i) == 'f')
            argsList.push_back(DataType_t::FLOAT);
        else if (args_list.at(i) == 'b')
            argsList.push_back(DataType_t::BOOL);
        else if (args_list.at(i) == 'd')
            argsList.push_back(DataType_t::DOUBLE);
        else if (args_list.at(i) == 'i')
            argsList.push_back(DataType_t::INT);
        else if (args_list.at(i) == 'u')
            argsList.push_back(DataType_t::UINT);
        else if (args_list.at(i) == 's')
            argsList.push_back(DataType_t::STRING);
        else if (args_list.at(i) == 'I')
            argsList.push_back(DataType_t::LONG_LONG);
        else if (args_list.at(i) == 'U')
            argsList.push_back(DataType_t::ULONG_LONG);
        else if (args_list.at(i) == 'v')
            argsList.push_back(DataType_t::VOID);
        else
            PRINTF("Invalid argument in list: '%c'.\n", args_list.at(i));
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

    if (hooksMap.find(id) == hooksMap.end())
        hooksMap.insert({id, hook});
    else
        hooksMap[id] = hook;

    hook->addCallback(dyno::CallbackType::Pre, DynHookHandler);
    hook->addCallback(dyno::CallbackType::Post, DynHookHandler);
    return id;
}

template <class ReturnType, class Function>
ReturnType CallHelper(Function func, DCCallVM *vm, void *addr)
{
    return (ReturnType)func(vm, (void *)addr);
}

void CallHelperVoid(DCCallVM *vm, void *addr) { dcCallVoid(vm, (void *)addr); }

luabridge::LuaRef PluginHooks::CallHookLua(std::string hookId, std::string hookPayload, lua_State *L)
{
    if (hooksMap.find(hookId) == hooksMap.end())
        return LuaSerializeData(nullptr, L);

    auto hook = hooksMap.at(hookId);
    if (hooksList.find(hook) == hooksList.end())
        return LuaSerializeData(nullptr, L);
    if (hooksList.at(hook).size() <= 0)
        return LuaSerializeData(nullptr, L);

    auto hk = hooksList.at(hook)[0];

    // Unpacking arguments
    std::vector<msgpack::object> args;

    msgpack::object_handle handle = msgpack::unpack(hookPayload.data(), hookPayload.size());
    msgpack::object main_obj = handle.get();

    if (main_obj.type == msgpack::type::ARRAY)
    {
        for (size_t i = 0; i < main_obj.via.array.size; i++)
            args.push_back(main_obj.via.array.ptr[i]);
    }

    dcReset(g_pCallVM);
    dcMode(g_pCallVM, DC_CALL_C_DEFAULT);

    for (size_t i = 0; i < args.size(); i++)
    {
        if (hk.argsList.size() >= i)
            break;

        if (hk.argsList.at(i) == 'p')
            dcArgPointer(g_pCallVM, (void *)(strtol(args[i].as<std::string>().c_str(), nullptr, 16)));
        else if (hk.argsList.at(i) == 'f')
            dcArgFloat(g_pCallVM, args[i].as<float>());
        else if (hk.argsList.at(i) == 'b')
            dcArgBool(g_pCallVM, args[i].as<bool>());
        else if (hk.argsList.at(i) == 'd')
            dcArgDouble(g_pCallVM, args[i].as<double>());
        else if (hk.argsList.at(i) == 'i')
            dcArgInt(g_pCallVM, args[i].as<int>());
        else if (hk.argsList.at(i) == 'u')
            dcArgLong(g_pCallVM, args[i].as<uint32_t>());
        else if (hk.argsList.at(i) == 's')
            dcArgPointer(g_pCallVM, (void *)args[i].as<std::string>().c_str());
        else if (hk.argsList.at(i) == 'I')
            dcArgLongLong(g_pCallVM, args[i].as<int64_t>());
        else if (hk.argsList.at(i) == 'U')
            dcArgLongLong(g_pCallVM, args[i].as<uint64_t>());
        else
        {
            PRINTF("Invalid Data Type: '%c'.\n", hk.argsList.at(i));
            break;
        }
    }

    std::any retval = nullptr;
    if (hk.retType.at(0) == 'p')
        retval = string_format("%p", CallHelper<void *>(dcCallPointer, g_pCallVM, hk.ptr));
    else if (hk.retType.at(0) == 'f')
        retval = CallHelper<float>(dcCallFloat, g_pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 'b')
        retval = CallHelper<bool>(dcCallBool, g_pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 'd')
        retval = CallHelper<double>(dcCallDouble, g_pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 'i')
        retval = CallHelper<int>(dcCallInt, g_pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 'u')
        retval = CallHelper<uint32_t>(dcCallInt, g_pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 's')
        retval = std::string(CallHelper<const char *>(dcCallPointer, g_pCallVM, hk.ptr));
    else if (hk.retType.at(0) == 'I')
        retval = CallHelper<int64_t>(dcCallLongLong, g_pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 'U')
        retval = CallHelper<uint64_t>(dcCallLongLong, g_pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 'v')
    {
        CallHelperVoid(g_pCallVM, hk.ptr);
        retval = nullptr;
    }
    else
    {
        PRINTF("Invalid return type: '%c'.\n", hk.retType.at(0));
        retval = nullptr;
    }
    return LuaSerializeData(retval, L);
}

std::string PluginHooks::AddEntityOutputHook(std::string classname, std::string output)
{
    std::string id = get_uuid();
    auto outputKey = OutputPair_t(classname, output);

    if (outputHooksList.find(outputKey) == outputHooksList.end())
        outputHooksList.insert({outputKey, {}});

    outputHooksList[outputKey].push_back(id);
    return id;
}

// void Hook_FireOutputInternal(CEntityIOOutput *const pThis, CEntityInstance *pActivator, CEntityInstance *pCaller, const CVariant *const value, float flDelay)
// {
//     std::vector searchOutputs{OutputPair_t("*", pThis->m_pDesc->m_pName), OutputPair_t("*", "*")};

//     if (pCaller)
//     {
//         searchOutputs.push_back(OutputPair_t(pCaller->GetClassname(), pThis->m_pDesc->m_pName));
//         searchOutputs.push_back(OutputPair_t(pCaller->GetClassname(), "*"));
//     }

//     std::vector<std::string> hookIds;

//     if (pCaller)
//     {
//         for (auto output : searchOutputs)
//             if (outputHooksList.find(output) != outputHooksList.end())
//                 for (auto hookid : outputHooksList.at(output))
//                     hookIds.push_back(hookid);
//     }

//     PluginEvent *preEvent = new PluginEvent("core", nullptr, nullptr);
//     std::stringstream preSS;
//     std::vector<msgpack::object> preEventData;

//     preEventData.push_back(msgpack::object(string_format("%p", pThis).c_str()));
//     preEventData.push_back(msgpack::object(pThis->m_pDesc->m_pName));
//     preEventData.push_back(msgpack::object(string_format("%p", pActivator).c_str()));
//     preEventData.push_back(msgpack::object(string_format("%p", pCaller).c_str()));
//     preEventData.push_back(msgpack::object(flDelay));

//     msgpack::pack(preSS, preEventData);
//     for (auto id : hookIds)
//     {
//         auto result = g_pluginManager->ExecuteEvent("core", "hook:Pre:" + id, preSS.str(), preEvent);
//         if (result != EventResult::Continue)
//         {
//             delete preEvent;
//             return;
//         }
//     }
//     delete preEvent;

//     TFireOutputInternal(pThis, pActivator, pCaller, value, flDelay);

//     PluginEvent *postEvent = new PluginEvent("core", nullptr, nullptr);
//     std::stringstream postSS;
//     std::vector<msgpack::object> postEventData;

//     postEventData.push_back(msgpack::object(string_format("%p", pThis).c_str()));
//     postEventData.push_back(msgpack::object(pThis->m_pDesc->m_pName));
//     postEventData.push_back(msgpack::object(string_format("%p", pActivator).c_str()));
//     postEventData.push_back(msgpack::object(string_format("%p", pCaller).c_str()));
//     postEventData.push_back(msgpack::object(flDelay));

//     msgpack::pack(postSS, postEventData);
//     for (auto id : hookIds)
//     {
//         auto result = g_pluginManager->ExecuteEvent("core", "hook:Post:" + id, postSS.str(), postEvent);
//         if (result != EventResult::Continue)
//         {
//             delete postEvent;
//             return;
//         }
//     }
//     delete postEvent;
// }