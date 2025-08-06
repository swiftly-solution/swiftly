#include <scripting/core.h>

#include <entities/system.h>
#include <engine/precacher/precacher.h>
#include <memory/virtual/virtual.h>
#include <memory/gamedata/gamedata.h>
#include <sdk/schema.h>
#include <sdk/access.h>
#include <sdk/game.h>
#include <sdk/components/CTakeDamageInfo.h>
#include <sdk/components/CPlayerPawnComponent.h>
#include <sdk/components/EmitSound_t.h>
#include <sdk/components/CSingleRecipientFilter.h>
#include <tools/crashreporter/crashreporter.h>
#include <utils/common.h>
#include <utils/utils.h>

#include "ehandle.h"

typedef void (*CAttributeList_SetOrAddAttributeValueByName_t)(void*, const char*, float);
typedef void (*CBaseModelEntity_SetBodygroup_t)(void*, const char*, ...);
typedef void (*CBaseModelEntity_SetModel_t)(void*, const char*);
typedef void (*CBaseEntity_TakeDamage)(void*, CTakeDamageInfo*);
typedef SndOpEventGuid_t(*CBaseEntity_EmitSoundFilter)(IRecipientFilter& filter, CEntityIndex ent, const EmitSound_t& params);
typedef void (*CBaseEntity_EmitSoundParams)(void*, const char*, int, float, float);

std::set<uint64_t> classFuncs = {
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("EHandle")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("Spawn")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("Despawn")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("AcceptInput")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("GetClassname")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("GetVData")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("Teleport")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("EmitSound")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("EmitSoundFromEntity")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("TakeDamage")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("CollisionRulesChanged")),
    ((uint64_t)hash_32_fnv1a_const("CBaseModelEntity") << 32 | hash_32_fnv1a_const("SetModel")),
    ((uint64_t)hash_32_fnv1a_const("CBaseModelEntity") << 32 | hash_32_fnv1a_const("SetSolidType")),
    ((uint64_t)hash_32_fnv1a_const("CBaseModelEntity") << 32 | hash_32_fnv1a_const("SetBodygroup")),
    ((uint64_t)hash_32_fnv1a_const("CAttributeList") << 32 | hash_32_fnv1a_const("SetOrAddAttributeValueByName")),
    ((uint64_t)hash_32_fnv1a_const("CBasePlayerController") << 32 | hash_32_fnv1a_const("EntityIndex")),
    ((uint64_t)hash_32_fnv1a_const("CGameSceneNode") << 32 | hash_32_fnv1a_const("GetSkeletonInstance")),
    ((uint64_t)hash_32_fnv1a_const("CPlayerPawnComponent") << 32 | hash_32_fnv1a_const("GetPawn")),
};

std::set<std::string> skipFunctions = {
    "__call",
    "call",
    "__tostring",
    "toString",
    "ToPtr",
    "IsValid"
};

void DummyGetSetSDK(FunctionContext* context, ClassData* data) {}
EValue MakeSDKClassInstance(std::string className, void* ptr, EContext* context)
{
    return MAKE_CLASS_INSTANCE("SDKClass", { { "class_name", className }, { "class_ptr", ptr } });
}

EValue AccessSDK(void* ptr, std::string className, std::string fieldName, EContext* state);
void UpdateSDK(void* ptr, std::string className, std::string fieldName, EValue value, EContext* state);

