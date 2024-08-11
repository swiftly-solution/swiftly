#include "../scripting.h"
#include "../../../hooks/FuncHook.h"

#include <dynohook/core.h>
#include <dynohook/manager.h>

#ifdef _WIN32
#include <dynohook/conventions/x64/x64MsFastcall.h>
#else
#include <dynohook/conventions/x64/x64SystemVcall.h>
#endif

#include <dyncall/dyncall.h>

#include <msgpack.hpp>
#include <sstream>

typedef std::pair<std::string, std::string> OutputPair_t;
std::map<OutputPair_t, std::vector<std::string>> outputHooksList;
void Hook_FireOutputInternal(CEntityIOOutput* const pThis, CEntityInstance* pActivator, CEntityInstance* pCaller, const CVariant* const value, float flDelay);
FuncHook<decltype(Hook_FireOutputInternal)> TFireOutputInternal(Hook_FireOutputInternal, "FireOutputInternal");

DCCallVM* pCallVM = dcNewCallVM(4096);

std::map<dyno::Hook*, std::vector<Hook>> hooksList;
std::map<std::string, dyno::Hook*> hooksMap;

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

dyno::ReturnAction DynHookHandler(dyno::HookType hookType, dyno::Hook& hook)
{
    dyno::Hook* hookPtr = &hook;
    std::string callbackType = (hookType == dyno::HookType::Pre ? "Pre" : "Post");
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

    PluginEvent* event = new PluginEvent("core", nullptr, hookPtr);
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
    REGISTER_CALLSTACK(this->m_plugin_name, string_format("PluginHooks::AddHook(mem=%p,args_list=\"%s\",ret_type=\"%s\")", mem.GetRawPtr(), args_list.c_str(), ret_type.c_str()));

    if (!mem.IsValid())
    {
        PRINT("ERROR: Tried to add a hook with invalid memory.\n");
        return "00000000-0000-0000-0000-000000000000";
    }

    void* funcPtr = mem.GetRawPtr();

    std::string id = get_uuid();
    Hook hk = {
        funcPtr,
        args_list,
        ret_type,
        id,
    };

    std::vector<DataType_t> argTypes = ParseArgsList(args_list);

    dyno::HookManager& manager = dyno::HookManager::Get();
    dyno::Hook* hook = manager.hook(funcPtr, [argTypes, ret_type]
        {
#ifdef _WIN32
            return new dyno::x64MsFastcall(ConvertDT(argTypes), static_cast<dyno::DataType>(ParseArgsList(ret_type)[0]));
#else
            return new dyno::x64SystemVcall(ConvertDT(argTypes), static_cast<dyno::DataType>(ParseArgsList(ret_type)[0]));
#endif
        });

    if (hooksList.find(hook) == hooksList.end())
        hooksList.insert({ hook, {} });

    hooksList[hook].push_back(hk);

    if (hooksMap.find(id) == hooksMap.end())
        hooksMap.insert({ id, hook });
    else
        hooksMap[id] = hook;

    hook->addCallback(dyno::HookType::Pre, (dyno::HookHandler*)&DynHookHandler);
    hook->addCallback(dyno::HookType::Post, (dyno::HookHandler*)&DynHookHandler);
    return id;
}

