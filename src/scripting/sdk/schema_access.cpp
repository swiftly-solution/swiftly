#include <scripting/core.h>

#include <utils/common.h>
#include <utils/utils.h>
#include <public/mathlib/vector.h>

#include <sdk/game.h>
#include <sdk/access.h>
#include <sdk/schema.h>
#include <public/tier1/utlstringtoken.h>

#include "ehandle.h"

extern bool followServerGuidelines;

EValue AccessSDK(void* ptr, std::string className, std::string fieldName, uint64_t path, EContext* state)
{
    if (!g_sdk.ExistsField(path)) return EValue(state);

    std::string& field = g_sdk.GetFieldName(path);

    if (followServerGuidelines && g_sdk.IsFieldBlocked(field))
    {
        PRINTF("Getting or setting %s::%s is not permitted due to %s Server Guidelines violation.\nTo get or set this value, switch to false the \"core.Follow%sServerGuidelines\" field.\nNote: Using non-compliant field values can result in a GSLT ban.\nNote: We are not providing any kind of support for people which are using these fields.\n", className.c_str(), fieldName.c_str(), str_toupper(GetGameName()).c_str(), str_toupper(GetGameName()).c_str());
        return EValue(state);
    }

    switch (g_sdk.GetFieldType(path))
    {
    case Bool:
        return EValue(state, schema::GetProp<bool>(ptr, className.c_str(), field.c_str()));
    case Int8:
        return EValue(state, schema::GetProp<int8_t>(ptr, className.c_str(), field.c_str()));
    case Int16:
        return EValue(state, schema::GetProp<int16_t>(ptr, className.c_str(), field.c_str()));
    case Int32:
        return EValue(state, schema::GetProp<int32_t>(ptr, className.c_str(), field.c_str()));
    case Int64:
        return EValue(state, schema::GetProp<int64_t>(ptr, className.c_str(), field.c_str()));
    case UInt8:
        return EValue(state, schema::GetProp<uint8_t>(ptr, className.c_str(), field.c_str()));
    case UInt16:
        return EValue(state, schema::GetProp<uint16_t>(ptr, className.c_str(), field.c_str()));
    case UInt32:
        return EValue(state, schema::GetProp<uint32_t>(ptr, className.c_str(), field.c_str()));
    case UInt64:
        return EValue(state, schema::GetProp<uint64_t>(ptr, className.c_str(), field.c_str()));
    case Float:
        return EValue(state, schema::GetProp<float>(ptr, className.c_str(), field.c_str()));
    case Double:
        return EValue(state, schema::GetProp<double>(ptr, className.c_str(), field.c_str()));
    case Parent:
        return MakeSDKClassInstance(field, ptr, state);
    case StringToken:
        return EValue(state, schema::GetProp<CUtlStringToken>(ptr, className.c_str(), field.c_str()).GetHashCode());
    case StringSymbolLarge:
        return EValue(state, std::string(schema::GetProp<CUtlSymbolLarge>(ptr, className.c_str(), field.c_str()).String()));
    case StringUtl:
        return EValue(state, std::string(schema::GetProp<CUtlString>(ptr, className.c_str(), field.c_str()).Get()));
    case String:
        return EValue(state, std::string(schema::GetPropPtr<char>(ptr, className.c_str(), field.c_str())));
    case Class:
        return MakeSDKClassInstance(g_sdk.GetFieldClass(path), schema::GetSchemaPtr(ptr, className.c_str(), field.c_str()), state);
    case SDKCHandle:
        return MakeSDKClassInstance(g_sdk.GetFieldClass(path), (void*)(schema::GetProp<CHandle<CEntityInstance>>(ptr, className.c_str(), field.c_str()).Get()), state);
    case EntityIndex:
        return EValue(state, schema::GetProp<CEntityIndex>(ptr, className.c_str(), field.c_str()).Get());
    case SColor:
        return MAKE_CLASS_INSTANCE_CTX(state, "Color", { { "Color_ptr", schema::GetProp<Color>(ptr, className.c_str(), field.c_str()) } });
    case SQAngle:
        return MAKE_CLASS_INSTANCE_CTX(state, "QAngle", { { "QAngle_ptr", schema::GetProp<QAngle>(ptr, className.c_str(), field.c_str()) } });
    case SVector:
        return MAKE_CLASS_INSTANCE_CTX(state, "Vector", { { "vector_ptr", schema::GetProp<Vector>(ptr, className.c_str(), field.c_str()) } });
    case SVector2D:
        return MAKE_CLASS_INSTANCE_CTX(state, "Vector2D", { { "Vector2D_ptr", schema::GetProp<Vector2D>(ptr, className.c_str(), field.c_str()) } });
    case SVector4D:
        return MAKE_CLASS_INSTANCE_CTX(state, "Vector4D", { { "Vector4D_ptr", schema::GetProp<Vector4D>(ptr, className.c_str(), field.c_str()) } });
    case ClassPointer:
        return MakeSDKClassInstance(g_sdk.GetFieldClass(path), *(void**)schema::GetSchemaPtr(ptr, className.c_str(), field.c_str()), state);
    case RawListEntityIndex: {
        CEntityIndex* outValue = schema::GetPropPtr<CEntityIndex>(ptr, className.c_str(), field.c_str());
        std::vector<int> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i].Get());

        return EValue(state, ret);
    }
    case StringSymbolLargeArray: {
        CUtlSymbolLarge* outValue = schema::GetPropPtr<CUtlSymbolLarge>(ptr, className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i].String());

        return EValue(state, ret);
    }
    case StringTokenArray: {
        CUtlStringToken* outValue = schema::GetPropPtr<CUtlStringToken>(ptr, className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i].GetHashCode());

        return EValue(state, ret);
    }
    case StringUtlArray: {
        CUtlString* outValue = schema::GetPropPtr<CUtlString>(ptr, className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i].Get());

        return EValue(state, ret);
    }
    case Int8Array: {
        int8_t* outValue = schema::GetPropPtr<int8_t>(ptr, className.c_str(), field.c_str());
        std::vector<int8_t> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case Int16Array: {
        int16_t* outValue = schema::GetPropPtr<int16_t>(ptr, className.c_str(), field.c_str());
        std::vector<int16_t> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case Int32Array: {
        int32_t* outValue = schema::GetPropPtr<int32_t>(ptr, className.c_str(), field.c_str());
        std::vector<int32_t> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case Int64Array: {
        int64_t* outValue = schema::GetPropPtr<int64_t>(ptr, className.c_str(), field.c_str());
        std::vector<int64_t> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case UInt8Array: {
        uint8_t* outValue = schema::GetPropPtr<uint8_t>(ptr, className.c_str(), field.c_str());
        std::vector<uint8_t> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case UInt16Array: {
        uint16_t* outValue = schema::GetPropPtr<uint16_t>(ptr, className.c_str(), field.c_str());
        std::vector<uint16_t> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case UInt32Array: {
        uint32_t* outValue = schema::GetPropPtr<uint32_t>(ptr, className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case UInt64Array: {
        uint64_t* outValue = schema::GetPropPtr<uint64_t>(ptr, className.c_str(), field.c_str());
        std::vector<uint64_t> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case FloatArray: {
        float* outValue = schema::GetPropPtr<float>(ptr, className.c_str(), field.c_str());
        std::vector<float> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case DoubleArray: {
        double* outValue = schema::GetPropPtr<double>(ptr, className.c_str(), field.c_str());
        std::vector<double> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case BoolArray: {
        bool* outValue = schema::GetPropPtr<bool>(ptr, className.c_str(), field.c_str());
        std::vector<bool> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return EValue(state, ret);
    }
    case SColorArray: {
        Color* outValue = schema::GetPropPtr<Color>(ptr, className.c_str(), field.c_str());
        std::vector<EValue> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(MAKE_CLASS_INSTANCE_CTX(state, "Color", { { "Color_ptr", outValue[i] } }));

        return EValue(state, ret);
    }
    case SQAngleArray: {
        QAngle* outValue = schema::GetPropPtr<QAngle>(ptr, className.c_str(), field.c_str());
        std::vector<EValue> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(MAKE_CLASS_INSTANCE_CTX(state, "QAngle", { { "QAngle_ptr", outValue[i] } }));

        return EValue(state, ret);
    }
    case SVectorArray: {
        Vector* outValue = schema::GetPropPtr<Vector>(ptr, className.c_str(), field.c_str());
        std::vector<EValue> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(MAKE_CLASS_INSTANCE_CTX(state, "Vector", { { "vector_ptr", outValue[i] } }));

        return EValue(state, ret);
    }
    case SVector2DArray: {
        Vector2D* outValue = schema::GetPropPtr<Vector2D>(ptr, className.c_str(), field.c_str());
        std::vector<EValue> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(MAKE_CLASS_INSTANCE_CTX(state, "Vector2D", { { "Vector2D_ptr", outValue[i] } }));

        return EValue(state, ret);
    }
    case SVector4DArray: {
        Vector4D* outValue = schema::GetPropPtr<Vector4D>(ptr, className.c_str(), field.c_str());
        std::vector<EValue> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(MAKE_CLASS_INSTANCE_CTX(state, "Vector4D", { { "Vector4D_ptr", outValue[i] } }));

        return EValue(state, ret);
    }
    case ClassArray: {
        void** outValue = schema::GetPropPtr<void*>(ptr, className.c_str(), field.c_str());
        std::vector<EValue> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(MakeSDKClassInstance(g_sdk.GetFieldClass(path), outValue[i], state));

        return EValue(state, ret);
    }
    case CHandleArray: {
        CHandle<CEntityInstance>* outValue = schema::GetPropPtr<CHandle<CEntityInstance>>(ptr, className.c_str(), field.c_str());
        std::vector<EValue> ret;
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            ret.push_back(MakeSDKClassInstance(g_sdk.GetFieldClass(path), (void*)outValue[i].Get(), state));

        return EValue(state, ret);
    }
    case CHandleCUtlVector: {
        CUtlVector<CHandle<CEntityInstance>>* vec = schema::GetPropPtr<CUtlVector<CHandle<CEntityInstance>>>(ptr, className.c_str(), field.c_str());
        std::vector<EValue> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(MakeSDKClassInstance(g_sdk.GetFieldClass(path), (void*)(vec->Element(i).Get()), state));

        return EValue(state, ret);
    }
    case StringSymbolLargeCUtlVector: {
        CUtlVector<CUtlSymbolLarge>* outValue = schema::GetPropPtr<CUtlVector<CUtlSymbolLarge>>(ptr, className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (int i = 0; i < outValue->Count(); i++)
            ret.push_back(outValue->Element(i).String());

        return EValue(state, ret);
    }
    case StringTokenCUtlVector: {
        CUtlVector<CUtlStringToken>* outValue = schema::GetPropPtr<CUtlVector<CUtlStringToken>>(ptr, className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (int i = 0; i < outValue->Count(); i++)
            ret.push_back(outValue->Element(i).GetHashCode());

        return EValue(state, ret);
    }
    case StringUtlCUtlVector: {
        CUtlVector<CUtlString>* outValue = schema::GetPropPtr<CUtlVector<CUtlString>>(ptr, className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (int i = 0; i < outValue->Count(); i++)
            ret.push_back(outValue->Element(i).Get());

        return EValue(state, ret);
    }
    case Int8CUtlVector: {
        CUtlVector<int8_t>* vec = schema::GetPropPtr<CUtlVector<int8_t>>(ptr, className.c_str(), field.c_str());
        std::vector<int8_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case Int16CUtlVector: {
        CUtlVector<int16_t>* vec = schema::GetPropPtr<CUtlVector<int16_t>>(ptr, className.c_str(), field.c_str());
        std::vector<int16_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case Int32CUtlVector: {
        CUtlVector<int32_t>* vec = schema::GetPropPtr<CUtlVector<int32_t>>(ptr, className.c_str(), field.c_str());
        std::vector<int32_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case Int64CUtlVector: {
        CUtlVector<int64_t>* vec = schema::GetPropPtr<CUtlVector<int64_t>>(ptr, className.c_str(), field.c_str());
        std::vector<int64_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case UInt8CUtlVector: {
        CUtlVector<uint8_t>* vec = schema::GetPropPtr<CUtlVector<uint8_t>>(ptr, className.c_str(), field.c_str());
        std::vector<uint8_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case UInt16CUtlVector: {
        CUtlVector<uint16_t>* vec = schema::GetPropPtr<CUtlVector<uint16_t>>(ptr, className.c_str(), field.c_str());
        std::vector<uint16_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case UInt32CUtlVector: {
        CUtlVector<uint32_t>* vec = schema::GetPropPtr<CUtlVector<uint32_t>>(ptr, className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case UInt64CUtlVector: {
        CUtlVector<uint64_t>* vec = schema::GetPropPtr<CUtlVector<uint64_t>>(ptr, className.c_str(), field.c_str());
        std::vector<uint64_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case FloatCUtlVector: {
        CUtlVector<float>* vec = schema::GetPropPtr<CUtlVector<float>>(ptr, className.c_str(), field.c_str());
        std::vector<float> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case DoubleCUtlVector: {
        CUtlVector<double>* vec = schema::GetPropPtr<CUtlVector<double>>(ptr, className.c_str(), field.c_str());
        std::vector<double> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    case SColorCUtlVector: {
        CUtlVector<Color>* vec = schema::GetPropPtr<CUtlVector<Color>>(ptr, className.c_str(), field.c_str());
        std::vector<EValue> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(MAKE_CLASS_INSTANCE_CTX(state, "Color", { { "Color_ptr", vec->Element(i) } }));

        return EValue(state, ret);
    }
    case SQAngleCUtlVector: {
        CUtlVector<QAngle>* vec = schema::GetPropPtr<CUtlVector<QAngle>>(ptr, className.c_str(), field.c_str());
        std::vector<EValue> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(MAKE_CLASS_INSTANCE_CTX(state, "QAngle", { { "QAngle_ptr", vec->Element(i) } }));

        return EValue(state, ret);
    }
    case SVectorCUtlVector: {
        CUtlVector<Vector>* vec = schema::GetPropPtr<CUtlVector<Vector>>(ptr, className.c_str(), field.c_str());
        std::vector<EValue> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(MAKE_CLASS_INSTANCE_CTX(state, "Vector", { { "vector_ptr", vec->Element(i) } }));

        return EValue(state, ret);
    }
    case SVector2DCUtlVector: {
        CUtlVector<Vector2D>* vec = schema::GetPropPtr<CUtlVector<Vector2D>>(ptr, className.c_str(), field.c_str());
        std::vector<EValue> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(MAKE_CLASS_INSTANCE_CTX(state, "Vector2D", { { "Vector2D_ptr", vec->Element(i) } }));

        return EValue(state, ret);
    }
    case SVector4DCUtlVector: {
        CUtlVector<Vector4D>* vec = schema::GetPropPtr<CUtlVector<Vector4D>>(ptr, className.c_str(), field.c_str());
        std::vector<EValue> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(MAKE_CLASS_INSTANCE_CTX(state, "Vector4D", { { "Vector4D_ptr", vec->Element(i) } }));

        return EValue(state, ret);
    }
    case BoolCUtlVector: {
        CUtlVector<bool>* vec = schema::GetPropPtr<CUtlVector<bool>>(ptr, className.c_str(), field.c_str());
        std::vector<bool> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return EValue(state, ret);
    }
    }

    return EValue(state, fieldName);
}

void UpdateSDK(void* ptr, std::string className, std::string fieldName, EValue value, EContext* state)
{
    uint64 path = ((uint64_t)hash_32_fnv1a_const(className.c_str()) << 32 | hash_32_fnv1a_const(fieldName.c_str()));
    if (!g_sdk.ExistsField(path)) return;

    std::string& field = g_sdk.GetFieldName(path);

    if (followServerGuidelines && g_sdk.IsFieldBlocked(field))
    {
        PRINTF("Getting or setting %s::%s is not permitted due to %s Server Guidelines violation.\nTo get or set this value, switch to false the \"core.Follow%sServerGuidelines\" field.\nNote: Using non-compliant field values can result in a GSLT ban.\nNote: We are not providing any kind of support for people which are using these fields.\n", className.c_str(), fieldName.c_str(), str_toupper(GetGameName()).c_str(), str_toupper(GetGameName()).c_str());
        return;
    }

    switch (g_sdk.GetFieldType(path))
    {
    case Bool:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<bool>());
    case Int8:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<int8_t>());
    case Int16:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<int16_t>());
    case Int32:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<int32_t>());
    case Int64:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<int64_t>());
    case UInt8:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<uint8_t>());
    case UInt16:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<uint16_t>());
    case UInt32:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<uint32_t>());
    case UInt64:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<uint64_t>());
    case Float:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<float>());
    case Double:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<double>());
    case StringToken:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), CUtlStringToken(value.cast<uint32_t>()));
    case StringSymbolLarge:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), CUtlSymbolLarge(strdup(value.cast<std::string>().c_str())));
    case StringUtl:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), CUtlString(strdup(value.cast<std::string>().c_str())));
    case String:
        return schema::WriteSchemaPtrValue(ptr, className.c_str(), field.c_str(), reinterpret_cast<byte*>(const_cast<char*>(value.cast<std::string>().c_str())), g_sdk.GetFieldSize(path));
    case EntityIndex:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), CEntityIndex(value.cast<int>()));
    case SColor:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<ClassData*>()->GetData<Color>("Color_ptr"));
    case SQAngle:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<ClassData*>()->GetData<QAngle>("QAngle_ptr"));
    case SVector:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<ClassData*>()->GetData<Vector>("vector_ptr"));
    case SVector2D:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<ClassData*>()->GetData<Vector2D>("Vector2D_ptr"));
    case SVector4D:
        return schema::SetProp(ptr, className.c_str(), field.c_str(), value.cast<ClassData*>()->GetData<Vector4D>("Vector4D_ptr"));
    case RawListEntityIndex: {
        auto val = schema::GetPropPtr<CEntityIndex>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            val[i] = CEntityIndex(ret[i]);

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case StringSymbolLargeArray: {
        auto val = schema::GetPropPtr<CUtlSymbolLarge>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<std::string>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++) {
            val[i] = CUtlSymbolLarge(ret[i].c_str());
        }

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case StringTokenArray: {
        auto val = schema::GetPropPtr<CUtlStringToken>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint32_t>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            val[i] = CUtlStringToken(ret[i]);

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case StringUtlArray: {
        auto val = schema::GetPropPtr<CUtlString>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<std::string>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            val[i] = CUtlString(ret[i].c_str());

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case Int8Array: {
        auto outValue = schema::GetPropPtr<int8_t>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int8_t>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case Int16Array: {
        auto outValue = schema::GetPropPtr<int16_t>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int16_t>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case Int32Array: {
        auto outValue = schema::GetPropPtr<int32_t>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int32_t>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case Int64Array: {
        auto outValue = schema::GetPropPtr<int64_t>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int64_t>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case UInt8Array: {
        auto outValue = schema::GetPropPtr<uint8_t>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint8_t>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case UInt16Array: {
        auto outValue = schema::GetPropPtr<uint16_t>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint16_t>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case UInt32Array: {
        auto outValue = schema::GetPropPtr<uint32_t>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint32_t>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case UInt64Array: {
        auto outValue = schema::GetPropPtr<uint64_t>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint64_t>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case FloatArray: {
        auto outValue = schema::GetPropPtr<float>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<float>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case DoubleArray: {
        auto outValue = schema::GetPropPtr<double>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<double>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case SDKCHandle: {
        if (!value.isInstance<ClassData*>()) return;

        auto outVal = schema::GetPropPtr<CHandle<CEntityInstance>>(ptr, className.c_str(), field.c_str());
        outVal->Set((CEntityInstance*)(value.cast<ClassData*>()->GetDataOr<void*>("class_ptr", nullptr)));

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case CHandleArray: {
        auto outValue = schema::GetPropPtr<CHandle<CEntityInstance>>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<EValue>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++) {
            if (!ret[i].isInstance<ClassData*>()) continue;
            outValue[i].Set((CEntityInstance*)(ret[i].cast<ClassData*>()->GetDataOr<void*>("class_ptr", nullptr)));
        }

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case CHandleCUtlVector: {
        auto ret = value.cast<std::vector<EValue>>();

        auto m_key = sch::GetOffset(className.c_str(), field.c_str());

        SetStateChanged((uintptr_t)ptr, className, field, 0);

        CUtlVector<CHandle<CEntityInstance>>* vec = reinterpret_cast<CUtlVector<CHandle<CEntityInstance>> *>((uintptr_t)(ptr)+m_key);
        FOR_EACH_VEC(*vec, i) {
            if (!ret[i].isInstance<ClassData*>()) continue;
            vec->Element(i).Set((CEntityInstance*)(ret[i].cast<ClassData*>()->GetDataOr<void*>("class_ptr", nullptr)));
        }

        SetStateChanged((uintptr_t)ptr, className, field, 0);

        return;
    }
    case BoolArray: {
        auto outValue = schema::GetPropPtr<bool>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<bool>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++)
            outValue[i] = ret[i];

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case SColorArray: {
        auto outValue = schema::GetPropPtr<Color>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<EValue>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++) {
            if (!ret[i].isInstance<ClassData*>()) continue;
            outValue[i] = ret[i].cast<ClassData*>()->GetDataOr<Color>("Color_ptr", outValue[i]);
        }

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case SQAngleArray: {
        auto outValue = schema::GetPropPtr<QAngle>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<EValue>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++) {
            if (!ret[i].isInstance<ClassData*>()) continue;
            outValue[i] = ret[i].cast<ClassData*>()->GetDataOr<QAngle>("QAngle_ptr", outValue[i]);
        }

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case SVectorArray: {
        auto outValue = schema::GetPropPtr<Vector>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<EValue>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++) {
            if (!ret[i].isInstance<ClassData*>()) continue;
            outValue[i] = ret[i].cast<ClassData*>()->GetDataOr<Vector>("vector_ptr", outValue[i]);
        }

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case SVector2DArray: {
        auto outValue = schema::GetPropPtr<Vector2D>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<EValue>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++) {
            if (!ret[i].isInstance<ClassData*>()) continue;
            outValue[i] = ret[i].cast<ClassData*>()->GetDataOr<Vector2D>("Vector2D_ptr", outValue[i]);
        }

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case SVector4DArray: {
        auto outValue = schema::GetPropPtr<Vector4D>(ptr, className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<EValue>>();
        for (uint32_t i = 0; i < g_sdk.GetFieldSize(path); i++) {
            if (!ret[i].isInstance<ClassData*>()) continue;
            outValue[i] = ret[i].cast<ClassData*>()->GetDataOr<Vector4D>("Vector4D_ptr", outValue[i]);
        }

        SetStateChanged((uintptr_t)ptr, className.c_str(), field.c_str(), 0);
        return;
    }
    case StringSymbolLargeCUtlVector: {
        std::vector<CUtlSymbolLarge> newValues;
        auto val = value.cast<std::vector<std::string>>();
        for (auto elem : val)
            newValues.push_back(CUtlSymbolLarge(elem.c_str()));

        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), newValues);
    }
    case StringTokenCUtlVector: {
        std::vector<CUtlStringToken> newValues;
        auto val = value.cast<std::vector<uint32_t>>();
        for (auto elem : val)
            newValues.push_back(CUtlStringToken(elem));

        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), newValues);
    }
    case StringUtlCUtlVector: {
        std::vector<CUtlString> newValues;
        auto val = value.cast<std::vector<std::string>>();
        for (auto elem : val)
            newValues.push_back(CUtlString(elem.c_str()));

        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), newValues);
    }
    case Int8CUtlVector:
        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), value.cast<std::vector<int8_t>>());
    case Int16CUtlVector:
        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), value.cast<std::vector<int16_t>>());
    case Int32CUtlVector:
        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), value.cast<std::vector<int32_t>>());
    case Int64CUtlVector:
        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), value.cast<std::vector<int64_t>>());
    case UInt8CUtlVector:
        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), value.cast<std::vector<uint8_t>>());
    case UInt16CUtlVector:
        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), value.cast<std::vector<uint16_t>>());
    case UInt32CUtlVector:
        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), value.cast<std::vector<uint32_t>>());
    case UInt64CUtlVector:
        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), value.cast<std::vector<uint64_t>>());
    case FloatCUtlVector:
        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), value.cast<std::vector<float>>());
    case DoubleCUtlVector:
        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), value.cast<std::vector<double>>());
    case SColorCUtlVector: {
        std::vector<Color> newValues;
        auto val = value.cast<std::vector<EValue>>();
        for (auto elem : val)
            newValues.push_back(elem.cast<ClassData*>()->GetData<Color>("Color_ptr"));

        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), newValues);
    }
    case SQAngleCUtlVector: {
        std::vector<QAngle> newValues;
        auto val = value.cast<std::vector<EValue>>();
        for (auto elem : val)
            newValues.push_back(elem.cast<ClassData*>()->GetData<QAngle>("QAngle_ptr"));

        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), newValues);
    }
    case SVectorCUtlVector: {
        std::vector<Vector> newValues;
        auto val = value.cast<std::vector<EValue>>();
        for (auto elem : val)
            newValues.push_back(elem.cast<ClassData*>()->GetData<Vector>("vector_ptr"));

        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), newValues);
    }
    case SVector2DCUtlVector: {
        std::vector<Vector2D> newValues;
        auto val = value.cast<std::vector<EValue>>();
        for (auto elem : val)
            newValues.push_back(elem.cast<ClassData*>()->GetData<Vector2D>("Vector2D_ptr"));

        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), newValues);
    }
    case SVector4DCUtlVector: {
        std::vector<Vector4D> newValues;
        auto val = value.cast<std::vector<EValue>>();
        for (auto elem : val)
            newValues.push_back(elem.cast<ClassData*>()->GetData<Vector4D>("Vector4D_ptr"));

        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), newValues);
    }
    case BoolCUtlVector:
        return schema::SetPropCUtlVector(ptr, className.c_str(), field.c_str(), value.cast<std::vector<bool>>());
    }
}