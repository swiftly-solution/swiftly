#include "../../core.h"
#include "../../../../sdk/access/sdkaccess.h"

std::set<uint64_t> classFuncs = {
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("EHandle")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("Spawn")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("Despawn")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("AcceptInput")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("GetClassname")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("GetVData")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("Teleport")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("EmitSound")),
    ((uint64_t)hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("CollisionRulesChanged")),
    ((uint64_t)hash_32_fnv1a_const("CBaseModelEntity") << 32 | hash_32_fnv1a_const("SetModel")),
    ((uint64_t)hash_32_fnv1a_const("CBaseModelEntity") << 32 | hash_32_fnv1a_const("SetSolidType")),
    ((uint64_t)hash_32_fnv1a_const("CBaseModelEntity") << 32 | hash_32_fnv1a_const("SetBodygroup")),
    ((uint64_t)hash_32_fnv1a_const("CAttributeList") << 32 | hash_32_fnv1a_const("SetOrAddAttributeValueByName")),
    ((uint64_t)hash_32_fnv1a_const("CBasePlayerController") << 32 | hash_32_fnv1a_const("EntityIndex")),
    ((uint64_t)hash_32_fnv1a_const("CGameSceneNode") << 32 | hash_32_fnv1a_const("GetSkeletonInstance")),
    ((uint64_t)hash_32_fnv1a_const("CPlayerPawnComponent") << 32 | hash_32_fnv1a_const("GetPawn")),
};

SDKBaseClass* SDKBaseClass_SetData(SDKBaseClass* th, EValue val) {
    if (val.isInstance<SDKBaseClass>()) {
        th->SetPtr(val.cast<SDKBaseClass*>()->GetPtr());
    } else if (val.isString()) {
        auto str = val.cast<std::string>();
        if (starts_with(str, "0x"))
            th->SetPtr((void*)(strtol(str.c_str(), nullptr, 16)));
        else
            throw std::runtime_error(string_format("Invalid pointer: %s", str.c_str()));
    }
    else {
        throw std::runtime_error("Invalid pointer or object.");
    }
    return th;
}

int SDKBaseClass_GetProp(lua_State* state)
{
    EContext* ctx = GetContextByState(state);
    SDKBaseClass *th = EValue::fromLuaStack(ctx, 1).cast<SDKBaseClass*>();
    std::string field_name = EValue::fromLuaStack(ctx, 2).cast<std::string>();

    uint64_t path = (th->classOffset | hash_32_fnv1a_const(field_name.c_str()));

    if (field_name == "IsValid" || field_name == "ToPtr" || classFuncs.find(path) != classFuncs.end()) return CHelpers::indexMetaMethod(state);

    uint64_t id = g_callStack->RegisterPluginCallstack(FetchPluginName(ctx), string_format("SDK Get: %s::%s(ptr=%p)", th->m_className.c_str(), field_name.c_str(), th->GetPtr()));
    th->AccessSDK(field_name, path, ctx).pushLua();
    g_callStack->UnregisterPluginCallstack(FetchPluginName(ctx), id);
    return 1;
}

int SDKBaseClass_SetProp(lua_State* state)
{
    EContext* ctx = GetContextByState(state);
    SDKBaseClass *th = EValue::fromLuaStack(ctx, 1).cast<SDKBaseClass*>();
    std::string field_name = EValue::fromLuaStack(ctx, 2).cast<std::string>();
    EValue val = EValue::fromLuaStack(ctx, 3);

    uint64_t id = g_callStack->RegisterPluginCallstack(FetchPluginName(ctx), string_format("SDK Set: %s::%s(ptr=%p,value=%s)", th->m_className.c_str(), field_name.c_str(), th->GetPtr(), val.tostring()));

    th->UpdateSDK(field_name, val, ctx);

    g_callStack->UnregisterPluginCallstack(FetchPluginName(ctx), id);
    return 0;
}

int SDKBaseClass_CallProp(lua_State* state)
{
    EContext* ctx = GetContextByState(state);
    SDKBaseClass *th = EValue::fromLuaStack(ctx, 1).cast<SDKBaseClass*>();
    auto val = EValue::fromLuaStack(ctx, 2);
    SDKBaseClass_SetData(th, val);
    EValue(ctx, th).pushLua();
    return 1;
}

