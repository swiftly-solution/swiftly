#include "core.h"
#include "../../../sdk/sdkaccess.h"

std::map<std::string, std::vector<std::string>> classFuncs = {
    {
        "CBaseEntity",
        {
            "EHandle",
            "Spawn",
            "Despawn",
            "AcceptInput",
            "GetClassname",
            "GetVData",
            "Teleport",
            "EmitSound",
            "CollisionRulesChanged"
        }
    },
    {
        "CBaseModelEntity",
        {
            "SetModel",
            "SetSolidType",
            "SetBodygroup",
        }
    },
    {
        "CAttributeList",
        {
            "SetOrAddAttributeValueByName"
        }
    },
    {
        "CBasePlayerController",
        {
            "EntityIndex"
        }
    },
    {
        "CGameSceneNode",
        {
            "GetSkeletonInstance"
        }
    },
    {
        "CPlayerPawnComponent",
        {
            "GetPawn"
        }
    }
};

int SDKBaseClass::GetProp(lua_State* state)
{
    std::string field_name = luabridge::LuaRef::fromStack(state, 2).cast<std::string>();

    if (field_name == "IsValid" || field_name == "ToPtr") return luabridge::detail::CFunc::indexMetaMethod(state);

    if (classFuncs.find(this->m_className) == classFuncs.end())
        this->AccessSDKLua(field_name, state).push();
    else
        if (std::find(classFuncs[this->m_className].begin(), classFuncs[this->m_className].end(), field_name) != classFuncs[this->m_className].end())
            return luabridge::detail::CFunc::indexMetaMethod(state);
        else
            this->AccessSDKLua(field_name, state).push();

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