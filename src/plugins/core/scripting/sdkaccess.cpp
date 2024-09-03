#include "../scripting.h"
#include "../../../sdk/sdkaccess.h"
#include "../../../sdk/entity/CBasePlayerController.h"
#include "../../../sdk/entity/CBaseModelEntity.h"
#include "../../../sdk/entity/CBaseEntity.h"
#include "../../../sdk/entity/CCSWeaponBase.h"
#include "../../../player/PlayerManager.h"

std::string FetchPluginName(lua_State* state);

int CBasePlayerController_EntityIndex(SDKBaseClass* _this) {
    return ((CBasePlayerController*)_this->GetPtr())->GetEntityIndex().Get();
}

void CAttributeList_SetOrAddAttributeValueByName(SDKBaseClass* _this, std::string str, float value) {
    ((CAttributeList*)_this->GetPtr())->SetOrAddAttributeValueByName(str.c_str(), value);
}

void CBaseModelEntity_SetModel(SDKBaseClass* _this, std::string model)
{
    ((CBaseModelEntity*)_this->GetPtr())->SetModel(model.c_str());
}

void CBaseModelEntity_SetSolidType(SDKBaseClass* _this, int64_t solidType)
{
    ((CBaseModelEntity*)_this->GetPtr())->SetSolidType((SolidType_t)solidType);
}

void CBaseModelEntity_SetBodygroup(SDKBaseClass* _this, std::string str, int64_t val)
{
    ((CBaseModelEntity*)_this->GetPtr())->SetBodygroup(str.c_str(), (uint64_t)val);
}

SDKBaseClass CBaseEntity_EHandle(SDKBaseClass* _this) {
    return SDKBaseClass(((CBaseEntity*)_this->GetPtr())->m_pEntity->m_EHandle.Get(), "CBaseEntity");
}

void CBaseEntity_Spawn(SDKBaseClass* _this) {
    ((CBaseEntity*)_this->GetPtr())->DispatchSpawn();
}

void CBaseEntity_Despawn(SDKBaseClass* _this) {
    ((CBaseEntity*)_this->GetPtr())->Despawn();
}

void CBaseEntity_AcceptInput(SDKBaseClass* _this, std::string input, SDKBaseClass activator, SDKBaseClass caller, std::string value, int outputID) {
    ((CBaseEntity*)_this->GetPtr())->AcceptInput(input.c_str(), (CEntityInstance*)activator.GetPtr(), (CEntityInstance*)caller.GetPtr(), value.c_str(), outputID);
}

std::string CBaseEntity_GetClassname(SDKBaseClass* _this) {
    return ((CBaseEntity*)_this->GetPtr())->GetClassname();
}

SDKBaseClass CBaseEntity_GetVData(SDKBaseClass* _this) {
    return SDKBaseClass(((CBaseEntity*)_this->GetPtr())->GetVData(), "CEntitySubclassVDataBase");
}

void CBaseEntity_Teleport(SDKBaseClass* _this, Vector value, QAngle angle) {
    ((CBaseEntity*)_this->GetPtr())->Teleport(&value, &angle, nullptr);
}

void CBaseEntity_EmitSound(SDKBaseClass* _this, std::string sound_name, float pitch, float volume) {
    for (int i = 0; i < g_playerManager->GetPlayerCap(); i++) {
        Player* player = g_playerManager->GetPlayer(i);
        if (!player) continue;
        if (player->IsFakeClient()) continue;
        if ((void*)player->GetPlayerController() == _this->GetPtr()) {
            CSingleRecipientFilter filter(i);
            ((CBaseEntity*)_this->GetPtr())->EmitSoundFilter(filter, sound_name, pitch, volume);
            break;
        }
    }
}

SDKBaseClass::SDKBaseClass(std::string ptr, lua_State* state)
{
    this->m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));

    lua_getmetatable(state, -1);
    lua_rawgetp(state, -1, reinterpret_cast<void*>(0x71));
    this->m_className = lua_tostring(state, -1);
    lua_pop(state, 2);
}