void SchemaCallback(PluginObject plugin, EContext* ctx) {
    ADD_CLASS("SDKClass");

    ADD_FUNCTION("IsSDKClass", [](FunctionContext* context) -> void {
        context->SetReturn(sch::IsClassLoaded(context->GetArgumentOr<std::string>(0, "").c_str()));
    });

    ADD_FUNCTION("GenerateSDKFactory", [](FunctionContext* context) -> void {
        void* ptr = nullptr;
        auto classData = context->GetArgumentOr<ClassData*>(1, nullptr);
        if (classData) {
            if (classData->HasData("class_ptr")) {
                ptr = classData->GetData<void*>("class_ptr");
            }
            else if (classData->HasData("ptr")) {
                ptr = classData->GetData<void*>("ptr");
            }
            else ptr = (void*)nullptr;
        }
        else {
            auto strptr = context->GetArgumentOr<std::string>(1, "");
            if (starts_with(strptr, "0x")) {
                ptr = (void*)StringToPtr(strptr);
            }
            else ptr = (void*)nullptr;
        }

        context->SetReturn(MAKE_CLASS_INSTANCE("SDKClass", { { "class_name", context->GetArgument<std::string>(0) }, { "class_ptr", ptr } }));
    });

    ADD_CLASS_FUNCTION("SDKClass", "__tostring", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("class_string")) {
            if (!data->HasData("class_ptr")) data->SetData("class_ptr", (void*)nullptr);
            data->SetData("class_string", string_format("%s(ptr=%p)", data->GetData<std::string>("class_name").c_str(), data->GetData<void*>("class_ptr")));
        }
        context->SetReturn(data->GetData<std::string>("class_string"));
    });

    ADD_CLASS_FUNCTION("SDKClass", "IsValid", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(g_entSystem.IsValidEntity(data->GetData<void*>("class_ptr")));
    });

    ADD_CLASS_FUNCTION("SDKClass", "ToPtr", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(string_format("%p", data->GetData<void*>("class_ptr")));
    });

    ADD_CLASS_FUNCTION("SDKClass", "EHandle", [](FunctionContext* context, ClassData* data) -> void {
        CEntityInstance* instance = (CEntityInstance*)data->GetData<void*>("class_ptr");
        context->SetReturn(MakeSDKClassInstance("CBaseEntity", instance->m_pEntity->m_EHandle.Get(), context->GetPluginContext()));
    });

    ADD_CLASS_FUNCTION("SDKClass", "Spawn", [](FunctionContext* context, ClassData* data) -> void {
        void* instance = data->GetData<void*>("class_ptr");
        ClassData* keyvals = context->GetArgumentOr<ClassData*>(0, nullptr);

        if (keyvals && keyvals->HasData("centitykeyvalues_ptr")) {
            g_entSystem.Spawn(instance, (void*)keyvals->GetData<CEntityKeyValues*>("centitykeyvalues_ptr"));
            return;
        }

        g_entSystem.Spawn(instance, nullptr);
    });

    ADD_CLASS_FUNCTION("SDKClass", "Despawn", [](FunctionContext* context, ClassData* data) -> void {
        void* instance = data->GetData<void*>("class_ptr");
        g_entSystem.Despawn(instance);
    });

    ADD_CLASS_FUNCTION("SDKClass", "AcceptInput", [](FunctionContext* context, ClassData* data) -> void {
        void* instance = data->GetData<void*>("class_ptr");
        std::string input = context->GetArgumentOr<std::string>(0, "");
        ClassData* activator = context->GetArgumentOr<ClassData*>(1, nullptr);
        ClassData* caller = context->GetArgumentOr<ClassData*>(2, nullptr);
        std::string value = context->GetArgumentOr<std::string>(3, "");
        int outputID = context->GetArgumentOr<int>(4, 0);

        void* activatorptr = nullptr;
        void* callerptr = nullptr;

        if (activator && activator->HasData("class_ptr"))
            activatorptr = activator->GetData<void*>("class_ptr");
        if (caller && caller->HasData("class_ptr"))
            callerptr = caller->GetData<void*>("class_ptr");

        g_entSystem.AcceptInput(instance, input, activatorptr, callerptr, value, outputID);
    });

    ADD_CLASS_FUNCTION("SDKClass", "GetClassname", [](FunctionContext* context, ClassData* data) -> void {
        CEntityInstance* instance = (CEntityInstance*)data->GetData<void*>("class_ptr");
        context->SetReturn(instance->GetClassname());
    });

    ADD_CLASS_FUNCTION("SDKClass", "GetVData", [](FunctionContext* context, ClassData* data) -> void {
        void* instance = data->GetData<void*>("class_ptr");
        context->SetReturn(MakeSDKClassInstance("CEntitySubclassVDataBase", schema::GetVData(instance), context->GetPluginContext()));
    });

    ADD_CLASS_FUNCTION("SDKClass", "Teleport", [](FunctionContext* context, ClassData* data) -> void {
        void* instance = data->GetData<void*>("class_ptr");
        ClassData* pos = context->GetArgumentOr<ClassData*>(0, nullptr);
        ClassData* ang = context->GetArgumentOr<ClassData*>(1, nullptr);
        ClassData* vel = context->GetArgumentOr<ClassData*>(2, nullptr);

        Vector po(0.0, 0.0, 0.0);
        Vector ve(0.0, 0.0, 0.0);
        QAngle an(0.0, 0.0, 0.0);

        if (pos && pos->HasData("vector_ptr"))
            po = pos->GetDataOr<Vector>("vector_ptr", po);
        if (ang && ang->HasData("QAngle_ptr"))
            an = ang->GetDataOr<QAngle>("QAngle_ptr", an);
        if (vel && vel->HasData("vector_ptr"))
            ve = vel->GetDataOr<Vector>("vector_ptr", ve);

        CALL_VIRTUAL(void, g_GameData.GetOffset("CBaseEntity_Teleport"), instance, &po, &an, &ve);
    });

    ADD_CLASS_FUNCTION("SDKClass", "EmitSound", [](FunctionContext* context, ClassData* data) -> void {
        CEntityInstance* instance = (CEntityInstance*)data->GetData<void*>("class_ptr");
        std::string sound_name = context->GetArgumentOr<std::string>(0, "");
        float pitch = context->GetArgumentOr<float>(1, 0.0f);
        float volume = context->GetArgumentOr<float>(2, 0.0f);

        EmitSound_t params;
        params.m_pSoundName = sound_name.c_str();
        params.m_flVolume = volume;
        params.m_nPitch = pitch;

        CBaseEntity_EmitSoundFilter filter = g_GameData.FetchSignature<CBaseEntity_EmitSoundFilter>("CBaseEntity_EmitSoundFilter");

        for (int i = 1; i <= GetMaxGameClients(); i++) {
            auto controllerPtr = g_pEntitySystem->GetEntityInstance(CEntityIndex(i));
            if (controllerPtr == instance) {
                CSingleRecipientFilter playerfilter(i - 1);
                filter(playerfilter, instance->m_pEntity->m_EHandle.GetEntryIndex(), params);
            }
            else {
                CHandle<CEntityInstance> pawnHandle = schema::GetProp<CHandle<CEntityInstance>>(instance, "CCSPlayerController", "m_hPlayerPawn");
                if (pawnHandle.Get() == instance) {
                    CSingleRecipientFilter playerfilter(i - 1);
                    filter(playerfilter, instance->m_pEntity->m_EHandle.GetEntryIndex(), params);
                }
            }
        }
    });

    ADD_CLASS_FUNCTION("SDKClass", "EmitSoundFromEntity", [](FunctionContext* context, ClassData* data) -> void {
        void* instance = data->GetData<void*>("class_ptr");
        std::string sound_name = context->GetArgumentOr<std::string>(0, "");
        float pitch = context->GetArgumentOr<float>(1, 0.0f);
        float volume = context->GetArgumentOr<float>(2, 0.0f);
        float delay = context->GetArgumentOr<float>(3, 0.0f);

        g_GameData.FetchSignature<CBaseEntity_EmitSoundParams>("CBaseEntity_EmitSoundParams")(instance, sound_name.c_str(), pitch, volume, delay);
    });

    ADD_CLASS_FUNCTION("SDKClass", "TakeDamage", [](FunctionContext* context, ClassData* data) -> void {
        ClassData* attacker = context->GetArgumentOr<ClassData*>(0, nullptr);
        ClassData* inflictor = context->GetArgumentOr<ClassData*>(1, nullptr);
        ClassData* ability = context->GetArgumentOr<ClassData*>(2, nullptr);
        int damageType = context->GetArgumentOr<int>(3, 0);
        float damage = context->GetArgumentOr<float>(4, 0.0f);

        void* pinflictor = nullptr;
        void* pability = nullptr;
        void* pattacker = nullptr;

        if (inflictor && inflictor->HasData("class_name"))
            pinflictor = inflictor->GetData<void*>("class_ptr");
        if (ability && ability->HasData("class_name"))
            pability = ability->GetData<void*>("class_ptr");
        if (ability && attacker->HasData("class_name"))
            pattacker = attacker->GetData<void*>("class_ptr");

        if (!pinflictor) pinflictor = pattacker;

        void* instance = data->GetData<void*>("class_ptr");

        CTakeDamageInfo info(pinflictor, pattacker, pability, damage, damageType);
        g_GameData.FetchSignature<CBaseEntity_TakeDamage>("CBaseEntity_TakeDamage")(instance, &info);
    });

    ADD_CLASS_FUNCTION("SDKClass", "CollisionRulesChanged", [](FunctionContext* context, ClassData* data) -> void {
        void* instance = data->GetData<void*>("class_ptr");
        CALL_VIRTUAL(void, g_GameData.GetOffset("CollisionRulesChanged"), instance);
    });

    ADD_CLASS_FUNCTION("SDKClass", "SetModel", [](FunctionContext* context, ClassData* data) -> void {
        std::string model = context->GetArgumentOr<std::string>(0, "");
        if (model == "") return;

        if (!g_precacher.HasModelInList(model)) {
            g_precacher.AddItem(model);
            PLUGIN_PRINTF("Precacher", "Model '%s' was not precached before and it was added to the list.\n", model.c_str());
            PLUGIN_PRINTF("Precacher", "It may work on the second map change if the model is valid.\n");
        }

        void* instance = data->GetData<void*>("class_ptr");
        g_GameData.FetchSignature<CBaseModelEntity_SetModel_t>("CBaseModelEntity_SetModel")(instance, model.c_str());
    });

    ADD_CLASS_FUNCTION("SDKClass", "SetSolidType", [](FunctionContext* context, ClassData* data) -> void {
        int solidID = context->GetArgumentOr<uint8_t>(0, 0);
        if (solidID < 0) return;

        void* instance = data->GetData<void*>("class_ptr");
        void* collision = schema::GetPropPtr<void>(instance, "CBaseModelEntity", "m_Collision");
        schema::SetProp(collision, "m_nSolidType", "m_nSolidType", solidID);
        CALL_VIRTUAL(void, g_GameData.GetOffset("CollisionRulesChanged"), instance);
    });

    ADD_CLASS_FUNCTION("SDKClass", "SetBodygroup", [](FunctionContext* context, ClassData* data) -> void {
        void* instance = data->GetData<void*>("class_ptr");
        std::string str = context->GetArgumentOr<std::string>(0, "");
        uint64_t value = context->GetArgumentOr<uint64_t>(1, 0);
        g_GameData.FetchSignature<CBaseModelEntity_SetBodygroup_t>("CBaseModelEntity_SetBodygroup")(instance, str.c_str(), value);
    });

    ADD_CLASS_FUNCTION("SDKClass", "SetOrAddAttributeValueByName", [](FunctionContext* context, ClassData* data) -> void {
        void* instance = data->GetData<void*>("class_ptr");
        std::string str = context->GetArgumentOr<std::string>(0, "");
        float value = context->GetArgumentOr<float>(1, 0.0f);
        g_GameData.FetchSignature<CAttributeList_SetOrAddAttributeValueByName_t>("CAttributeList_SetOrAddAttributeValueByName")(instance, str.c_str(), value);
    });

    ADD_CLASS_FUNCTION("SDKClass", "EntityIndex", [](FunctionContext* context, ClassData* data) -> void {
        CEntityInstance* instance = (CEntityInstance*)data->GetData<void*>("class_ptr");
        context->SetReturn(instance->GetEntityIndex().Get());
    });

    ADD_CLASS_FUNCTION("SDKClass", "GetSkeletonInstance", [](FunctionContext* context, ClassData* data) -> void {
        void* instance = data->GetData<void*>("class_ptr");
        context->SetReturn(MakeSDKClassInstance("CSkeletonInstance", CALL_VIRTUAL(void*, g_GameData.GetOffset("CGameSceneNode_GetSkeletonInstance"), instance), context->GetPluginContext()));
    });

    ADD_CLASS_FUNCTION("SDKClass", "GetPawn", [](FunctionContext* context, ClassData* data) -> void {
        CPlayerPawnComponent* instance = (CPlayerPawnComponent*)data->GetData<void*>("class_ptr");
        context->SetReturn(MakeSDKClassInstance("CBasePlayerPawn", instance->m_pPawn, context->GetPluginContext()));
    });

    auto fields = g_sdk.GetProcessedFieldNames();
    for (auto it = fields.begin(); it != fields.end(); ++it) ADD_CLASS_MEMBER("SDKClass", *it, DummyGetSetSDK, DummyGetSetSDK);

    ADD_CLASS_MEMBER_PRE("SDKClass", ".*", [](FunctionContext* context, ClassData* data) -> void {
        std::string className = data->GetData<std::string>("class_name");
        std::string fieldName = explode(context->GetFunctionKey(), " ").back();
        if (skipFunctions.find(fieldName) != skipFunctions.end()) return;

        void* instance = data->GetData<void*>("class_ptr");
        if (!g_entSystem.IsValidEntity(instance)) {
            ReportPreventionIncident("Schema / SDK", string_format("Tried to get member '%s::%s' but the entity is invalid.", className.c_str(), fieldName.c_str()));
            return context->StopExecution();
        }

        context->SetReturn(AccessSDK(data->GetData<void*>("class_ptr"), className, fieldName, context->GetPluginContext()));
        context->StopExecution();
    }, [](FunctionContext* context, ClassData* data) -> void {
        std::string className = data->GetData<std::string>("class_name");
        std::string fieldName = explode(context->GetFunctionKey(), " ").back();

        void* instance = data->GetData<void*>("class_ptr");
        if (!g_entSystem.IsValidEntity(instance)) {
            ReportPreventionIncident("Schema / SDK", string_format("Tried to set member '%s::%s' but the entity is invalid.", className.c_str(), fieldName.c_str()));
            return context->StopExecution();
        }

        UpdateSDK(data->GetData<void*>("class_ptr"), className, fieldName, context->GetArgument<EValue>(0), context->GetPluginContext());
        context->StopExecution();
        });

    ADD_CLASS_FUNCTION_PRE("SDKClass", ".*", [](FunctionContext* context, ClassData* data) -> void {
        std::string function_name = explode(context->GetFunctionKey(), " ").back();
        if (skipFunctions.find(function_name) != skipFunctions.end()) return;

        std::string className = data->GetData<std::string>("class_name");
        uint64_t path = ((uint64_t)hash_32_fnv1a_const(className.c_str()) << 32 | hash_32_fnv1a_const(function_name.c_str()));
        if (classFuncs.find(path) != classFuncs.end()) {
            void* instance = data->GetData<void*>("class_ptr");
            if (!g_entSystem.IsValidEntity(instance)) {
                ReportPreventionIncident("Schema / SDK", string_format("Tried to call function '%s::%s' but the entity is invalid.", className.c_str(), function_name.c_str()));
                return context->StopExecution();
            }
            return;
        }
        else {
            uint64_t parent = ((uint64_t)hash_32_fnv1a_const(className.c_str()) << 32 | hash_32_fnv1a_const("Parent"));

            bool found = false;
            while (g_sdk.ExistsField(parent)) {
                className = g_sdk.GetFieldName(parent);

                path = ((uint64_t)hash_32_fnv1a_const(className.c_str()) << 32 | hash_32_fnv1a_const(function_name.c_str()));

                if (g_sdk.ExistsField(path)) {
                    found = true;
                    break;
                }
                else {
                    parent = ((uint64_t)hash_32_fnv1a_const(className.c_str()) << 32 | hash_32_fnv1a_const("Parent"));
                }
            }

            if (found) {
                void* instance = data->GetData<void*>("class_ptr");
                if (!g_entSystem.IsValidEntity(instance)) {
                    ReportPreventionIncident("Schema / SDK", string_format("Tried to call function '%s::%s' but the entity is invalid.", className.c_str(), function_name.c_str()));
                    return context->StopExecution();
                }
                return;
            }
        }
        context->StopExecution();
    });
}

LoadScriptingComponent(schema, SchemaCallback)