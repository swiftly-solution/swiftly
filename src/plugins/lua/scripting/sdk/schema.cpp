#include "../core.h"
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

extern std::set<std::string> BlockedCS2GuidelinesFields;
extern bool followCS2Guidelines;

luabridge::LuaRef SDKBaseClass::AccessSDKLua(std::string fieldName, uint64_t path, lua_State* state)
{
    if (followCS2Guidelines && BlockedCS2GuidelinesFields.find(fieldName) != BlockedCS2GuidelinesFields.end())
    {
        PRINTF("Getting or setting %s::%s is not permitted due to CS2 Server Guidelines violation.\nTo get or set this value, switch to false the \"core.FollowCS2ServerGuidelines\" field.\nNote: Using non-compliant field values can result in a GSLT ban.\nNote: We are not providing any kind of support for people which are using these fields.\n", this->m_className.c_str(), fieldName.c_str());
        return luabridge::LuaRef(state);
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
        return luabridge::LuaRef(state, GetSchemaValue<CUtlStringToken>(m_ptr, this->m_className.c_str(), field.c_str()).GetHashCode());
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
            ret.push_back(outValue[i].GetHashCode());

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
        bool* outValue = GetSchemaValuePtr<bool>(m_ptr, this->m_className.c_str(), field.c_str());
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
            ret.push_back(outValue->Element(i).GetHashCode());

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

int SDKBaseClass::GetProp(lua_State* state)
{
    std::string field_name = luabridge::LuaRef::fromStack(state, 2).cast<std::string>();

    uint64_t path = (this->classOffset | hash_32_fnv1a_const(field_name.c_str()));

    if (field_name == "IsValid" || field_name == "ToPtr" || classFuncs.find(path) != classFuncs.end()) return luabridge::detail::CFunc::indexMetaMethod(state);

    uint64_t id = g_callStack->RegisterPluginCallstack(FetchPluginName(state), string_format("SDK Get: %s::%s(ptr=%p)", this->m_className.c_str(), field_name.c_str(), m_ptr));
    this->AccessSDKLua(field_name, path, state).push();
    g_callStack->UnregisterPluginCallstack(FetchPluginName(state), id);
    return 1;
}

int SDKBaseClass::SetProp(lua_State* state)
{
    std::string field_name = luabridge::LuaRef::fromStack(state, 2).cast<std::string>();
    luabridge::LuaRef val = luabridge::LuaRef::fromStack(state, 3);

    uint64_t id = g_callStack->RegisterPluginCallstack(FetchPluginName(state), string_format("SDK Set: %s::%s(ptr=%p,value=%s)", this->m_className.c_str(), field_name.c_str(), m_ptr, val.tostring()));

    this->UpdateSDKLua(field_name, val, state);

    g_callStack->UnregisterPluginCallstack(FetchPluginName(state), id);
    return 0;
}

int SDKBaseClass::CallProp(lua_State* state)
{
    auto val = luabridge::LuaRef::fromStack(state, 2);
    if (val.type() == LUA_TSTRING) {
        auto str = val.cast<std::string>();
        if (starts_with(str, "0x"))
            this->m_ptr = (void*)(strtol(str.c_str(), nullptr, 16));
        else
            throw std::runtime_error(string_format("Invalid pointer: %s", str.c_str()));
    }
    else if (val.isInstance<SDKBaseClass>()) {
        this->m_ptr = val.cast<SDKBaseClass>().GetPtr();
    }
    else {
        throw std::runtime_error("Invalid pointer or object.");
    }
    luabridge::push(state, this);
    return 1;
}

void SDKBaseClass::CBaseEntity_SpawnLua(lua_State* state) {
    luabridge::LuaRef ref = luabridge::LuaRef::fromStack(state, 2);
    if (ref.isInstance<PluginCEntityKeyValues>()) {
        auto kv = ref.cast<PluginCEntityKeyValues>();
        CBaseEntity_Spawn(&kv);
    }
    else
        CBaseEntity_Spawn(nullptr);
}

void SDKBaseClass::CBaseEntity_TeleportLua(lua_State* L)
{
    auto pos = luabridge::LuaRef::fromStack(L, 2);
    auto ang = luabridge::LuaRef::fromStack(L, 3);
    auto vel = luabridge::LuaRef::fromStack(L, 4);
    Vector po(0.0, 0.0, 0.0), ve(0.0, 0.0, 0.0);
    QAngle an(0.0, 0.0, 0.0);
    if (pos.isInstance<Vector>())
        po = pos.cast<Vector>();
    if (ang.isInstance<QAngle>())
        an = ang.cast<QAngle>();
    if (vel.isInstance<Vector>())
        ve = vel.cast<Vector>();

    CBaseEntity_Teleport(po, an, ve);
}

LoadLuaScriptingComponent(
    schema,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .addFunction("IsSDKClass", +[](std::string key) -> bool {
            return sch::IsClassLoaded(key.c_str());
                })
            .addFunction("GenerateSDKFactory", +[](std::string className) -> SDKBaseClass {
            return SDKBaseClass(nullptr, className);
                });

        auto cls = luabridge::getGlobalNamespace(state).beginClass<SDKBaseClass>("SDKBaseClass");
        cls.addConstructor<void(*)(std::string, std::string)>();
        cls.addFunction("EntityIndex", &SDKBaseClass::CBasePlayerController_EntityIndex);
        cls.addFunction("SetModel", &SDKBaseClass::CBaseModelEntity_SetModel);
        cls.addFunction("SetSolidType", &SDKBaseClass::CBaseModelEntity_SetSolidType);
        cls.addFunction("SetBodygroup", &SDKBaseClass::CBaseModelEntity_SetBodygroup);
        cls.addFunction("SetOrAddAttributeValueByName", &SDKBaseClass::CAttributeList_SetOrAddAttributeValueByName);
        cls.addFunction("EHandle", &SDKBaseClass::CBaseEntity_EHandle);
        cls.addFunction("Spawn", &SDKBaseClass::CBaseEntity_SpawnLua);
        cls.addFunction("Despawn", &SDKBaseClass::CBaseEntity_Despawn);
        cls.addFunction("AcceptInput", &SDKBaseClass::CBaseEntity_AcceptInput);
        cls.addFunction("GetClassname", &SDKBaseClass::CBaseEntity_GetClassname);
        cls.addFunction("GetVData", &SDKBaseClass::CBaseEntity_GetVData);
        cls.addFunction("Teleport", &SDKBaseClass::CBaseEntity_TeleportLua);
        cls.addFunction("EmitSound", &SDKBaseClass::CBaseEntity_EmitSound);
        cls.addFunction("CollisionRulesChanged", &SDKBaseClass::CBaseEntity_CollisionRulesChanged);
        cls.addFunction("GetSkeletonInstance", &SDKBaseClass::CGameSceneNode_GetSkeletonInstance);
        cls.addFunction("GetPawn", &SDKBaseClass::CPlayerPawnComponent_GetPawn);
        cls.addFunction("__index", &SDKBaseClass::GetProp);
        cls.addFunction("__newindex", &SDKBaseClass::SetProp);
        cls.addFunction("__call", &SDKBaseClass::CallProp);
        cls.addFunction("IsValid", &SDKBaseClass::IsValid);
        cls.addFunction("ToPtr", &SDKBaseClass::ToPtr);
        cls.endClass();
    }
)
