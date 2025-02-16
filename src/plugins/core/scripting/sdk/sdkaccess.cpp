#include "../../scripting.h"
#include "../../../../sdk/access/sdkaccess.h"
#include "../../../../sdk/entity/CBasePlayerController.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"
#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CCSWeaponBase.h"
#include "../../../../player/playermanager/PlayerManager.h"

#include <set>

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

void SDKBaseClass::CBaseEntity_Spawn(PluginCEntityKeyValues* kv) {
    ((CBaseEntity*)this->GetPtr())->DispatchSpawn(kv ? kv->GetKeyVals() : nullptr);
}

void SDKBaseClass::CBaseEntity_Despawn() {
    ((CBaseEntity*)this->GetPtr())->Despawn();
}

void SDKBaseClass::CBaseEntity_AcceptInput(std::string input, EValue activator, EValue caller, std::string value, int outputID) {
    ((CBaseEntity*)this->GetPtr())->AcceptInput(input.c_str(), (CEntityInstance*)activator.cast_or<SDKBaseClass>(SDKBaseClass(nullptr, "CEntityInstance")).GetPtr(), (CEntityInstance*)caller.cast_or<SDKBaseClass>(SDKBaseClass(nullptr, "CEntityInstance")).GetPtr(), value.c_str(), outputID);
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

void SDKBaseClass::CBaseEntity_Teleport(Vector value, QAngle angle, Vector velocity) {
    if(!IsValid()) return;
    
    ((CBaseEntity*)this->GetPtr())->Teleport(&value, &angle, &velocity);
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

SDKBaseClass::SDKBaseClass(std::string ptr, std::string className)
{
    this->m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
    this->m_className = className;
    this->classOffset = ((uint64_t)hash_32_fnv1a_const(this->m_className.c_str()) << 32);
}

SDKBaseClass::SDKBaseClass(void* ptr, std::string className)
{
    this->m_ptr = ptr;
    this->m_className = className;
    this->classOffset = ((uint64_t)hash_32_fnv1a_const(this->m_className.c_str()) << 32);
}

std::string SDKBaseClass::GetClassName()
{
    return this->m_className;
}

void SDKBaseClass::SetPtr(void* ptr)
{
    this->m_ptr = ptr;
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

extern std::set<std::string> BlockedCS2GuidelinesFields;
extern bool followCS2Guidelines;

EValue SDKBaseClass::AccessSDK(std::string fieldName, uint64_t path, EContext* state)
{
    if (followCS2Guidelines && BlockedCS2GuidelinesFields.find(fieldName) != BlockedCS2GuidelinesFields.end())
    {
        PRINTF("Getting or setting %s::%s is not permitted due to CS2 Server Guidelines violation.\nTo get or set this value, switch to false the \"core.FollowCS2ServerGuidelines\" field.\nNote: Using non-compliant field values can result in a GSLT ban.\nNote: We are not providing any kind of support for people which are using these fields.\n", this->m_className.c_str(), fieldName.c_str());
        return EValue(state);
    }

    if (!g_sdk->ExistsField(path)) return EValue(state);

    std::string field = g_sdk->GetFieldName(path);

    switch (g_sdk->GetFieldType(path))
    {
    case Bool:
        return EValue(state, GetSchemaValue<bool>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Int8:
        return EValue(state, GetSchemaValue<int8_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Int16:
        return EValue(state, GetSchemaValue<int16_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Int32:
        return EValue(state, GetSchemaValue<int32_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Int64:
        return EValue(state, GetSchemaValue<int64_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case UInt8:
        return EValue(state, GetSchemaValue<uint8_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case UInt16:
        return EValue(state, GetSchemaValue<uint16_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case UInt32:
        return EValue(state, GetSchemaValue<uint32_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case UInt64:
        return EValue(state, GetSchemaValue<uint64_t>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Float:
        return EValue(state, GetSchemaValue<float>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Double:
        return EValue(state, GetSchemaValue<double>(m_ptr, this->m_className.c_str(), field.c_str()));
    case Parent:
        return EValue(state, SDKBaseClass(m_ptr, field));
    case StringToken:
        return EValue(state, GetSchemaValue<CUtlStringToken>(m_ptr, this->m_className.c_str(), field.c_str()).GetHashCode());
    case StringSymbolLarge:
        return EValue(state, std::string(GetSchemaValue<CUtlSymbolLarge>(m_ptr, this->m_className.c_str(), field.c_str()).String()));
    case StringUtl:
        return EValue(state, std::string(GetSchemaValue<CUtlString>(m_ptr, this->m_className.c_str(), field.c_str()).Get()));
    case String:
        return EValue(state, std::string(GetSchemaValuePtr<char>(m_ptr, this->m_className.c_str(), field.c_str())));
    case Class:
        return EValue(state, SDKBaseClass(GetSchemaPtr(m_ptr, this->m_className.c_str(), field.c_str()), g_sdk->GetFieldClass(path)));
    case SDKCHandle:
        return EValue(state, SDKBaseClass((void*)(GetSchemaValue<CHandle<CEntityInstance>>(m_ptr, this->m_className.c_str(), field.c_str()).Get()), g_sdk->GetFieldClass(path)));
    case EntityIndex:
        return EValue(state, GetSchemaValue<CEntityIndex>(m_ptr, this->m_className.c_str(), field.c_str()).Get());
    case SColor:
        return EValue(state, GetSchemaValue<Color>(m_ptr, this->m_className.c_str(), field.c_str()));
    case SQAngle:
        return EValue(state, GetSchemaValue<QAngle>(m_ptr, this->m_className.c_str(), field.c_str()));
    case SVector:
        return EValue(state, GetSchemaValue<Vector>(m_ptr, this->m_className.c_str(), field.c_str()));
    case SVector2D:
        return EValue(state, GetSchemaValue<Vector2D>(m_ptr, this->m_className.c_str(), field.c_str()));
    case SVector4D:
        return EValue(state, GetSchemaValue<Vector4D>(m_ptr, this->m_className.c_str(), field.c_str()));
    case ClassPointer:
        return EValue(state, SDKBaseClass(*(void**)GetSchemaPtr(m_ptr, this->m_className.c_str(), field.c_str()), g_sdk->GetFieldClass(path)));
    case RawListEntityIndex: {
        CEntityIndex* outValue = GetSchemaValuePtr<CEntityIndex>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i].Get());

        return EValue(state, ret);
    }
    case StringSymbolLargeArray: {
        CUtlSymbolLarge* outValue = GetSchemaValuePtr<CUtlSymbolLarge>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i].String());

        return EValue(state, ret);
    }
    case StringTokenArray: {
        CUtlStringToken* outValue = GetSchemaValuePtr<CUtlStringToken>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i].GetHashCode());

        return EValue(state, ret);
    }
    case StringUtlArray: {
        CUtlString* outValue = GetSchemaValuePtr<CUtlString>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i].Get());

        return EValue(state, ret);
    }
    case Int8Array: {
        int8_t* outValue = GetSchemaValuePtr<int8_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int8_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case Int16Array: {
        int16_t* outValue = GetSchemaValuePtr<int16_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int16_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case Int32Array: {
        int32_t* outValue = GetSchemaValuePtr<int32_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int32_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case Int64Array: {
        int64_t* outValue = GetSchemaValuePtr<int64_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int64_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case UInt8Array: {
        uint8_t* outValue = GetSchemaValuePtr<uint8_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint8_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case UInt16Array: {
        uint16_t* outValue = GetSchemaValuePtr<uint16_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint16_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case UInt32Array: {
        uint32_t* outValue = GetSchemaValuePtr<uint32_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case UInt64Array: {
        uint64_t* outValue = GetSchemaValuePtr<uint64_t>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint64_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case FloatArray: {
        float* outValue = GetSchemaValuePtr<float>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<float> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case DoubleArray: {
        double* outValue = GetSchemaValuePtr<double>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<double> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case BoolArray: {
        bool* outValue = GetSchemaValuePtr<bool>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<bool> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case SColorArray: {
        Color* outValue = GetSchemaValuePtr<Color>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Color> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case SQAngleArray: {
        QAngle* outValue = GetSchemaValuePtr<QAngle>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<QAngle> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case SVectorArray: {
        Vector* outValue = GetSchemaValuePtr<Vector>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case SVector2DArray: {
        Vector2D* outValue = GetSchemaValuePtr<Vector2D>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector2D> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case SVector4DArray: {
        Vector4D* outValue = GetSchemaValuePtr<Vector4D>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector4D> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case ClassArray: {
        void** outValue = GetSchemaValuePtr<void*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<SDKBaseClass> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(SDKBaseClass(outValue[i], g_sdk->GetFieldClass(path)));

        return EValue(state, ret);
    }
    case CHandleArray: {
        CHandle<CEntityInstance>* outValue = GetSchemaValuePtr<CHandle<CEntityInstance>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<SDKBaseClass> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(SDKBaseClass((void*)outValue[i].Get(), g_sdk->GetFieldClass(path)));

        return EValue(state, ret);
    }
    case CHandleCUtlVector: {
        CUtlVector<CHandle<CEntityInstance>>* vec = GetSchemaValuePtr<CUtlVector<CHandle<CEntityInstance>>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<SDKBaseClass> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(SDKBaseClass((void*)(vec->Element(i).Get()), g_sdk->GetFieldClass(path)));

        return EValue(state, ret);
    }
    case StringSymbolLargeCUtlVector: {
        CUtlVector<CUtlSymbolLarge>* outValue = GetSchemaValuePtr<CUtlVector<CUtlSymbolLarge>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (int i = 0; i < outValue->Count(); i++)
            ret.push_back(outValue->Element(i).String());

        return EValue(state, ret);
    }
    case StringTokenCUtlVector: {
        CUtlVector<CUtlStringToken>* outValue = GetSchemaValuePtr<CUtlVector<CUtlStringToken>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (int i = 0; i < outValue->Count(); i++)
            ret.push_back(outValue->Element(i).GetHashCode());

        return EValue(state, ret);
    }
    case StringUtlCUtlVector: {
        CUtlVector<CUtlString>* outValue = GetSchemaValuePtr<CUtlVector<CUtlString>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (int i = 0; i < outValue->Count(); i++)
            ret.push_back(outValue->Element(i).Get());

        return EValue(state, ret);
    }
    case Int8CUtlVector: {
        CUtlVector<int8_t>* vec = GetSchemaValuePtr<CUtlVector<int8_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int8_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case Int16CUtlVector: {
        CUtlVector<int16_t>* vec = GetSchemaValuePtr<CUtlVector<int16_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int16_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case Int32CUtlVector: {
        CUtlVector<int32_t>* vec = GetSchemaValuePtr<CUtlVector<int32_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int32_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case Int64CUtlVector: {
        CUtlVector<int64_t>* vec = GetSchemaValuePtr<CUtlVector<int64_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int64_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case UInt8CUtlVector: {
        CUtlVector<uint8_t>* vec = GetSchemaValuePtr<CUtlVector<uint8_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint8_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case UInt16CUtlVector: {
        CUtlVector<uint16_t>* vec = GetSchemaValuePtr<CUtlVector<uint16_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint16_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case UInt32CUtlVector: {
        CUtlVector<uint32_t>* vec = GetSchemaValuePtr<CUtlVector<uint32_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case UInt64CUtlVector: {
        CUtlVector<uint64_t>* vec = GetSchemaValuePtr<CUtlVector<uint64_t>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint64_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case FloatCUtlVector: {
        CUtlVector<float>* vec = GetSchemaValuePtr<CUtlVector<float>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<float> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case DoubleCUtlVector: {
        CUtlVector<double>* vec = GetSchemaValuePtr<CUtlVector<double>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<double> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case SColorCUtlVector: {
        CUtlVector<Color>* vec = GetSchemaValuePtr<CUtlVector<Color>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Color> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case SQAngleCUtlVector: {
        CUtlVector<QAngle>* vec = GetSchemaValuePtr<CUtlVector<QAngle>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<QAngle> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case SVectorCUtlVector: {
        CUtlVector<Vector>* vec = GetSchemaValuePtr<CUtlVector<Vector>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case SVector2DCUtlVector: {
        CUtlVector<Vector2D>* vec = GetSchemaValuePtr<CUtlVector<Vector2D>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector2D> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case SVector4DCUtlVector: {
        CUtlVector<Vector4D>* vec = GetSchemaValuePtr<CUtlVector<Vector4D>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector4D> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case BoolCUtlVector: {
        CUtlVector<bool>* vec = GetSchemaValuePtr<CUtlVector<bool>>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<bool> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    }

    return EValue(state, fieldName);
}

void SDKBaseClass::UpdateSDK(std::string fieldName, EValue value, EContext* state)
{
    if (followCS2Guidelines && BlockedCS2GuidelinesFields.find(fieldName) != BlockedCS2GuidelinesFields.end())
    {
        PRINTF("Getting or setting %s::%s is not permitted due to CS2 Server Guidelines violation.\nTo get or set this value, switch to false the \"core.FollowCS2ServerGuidelines\" field.\nNote: Using non-compliant field values can result in a GSLT ban.\nNote: We are not providing any kind of support for people which are using these fields.\n", this->m_className.c_str(), fieldName.c_str());
        return;
    }

    uint64 path = (this->classOffset | hash_32_fnv1a_const(fieldName.c_str()));
    if (!g_sdk->ExistsField(path)) return;

    std::string field = g_sdk->GetFieldName(path);

    switch (g_sdk->GetFieldType(path))
    {
    case Bool:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<bool>());
    case Int8:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<int8_t>());
    case Int16:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<int16_t>());
    case Int32:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<int32_t>());
    case Int64:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<int64_t>());
    case UInt8:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<uint8_t>());
    case UInt16:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<uint16_t>());
    case UInt32:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<uint32_t>());
    case UInt64:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<uint64_t>());
    case Float:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<float>());
    case Double:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<double>());
    case StringToken:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), CUtlStringToken(value.cast<uint32_t>()));
    case StringSymbolLarge:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), CUtlSymbolLarge(strdup(value.cast<std::string>().c_str())));
    case StringUtl:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), CUtlString(strdup(value.cast<std::string>().c_str())));
    case String:
        return WriteSchemaPtrValue(m_ptr, this->m_className.c_str(), field.c_str(), reinterpret_cast<byte*>(const_cast<char*>(value.cast<std::string>().c_str())), g_sdk->GetFieldSize(path));
    case EntityIndex:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), CEntityIndex(value.cast<int>()));
    case SColor:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<Color>());
    case SQAngle:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<QAngle>());
    case SVector:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<Vector>());
    case SVector2D:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<Vector2D>());
    case SVector4D:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<Vector4D>());
    case RawListEntityIndex: {
        auto val = GetSchemaValuePtr<CEntityIndex>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            val[i] = CEntityIndex(ret[i]);

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case StringSymbolLargeArray: {
        auto val = GetSchemaValuePtr<CUtlSymbolLarge>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<std::string>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++) {
            val[i] = CUtlSymbolLarge(ret[i].c_str());
        }

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case StringTokenArray: {
        auto val = GetSchemaValuePtr<CUtlStringToken>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint32_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            val[i] = CUtlStringToken(ret[i]);

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case StringUtlArray: {
        auto val = GetSchemaValuePtr<CUtlString>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<std::string>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            val[i] = CUtlString(ret[i].c_str());

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case Int8Array: {
        auto outValue = GetSchemaValuePtr<int8_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int8_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case Int16Array: {
        auto outValue = GetSchemaValuePtr<int16_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int16_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case Int32Array: {
        auto outValue = GetSchemaValuePtr<int32_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int32_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case Int64Array: {
        auto outValue = GetSchemaValuePtr<int64_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int64_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case UInt8Array: {
        auto outValue = GetSchemaValuePtr<uint8_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint8_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case UInt16Array: {
        auto outValue = GetSchemaValuePtr<uint16_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint16_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case UInt32Array: {
        auto outValue = GetSchemaValuePtr<uint32_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint32_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case UInt64Array: {
        auto outValue = GetSchemaValuePtr<uint64_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint64_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case FloatArray: {
        auto outValue = GetSchemaValuePtr<float>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<float>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case DoubleArray: {
        auto outValue = GetSchemaValuePtr<double>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<double>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case SDKCHandle: {
        auto outVal = GetSchemaValuePtr<CHandle<CEntityInstance>>(m_ptr, this->m_className.c_str(), field.c_str());
        outVal->Set((CEntityInstance*)(value.cast<SDKBaseClass>().GetPtr()));

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case CHandleArray: {
        auto outValue = GetSchemaValuePtr<CHandle<CEntityInstance>>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<SDKBaseClass>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i].Set((CEntityInstance*)(ret[i].GetPtr()));

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case CHandleCUtlVector: {
        auto ret = value.cast<std::vector<SDKBaseClass>>();

        auto m_key = sch::GetOffset(this->m_className.c_str(), field.c_str());

        SetStateChanged((uintptr_t)m_ptr, this->m_className, field, 0);

        CUtlVector<CHandle<CEntityInstance>>* vec = reinterpret_cast<CUtlVector<CHandle<CEntityInstance>> *>((uintptr_t)(m_ptr)+m_key);
        FOR_EACH_VEC(*vec, i) {
            vec->Element(i).Set((CEntityInstance*)(ret[i].GetPtr()));
        }

        SetStateChanged((uintptr_t)m_ptr, this->m_className, field, 0);

        return;
    }
    case BoolArray: {
        auto outValue = GetSchemaValuePtr<bool>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<bool>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case SColorArray: {
        auto outValue = GetSchemaValuePtr<Color>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<Color>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case SQAngleArray: {
        auto outValue = GetSchemaValuePtr<QAngle>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<QAngle>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case SVectorArray: {
        auto outValue = GetSchemaValuePtr<Vector>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<Vector>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case SVector2DArray: {
        auto outValue = GetSchemaValuePtr<Vector2D>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<Vector2D>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case SVector4DArray: {
        auto outValue = GetSchemaValuePtr<Vector4D>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<Vector4D>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)m_ptr, this->m_className.c_str(), field.c_str(), 0);
        return;
    }
    case StringSymbolLargeCUtlVector: {
        std::vector<CUtlSymbolLarge> newValues;
        auto val = value.cast<std::vector<std::string>>();
        for (auto elem : val)
            newValues.push_back(CUtlSymbolLarge(elem.c_str()));

        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), newValues);
    }
    case StringTokenCUtlVector: {
        std::vector<CUtlStringToken> newValues;
        auto val = value.cast<std::vector<uint32_t>>();
        for (auto elem : val)
            newValues.push_back(CUtlStringToken(elem));

        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), newValues);
    }
    case StringUtlCUtlVector: {
        std::vector<CUtlString> newValues;
        auto val = value.cast<std::vector<std::string>>();
        for (auto elem : val)
            newValues.push_back(CUtlString(elem.c_str()));

        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), newValues);
    }
    case Int8CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<int8_t>>());
    case Int16CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<int16_t>>());
    case Int32CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<int32_t>>());
    case Int64CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<int64_t>>());
    case UInt8CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<uint8_t>>());
    case UInt16CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<uint16_t>>());
    case UInt32CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<uint32_t>>());
    case UInt64CUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<uint64_t>>());
    case FloatCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<float>>());
    case DoubleCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<double>>());
    case SColorCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<Color>>());
    case SQAngleCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<QAngle>>());
    case SVectorCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<Vector>>());
    case SVector2DCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<Vector2D>>());
    case SVector4DCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<Vector4D>>());
    case BoolCUtlVector:
        return SetSchemaValueCUtlVector(m_ptr, this->m_className.c_str(), field.c_str(), value.cast<std::vector<bool>>());
    }
}

SDKBaseType::SDKBaseType(std::string typeName)
{
    m_typeName = typeName;
}

int64_t SDKBaseType::GetTypeValue(std::string key)
{
    auto types = g_sdk->GetSDKTypes();
    if(types.find(m_typeName) == types.end()) return 0;
    if(types[m_typeName].find(key) == types[m_typeName].end()) return 0;

    return types[m_typeName][key];
}