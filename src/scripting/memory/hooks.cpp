#include <scripting/core.h>

#include <memory/hooks/manager.h>
#include <utils/common.h>
#include <plugins/manager.h>

#include "ehandle.h"

/*
    Args List Convention
        - p -> Pointer
        - b -> Boolean
        - f -> Float
        - d -> Double
        - i -> Integer 32-bit
        - u -> Unsigned Integer 32-bit
        - s -> const char*
        - I -> Integer 64-bit
        - U -> Unsigned Integer 64-bit
        - v -> Void
*/

struct Hook
{
    void* hookPtrPre;
    void* hookPtrPost;
    std::string argsList;
    char retType;
    std::string id;
    bool isVirtual;
};

struct EntityIOConnectionDesc_t
{
    string_t m_targetDesc;
    string_t m_targetInput;
    string_t m_valueOverride;
    CEntityHandle m_hTarget;
    EntityIOTargetType_t m_nTargetType;
    int32 m_nTimesToFire;
    float m_flDelay;
};

struct EntityIOConnection_t : EntityIOConnectionDesc_t
{
    bool m_bMarkedForRemoval;
    EntityIOConnection_t* m_pNext;
};

struct EntityIOOutputDesc_t
{
    const char* m_pName;
    uint32 m_nFlags;
    uint32 m_nOutputOffset;
};

class CEntityIOOutput
{
public:
    void* vtable;
    EntityIOConnection_t* m_pConnections;
    EntityIOOutputDesc_t* m_pDesc;
};

std::map<dyno::IHook*, std::vector<Hook>> hooksList;
std::map<std::string, dyno::IHook*> hooksMap;
std::map<uint64_t, std::vector<std::string>> outputHooksList;

dyno::ReturnAction HookCallback(dyno::CallbackType type, dyno::IHook& hook) {
    dyno::IHook* hptr = &hook;

    std::string callbackType = (type == dyno::CallbackType::Pre ? "Pre" : "Post");
    if (hooksList.find(hptr) == hooksList.end())
        return dyno::ReturnAction::Ignored;

    ClassData* ev = new ClassData({ { "plugin_name", std::string("core") }, { "hook_ptr", hptr } }, "Event", nullptr);
    for (auto hk : hooksList[hptr])
    {
        printf("Hook called: %s\n", hk.id.c_str());
        if (g_pluginManager.ExecuteEvent("core", "hook:" + callbackType + ":" + hk.id, {}, ev) != EventResult::Continue) {
            delete ev;
            return dyno::ReturnAction::Supercede;
        }
    }

    delete ev;
    return dyno::ReturnAction::Ignored;
}

dyno::ReturnAction Hook_FireOutputInternal(dyno::CallbackType type, dyno::IHook& hook) {
    CEntityIOOutput* pThis = hook.getArgument<CEntityIOOutput*>(0);
    CEntityInstance* pActivator = hook.getArgument<CEntityInstance*>(1);
    CEntityInstance* pCaller = hook.getArgument<CEntityInstance*>(2);
    float delay = hook.getArgument<float>(4);

    std::vector searchOutputs{
        ((uint64_t)hash_32_fnv1a_const("*") << 32 | hash_32_fnv1a_const(pThis->m_pDesc->m_pName)),
        ((uint64_t)hash_32_fnv1a_const("*") << 32 | hash_32_fnv1a_const("*"))
    };

    if (pCaller)
    {
        searchOutputs.push_back(((uint64_t)hash_32_fnv1a_const(pCaller->GetClassname()) << 32 | hash_32_fnv1a_const(pThis->m_pDesc->m_pName)));
        searchOutputs.push_back(((uint64_t)hash_32_fnv1a_const(pCaller->GetClassname()) << 32 | hash_32_fnv1a_const("*")));
    }

    std::vector<std::string> hookIds;

    if (pCaller)
        for (auto output : searchOutputs)
            for (auto hookid : outputHooksList[output])
                hookIds.push_back(hookid);

    if (hookIds.size() > 0)
    {
        ClassData* ev = new ClassData({ { "plugin_name", std::string("core") } }, "Event", nullptr);

        ClassData* entIOOutput = new ClassData({ { "class_name", std::string("CEntityIOOutput") }, { "class_ptr", (void*)pThis } }, "SDKClass", nullptr);
        ClassData* Activator = new ClassData({ { "class_name", std::string("CEntityInstance") }, { "class_ptr", (void*)pActivator } }, "SDKClass", nullptr);
        ClassData* Caller = new ClassData({ { "class_name", std::string("CEntityInstance") }, { "class_ptr", (void*)pCaller } }, "SDKClass", nullptr);

        for (auto id : hookIds)
        {
            auto result = g_pluginManager.ExecuteEvent("core", std::string("hook:") + (type == dyno::CallbackType::Pre ? "Pre" : "Post") + ":" + id, {
                entIOOutput,
                pThis->m_pDesc->m_pName,
                Activator,
                Caller,
                delay
            }, ev);
            if (result != EventResult::Continue)
            {
                delete entIOOutput;
                delete Activator;
                delete Caller;
                delete ev;
                return dyno::ReturnAction::Supercede;
            }
        }

        delete entIOOutput;
        delete Activator;
        delete Caller;
        delete ev;
    }

    return dyno::ReturnAction::Ignored;
}