luabridge::LuaRef PluginHooks::CallHookLua(std::string hookId, std::string hookPayload, lua_State* L)
{
    REGISTER_CALLSTACK(this->m_plugin_name, string_format("PluginHooks::CallHookLua(hookId=\"%s\")", hookId.c_str()));
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

    dcReset(pCallVM);
    dcMode(pCallVM, DC_CALL_C_DEFAULT);

    for (size_t i = 0; i < args.size(); i++)
    {
        if (hk.argsList.size() <= i)
            break;

        if (hk.argsList.at(i) == 'p')
            dcArgPointer(pCallVM, (void*)strtol(args[i].as<std::string>().c_str(), nullptr, 16));
        else if (hk.argsList.at(i) == 'f')
            dcArgFloat(pCallVM, args[i].as<float>());
        else if (hk.argsList.at(i) == 'b')
            dcArgBool(pCallVM, args[i].as<bool>());
        else if (hk.argsList.at(i) == 'd')
            dcArgDouble(pCallVM, args[i].as<double>());
        else if (hk.argsList.at(i) == 'i')
            dcArgInt(pCallVM, args[i].as<int>());
        else if (hk.argsList.at(i) == 'u')
            dcArgLong(pCallVM, args[i].as<uint32_t>());
        else if (hk.argsList.at(i) == 's')
            dcArgPointer(pCallVM, (void*)args[i].as<std::string>().c_str());
        else if (hk.argsList.at(i) == 'I')
            dcArgLongLong(pCallVM, args[i].as<int64_t>());
        else if (hk.argsList.at(i) == 'U')
            dcArgLongLong(pCallVM, args[i].as<uint64_t>());
        else
        {
            PRINTF("Invalid Data Type: '%c'.\n", hk.argsList.at(i));
            break;
        }
    }

    std::any retval = nullptr;
    if (hk.retType.at(0) == 'p')
        retval = string_format("%p", (void*)dcCallPointer(pCallVM, hk.ptr));
    else if (hk.retType.at(0) == 'f')
        retval = (float)dcCallFloat(pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 'b')
        retval = (bool)dcCallBool(pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 'd')
        retval = (double)dcCallDouble(pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 'i')
        retval = (int)dcCallInt(pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 'u')
        retval = (uint32_t)dcCallInt(pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 's')
        retval = std::string((const char*)dcCallPointer(pCallVM, hk.ptr));
    else if (hk.retType.at(0) == 'I')
        retval = (int64_t)dcCallLongLong(pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 'U')
        retval = (uint64_t)dcCallLongLong(pCallVM, hk.ptr);
    else if (hk.retType.at(0) == 'v')
    {
        dcCallVoid(pCallVM, hk.ptr);
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
    REGISTER_CALLSTACK(this->m_plugin_name, string_format("PluginHooks::AddEntityOutputHook(classname=\"%s\",output=\"%s\")", classname.c_str(), output.c_str()));
    std::string id = get_uuid();
    auto outputKey = OutputPair_t(classname, output);

    if (outputHooksList.find(outputKey) == outputHooksList.end())
        outputHooksList.insert({ outputKey, {} });

    outputHooksList[outputKey].push_back(id);
    return id;
}

void Hook_FireOutputInternal(CEntityIOOutput* const pThis, CEntityInstance* pActivator, CEntityInstance* pCaller, const CVariant* const value, float flDelay)
{
    std::vector searchOutputs{ OutputPair_t("*", pThis->m_pDesc->m_pName), OutputPair_t("*", "*") };

    if (pCaller)
    {
        searchOutputs.push_back(OutputPair_t(pCaller->GetClassname(), pThis->m_pDesc->m_pName));
        searchOutputs.push_back(OutputPair_t(pCaller->GetClassname(), "*"));
    }

    std::vector<std::string> hookIds;

    if (pCaller)
    {

        for (auto output : searchOutputs)
            if (outputHooksList.find(output) != outputHooksList.end())
                for (auto hookid : outputHooksList.at(output))
                    hookIds.push_back(hookid);
    }

    if (hookIds.size() > 0)
    {
        PluginEvent* preEvent = new PluginEvent("core", nullptr, nullptr);
        std::stringstream preSS;
        std::vector<msgpack::object> preEventData;

        preEventData.push_back(msgpack::object(pThis ? string_format("%p", pThis).c_str() : "0x00000000"));
        preEventData.push_back(msgpack::object(pThis->m_pDesc->m_pName));
        preEventData.push_back(msgpack::object(pActivator ? string_format("%p", pActivator).c_str() : "0x00000000"));
        preEventData.push_back(msgpack::object(pCaller ? string_format("%p", pCaller).c_str() : "0x00000000"));
        preEventData.push_back(msgpack::object(flDelay));

        msgpack::pack(preSS, preEventData);
        for (auto id : hookIds)
        {
            auto result = g_pluginManager->ExecuteEvent("core", "hook:Pre:" + id, preSS.str(), preEvent);
            if (result != EventResult::Continue)
            {
                delete preEvent;
                return;
            }
        }
        delete preEvent;
    }

    TFireOutputInternal(pThis, pActivator, pCaller, value, flDelay);

    if (hookIds.size() > 0)
    {
        PluginEvent* postEvent = new PluginEvent("core", nullptr, nullptr);
        std::stringstream postSS;
        std::vector<msgpack::object> postEventData;

        postEventData.push_back(msgpack::object(string_format("%p", pThis).c_str()));
        postEventData.push_back(msgpack::object(pThis->m_pDesc->m_pName));
        postEventData.push_back(msgpack::object(string_format("%p", pActivator).c_str()));
        postEventData.push_back(msgpack::object(string_format("%p", pCaller).c_str()));
        postEventData.push_back(msgpack::object(flDelay));

        msgpack::pack(postSS, postEventData);
        for (auto id : hookIds)
        {
            auto result = g_pluginManager->ExecuteEvent("core", "hook:Post:" + id, postSS.str(), postEvent);
            if (result != EventResult::Continue)
            {
                delete postEvent;
                return;
            }
        }
        delete postEvent;
    }
}