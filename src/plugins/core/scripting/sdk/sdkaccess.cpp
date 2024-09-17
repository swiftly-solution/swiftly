#include "../../scripting.h"
#include "../../../../sdk/sdkaccess.h"
#include "../../../../sdk/entity/CBasePlayerController.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"
#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CCSWeaponBase.h"
#include "../../../../player/PlayerManager.h"

#include <set>

std::string FetchPluginName(lua_State* state);

std::set<std::string> BlockedCS2GuidelinesFields = {
    "m_bIsValveDS",
    "m_bIsQuestEligible",
    "m_iEntityLevel",
    "m_iItemIDHigh",
    "m_iItemIDLow",
    "m_iAccountID",
    "m_iEntityQuality",
    "m_bInitialized",
    "m_szCustomName",
    "m_iAttributeDefinitionIndex",
    "m_iRawValue32",
    "m_iRawInitialValue32",
    "m_flValue",
    "m_flInitialValue",
    "m_bSetBonus",
    "m_nRefundableCurrency",
    "m_OriginalOwnerXuidLow",
    "m_OriginalOwnerXuidHigh",
    "m_nFallbackPaintKit",
    "m_nFallbackSeed",
    "m_flFallbackWear",
    "m_nFallbackStatTrak",
    "m_iCompetitiveWins",
    "m_iCompetitiveRanking",
    "m_iCompetitiveRankType",
    "m_iCompetitiveRankingPredicted_Win",
    "m_iCompetitiveRankingPredicted_Loss",
    "m_iCompetitiveRankingPredicted_Tie",
    "m_nActiveCoinRank",
    "m_nMusicID",
};

bool followCS2Guidelines = true;

int SDKBaseClass::CBasePlayerController_EntityIndex() {
    return ((CBasePlayerController*)this->GetPtr())->GetEntityIndex().Get();
}

void SDKBaseClass::CAttributeList_SetOrAddAttributeValueByName(std::string str, float value) {
    ((CAttributeList*)this->GetPtr())->SetOrAddAttributeValueByName(str.c_str(), value);
}

void SDKBaseClass::CBaseModelEntity_SetModel(std::string model)
{
    ((CBaseModelEntity*)this->GetPtr())->SetModel(model.c_str());
}

void SDKBaseClass::CBaseModelEntity_SetSolidType(int64_t solidType)
{
    ((CBaseModelEntity*)this->GetPtr())->SetSolidType((SolidType_t)solidType);
}

void SDKBaseClass::CBaseModelEntity_SetBodygroup(std::string str, int64_t val)
{
    ((CBaseModelEntity*)this->GetPtr())->SetBodygroup(str.c_str(), (uint64_t)val);
}

SDKBaseClass SDKBaseClass::CPlayerPawnComponent_GetPawn()
{
    return SDKBaseClass(((CPlayerPawnComponent*)this->GetPtr())->m_pPawn, "CBasePlayerPawn");
}

SDKBaseClass SDKBaseClass::CGameSceneNode_GetSkeletonInstance() {
    return SDKBaseClass(((CGameSceneNode*)this->GetPtr())->GetSkeletonInstance(), "CSkeletonInstance");
}

SDKBaseClass SDKBaseClass::CBaseEntity_EHandle() {
    return SDKBaseClass(((CBaseEntity*)this->GetPtr())->m_pEntity->m_EHandle.Get(), "CBaseEntity");
}

void SDKBaseClass::CBaseEntity_Spawn() {
    ((CBaseEntity*)this->GetPtr())->DispatchSpawn();
}

void SDKBaseClass::CBaseEntity_Despawn() {
    ((CBaseEntity*)this->GetPtr())->Despawn();
}

void SDKBaseClass::CBaseEntity_AcceptInput(std::string input, SDKBaseClass activator, SDKBaseClass caller, std::string value, int outputID) {
    ((CBaseEntity*)this->GetPtr())->AcceptInput(input.c_str(), (CEntityInstance*)activator.GetPtr(), (CEntityInstance*)caller.GetPtr(), value.c_str(), outputID);
}