FunctionHook FireOutputInternalPre("FireOutputInternal", dyno::CallbackType::Pre, Hook_FireOutputInternal, "ppppf", 'v');
FunctionHook FireOutputInternalPost("FireOutputInternal", dyno::CallbackType::Post, Hook_FireOutputInternal, "ppppf", 'v');

LoadScriptingComponent(hooks, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("Hooks");

    ADD_CLASS_FUNCTION("Hooks", "Hooks", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("hooks_arr", std::vector<Hook>{});
    });

    ADD_CLASS_FUNCTION("Hooks", "~Hooks", [](FunctionContext* context, ClassData* data) -> void {
        std::vector<Hook> hookArr = data->GetData<std::vector<Hook>>("hooks_arr");

        for (auto hk : hookArr) {
            auto hksMap = hooksMap[hk.id];
            if (hksMap) {
                for (auto it = hooksList[hksMap].begin(); it != hooksList[hksMap].end(); ++it) {
                    if ((*it).id == hk.id) {
                        hooksList[hksMap].erase(it);
                        break;
                    }
                }
            }

            hooksMap.erase(hk.id);

            if (!hk.isVirtual) {
                delete ((FunctionHook*)hk.hookPtrPre);
                delete ((FunctionHook*)hk.hookPtrPost);
            }
            else {
                delete ((VFunctionHook*)hk.hookPtrPre);
                delete ((VFunctionHook*)hk.hookPtrPost);
            }
        }
    });

    ADD_CLASS_FUNCTION("Hooks", "Add", [](FunctionContext* context, ClassData* data) -> void {
        auto classData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!classData) return;

        void* ptr = classData->GetDataOr<void*>("ptr", nullptr);
        if (!ptr) return;

        std::string args_list = context->GetArgumentOr<std::string>(1, "");
        char ret_type = context->GetArgumentOr<std::string>(2, "v").at(0);

        std::string id = get_uuid();
        Hook hk = {
            new FunctionHook(ptr, dyno::CallbackType::Pre, HookCallback, args_list, ret_type),
            new FunctionHook(ptr, dyno::CallbackType::Post, HookCallback, args_list, ret_type),
            args_list,
            ret_type,
            id,
            false
        };

        auto foundhook = ((FunctionHook*)(hk.hookPtrPre))->GetHookFunction();
        hooksList[foundhook].push_back(hk);

        std::vector<Hook> hookArr = data->GetData<std::vector<Hook>>("hooks_arr");
        hookArr.push_back(hk);
        data->SetData("hooks_arr", hookArr);

        context->SetReturn(id);
    });

    ADD_CLASS_FUNCTION("Hooks", "AddVirtual", [](FunctionContext* context, ClassData* data) -> void {
        std::string library = context->GetArgumentOr<std::string>(0, "");
        std::string vtable_name = context->GetArgumentOr<std::string>(1, "");
        std::string offset = context->GetArgumentOr<std::string>(2, "");

        std::string args_list = context->GetArgumentOr<std::string>(3, "");
        char ret_type = context->GetArgumentOr<std::string>(4, "v").at(0);

        std::string id = get_uuid();
        Hook hk = {
            new VFunctionHook(library, vtable_name, offset, dyno::CallbackType::Pre, HookCallback, args_list, ret_type),
            new VFunctionHook(library, vtable_name, offset, dyno::CallbackType::Post, HookCallback, args_list, ret_type),
            args_list,
            ret_type,
            id,
            true
        };

        auto foundhook = ((VFunctionHook*)(hk.hookPtrPre))->GetHookFunction();
        hooksList[foundhook].push_back(hk);

        std::vector<Hook> hookArr = data->GetData<std::vector<Hook>>("hooks_arr");
        hookArr.push_back(hk);
        data->SetData("hooks_arr", hookArr);

        context->SetReturn(id);
    });

    ADD_CLASS_FUNCTION("Hooks", "Call", [](FunctionContext* context, ClassData* data) -> void {
        std::string hookID = context->GetArgumentOr<std::string>(0, "");
        if (hookID == "") return;

        std::vector<std::any> hookPayload = context->GetArgumentOr<std::vector<std::any>>(1, std::vector<std::any>{});
        if (hooksMap.find(hookID) == hooksMap.end()) return;

        auto hook = hooksMap[hookID];
        if (hooksList.find(hook) == hooksList.end()) return;
        if (hooksList[hook].size() <= 0) return;

        auto hk = hooksList[hook][0];

        if (!hk.isVirtual) {
            context->SetReturn(((FunctionHook*)hk.hookPtrPre)->Call(hookPayload));
        }
        else {
            context->SetReturn(((VFunctionHook*)hk.hookPtrPre)->Call(hookPayload));
        }
    });

    ADD_CLASS_FUNCTION("Hooks", "AddEntityOutputHook", [](FunctionContext* context, ClassData* data) -> void {
        std::string classname = context->GetArgumentOr<std::string>(0, "");
        std::string output = context->GetArgumentOr<std::string>(1, "");

        std::string id = get_uuid();
        uint64_t outputKey = ((uint64_t)hash_32_fnv1a_const(classname.c_str()) << 32 | hash_32_fnv1a_const(output.c_str()));

        if (outputHooksList.find(outputKey) == outputHooksList.end())
            outputHooksList.insert({ outputKey, {} });

        outputHooksList[outputKey].push_back(id);
        context->SetReturn(id);
    });

    ADD_CLASS_FUNCTION("Event", "IsHook", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->HasData("hook_ptr"));
    });

    ADD_CLASS_FUNCTION("Event", "GetHookBool", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return context->SetReturn(false);

        int index = context->GetArgumentOr<int>(0, 0);
        context->SetReturn(data->GetData<dyno::IHook*>("hook_ptr")->getArgument<bool>(index));
    });

    ADD_CLASS_FUNCTION("Event", "GetHookInt", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return context->SetReturn(0);

        int index = context->GetArgumentOr<int>(0, 0);
        context->SetReturn(data->GetData<dyno::IHook*>("hook_ptr")->getArgument<int>(index));
    });

    ADD_CLASS_FUNCTION("Event", "GetHookUint64", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return context->SetReturn(0);

        int index = context->GetArgumentOr<int>(0, 0);
        context->SetReturn(data->GetData<dyno::IHook*>("hook_ptr")->getArgument<uint64_t>(index));
    });

    ADD_CLASS_FUNCTION("Event", "GetHookFloat", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return context->SetReturn(0.0);

        int index = context->GetArgumentOr<int>(0, 0);
        context->SetReturn(data->GetData<dyno::IHook*>("hook_ptr")->getArgument<float>(index));
    });

    ADD_CLASS_FUNCTION("Event", "GetHookString", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return context->SetReturn("");

        int index = context->GetArgumentOr<int>(0, 0);
        context->SetReturn(std::string(data->GetData<dyno::IHook*>("hook_ptr")->getArgument<const char*>(index)));
    });

    ADD_CLASS_FUNCTION("Event", "GetHookPointer", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return context->SetReturn(MAKE_CLASS_INSTANCE("Memory", { { "ptr", nullptr } }));

        int index = context->GetArgumentOr<int>(0, 0);
        context->SetReturn(MAKE_CLASS_INSTANCE("Memory", { { "ptr", data->GetData<dyno::IHook*>("hook_ptr")->getArgument<void*>(index) } }));
    });

    ADD_CLASS_FUNCTION("Event", "GetHookDouble", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return context->SetReturn(0.0);

        int index = context->GetArgumentOr<int>(0, 0);
        context->SetReturn(data->GetData<dyno::IHook*>("hook_ptr")->getArgument<double>(index));
    });

    ADD_CLASS_FUNCTION("Event", "GetHookUInt", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return context->SetReturn(0);

        int index = context->GetArgumentOr<int>(0, 0);
        context->SetReturn(data->GetData<dyno::IHook*>("hook_ptr")->getArgument<uint32_t>(index));
    });

    ADD_CLASS_FUNCTION("Event", "GetHookInt64", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return context->SetReturn(0);

        int index = context->GetArgumentOr<int>(0, 0);
        context->SetReturn(data->GetData<dyno::IHook*>("hook_ptr")->getArgument<int64_t>(index));
    });

    ADD_CLASS_FUNCTION("Event", "GetHookInt64", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return context->SetReturn(0);

        int index = context->GetArgumentOr<int>(0, 0);
        context->SetReturn(data->GetData<dyno::IHook*>("hook_ptr")->getArgument<int64_t>(index));
    });

    ADD_CLASS_FUNCTION("Event", "GetHookReturn", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return context->SetReturn(nullptr);

        auto hookPtr = data->GetData<dyno::IHook*>("hook_ptr");

        if (hooksList.find(hookPtr) == hooksList.end())
            return context->SetReturn(nullptr);

        if (hooksList[hookPtr].size() <= 0)
            return context->SetReturn(nullptr);

        Hook hk = hooksList[hookPtr][0];
        if (hk.retType == 0)
            return context->SetReturn(nullptr);

        if (hk.retType == 'p')
            return context->SetReturn(MAKE_CLASS_INSTANCE("Memory", { { "ptr", hookPtr->getReturn<void*>() } }));
        else if (hk.retType == 'f')
            return context->SetReturn(hookPtr->getReturn<float>());
        else if (hk.retType == 'b')
            return context->SetReturn(hookPtr->getReturn<bool>());
        else if (hk.retType == 'd')
            return context->SetReturn(hookPtr->getReturn<double>());
        else if (hk.retType == 'i')
            return context->SetReturn(hookPtr->getReturn<int32_t>());
        else if (hk.retType == 'u')
            return context->SetReturn(hookPtr->getReturn<uint32_t>());
        else if (hk.retType == 's')
            return context->SetReturn(std::string(hookPtr->getReturn<const char*>()));
        else if (hk.retType == 'I')
            return context->SetReturn(hookPtr->getReturn<int64_t>());
        else if (hk.retType == 'U')
            return context->SetReturn(hookPtr->getReturn<uint64_t>());
        else
        {
            PRINTF("Invalid argument in return value: '%c'.\n", hk.retType);
            return context->SetReturn(nullptr);
        }
    });

    ADD_CLASS_FUNCTION("Event", "SetHookBool", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return;

        auto hookPtr = data->GetData<dyno::IHook*>("hook_ptr");
        int index = context->GetArgumentOr<int>(0, 0);
        bool value = context->GetArgumentOr<bool>(1, false);

        hookPtr->setArgument(index, value);
    });

    ADD_CLASS_FUNCTION("Event", "SetHookInt", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return;

        auto hookPtr = data->GetData<dyno::IHook*>("hook_ptr");
        int index = context->GetArgumentOr<int>(0, 0);
        int value = context->GetArgumentOr<int>(1, 0);

        hookPtr->setArgument(index, value);
    });

    ADD_CLASS_FUNCTION("Event", "SetHookUint64", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return;

        auto hookPtr = data->GetData<dyno::IHook*>("hook_ptr");
        int index = context->GetArgumentOr<int>(0, 0);
        uint64_t value = context->GetArgumentOr<uint64_t>(1, 0);

        hookPtr->setArgument(index, value);
    });

    ADD_CLASS_FUNCTION("Event", "SetHookFloat", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return;

        auto hookPtr = data->GetData<dyno::IHook*>("hook_ptr");
        int index = context->GetArgumentOr<int>(0, 0);
        float value = context->GetArgumentOr<float>(1, 0.0f);

        hookPtr->setArgument(index, value);
    });

    ADD_CLASS_FUNCTION("Event", "SetHookString", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return;

        auto hookPtr = data->GetData<dyno::IHook*>("hook_ptr");
        int index = context->GetArgumentOr<int>(0, 0);
        std::string value = context->GetArgumentOr<std::string>(1, "");

        hookPtr->setArgument(index, value.c_str());
    });

    ADD_CLASS_FUNCTION("Event", "SetHookPointer", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return;

        auto hookPtr = data->GetData<dyno::IHook*>("hook_ptr");
        int index = context->GetArgumentOr<int>(0, 0);
        ClassData* value = context->GetArgumentOr<ClassData*>(1, nullptr);
        if (!value) return;

        void* mem = value->GetDataOr<void*>("ptr", nullptr);

        hookPtr->setArgument(index, mem);
    });

    ADD_CLASS_FUNCTION("Event", "SetHookDouble", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return;

        auto hookPtr = data->GetData<dyno::IHook*>("hook_ptr");
        int index = context->GetArgumentOr<int>(0, 0);
        double value = context->GetArgumentOr<double>(1, 0.0f);

        hookPtr->setArgument(index, value);
    });

    ADD_CLASS_FUNCTION("Event", "SetHookUInt", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return;

        auto hookPtr = data->GetData<dyno::IHook*>("hook_ptr");
        int index = context->GetArgumentOr<int>(0, 0);
        uint32_t value = context->GetArgumentOr<uint32_t>(1, 0);

        hookPtr->setArgument(index, value);
    });

    ADD_CLASS_FUNCTION("Event", "SetHookInt64", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return;

        auto hookPtr = data->GetData<dyno::IHook*>("hook_ptr");
        int index = context->GetArgumentOr<int>(0, 0);
        int64_t value = context->GetArgumentOr<int64_t>(1, 0);

        hookPtr->setArgument(index, value);
    });

    ADD_CLASS_FUNCTION("Event", "SetHookReturn", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("hook_ptr")) return;

        auto hookPtr = data->GetData<dyno::IHook*>("hook_ptr");
        std::any value = context->GetArgumentOr<std::any>(0, 0);

        if (!value.has_value())
            return;

        try
        {
            if (value.type() == typeid(const char*))
                return hookPtr->setReturn(std::any_cast<const char*>(value));
            else if (value.type() == typeid(std::string))
                return hookPtr->setReturn(std::any_cast<std::string>(value).c_str());
            else if (value.type() == typeid(uint64))
                return hookPtr->setReturn(std::any_cast<uint64>(value));
            else if (value.type() == typeid(uint32))
                return hookPtr->setReturn(std::any_cast<uint32>(value));
            else if (value.type() == typeid(unsigned long))
                return hookPtr->setReturn(std::any_cast<unsigned long>(value));
            else if (value.type() == typeid(uint16))
                return hookPtr->setReturn(std::any_cast<uint16>(value));
            else if (value.type() == typeid(uint8))
                return hookPtr->setReturn(std::any_cast<uint8>(value));
            else if (value.type() == typeid(int64))
                return hookPtr->setReturn(std::any_cast<int64>(value));
            else if (value.type() == typeid(int32))
                return hookPtr->setReturn(std::any_cast<int32>(value));
            else if (value.type() == typeid(long))
                return hookPtr->setReturn(std::any_cast<long>(value));
            else if (value.type() == typeid(int16))
                return hookPtr->setReturn(std::any_cast<int16>(value));
            else if (value.type() == typeid(int8))
                return hookPtr->setReturn(std::any_cast<int8>(value));
            else if (value.type() == typeid(bool))
                return hookPtr->setReturn(std::any_cast<bool>(value));
            else if (value.type() == typeid(float))
                return hookPtr->setReturn(std::any_cast<float>(value));
            else if (value.type() == typeid(ClassData*))
                return hookPtr->setReturn(std::any_cast<ClassData*>(value)->GetDataOr<void*>("ptr", nullptr));
            else if (value.type() == typeid(double))
                return hookPtr->setReturn(std::any_cast<double>(value));
            else if (value.type() == typeid(std::nullptr_t))
                return hookPtr->setReturn(0);
            else
                PRINTF("Unknown Data Type: %s\n", value.type().name());
        }
        catch (std::bad_any_cast& err)
        {
            PRINTF("Invalid casting: %s\n", err.what());
        }
    });
});