SDKBaseClass::SDKBaseClass(void* ptr, lua_State* state)
{
    this->m_ptr = ptr;

    lua_getmetatable(state, -1);
    lua_rawgetp(state, -1, reinterpret_cast<void*>(0x71));
    this->m_className = lua_tostring(state, -1);
    lua_pop(state, 2);
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

int SDKBaseClass::IndexFunc(lua_State* state)
{
    std::string field_name = luabridge::LuaRef::fromStack(state, 2).cast<std::string>();
    auto ref = this->AccessSDKLua(field_name, state);

    if (ref.isNil())
        luabridge::detail::CFunc::indexMetaMethod(state);
    else
        ref.push();

    return 1;
}

luabridge::LuaRef SDKBaseClass::AccessSDKLua(std::string fieldName, lua_State* state)
{
    REGISTER_CALLSTACK(FetchPluginName(state), string_format("SDK Get: %s::%s(ptr=%p)", this->m_className.c_str(), fieldName.c_str(), m_ptr));
    std::string path = this->m_className + "." + fieldName;
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
        CEntityIndex* outValue = GetSchemaValue<CEntityIndex*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i].Get());

        return luabridge::LuaRef(state, ret);
    }
    case StringSymbolLargeArray: {
        CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i].String());

        return luabridge::LuaRef(state, ret);
    }
    case StringTokenArray: {
        CUtlStringToken* outValue = GetSchemaValue<CUtlStringToken*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i].m_nHashCode);

        return luabridge::LuaRef(state, ret);
    }
    case StringUtlArray: {
        CUtlString* outValue = GetSchemaValue<CUtlString*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i].Get());

        return luabridge::LuaRef(state, ret);
    }
    case Int8Array: {
        int8_t* outValue = GetSchemaValue<int8_t*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int8_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case Int16Array: {
        int16_t* outValue = GetSchemaValue<int16_t*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int16_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case Int32Array: {
        int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int32_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case Int64Array: {
        int64_t* outValue = GetSchemaValue<int64_t*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int64_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case UInt8Array: {
        uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint8_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case UInt16Array: {
        uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint16_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case UInt32Array: {
        uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case UInt64Array: {
        uint64_t* outValue = GetSchemaValue<uint64_t*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint64_t> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case FloatArray: {
        float* outValue = GetSchemaValue<float*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<float> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case DoubleArray: {
        double* outValue = GetSchemaValue<double*>(m_ptr, this->m_className.c_str(), field.c_str());
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
        Color* outValue = GetSchemaValue<Color*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Color> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case SQAngleArray: {
        QAngle* outValue = GetSchemaValue<QAngle*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<QAngle> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case SVectorArray: {
        Vector* outValue = GetSchemaValue<Vector*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case SVector2DArray: {
        Vector2D* outValue = GetSchemaValue<Vector2D*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector2D> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case SVector4DArray: {
        Vector4D* outValue = GetSchemaValue<Vector4D*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector4D> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(outValue[i]);

        return luabridge::LuaRef(state, ret);
    }
    case ClassArray: {
        void** outValue = GetSchemaValue<void**>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<SDKBaseClass> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(SDKBaseClass(outValue[i], g_sdk->GetFieldClass(path)));

        return luabridge::LuaRef(state, ret);
    }
    case CHandleArray: {
        CHandle<CEntityInstance>* outValue = GetSchemaValue<CHandle<CEntityInstance>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<SDKBaseClass> ret;
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            ret.push_back(SDKBaseClass((void*)outValue[i].Get(), g_sdk->GetFieldClass(path)));

        return luabridge::LuaRef(state, ret);
    }
    case CHandleCUtlVector: {
        CUtlVector<CHandle<CEntityInstance>>* vec = GetSchemaValue<CUtlVector<CHandle<CEntityInstance>>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<SDKBaseClass> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(SDKBaseClass((void*)(vec->Element(i).Get()), g_sdk->GetFieldClass(path)));

        return luabridge::LuaRef(state, ret);
    }
    case StringSymbolLargeCUtlVector: {
        CUtlVector<CUtlSymbolLarge>* outValue = GetSchemaValue<CUtlVector<CUtlSymbolLarge>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (int i = 0; i < outValue->Count(); i++)
            ret.push_back(outValue->Element(i).String());

        return luabridge::LuaRef(state, ret);
    }
    case StringTokenCUtlVector: {
        CUtlVector<CUtlStringToken>* outValue = GetSchemaValue<CUtlVector<CUtlStringToken>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (int i = 0; i < outValue->Count(); i++)
            ret.push_back(outValue->Element(i).m_nHashCode);

        return luabridge::LuaRef(state, ret);
    }
    case StringUtlCUtlVector: {
        CUtlVector<CUtlString>* outValue = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<std::string> ret;
        for (int i = 0; i < outValue->Count(); i++)
            ret.push_back(outValue->Element(i).Get());

        return luabridge::LuaRef(state, ret);
    }
    case Int8CUtlVector: {
        CUtlVector<int8_t>* vec = GetSchemaValue<CUtlVector<int8_t>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int8_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case Int16CUtlVector: {
        CUtlVector<int16_t>* vec = GetSchemaValue<CUtlVector<int16_t>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int16_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case Int32CUtlVector: {
        CUtlVector<int32_t>* vec = GetSchemaValue<CUtlVector<int32_t>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int32_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case Int64CUtlVector: {
        CUtlVector<int64_t>* vec = GetSchemaValue<CUtlVector<int64_t>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<int64_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case UInt8CUtlVector: {
        CUtlVector<uint8_t>* vec = GetSchemaValue<CUtlVector<uint8_t>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint8_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case UInt16CUtlVector: {
        CUtlVector<uint16_t>* vec = GetSchemaValue<CUtlVector<uint16_t>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint16_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case UInt32CUtlVector: {
        CUtlVector<uint32_t>* vec = GetSchemaValue<CUtlVector<uint32_t>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint32_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case UInt64CUtlVector: {
        CUtlVector<uint64_t>* vec = GetSchemaValue<CUtlVector<uint64_t>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<uint64_t> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case FloatCUtlVector: {
        CUtlVector<float>* vec = GetSchemaValue<CUtlVector<float>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<float> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case DoubleCUtlVector: {
        CUtlVector<double>* vec = GetSchemaValue<CUtlVector<double>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<double> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case SColorCUtlVector: {
        CUtlVector<Color>* vec = GetSchemaValue<CUtlVector<Color>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Color> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case SQAngleCUtlVector: {
        CUtlVector<QAngle>* vec = GetSchemaValue<CUtlVector<QAngle>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<QAngle> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case SVectorCUtlVector: {
        CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case SVector2DCUtlVector: {
        CUtlVector<Vector2D>* vec = GetSchemaValue<CUtlVector<Vector2D>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector2D> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case SVector4DCUtlVector: {
        CUtlVector<Vector4D>* vec = GetSchemaValue<CUtlVector<Vector4D>*>(m_ptr, this->m_className.c_str(), field.c_str());
        std::vector<Vector4D> ret;
        for (int i = 0; i < vec->Count(); i++)
            ret.push_back(vec->Element(i));

        return luabridge::LuaRef(state, ret);
    }
    case BoolCUtlVector: {
        CUtlVector<bool>* vec = GetSchemaValue<CUtlVector<bool>*>(m_ptr, this->m_className.c_str(), field.c_str());
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
    REGISTER_CALLSTACK(FetchPluginName(state), string_format("SDK Set: %s::%s(ptr=%p)", this->m_className.c_str(), fieldName.c_str(), m_ptr));
    std::string path = this->m_className + "." + fieldName;
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
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), CUtlSymbolLarge(value.cast<std::string>().c_str()));
    case StringUtl:
        return SetSchemaValue(m_ptr, this->m_className.c_str(), field.c_str(), g_sdk->GetClassStructState(this->m_className), CUtlString(value.cast<std::string>().c_str()));
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

        return;
    }
    case StringSymbolLargeArray: {
        auto val = GetSchemaValuePtr<CUtlSymbolLarge>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<std::string>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            val[i] = CUtlSymbolLarge(ret[i].c_str());

        return;
    }
    case StringTokenArray: {
        auto val = GetSchemaValuePtr<CUtlStringToken>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint32_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            val[i] = CUtlStringToken(ret[i]);

        return;
    }
    case StringUtlArray: {
        auto val = GetSchemaValuePtr<CUtlString>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<std::string>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            val[i] = CUtlString(ret[i].c_str());

        return;
    }
    case Int8Array: {
        auto outValue = GetSchemaValuePtr<int8_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int8_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case Int16Array: {
        auto outValue = GetSchemaValuePtr<int16_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int16_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case Int32Array: {
        auto outValue = GetSchemaValuePtr<int32_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int32_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case Int64Array: {
        auto outValue = GetSchemaValuePtr<int64_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<int64_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case UInt8Array: {
        auto outValue = GetSchemaValuePtr<uint8_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint8_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case UInt16Array: {
        auto outValue = GetSchemaValuePtr<uint16_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint16_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case UInt32Array: {
        auto outValue = GetSchemaValuePtr<uint32_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint32_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case UInt64Array: {
        auto outValue = GetSchemaValuePtr<uint64_t>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<uint64_t>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case FloatArray: {
        auto outValue = GetSchemaValuePtr<float>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<float>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case DoubleArray: {
        auto outValue = GetSchemaValuePtr<double>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<double>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case BoolArray: {
        auto outValue = GetSchemaValuePtr<bool>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<bool>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case SColorArray: {
        auto outValue = GetSchemaValuePtr<Color>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<Color>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case SQAngleArray: {
        auto outValue = GetSchemaValuePtr<QAngle>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<QAngle>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case SVectorArray: {
        auto outValue = GetSchemaValuePtr<Vector>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<Vector>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case SVector2DArray: {
        auto outValue = GetSchemaValuePtr<Vector2D>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<Vector2D>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

        return;
    }
    case SVector4DArray: {
        auto outValue = GetSchemaValuePtr<Vector4D>(m_ptr, this->m_className.c_str(), field.c_str());
        auto ret = value.cast<std::vector<Vector4D>>();
        for (uint32_t i = 0; i < g_sdk->GetFieldSize(path); i++)
            outValue[i] = ret[i];

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