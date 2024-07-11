#include "../scripting.h"

#include "../../../sdk/entity/CRecipientFilters.h"

#ifdef GetMessage
#undef GetMessage
#endif

#define GETCHECK_FIELD(return_value)                                                                                  \
    const google::protobuf::FieldDescriptor *field = this->msgBuffer->GetDescriptor()->FindFieldByName(pszFieldName); \
    if (!field)                                                                                                       \
    {                                                                                                                 \
        return return_value;                                                                                          \
    }

#define CHECK_FIELD_NOT_REPEATED(return_value)                               \
    if (field->label() == google::protobuf::FieldDescriptor::LABEL_REPEATED) \
    {                                                                        \
        return return_value;                                                 \
    }

#define CHECK_FIELD_TYPE_VOID(type)                                             \
    if (field->cpp_type() != google::protobuf::FieldDescriptor::CPPTYPE_##type) \
    {                                                                           \
        return;                                                                 \
    }

#define CHECK_FIELD_TYPE(type, return_value)                                    \
    if (field->cpp_type() != google::protobuf::FieldDescriptor::CPPTYPE_##type) \
    {                                                                           \
        return return_value;                                                    \
    }

#define CHECK_FIELD_TYPE2_VOID(type1, type2)                                                                                                \
    google::protobuf::FieldDescriptor::CppType fieldType = field->cpp_type();                                                               \
    if (fieldType != google::protobuf::FieldDescriptor::CPPTYPE_##type1 && fieldType != google::protobuf::FieldDescriptor::CPPTYPE_##type2) \
    {                                                                                                                                       \
        return;                                                                                                                             \
    }

#define CHECK_FIELD_TYPE2(type1, type2, return_value)                                                                                       \
    google::protobuf::FieldDescriptor::CppType fieldType = field->cpp_type();                                                               \
    if (fieldType != google::protobuf::FieldDescriptor::CPPTYPE_##type1 && fieldType != google::protobuf::FieldDescriptor::CPPTYPE_##type2) \
    {                                                                                                                                       \
        return return_value;                                                                                                                \
    }

#define CHECK_FIELD_REPEATED(return_value)                                   \
    if (field->label() != google::protobuf::FieldDescriptor::LABEL_REPEATED) \
    {                                                                        \
        return return_value;                                                 \
    }

#define CHECK_REPEATED_ELEMENT_VOID(idx)                                                  \
    int elemCount = this->msgBuffer->GetReflection()->FieldSize(*this->msgBuffer, field); \
    if (elemCount == 0 || idx >= elemCount || idx < 0)                                    \
    {                                                                                     \
        return;                                                                           \
    }

#define CHECK_REPEATED_ELEMENT(idx, return_value)                                         \
    int elemCount = this->msgBuffer->GetReflection()->FieldSize(*this->msgBuffer, field); \
    if (elemCount == 0 || idx >= elemCount || idx < 0)                                    \
    {                                                                                     \
        return return_value;                                                              \
    }

PluginUserMessage::PluginUserMessage(std::string msgname)
{
    this->msgid = INVALID_MESSAGE_ID;

    auto msg = g_pNetworkMessages->FindNetworkMessagePartial(msgname.c_str());
    if (!msg)
        return;

    NetMessageInfo_t *msginfo = msg->GetNetMessageInfo();
    if (!msginfo)
        return;

    this->msgid = msginfo->m_MessageId;
    this->msgBuffer = msg->AllocateMessage()->ToPB<google::protobuf::Message>();
    this->internalMsg = msg;
}

PluginUserMessage::~PluginUserMessage()
{
    if (!this->internalMsg)
        return;
    if (!this->msgBuffer)
        return;

    this->internalMsg->DeallocateMessage(this->msgBuffer);
}

bool PluginUserMessage::IsValidMessage()
{
    return (this->msgid != INVALID_MESSAGE_ID);
}

std::string PluginUserMessage::GetMessageName()
{
    if (this->msgid == INVALID_MESSAGE_ID)
        return "";

    if (!this->internalMsg)
        return "";

    return this->internalMsg->GetUnscopedName();
}

int PluginUserMessage::GetMessageID()
{
    return this->msgid;
}
bool PluginUserMessage::HasField(const char *pszFieldName)
{
    if (!this->msgBuffer)
        return false;

    GETCHECK_FIELD(false)
    CHECK_FIELD_NOT_REPEATED(false)
    return this->msgBuffer->GetReflection()->HasField(*this->msgBuffer, field);
}
int32 PluginUserMessage::GetInt32(const char *pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(INT32, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    return this->msgBuffer->GetReflection()->GetInt32(*this->msgBuffer, field);
}
void PluginUserMessage::SetInt32(const char *pszFieldName, int32 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(INT32);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetInt32(this->msgBuffer, field, value);
}
int32 PluginUserMessage::GetRepeatedInt32(const char *pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(INT32, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    return this->msgBuffer->GetReflection()->GetRepeatedInt32(*this->msgBuffer, field, index);
}

void PluginUserMessage::SetRepeatedInt32(const char *pszFieldName, int index, int32 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(INT32);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedInt32(this->msgBuffer, field, index, value);
}
void PluginUserMessage::AddInt32(const char *pszFieldName, int32 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(INT32);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddInt32(this->msgBuffer, field, value);
}
int64 PluginUserMessage::GetInt64(const char *pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(INT64, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    return this->msgBuffer->GetReflection()->GetInt64(*this->msgBuffer, field);
}
void PluginUserMessage::SetInt64(const char *pszFieldName, int64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(INT64);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetInt64(this->msgBuffer, field, value);
}
int64 PluginUserMessage::GetRepeatedInt64(const char *pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(INT64, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    return this->msgBuffer->GetReflection()->GetRepeatedInt64(*this->msgBuffer, field, index);
}
void PluginUserMessage::SetRepeatedInt64(const char *pszFieldName, int index, int64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(INT64);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedInt64(this->msgBuffer, field, index, value);
}
void PluginUserMessage::AddInt64(const char *pszFieldName, int64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(INT64);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddInt64(this->msgBuffer, field, value);
}
uint32 PluginUserMessage::GetUInt32(const char *pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(UINT32, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    return this->msgBuffer->GetReflection()->GetUInt32(*this->msgBuffer, field);
}
void PluginUserMessage::SetUInt32(const char *pszFieldName, uint32 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(UINT32);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetUInt32(this->msgBuffer, field, value);
}
uint32 PluginUserMessage::GetRepeatedUInt32(const char *pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(UINT32, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    return this->msgBuffer->GetReflection()->GetRepeatedUInt32(*this->msgBuffer, field, index);
}
void PluginUserMessage::SetRepeatedUInt32(const char *pszFieldName, int index, uint32 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(UINT32);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedUInt32(this->msgBuffer, field, index, value);
}
void PluginUserMessage::AddUInt32(const char *pszFieldName, uint32 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(UINT32);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddUInt32(this->msgBuffer, field, value);
}
uint64 PluginUserMessage::GetUInt64(const char *pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(UINT64, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    return this->msgBuffer->GetReflection()->GetUInt64(*this->msgBuffer, field);
}
void PluginUserMessage::SetUInt64(const char *pszFieldName, uint64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(UINT64);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetUInt64(this->msgBuffer, field, value);
}
uint64 PluginUserMessage::GetRepeatedUInt64(const char *pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(UINT64, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    return this->msgBuffer->GetReflection()->GetRepeatedUInt64(*this->msgBuffer, field, index);
}
void PluginUserMessage::SetRepeatedUInt64(const char *pszFieldName, int index, uint64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(UINT64);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedUInt64(this->msgBuffer, field, index, value);
}
void PluginUserMessage::AddUInt64(const char *pszFieldName, uint64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(UINT64);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddUInt64(this->msgBuffer, field, value);
}
int64 PluginUserMessage::GetInt64OrUnsigned(const char *pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE2(INT64, UINT64, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
        return (int64)this->msgBuffer->GetReflection()->GetUInt64(*this->msgBuffer, field);
    else
        return this->msgBuffer->GetReflection()->GetInt64(*this->msgBuffer, field);
}
void PluginUserMessage::SetInt64OrUnsigned(const char *pszFieldName, int64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2_VOID(INT64, UINT64);
    CHECK_FIELD_NOT_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
    {
        this->msgBuffer->GetReflection()->SetUInt64(this->msgBuffer, field, (uint64)value);
    }
    else
    {
        this->msgBuffer->GetReflection()->SetInt64(this->msgBuffer, field, value);
    }
}
int64 PluginUserMessage::GetRepeatedInt64OrUnsigned(const char *pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE2(INT64, UINT64, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
        return (int64)this->msgBuffer->GetReflection()->GetRepeatedUInt64(*this->msgBuffer, field, index);
    else
        return this->msgBuffer->GetReflection()->GetRepeatedInt64(*this->msgBuffer, field, index);
}
void PluginUserMessage::SetRepeatedInt64OrUnsigned(const char *pszFieldName, int index, int64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2_VOID(INT64, UINT64);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
    {
        this->msgBuffer->GetReflection()->SetRepeatedUInt64(this->msgBuffer, field, index, (uint64)value);
    }
    else
    {
        this->msgBuffer->GetReflection()->SetRepeatedInt64(this->msgBuffer, field, index, value);
    }
}
void PluginUserMessage::AddInt64OrUnsigned(const char *pszFieldName, int64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2_VOID(INT64, UINT64);
    CHECK_FIELD_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
    {
        this->msgBuffer->GetReflection()->AddUInt64(this->msgBuffer, field, (uint64)value);
    }
    else
    {
        this->msgBuffer->GetReflection()->AddInt64(this->msgBuffer, field, value);
    }
}
bool PluginUserMessage::GetBool(const char *pszFieldName)
{
    GETCHECK_FIELD(false);
    CHECK_FIELD_TYPE(BOOL, false);
    CHECK_FIELD_NOT_REPEATED(false);

    return this->msgBuffer->GetReflection()->GetBool(*this->msgBuffer, field);
}
void PluginUserMessage::SetBool(const char *pszFieldName, bool value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(BOOL);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetBool(this->msgBuffer, field, value);
}
bool PluginUserMessage::GetRepeatedBool(const char *pszFieldName, int index)
{
    GETCHECK_FIELD(false);
    CHECK_FIELD_TYPE(BOOL, false);
    CHECK_FIELD_REPEATED(false);
    CHECK_REPEATED_ELEMENT(index, false);

    return this->msgBuffer->GetReflection()->GetRepeatedBool(*this->msgBuffer, field, index);
}
void PluginUserMessage::SetRepeatedBool(const char *pszFieldName, int index, bool value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(BOOL);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedBool(this->msgBuffer, field, index, value);
}
void PluginUserMessage::AddBool(const char *pszFieldName, bool value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(BOOL);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddBool(this->msgBuffer, field, value);
}
float PluginUserMessage::GetFloat(const char *pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(FLOAT, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    return this->msgBuffer->GetReflection()->GetFloat(*this->msgBuffer, field);
}
void PluginUserMessage::SetFloat(const char *pszFieldName, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(FLOAT);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetFloat(this->msgBuffer, field, value);
}
float PluginUserMessage::GetRepeatedFloat(const char *pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(FLOAT, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    return this->msgBuffer->GetReflection()->GetRepeatedFloat(*this->msgBuffer, field, index);
}
void PluginUserMessage::SetRepeatedFloat(const char *pszFieldName, int index, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(FLOAT);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedFloat(this->msgBuffer, field, index, value);
}
void PluginUserMessage::AddFloat(const char *pszFieldName, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(FLOAT);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddFloat(this->msgBuffer, field, value);
}
double PluginUserMessage::GetDouble(const char *pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(DOUBLE, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    return this->msgBuffer->GetReflection()->GetDouble(*this->msgBuffer, field);
}
void PluginUserMessage::SetDouble(const char *pszFieldName, double value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(DOUBLE);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetDouble(this->msgBuffer, field, value);
}
double PluginUserMessage::GetRepeatedDouble(const char *pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(DOUBLE, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    return this->msgBuffer->GetReflection()->GetRepeatedDouble(*this->msgBuffer, field, index);
}
void PluginUserMessage::SetRepeatedDouble(const char *pszFieldName, int index, double value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(DOUBLE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedDouble(this->msgBuffer, field, index, value);
}
void PluginUserMessage::AddDouble(const char *pszFieldName, double value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(DOUBLE);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddDouble(this->msgBuffer, field, value);
}
float PluginUserMessage::GetFloatOrDouble(const char *pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE2(FLOAT, DOUBLE, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE)
        return (float)this->msgBuffer->GetReflection()->GetDouble(*this->msgBuffer, field);
    else
        return this->msgBuffer->GetReflection()->GetFloat(*this->msgBuffer, field);
}
void PluginUserMessage::SetFloatOrDouble(const char *pszFieldName, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2_VOID(FLOAT, DOUBLE);
    CHECK_FIELD_NOT_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE)
        this->msgBuffer->GetReflection()->SetDouble(this->msgBuffer, field, (double)value);
    else
        this->msgBuffer->GetReflection()->SetFloat(this->msgBuffer, field, value);
}
float PluginUserMessage::GetRepeatedFloatOrDouble(const char *pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE2(FLOAT, DOUBLE, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE)
        return (float)this->msgBuffer->GetReflection()->GetRepeatedDouble(*this->msgBuffer, field, index);
    else
        return this->msgBuffer->GetReflection()->GetRepeatedFloat(*this->msgBuffer, field, index);
}
void PluginUserMessage::SetRepeatedFloatOrDouble(const char *pszFieldName, int index, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2_VOID(FLOAT, DOUBLE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE)
        this->msgBuffer->GetReflection()->SetRepeatedDouble(this->msgBuffer, field, index, (double)value);
    else
        this->msgBuffer->GetReflection()->SetRepeatedFloat(this->msgBuffer, field, index, value);
}
void PluginUserMessage::AddFloatOrDouble(const char *pszFieldName, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2_VOID(FLOAT, DOUBLE);
    CHECK_FIELD_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE)
        this->msgBuffer->GetReflection()->AddDouble(this->msgBuffer, field, (double)value);
    else
        this->msgBuffer->GetReflection()->AddFloat(this->msgBuffer, field, value);
}
std::string PluginUserMessage::GetString(const char *pszFieldName)
{
    GETCHECK_FIELD("");
    CHECK_FIELD_TYPE(STRING, "");
    CHECK_FIELD_NOT_REPEATED("");

    return this->msgBuffer->GetReflection()->GetString(*this->msgBuffer, field);
}
void PluginUserMessage::SetString(const char *pszFieldName, const char *value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(STRING);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetString(this->msgBuffer, field, value);
}
std::string PluginUserMessage::GetRepeatedString(const char *pszFieldName, int index)
{
    GETCHECK_FIELD("");
    CHECK_FIELD_TYPE(STRING, "");
    CHECK_FIELD_REPEATED("");
    CHECK_REPEATED_ELEMENT(index, "");

    std::string scratch;
    return this->msgBuffer->GetReflection()->GetRepeatedStringReference(*this->msgBuffer, field, index, &scratch);
}
void PluginUserMessage::SetRepeatedString(const char *pszFieldName, int index, const char *value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(STRING);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedString(this->msgBuffer, field, index, value);
}
void PluginUserMessage::AddString(const char *pszFieldName, const char *value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(STRING);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddString(this->msgBuffer, field, value);
}
Color PluginUserMessage::GetColor(const char *pszFieldName)
{
    GETCHECK_FIELD(Color(0, 0, 0, 0));
    CHECK_FIELD_TYPE(MESSAGE, Color(0, 0, 0, 0));
    CHECK_FIELD_NOT_REPEATED(Color(0, 0, 0, 0));

    const CMsgRGBA *msgRGBA = (const CMsgRGBA *)&this->msgBuffer->GetReflection()->GetMessage(*this->msgBuffer, field);

    return Color(msgRGBA->r(), msgRGBA->g(), msgRGBA->b(), msgRGBA->a());
}
void PluginUserMessage::SetColor(const char *pszFieldName, const Color &value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    CMsgRGBA *msgRGBA = (CMsgRGBA *)this->msgBuffer->GetReflection()->MutableMessage(this->msgBuffer, field);
    msgRGBA->set_r(value.r());
    msgRGBA->set_g(value.g());
    msgRGBA->set_b(value.b());
    msgRGBA->set_a(value.a());
}
Color PluginUserMessage::GetRepeatedColor(const char *pszFieldName, int index)
{
    GETCHECK_FIELD(Color(0, 0, 0, 0));
    CHECK_FIELD_TYPE(MESSAGE, Color(0, 0, 0, 0));
    CHECK_FIELD_REPEATED(Color(0, 0, 0, 0));
    CHECK_REPEATED_ELEMENT(index, Color(0, 0, 0, 0));

    const CMsgRGBA &msgRGBA = (const CMsgRGBA &)this->msgBuffer->GetReflection()->GetRepeatedMessage(*this->msgBuffer, field, index);
    return Color(msgRGBA.r(), msgRGBA.g(), msgRGBA.b(), msgRGBA.a());
}
void PluginUserMessage::SetRepeatedColor(const char *pszFieldName, int index, const Color &value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    CMsgRGBA *msgRGBA = (CMsgRGBA *)this->msgBuffer->GetReflection()->MutableRepeatedMessage(this->msgBuffer, field, index);
    msgRGBA->set_r(value.r());
    msgRGBA->set_g(value.g());
    msgRGBA->set_b(value.b());
    msgRGBA->set_a(value.a());
}
void PluginUserMessage::AddColor(const char *pszFieldName, const Color &value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();

    CMsgRGBA *msgRGBA = (CMsgRGBA *)this->msgBuffer->GetReflection()->AddMessage(this->msgBuffer, field);
    msgRGBA->set_r(value.r());
    msgRGBA->set_g(value.g());
    msgRGBA->set_b(value.b());
    msgRGBA->set_a(value.a());
}
Vector2D PluginUserMessage::GetVector2D(const char *pszFieldName)
{
    GETCHECK_FIELD(Vector2D(0, 0));
    CHECK_FIELD_TYPE(MESSAGE, Vector2D(0, 0));
    CHECK_FIELD_NOT_REPEATED(Vector2D(0, 0));

    const CMsgVector2D *msgVec2d = (const CMsgVector2D *)&this->msgBuffer->GetReflection()->GetMessage(*this->msgBuffer, field);
    return Vector2D(msgVec2d->x(), msgVec2d->y());
}
void PluginUserMessage::SetVector2D(const char *pszFieldName, Vector2D &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    CMsgVector2D *msgVec2d = (CMsgVector2D *)this->msgBuffer->GetReflection()->MutableMessage(this->msgBuffer, field);
    msgVec2d->set_x(vec.x);
    msgVec2d->set_y(vec.y);
}
Vector2D PluginUserMessage::GetRepeatedVector2D(const char *pszFieldName, int index)
{
    GETCHECK_FIELD(Vector2D(0, 0));
    CHECK_FIELD_TYPE(MESSAGE, Vector2D(0, 0));
    CHECK_FIELD_REPEATED(Vector2D(0, 0));
    CHECK_REPEATED_ELEMENT(index, Vector2D(0, 0));

    const CMsgVector2D &msgVec2d = (const CMsgVector2D &)this->msgBuffer->GetReflection()->GetRepeatedMessage(*this->msgBuffer, field, index);
    return Vector2D(msgVec2d.x(), msgVec2d.y());
}
void PluginUserMessage::SetRepeatedVector2D(const char *pszFieldName, int index, Vector2D &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    CMsgVector2D *msgVec2d = (CMsgVector2D *)this->msgBuffer->GetReflection()->MutableRepeatedMessage(this->msgBuffer, field, index);
    msgVec2d->set_x(vec.x);
    msgVec2d->set_y(vec.y);
}
void PluginUserMessage::AddVector2D(const char *pszFieldName, Vector2D &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();

    CMsgVector2D *msgVec2d = (CMsgVector2D *)this->msgBuffer->GetReflection()->AddMessage(this->msgBuffer, field);
    msgVec2d->set_x(vec.x);
    msgVec2d->set_y(vec.y);
}
Vector PluginUserMessage::GetVector(const char *pszFieldName)
{
    GETCHECK_FIELD(Vector(0, 0, 0));
    CHECK_FIELD_TYPE(MESSAGE, Vector(0, 0, 0));
    CHECK_FIELD_NOT_REPEATED(Vector(0, 0, 0));

    const CMsgVector *msgVec = (const CMsgVector *)&this->msgBuffer->GetReflection()->GetMessage(*this->msgBuffer, field);
    return Vector(msgVec->x(), msgVec->y(), msgVec->z());
}
void PluginUserMessage::SetVector(const char *pszFieldName, Vector &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    CMsgVector *msgVec = (CMsgVector *)this->msgBuffer->GetReflection()->MutableMessage(this->msgBuffer, field);
    msgVec->set_x(vec.x);
    msgVec->set_y(vec.y);
    msgVec->set_z(vec.z);
}
Vector PluginUserMessage::GetRepeatedVector(const char *pszFieldName, int index)
{
    GETCHECK_FIELD(Vector(0, 0, 0));
    CHECK_FIELD_TYPE(MESSAGE, Vector(0, 0, 0));
    CHECK_FIELD_REPEATED(Vector(0, 0, 0));
    CHECK_REPEATED_ELEMENT(index, Vector(0, 0, 0));

    const CMsgVector &msgVec = (const CMsgVector &)this->msgBuffer->GetReflection()->GetRepeatedMessage(*this->msgBuffer, field, index);
    return Vector(msgVec.x(), msgVec.y(), msgVec.z());
}
void PluginUserMessage::SetRepeatedVector(const char *pszFieldName, int index, Vector &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    CMsgVector *msgVec = (CMsgVector *)this->msgBuffer->GetReflection()->MutableRepeatedMessage(this->msgBuffer, field, index);
    msgVec->set_x(vec.x);
    msgVec->set_y(vec.y);
    msgVec->set_z(vec.z);
}
void PluginUserMessage::AddVector(const char *pszFieldName, Vector &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();

    CMsgVector *msgVec = (CMsgVector *)this->msgBuffer->GetReflection()->AddMessage(this->msgBuffer, field);
    msgVec->set_x(vec.x);
    msgVec->set_y(vec.y);
    msgVec->set_z(vec.z);
}
QAngle PluginUserMessage::GetQAngle(const char *pszFieldName)
{
    GETCHECK_FIELD(QAngle(0, 0, 0));
    CHECK_FIELD_TYPE(MESSAGE, QAngle(0, 0, 0));
    CHECK_FIELD_NOT_REPEATED(QAngle(0, 0, 0));

    const CMsgQAngle *msgAng = (const CMsgQAngle *)&this->msgBuffer->GetReflection()->GetMessage(*this->msgBuffer, field);
    return QAngle(msgAng->x(), msgAng->y(), msgAng->z());
}
void PluginUserMessage::SetQAngle(const char *pszFieldName, QAngle &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    CMsgQAngle *msgAng = (CMsgQAngle *)this->msgBuffer->GetReflection()->MutableMessage(this->msgBuffer, field);
    msgAng->set_x(vec.x);
    msgAng->set_y(vec.y);
    msgAng->set_z(vec.z);
}
QAngle PluginUserMessage::GetRepeatedQAngle(const char *pszFieldName, int index)
{
    GETCHECK_FIELD(QAngle(0, 0, 0));
    CHECK_FIELD_TYPE(MESSAGE, QAngle(0, 0, 0));
    CHECK_FIELD_REPEATED(QAngle(0, 0, 0));
    CHECK_REPEATED_ELEMENT(index, QAngle(0, 0, 0));

    const CMsgQAngle &msgAng = (const CMsgQAngle &)this->msgBuffer->GetReflection()->GetRepeatedMessage(*this->msgBuffer, field, index);
    return QAngle(msgAng.x(), msgAng.y(), msgAng.z());
}
void PluginUserMessage::SetRepeatedQAngle(const char *pszFieldName, int index, QAngle &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    CMsgQAngle *msgAng = (CMsgQAngle *)this->msgBuffer->GetReflection()->MutableRepeatedMessage(this->msgBuffer, field, index);
    msgAng->set_x(vec.x);
    msgAng->set_y(vec.y);
    msgAng->set_z(vec.z);
}
void PluginUserMessage::AddQAngle(const char *pszFieldName, QAngle &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();

    CMsgQAngle *msgAng = (CMsgQAngle *)this->msgBuffer->GetReflection()->AddMessage(this->msgBuffer, field);
    msgAng->set_x(vec.x);
    msgAng->set_y(vec.y);
    msgAng->set_z(vec.z);
}
void PluginUserMessage::RemoveRepeatedFieldValue(const char *pszFieldName, int index)
{
    GETCHECK_FIELD();
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    const google::protobuf::Reflection *pReflection = this->msgBuffer->GetReflection();
    for (int i = index; i < elemCount - 1; ++i)
        pReflection->SwapElements(this->msgBuffer, field, i, i + 1);

    pReflection->RemoveLast(this->msgBuffer, field);
}
int PluginUserMessage::GetRepeatedFieldCount(const char *pszFieldName)
{
    const google::protobuf::FieldDescriptor *field = this->msgBuffer->GetDescriptor()->FindFieldByName(pszFieldName);
    if (!field)
        return -1;

    if (field->label() != google::protobuf::FieldDescriptor::LABEL_REPEATED)
        return -1;

    return this->msgBuffer->GetReflection()->FieldSize(*this->msgBuffer, field);
}

void PluginUserMessage::SendToPlayer(int playerId)
{
    if (!this->internalMsg)
        return;

    if (!this->msgBuffer)
        return;

    CSingleRecipientFilter filter(playerId);
    g_pGameEventSystem->PostEventAbstract(0, false, &filter, this->internalMsg, this->msgBuffer, 0);
}
void PluginUserMessage::SendToAllPlayers()
{
    if (!this->internalMsg)
        return;

    if (!this->msgBuffer)
        return;

    CBroadcastRecipientFilter *filter = new CBroadcastRecipientFilter;
    g_pGameEventSystem->PostEventAbstract(0, false, filter, this->internalMsg, this->msgBuffer, 0);
    delete filter;
}