JSValue SDKBaseClass__GetProp(JSContext* ctx, JSValue this_obj, int argc, JSValue* argv)
{
    EContext* ct = GetContextByState(ctx);
    SDKBaseClass* th = EValue::fromJSStack(ct, argv[2]).cast<SDKBaseClass*>();
    std::string field_name = EValue::fromJSStack(ct, argv[1]).cast<std::string>();

    uint64_t path = (th->classOffset | hash_32_fnv1a_const(field_name.c_str()));

    if (field_name == "IsValid" || field_name == "call" || field_name == "ToPtr" || field_name == "toString" || classFuncs.find(path) != classFuncs.end()) {
        EValue v(ct, argv[0]);
        EValue newv = v[field_name];
        JSValue val = newv.pushJS();
        return val;
    }
    
    uint64_t id = g_callStack->RegisterPluginCallstack(FetchPluginName(ct), string_format("SDK Get: %s::%s(ptr=%p)", th->m_className.c_str(), field_name.c_str(), th->GetPtr()));
    JSValue val = Stack<EValue>::pushJS(ct, th->AccessSDK(field_name, path, ct));
    g_callStack->UnregisterPluginCallstack(FetchPluginName(ct), id);
    return val;
}

JSValue SDKBaseClass__SetProp(JSContext* ctx, JSValue this_obj, int argc, JSValue* argv)
{
    EContext* ct = GetContextByState(ctx);
    SDKBaseClass* th = EValue::fromJSStack(ct, argv[3]).cast<SDKBaseClass*>();
    std::string field_name = EValue::fromJSStack(ct, argv[1]).cast<std::string>();
    EValue val = EValue::fromJSStack(ct, argv[2]);

    uint64_t id = g_callStack->RegisterPluginCallstack(FetchPluginName(ct), string_format("SDK Set: %s::%s(ptr=%p,value=%s)", th->m_className.c_str(), field_name.c_str(), th->GetPtr(), val.tostring()));
    th->UpdateSDK(field_name, val, ct);
    g_callStack->UnregisterPluginCallstack(FetchPluginName(ct), id);
    return JS_UNDEFINED;
}

JSValue SDKBaseClass__CallProp(JSContext* ctx, JSValue this_obj, int argc, JSValue* argv)
{
    EContext* ct = GetContextByState(ctx);
    SDKBaseClass* th = EValue::fromJSStack(ct, this_obj).cast<SDKBaseClass*>();
    auto val = EValue::fromJSStack(ct, argv[0]);

    SDKBaseClass_SetData(th, val);
    return JS_DupValue(ctx, EValue(ct, th).pushJS());
}

int CBaseEntity_SpawnLua(lua_State* state) {
    SDKBaseClass* ptr = EValue::fromLuaStack(GetContextByState(state), 1).cast<SDKBaseClass*>();
    EValue ref = EValue::fromLuaStack(GetContextByState(state), 2);
    if (ref.isInstance<PluginCEntityKeyValues*>()) {
        auto kv = ref.cast<PluginCEntityKeyValues*>();
        ptr->CBaseEntity_Spawn(kv);
    }
    else
        ptr->CBaseEntity_Spawn(nullptr);
    return 0;
}

int CBaseEntity_TeleportLua(lua_State* L)
{
    SDKBaseClass* ptr = EValue::fromLuaStack(GetContextByState(L), 1).cast<SDKBaseClass*>();
    auto pos = EValue::fromLuaStack(GetContextByState(L), 2);
    auto ang = EValue::fromLuaStack(GetContextByState(L), 3);
    auto vel = EValue::fromLuaStack(GetContextByState(L), 4);
    Vector po(0.0, 0.0, 0.0), ve(0.0, 0.0, 0.0);
    QAngle an(0.0, 0.0, 0.0);
    if (pos.isInstance<Vector>())
        po = pos.cast<Vector>();
    if (ang.isInstance<QAngle>())
        an = ang.cast<QAngle>();
    if (vel.isInstance<Vector>())
        ve = vel.cast<Vector>();

    ptr->CBaseEntity_Teleport(po, an, ve);
    return 0;
}

JSValue CBaseEntity_SpawnJS(JSContext* ctx, JSValue this_arg, int argc, JSValue* argv)
{
    SDKBaseClass* ptr = EValue::fromJSStack(GetContextByState(ctx), this_arg).cast<SDKBaseClass*>();
    if(argc == 1) {
        EValue ref = EValue::fromJSStack(GetContextByState(ctx), argv[0]);
        if (ref.isInstance<PluginCEntityKeyValues>()) {
            auto kv = ref.cast<PluginCEntityKeyValues*>();
            ptr->CBaseEntity_Spawn(kv);
        }
        else
            ptr->CBaseEntity_Spawn(nullptr);
    } else {
        ptr->CBaseEntity_Spawn(nullptr);
    }
    return JS_UNDEFINED;
}

