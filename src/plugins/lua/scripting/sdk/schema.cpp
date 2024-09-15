#include "../core.h"
#include "../../../../sdk/sdkaccess.h"

std::set<uint64_t> classFuncs = {
    ((uint64_t) hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("EHandle")),
    ((uint64_t) hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("Spawn")),
    ((uint64_t) hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("Despawn")),
    ((uint64_t) hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("AcceptInput")),
    ((uint64_t) hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("GetClassname")),
    ((uint64_t) hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("GetVData")),
    ((uint64_t) hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("Teleport")),
    ((uint64_t) hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("EmitSound")),
    ((uint64_t) hash_32_fnv1a_const("CBaseEntity") << 32 | hash_32_fnv1a_const("CollisionRulesChanged")),
    ((uint64_t) hash_32_fnv1a_const("CBaseModelEntity") << 32 | hash_32_fnv1a_const("SetModel")),
    ((uint64_t) hash_32_fnv1a_const("CBaseModelEntity") << 32 | hash_32_fnv1a_const("SetSolidType")),
    ((uint64_t) hash_32_fnv1a_const("CBaseModelEntity") << 32 | hash_32_fnv1a_const("SetBodygroup")),
    ((uint64_t) hash_32_fnv1a_const("CAttributeList") << 32 | hash_32_fnv1a_const("SetOrAddAttributeValueByName")),
    ((uint64_t) hash_32_fnv1a_const("CBasePlayerController") << 32 | hash_32_fnv1a_const("EntityIndex")),
    ((uint64_t) hash_32_fnv1a_const("CGameSceneNode") << 32 | hash_32_fnv1a_const("GetSkeletonInstance")),
    ((uint64_t) hash_32_fnv1a_const("CPlayerPawnComponent") << 32 | hash_32_fnv1a_const("GetPawn")),
};

int SDKBaseClass::GetProp(lua_State* state)
{
    std::string field_name = luabridge::LuaRef::fromStack(state, 2).cast<std::string>();

    uint64_t path = ((uint64_t) hash_32_fnv1a_const(this->m_className.c_str()) << 32 | hash_32_fnv1a_const(field_name.c_str()));

    if (field_name == "IsValid" || field_name == "ToPtr" || classFuncs.find(path) != classFuncs.end()) return luabridge::detail::CFunc::indexMetaMethod(state);
    
    this->AccessSDKLua(field_name, path, state).push();
    return 1;
}

int SDKBaseClass::SetProp(lua_State* state)
{
    this->UpdateSDKLua(luabridge::LuaRef::fromStack(state, 2).cast<std::string>(), luabridge::LuaRef::fromStack(state, 3), state);
    return 0;
}

void SetupLuaClasses(LuaPlugin* plugin, lua_State* state)
{
    auto classnames = g_sdk->GetClassnames();
    for (size_t i = 0; i < classnames.size(); i++) {
        auto cls = luabridge::getGlobalNamespace(state).beginClass<SDKBaseClass>(classnames[i].c_str());
        cls.addConstructor<void(*)(std::string, lua_State*)>();
        cls.addFunction("EntityIndex", &SDKBaseClass::CBasePlayerController_EntityIndex);
        cls.addFunction("SetModel", &SDKBaseClass::CBaseModelEntity_SetModel);
        cls.addFunction("SetSolidType", &SDKBaseClass::CBaseModelEntity_SetSolidType);
        cls.addFunction("SetBodygroup", &SDKBaseClass::CBaseModelEntity_SetBodygroup);
        cls.addFunction("SetOrAddAttributeValueByName", &SDKBaseClass::CAttributeList_SetOrAddAttributeValueByName);
        cls.addFunction("EHandle", &SDKBaseClass::CBaseEntity_EHandle);
        cls.addFunction("Spawn", &SDKBaseClass::CBaseEntity_Spawn);
        cls.addFunction("Despawn", &SDKBaseClass::CBaseEntity_Despawn);
        cls.addFunction("AcceptInput", &SDKBaseClass::CBaseEntity_AcceptInput);
        cls.addFunction("GetClassname", &SDKBaseClass::CBaseEntity_GetClassname);
        cls.addFunction("GetVData", &SDKBaseClass::CBaseEntity_GetVData);
        cls.addFunction("Teleport", &SDKBaseClass::CBaseEntity_Teleport);
        cls.addFunction("EmitSound", &SDKBaseClass::CBaseEntity_EmitSound);
        cls.addFunction("CollisionRulesChanged", &SDKBaseClass::CBaseEntity_CollisionRulesChanged);
        cls.addFunction("GetSkeletonInstance", &SDKBaseClass::CGameSceneNode_GetSkeletonInstance);
        cls.addFunction("GetPawn", &SDKBaseClass::CPlayerPawnComponent_GetPawn);
        cls.addFunction("__index", &SDKBaseClass::GetProp);
        cls.addFunction("__newindex", &SDKBaseClass::SetProp);
        cls.addFunction("IsValid", &SDKBaseClass::IsValid);
        cls.addFunction("ToPtr", &SDKBaseClass::ToPtr);
        cls.endClass();
    }
}