std::string SDKBaseClass::CBaseEntity_GetClassname() {
    return ((CBaseEntity*)this->GetPtr())->GetClassname();
}

SDKBaseClass SDKBaseClass::CBaseEntity_GetVData() {
    return SDKBaseClass(((CBaseEntity*)this->GetPtr())->GetVData(), "CEntitySubclassVDataBase");
}

void SDKBaseClass::CBaseEntity_CollisionRulesChanged()
{
    ((CBaseEntity*)this->GetPtr())->CollisionRulesChanged();
}

void SDKBaseClass::CBaseEntity_Teleport(Vector value, QAngle angle) {
    ((CBaseEntity*)this->GetPtr())->Teleport(&value, &angle, nullptr);
}

void SDKBaseClass::CBaseEntity_EmitSound(std::string sound_name, float pitch, float volume) {
    for (int i = 0; i < g_playerManager->GetPlayerCap(); i++) {
        Player* player = g_playerManager->GetPlayer(i);
        if (!player) continue;
        if (player->IsFakeClient()) continue;
        if ((void*)player->GetPlayerController() == this->GetPtr()) {
            CSingleRecipientFilter filter(i);
            ((CBaseEntity*)this->GetPtr())->EmitSoundFilter(filter, sound_name, pitch, volume);
            break;
        }
    }
}

SDKBaseClass::SDKBaseClass(std::string ptr, lua_State* state)
{
    this->m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));

    lua_Debug ar;
    if (lua_getstack(state, 0, &ar)) {
        lua_getinfo(state, "n", &ar);
        this->m_className = ar.name;
    }
    else {
        this->m_className = "CBaseEntity";
    }
}

SDKBaseClass::SDKBaseClass(std::string ptr, std::string className)
{
    this->m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
    this->m_className = className;
}

SDKBaseClass::SDKBaseClass(void* ptr, std::string className)
{
    this->m_ptr = ptr;
    this->m_className = className;
}

std::string SDKBaseClass::GetClassName()
{
    return this->m_className;
}

void* SDKBaseClass::GetPtr()
{
    return this->m_ptr;
}

std::string SDKBaseClass::ToPtr()
{
    return string_format("%p", this->m_ptr);
}

bool SDKBaseClass::IsValid()
{
    return (this->m_ptr != nullptr);
}