JSValue CBaseEntity_TeleportJS(JSContext* ctx, JSValue this_arg, int argc, JSValue* argv)
{
    SDKBaseClass* ptr = EValue::fromJSStack(GetContextByState(ctx), this_arg).cast<SDKBaseClass*>();
    Vector po(0.0, 0.0, 0.0), ve(0.0, 0.0, 0.0);
    QAngle an(0.0, 0.0, 0.0);
    if(argc >= 1) {
        auto pos = EValue::fromJSStack(GetContextByState(ctx), argv[0]);
        if(pos.isInstance<Vector>())
            po = pos.cast<Vector>();
    }
    if(argc >= 2) {
        auto ang = EValue::fromJSStack(GetContextByState(ctx), argv[1]);
        if(ang.isInstance<QAngle>())
            an = ang.cast<QAngle>();
    }
    if(argc >= 3) {
        auto vel = EValue::fromJSStack(GetContextByState(ctx), argv[2]);
        if(vel.isInstance<Vector>())
            ve = vel.cast<Vector>();
    }

    ptr->CBaseEntity_Teleport(po, an, ve);
    return JS_UNDEFINED;
}

std::string SDKBaseClass_tostring(SDKBaseClass* basecls)
{
    return string_format("%s(ptr=%p)", basecls->GetClassName().c_str(), basecls->GetPtr());
}

bool IsSDKClass(std::string key) {
    return sch::IsClassLoaded(key.c_str());
}

SDKBaseClass GenerateSDKFactory(std::string className) {
    return SDKBaseClass(nullptr, className);
}

void SchemaLoad(Plugin* plugin, EContext* state)
{
    GetGlobalNamespace(state)
        .addFunction("IsSDKClass", IsSDKClass)
        .addFunction("GenerateSDKFactory", GenerateSDKFactory);

    BeginClass<SDKBaseClass>("SDKBaseClass", state)
        .addConstructor<std::string, std::string>()
        .addFunction("EntityIndex", &SDKBaseClass::CBasePlayerController_EntityIndex)
        .addFunction("SetModel", &SDKBaseClass::CBaseModelEntity_SetModel)
        .addFunction("SetSolidType", &SDKBaseClass::CBaseModelEntity_SetSolidType)
        .addFunction("SetBodygroup", &SDKBaseClass::CBaseModelEntity_SetBodygroup)
        .addFunction("SetOrAddAttributeValueByName", &SDKBaseClass::CAttributeList_SetOrAddAttributeValueByName)
        .addFunction("EHandle", &SDKBaseClass::CBaseEntity_EHandle)
        .addLuaFunction("Spawn", CBaseEntity_SpawnLua)
        .addJSFunction("Spawn", CBaseEntity_SpawnJS)
        .addFunction("Despawn", &SDKBaseClass::CBaseEntity_Despawn)
        .addFunction("AcceptInput", &SDKBaseClass::CBaseEntity_AcceptInput)
        .addFunction("GetClassname", &SDKBaseClass::CBaseEntity_GetClassname)
        .addFunction("GetVData", &SDKBaseClass::CBaseEntity_GetVData)
        .addLuaFunction("Teleport", CBaseEntity_TeleportLua)
        .addJSFunction("Teleport", CBaseEntity_TeleportJS)
        .addFunction("EmitSound", &SDKBaseClass::CBaseEntity_EmitSound)
        .addFunction("CollisionRulesChanged", &SDKBaseClass::CBaseEntity_CollisionRulesChanged)
        .addFunction("GetSkeletonInstance", &SDKBaseClass::CGameSceneNode_GetSkeletonInstance)
        .addFunction("GetPawn", &SDKBaseClass::CPlayerPawnComponent_GetPawn)
        .addLuaFunction("__index", SDKBaseClass_GetProp)
        .addLuaFunction("__newindex", SDKBaseClass_SetProp)
        .addLuaFunction("__call", SDKBaseClass_CallProp)
        .addJSFunction("call", SDKBaseClass__CallProp)
        .addFunction("IsValid", &SDKBaseClass::IsValid)
        .addFunction("ToPtr", &SDKBaseClass::ToPtr)
        .addLuaFunction("__tostring", SDKBaseClass_tostring)
        .addJSFunction("toString", SDKBaseClass_tostring)
        .addJSCustomIndex(SDKBaseClass__GetProp, SDKBaseClass__SetProp)
    .endClass();
}

LoadScriptingComponent(
    schema,
    SchemaLoad
)