luabridge::LuaRef SDKBaseClass::AccessSDKLua(std::string fieldName, uint64_t path, lua_State* state)
{
    if (followCS2Guidelines && BlockedCS2GuidelinesFields.find(fieldName) != BlockedCS2GuidelinesFields.end())
    {
        PRINTF("Getting or setting %s::%s is not permitted due to CS2 Server Guidelines violation.\nTo get or set this value, switch to false the \"core.FollowCS2ServerGuidelines\" field.\nNote: Using non-compliant field values can result in a GSLT ban.\nNote: We are not providing any kind of support for people which are using these fields.\n", this->m_className.c_str(), fieldName.c_str());
        return luabridge::LuaRef(state);
    }

    if(!m_ptr) {
        REGISTER_CALLSTACK(FetchPluginName(state), string_format("SDK Get: %s::%s(ptr=%p)", this->m_className.c_str(), fieldName.c_str(), m_ptr));
    }
    if (!g_sdk->ExistsField(path)) return luabridge::LuaRef(state);

    std::string field = g_sdk->GetFieldName(path);

    switch (g_sdk->GetFieldType(path))
    {
    case Bool:
        return luabridge::LuaRef(state, GetSchemaValue<bool>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Int8:
        return luabridge::LuaRef(state, GetSchemaValue<int8_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Int16:
        return luabridge::LuaRef(state, GetSchemaValue<int16_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Int32:
        return luabridge::LuaRef(state, GetSchemaValue<int32_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Int64:
        return luabridge::LuaRef(state, GetSchemaValue<int64_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case UInt8:
        return luabridge::LuaRef(state, GetSchemaValue<uint8_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case UInt16:
        return luabridge::LuaRef(state, GetSchemaValue<uint16_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case UInt32:
        return luabridge::LuaRef(state, GetSchemaValue<uint32_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case UInt64:
        return luabridge::LuaRef(state, GetSchemaValue<uint64_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Float:
        return luabridge::LuaRef(state, GetSchemaValue<float>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Double:
        return luabridge::LuaRef(state, GetSchemaValue<double>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Parent:
        return luabridge::LuaRef(state, SDKBaseClass(m_ptr, field));
    case StringToken:
        return luabridge::LuaRef(state, GetSchemaValue<CUtlStringToken>(m_ptr, this->m_className.c_str(), field.c_str()).m_nHashCode);
    case StringSymbolLarge:
        return luabridge::LuaRef(state, std::string(GetSchemaValue<CUtlSymbolLarge>(m_ptr, this->m_className.c_str(), field.c_str()).String()));
    case StringUtl:
        return luabridge::LuaRef(state, std::string(GetSchemaValue<CUtlString>(m_ptr, this->m_className.c_str(), field.c_str()).Get()));
    case String:
        return luabridge::LuaRef(state, std::string(GetSchemaValuePtr<char>(m_ptr, this->m_className.c_str(), field.c_str())));
    case Class:
        return luabridge::LuaRef(state, SDKBaseClass(GetSchemaPtr(m_ptr, this->m_className.c_str(), field.c_str()), g_sdk->GetFieldClass(path)));
    case SDKCHandle:
        return luabridge::LuaRef(state, SDKBaseClass((void*)(GetSchemaValue<CHandle<CEntityInstance>>(m_ptr, this->m_className.c_str(), field.c_str()).Get()), g_sdk->GetFieldClass(path)));
    case EntityIndex:
        return luabridge::LuaRef(state, GetSchemaValue<CEntityIndex>(m_ptr, this->m_className.c_str(), field.c_str()).Get());
    case SColor:
        return luabridge::LuaRef(state, GetSchemaValue<Color>(m_ptr, this->m_className.c_str(), field.c_str()));
    case SQAngle:
        return luabridge::LuaRef(state, GetSchemaValue<QAngle>(m_ptr, this->m_className.c_str(), field.c_str()));
    case SVector:
        return luabridge::LuaRef(state, GetSchemaValue<Vector>(m_ptr, this->m_className.c_str(), field.c_str()));
    case SVector2D:
        return luabridge::LuaRef(state, GetSchemaValue<Vector2D>(m_ptr, this->m_className.c_str(), field.c_str()));
    case SVector4D:
        return luabridge::LuaRef(state, GetSchemaValue<Vector4D>(m_ptr, this->m_className.c_str(), field.c_str()));
    case ClassPointer:
        return luabridge::LuaRef(state, SDKBaseClass(*(void**)GetSchemaPtr(m_ptr, this->m_className.c_str(), field.c_str()), g_sdk->GetFieldClass(path)));
    case RawListEntityIndex: {
        CEntityIndex* outValue = GetSchemaValuePtr<CEntityIndex>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i].Get());

        return luabridge::LuaRef(state, ret);
    }
    case StringSymbolLargeArray: {
        CUtlSymbolLarge* outValue = GetSchemaValuePtr<CUtlSymbolLarge>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i].String());

        return luabridge::LuaRef(state, ret);
    }
    case StringTokenArray: {
        CUtlStringToken* outValue = GetSchemaValuePtr<CUtlStringToken>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i].m_nHashCode);

        return luabridge::LuaRef(state, ret);
    }
    case StringUtlArray: {
        CUtlString* outValue = GetSchemaValuePtr<CUtlString>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i].Get());

        return luabridge::LuaRef(state, ret);
    }
    case Int8Array: {
        int8_t* outValue = GetSchemaValuePtr<int8_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int8_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case Int16Array: {
        int16_t* outValue = GetSchemaValuePtr<int16_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int16_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case Int32Array: {
        int32_t* outValue = GetSchemaValuePtr<int32_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int32_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case Int64Array: {
        int64_t* outValue = GetSchemaValuePtr<int64_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int64_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case UInt8Array: {
        uint8_t* outValue = GetSchemaValuePtr<uint8_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint8_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case UInt16Array: {
        uint16_t* outValue = GetSchemaValuePtr<uint16_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint16_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case UInt32Array: {
        uint32_t* outValue = GetSchemaValuePtr<uint32_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case UInt64Array: {
        uint64_t* outValue = GetSchemaValuePtr<uint64_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint64_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case FloatArray: {
        float* outValue = GetSchemaValuePtr<float>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<float> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case DoubleArray: {
        double* outValue = GetSchemaValuePtr<double>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<double> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case BoolArray: {
        bool* outValue = GetSchemaValue<bool*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<bool> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case SColorArray: {
        Color* outValue = GetSchemaValuePtr<Color>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Color> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case SQAngleArray: {
        QAngle* outValue = GetSchemaValuePtr<QAngle>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<QAngle> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case SVectorArray: {
        Vector* outValue = GetSchemaValuePtr<Vector>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case SVector2DArray: {
        Vector2D* outValue = GetSchemaValuePtr<Vector2D>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector2D> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case SVector4DArray: {
        Vector4D* outValue = GetSchemaValuePtr<Vector4D>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector4D> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case ClassArray: {
        void** outValue = GetSchemaValuePtr<void*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<SDKBaseClass> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(SDKBaseClass(outValue[i], g_sdk->GetFieldClass(path)));

        return luabridge::LuaRef(state, ret);
    }
    case CHandleArray: {
        CHandle<CEntityInstance>* outValue = GetSchemaValuePtr<CHandle<CEntityInstance>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<SDKBaseClass> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(SDKBaseClass((void*)outValue[i].Get(), g_sdk->GetFieldClass(path)));

        return luabridge::LuaRef(state, ret);
    }
    case CHandleCUtlVector: {
        CUtlVector<CHandle<CEntityInstance>>* vec = GetSchemaValuePtr<CUtlVector<CHandle<CEntityInstance>>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<SDKBaseClass> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(SDKBaseClass((void*)(vec->Element(i).Get()), g_sdk->GetFieldClass(path)));

        return luabridge::LuaRef(state, ret);
    }
    case StringSymbolLargeCUtlVector: {
        CUtlVector<CUtlSymbolLarge>* outValue = GetSchemaValuePtr<CUtlVector<CUtlSymbolLarge>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (int i = 0; i < outValue->Count(); i++)
            ret.push_back(outValue->Element(i).String());

        return luabridge::LuaRef(state, ret);
    }
    case StringTokenCUtlVector: {
        CUtlVector<CUtlStringToken>* outValue = GetSchemaValuePtr<CUtlVector<CUtlStringToken>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (int i = 0; i < outValue->Count(); i++)
            ret.push_back(outValue->Element(i).m_nHashCode);

        return luabridge::LuaRef(state, ret);
    }
    case StringUtlCUtlVector: {
        CUtlVector<CUtlString>* outValue = GetSchemaValuePtr<CUtlVector<CUtlString>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (int i = 0; i < outValue->Count(); i++)
            ret.push_back(outValue->Element(i).Get());

        return luabridge::LuaRef(state, ret);
    }
    case Int8CUtlVector: {
        CUtlVector<int8_t>* vec = GetSchemaValuePtr<CUtlVector<int8_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int8_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case Int16CUtlVector: {
        CUtlVector<int16_t>* vec = GetSchemaValuePtr<CUtlVector<int16_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int16_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case Int32CUtlVector: {
        CUtlVector<int32_t>* vec = GetSchemaValuePtr<CUtlVector<int32_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int32_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case Int64CUtlVector: {
        CUtlVector<int64_t>* vec = GetSchemaValuePtr<CUtlVector<int64_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int64_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case UInt8CUtlVector: {
        CUtlVector<uint8_t>* vec = GetSchemaValuePtr<CUtlVector<uint8_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint8_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case UInt16CUtlVector: {
        CUtlVector<uint16_t>* vec = GetSchemaValuePtr<CUtlVector<uint16_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint16_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case UInt32CUtlVector: {
        CUtlVector<uint32_t>* vec = GetSchemaValuePtr<CUtlVector<uint32_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case UInt64CUtlVector: {
        CUtlVector<uint64_t>* vec = GetSchemaValuePtr<CUtlVector<uint64_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint64_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case FloatCUtlVector: {
        CUtlVector<float>* vec = GetSchemaValuePtr<CUtlVector<float>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<float> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case DoubleCUtlVector: {
        CUtlVector<double>* vec = GetSchemaValuePtr<CUtlVector<double>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<double> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case SColorCUtlVector: {
        CUtlVector<Color>* vec = GetSchemaValuePtr<CUtlVector<Color>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Color> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case SQAngleCUtlVector: {
        CUtlVector<QAngle>* vec = GetSchemaValuePtr<CUtlVector<QAngle>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<QAngle> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case SVectorCUtlVector: {
        CUtlVector<Vector>* vec = GetSchemaValuePtr<CUtlVector<Vector>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case SVector2DCUtlVector: {
        CUtlVector<Vector2D>* vec = GetSchemaValuePtr<CUtlVector<Vector2D>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector2D> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case SVector4DCUtlVector: {
        CUtlVector<Vector4D>* vec = GetSchemaValuePtr<CUtlVector<Vector4D>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector4D> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case BoolCUtlVector: {
        CUtlVector<bool>* vec = GetSchemaValuePtr<CUtlVector<bool>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<bool> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    }

    return luabridge::LuaRef(state, fieldName);
}

void SDKBaseClass::UpdateSDKLua(std::string fieldName, luabridge::LuaRef value, lua_State* state)
{
    if (followCS2Guidelines && BlockedCS2GuidelinesFields.find(fieldName) != BlockedCS2GuidelinesFields.end())
    {
        PRINTF("Getting or setting %s::%s is not permitted due to CS2 Server Guidelines violation.\nTo get or set this value, switch to false the \"core.FollowCS2ServerGuidelines\" field.\nNote: Using non-compliant field values can result in a GSLT ban.\nNote: We are not providing any kind of support for people which are using these fields.\n", this->m_className.c_str(), fieldName.c_str());
        return;
    }

    if(!m_ptr) {
        REGISTER_CALLSTACK(FetchPluginName(state), string_format("SDK Set: %s::%s(ptr=%p)", this->m_className.c_str(), fieldName.c_str(), m_ptr));
    }
    uint64 path = ((uint64) hash_32_fnv1a_const(this->m_className.c_str()) << 32 | hash_32_fnv1a_const(fieldName.c_str()));
    if (!g_sdk->ExistsField(path)) return;

    std::string field = g_sdk->GetFieldName(path);

    switch (g_sdk->GetFieldType(path))
    {
    case Bool:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<bool>());
    case Int8:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<int8_t>());
    case Int16:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<int16_t>());
    case Int32:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<int32_t>());
    case Int64:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<int64_t>());
    case UInt8:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<uint8_t>());
    case UInt16:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<uint16_t>());
    case UInt32:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<uint32_t>());
    case UInt64:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<uint64_t>());
    case Float:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<float>());
    case Double:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<double>());
    case StringToken:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), CUtlStringToken(value.cast<uint32_t>()));
    case StringSymbolLarge:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), CUtlSymbolLarge(strdup(value.cast<std::string>().c_str())));
    case StringUtl:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), CUtlString(strdup(value.cast<std::string>().c_str())));
    case String:
        return WriteSchemaPtrValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), reinterpret_cast<byte*>(const_cast<char*>(value.cast<std::string>().c_str())), g_sdk->GetFieldSize(path));
    case EntityIndex:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), CEntityIndex(value.cast<int>()));
    case SColor:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<Color>());
    case SQAngle:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<QAngle>());
    case SVector:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<Vector>());
    case SVector2D:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<Vector2D>());
    case SVector4D:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<Vector4D>());
    case RawListEntityIndex: {
        auto val = GetSchemaValuePtr<CEntityIndex>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            val[i] = CEntityIndex(ret[i]);

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case StringSymbolLargeArray: {
        auto val = GetSchemaValuePtr<CUtlSymbolLarge>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<std::string>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++) {
            val[i] = CUtlSymbolLarge(ret[i].c_str());
        }

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case StringTokenArray: {
        auto val = GetSchemaValuePtr<CUtlStringToken>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint32_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            val[i] = CUtlStringToken(ret[i]);

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case StringUtlArray: {
        auto val = GetSchemaValuePtr<CUtlString>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<std::string>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            val[i] = CUtlString(ret[i].c_str());

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case Int8Array: {
        auto outValue = GetSchemaValuePtr<int8_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int8_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case Int16Array: {
        auto outValue = GetSchemaValuePtr<int16_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int16_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case Int32Array: {
        auto outValue = GetSchemaValuePtr<int32_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int32_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case Int64Array: {
        auto outValue = GetSchemaValuePtr<int64_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int64_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case UInt8Array: {
        auto outValue = GetSchemaValuePtr<uint8_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint8_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case UInt16Array: {
        auto outValue = GetSchemaValuePtr<uint16_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint16_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case UInt32Array: {
        auto outValue = GetSchemaValuePtr<uint32_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint32_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case UInt64Array: {
        auto outValue = GetSchemaValuePtr<uint64_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint64_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case FloatArray: {
        auto outValue = GetSchemaValuePtr<float>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<float>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case DoubleArray: {
        auto outValue = GetSchemaValuePtr<double>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<double>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case BoolArray: {
        auto outValue = GetSchemaValuePtr<bool>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<bool>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case SColorArray: {
        auto outValue = GetSchemaValuePtr<Color>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<Color>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case SQAngleArray: {
        auto outValue = GetSchemaValuePtr<QAngle>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<QAngle>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case SVectorArray: {
        auto outValue = GetSchemaValuePtr<Vector>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<Vector>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case SVector2DArray: {
        auto outValue = GetSchemaValuePtr<Vector2D>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<Vector2D>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case SVector4DArray: {
        auto outValue = GetSchemaValuePtr<Vector4D>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<Vector4D>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0, g_sdk->GetClassStructState(this->m_className));
        return;
    }
    case StringSymbolLargeCUtlVector: {
        std::vector<CUtlSymbolLarge> newValues;
        auto val = value.cast<std::vector<std::string>>();
        for (auto elem : val)
            newValues.push_back(CUtlSymbolLarge(elem.c_str()));

        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), newValues);
    }
    case StringTokenCUtlVector: {
        std::vector<CUtlStringToken> newValues;
        auto val = value.cast<std::vector<uint32_t>>();
        for (auto elem : val)
            newValues.push_back(CUtlStringToken(elem));

        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), newValues);
    }
    case StringUtlCUtlVector: {
        std::vector<CUtlString> newValues;
        auto val = value.cast<std::vector<std::string>>();
        for (auto elem : val)
            newValues.push_back(CUtlString(elem.c_str()));

        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), newValues);
    }
    case Int8CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<int8_t>>());
    case Int16CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<int16_t>>());
    case Int32CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<int32_t>>());
    case Int64CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<int64_t>>());
    case UInt8CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<uint8_t>>());
    case UInt16CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<uint16_t>>());
    case UInt32CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<uint32_t>>());
    case UInt64CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<uint64_t>>());
    case FloatCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<float>>());
    case DoubleCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<double>>());
    case SColorCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<Color>>());
    case SQAngleCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<QAngle>>());
    case SVectorCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<Vector>>());
    case SVector2DCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<Vector2D>>());
    case SVector4DCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<Vector4D>>());
    case BoolCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), value.cast<std::vector<bool>>());
    }
}