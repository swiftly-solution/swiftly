#include "usermessage.h"

#include "networkbasetypes.pb.h"
#include <sdk/components/CSingleRecipientFilter.h>

#ifdef GetMessage
#undef GetMessage
#endif

#define GETCHECK_FIELD(return_value)                                                                                          \
    if (!this->msgBuffer)                                                                                                     \
        return return_value;                                                                                                  \
    const google::protobuf::FieldDescriptor *field = this->msgBuffer->GetDescriptor()->FindFieldByName(pszFieldName);         \
    if (!field)                                                                                                               \
    {                                                                                                                         \
        return return_value;                                                                                                  \
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

UserMessage::UserMessage(std::string msgname)
{
    this->msgid = INVALID_MESSAGE_ID;

    auto msg = g_pNetworkMessages->FindNetworkMessagePartial(msgname.c_str());
    if (!msg)
        return;

    NetMessageInfo_t* msginfo = msg->GetNetMessageInfo();
    if (!msginfo)
        return;

    this->msgid = msginfo->m_MessageId;
    this->msgBuffer = msg->AllocateMessage()->ToPB<google::protobuf::Message>();
    this->internalMsg = msg;
}

UserMessage::UserMessage(INetworkMessageInternal* msg, CNetMessage* data, uint64_t* cls)
{
    this->msgid = INVALID_MESSAGE_ID;

    if (!msg || !data) return;

    NetMessageInfo_t* msginfo = msg->GetNetMessageInfo();
    if (!msginfo)
        return;

    this->msgid = msginfo->m_MessageId;
    this->msgBuffer = data->ToPB<google::protobuf::Message>();
    this->internalMsg = msg;
    this->clients = cls;
}

UserMessage::UserMessage(google::protobuf::Message* msg)
{
    this->msgBuffer = (CNetMessagePB<google::protobuf::Message> *)msg;
}

UserMessage::~UserMessage()
{
}

bool UserMessage::IsValidMessage()
{
    return (this->msgid != INVALID_MESSAGE_ID);
}

std::string UserMessage::GetMessageName()
{
    if (this->msgid == INVALID_MESSAGE_ID)
        return "";

    if (!this->internalMsg)
        return "";

    return this->internalMsg->GetUnscopedName();
}

int UserMessage::GetMessageID()
{
    return this->msgid;
}
bool UserMessage::HasField(std::string pszFieldName)
{
    if (!this->msgBuffer)
        return false;

    GETCHECK_FIELD(false);
    CHECK_FIELD_NOT_REPEATED(false);
    return this->msgBuffer->GetReflection()->HasField(*this->msgBuffer, field);
}
int32_t UserMessage::GetInt32(std::string pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(INT32, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    return this->msgBuffer->GetReflection()->GetInt32(*this->msgBuffer, field);
}
void UserMessage::SetInt32(std::string pszFieldName, int32_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(INT32);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetInt32(this->msgBuffer, field, value);
}
int32_t UserMessage::GetRepeatedInt32(std::string pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(INT32, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    return this->msgBuffer->GetReflection()->GetRepeatedInt32(*this->msgBuffer, field, index);
}

void UserMessage::SetRepeatedInt32(std::string pszFieldName, int index, int32_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(INT32);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedInt32(this->msgBuffer, field, index, value);
}
void UserMessage::AddInt32(std::string pszFieldName, int32_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(INT32);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddInt32(this->msgBuffer, field, value);
}
int64_t UserMessage::GetInt64(std::string pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(INT64, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    return this->msgBuffer->GetReflection()->GetInt64(*this->msgBuffer, field);
}
void UserMessage::SetInt64(std::string pszFieldName, int64_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(INT64);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetInt64(this->msgBuffer, field, value);
}
int64_t UserMessage::GetRepeatedInt64(std::string pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(INT64, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    return this->msgBuffer->GetReflection()->GetRepeatedInt64(*this->msgBuffer, field, index);
}
void UserMessage::SetRepeatedInt64(std::string pszFieldName, int index, int64_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(INT64);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedInt64(this->msgBuffer, field, index, value);
}
void UserMessage::AddInt64(std::string pszFieldName, int64_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(INT64);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddInt64(this->msgBuffer, field, value);
}
uint32_t UserMessage::GetUInt32(std::string pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(UINT32, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    return this->msgBuffer->GetReflection()->GetUInt32(*this->msgBuffer, field);
}
void UserMessage::SetUInt32(std::string pszFieldName, uint32_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(UINT32);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetUInt32(this->msgBuffer, field, value);
}
uint32_t UserMessage::GetRepeatedUInt32(std::string pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(UINT32, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    return this->msgBuffer->GetReflection()->GetRepeatedUInt32(*this->msgBuffer, field, index);
}
void UserMessage::SetRepeatedUInt32(std::string pszFieldName, int index, uint32_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(UINT32);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedUInt32(this->msgBuffer, field, index, value);
}
void UserMessage::AddUInt32(std::string pszFieldName, uint32_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(UINT32);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddUInt32(this->msgBuffer, field, value);
}
uint64_t UserMessage::GetUInt64(std::string pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(UINT64, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    return this->msgBuffer->GetReflection()->GetUInt64(*this->msgBuffer, field);
}
void UserMessage::SetUInt64(std::string pszFieldName, uint64_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(UINT64);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetUInt64(this->msgBuffer, field, value);
}
uint64_t UserMessage::GetRepeatedUInt64(std::string pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(UINT64, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    return this->msgBuffer->GetReflection()->GetRepeatedUInt64(*this->msgBuffer, field, index);
}
void UserMessage::SetRepeatedUInt64(std::string pszFieldName, int index, uint64_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(UINT64);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedUInt64(this->msgBuffer, field, index, value);
}
void UserMessage::AddUInt64(std::string pszFieldName, uint64_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(UINT64);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddUInt64(this->msgBuffer, field, value);
}
int64_t UserMessage::GetInt64OrUnsigned(std::string pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE2(INT64, UINT64, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
        return (int64_t)this->msgBuffer->GetReflection()->GetUInt64(*this->msgBuffer, field);
    else
        return this->msgBuffer->GetReflection()->GetInt64(*this->msgBuffer, field);
}
void UserMessage::SetInt64OrUnsigned(std::string pszFieldName, int64_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2_VOID(INT64, UINT64);
    CHECK_FIELD_NOT_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
    {
        this->msgBuffer->GetReflection()->SetUInt64(this->msgBuffer, field, (uint64_t)value);
    }
    else
    {
        this->msgBuffer->GetReflection()->SetInt64(this->msgBuffer, field, value);
    }
}
int64_t UserMessage::GetRepeatedInt64OrUnsigned(std::string pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE2(INT64, UINT64, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
        return (int64_t)this->msgBuffer->GetReflection()->GetRepeatedUInt64(*this->msgBuffer, field, index);
    else
        return this->msgBuffer->GetReflection()->GetRepeatedInt64(*this->msgBuffer, field, index);
}
void UserMessage::SetRepeatedInt64OrUnsigned(std::string pszFieldName, int index, int64_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2_VOID(INT64, UINT64);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
    {
        this->msgBuffer->GetReflection()->SetRepeatedUInt64(this->msgBuffer, field, index, (uint64_t)value);
    }
    else
    {
        this->msgBuffer->GetReflection()->SetRepeatedInt64(this->msgBuffer, field, index, value);
    }
}
void UserMessage::AddInt64OrUnsigned(std::string pszFieldName, int64_t value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2_VOID(INT64, UINT64);
    CHECK_FIELD_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
    {
        this->msgBuffer->GetReflection()->AddUInt64(this->msgBuffer, field, (uint64_t)value);
    }
    else
    {
        this->msgBuffer->GetReflection()->AddInt64(this->msgBuffer, field, value);
    }
}
bool UserMessage::GetBool(std::string pszFieldName)
{
    GETCHECK_FIELD(false);
    CHECK_FIELD_TYPE(BOOL, false);
    CHECK_FIELD_NOT_REPEATED(false);

    return this->msgBuffer->GetReflection()->GetBool(*this->msgBuffer, field);
}
void UserMessage::SetBool(std::string pszFieldName, bool value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(BOOL);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetBool(this->msgBuffer, field, value);
}
bool UserMessage::GetRepeatedBool(std::string pszFieldName, int index)
{
    GETCHECK_FIELD(false);
    CHECK_FIELD_TYPE(BOOL, false);
    CHECK_FIELD_REPEATED(false);
    CHECK_REPEATED_ELEMENT(index, false);

    return this->msgBuffer->GetReflection()->GetRepeatedBool(*this->msgBuffer, field, index);
}
void UserMessage::SetRepeatedBool(std::string pszFieldName, int index, bool value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(BOOL);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedBool(this->msgBuffer, field, index, value);
}
void UserMessage::AddBool(std::string pszFieldName, bool value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(BOOL);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddBool(this->msgBuffer, field, value);
}
float UserMessage::GetFloat(std::string pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(FLOAT, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    return this->msgBuffer->GetReflection()->GetFloat(*this->msgBuffer, field);
}
void UserMessage::SetFloat(std::string pszFieldName, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(FLOAT);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetFloat(this->msgBuffer, field, value);
}
float UserMessage::GetRepeatedFloat(std::string pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(FLOAT, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    return this->msgBuffer->GetReflection()->GetRepeatedFloat(*this->msgBuffer, field, index);
}
void UserMessage::SetRepeatedFloat(std::string pszFieldName, int index, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(FLOAT);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedFloat(this->msgBuffer, field, index, value);
}
void UserMessage::AddFloat(std::string pszFieldName, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(FLOAT);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddFloat(this->msgBuffer, field, value);
}
double UserMessage::GetDouble(std::string pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(DOUBLE, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    return this->msgBuffer->GetReflection()->GetDouble(*this->msgBuffer, field);
}
void UserMessage::SetDouble(std::string pszFieldName, double value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(DOUBLE);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetDouble(this->msgBuffer, field, value);
}
double UserMessage::GetRepeatedDouble(std::string pszFieldName, int index)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE(DOUBLE, 0);
    CHECK_FIELD_REPEATED(0);
    CHECK_REPEATED_ELEMENT(index, 0);

    return this->msgBuffer->GetReflection()->GetRepeatedDouble(*this->msgBuffer, field, index);
}
void UserMessage::SetRepeatedDouble(std::string pszFieldName, int index, double value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(DOUBLE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedDouble(this->msgBuffer, field, index, value);
}
void UserMessage::AddDouble(std::string pszFieldName, double value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(DOUBLE);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddDouble(this->msgBuffer, field, value);
}
float UserMessage::GetFloatOrDouble(std::string pszFieldName)
{
    GETCHECK_FIELD(0);
    CHECK_FIELD_TYPE2(FLOAT, DOUBLE, 0);
    CHECK_FIELD_NOT_REPEATED(0);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE)
        return (float)this->msgBuffer->GetReflection()->GetDouble(*this->msgBuffer, field);
    else
        return this->msgBuffer->GetReflection()->GetFloat(*this->msgBuffer, field);
}
void UserMessage::SetFloatOrDouble(std::string pszFieldName, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2_VOID(FLOAT, DOUBLE);
    CHECK_FIELD_NOT_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE)
        this->msgBuffer->GetReflection()->SetDouble(this->msgBuffer, field, (double)value);
    else
        this->msgBuffer->GetReflection()->SetFloat(this->msgBuffer, field, value);
}
float UserMessage::GetRepeatedFloatOrDouble(std::string pszFieldName, int index)
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
void UserMessage::SetRepeatedFloatOrDouble(std::string pszFieldName, int index, float value)
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
void UserMessage::AddFloatOrDouble(std::string pszFieldName, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2_VOID(FLOAT, DOUBLE);
    CHECK_FIELD_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE)
        this->msgBuffer->GetReflection()->AddDouble(this->msgBuffer, field, (double)value);
    else
        this->msgBuffer->GetReflection()->AddFloat(this->msgBuffer, field, value);
}
std::string UserMessage::GetString(std::string pszFieldName)
{
    GETCHECK_FIELD("");
    CHECK_FIELD_TYPE(STRING, "");
    CHECK_FIELD_NOT_REPEATED("");

    return this->msgBuffer->GetReflection()->GetString(*this->msgBuffer, field);
}
void UserMessage::SetString(std::string pszFieldName, const char* value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(STRING);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetString(this->msgBuffer, field, value);
}
std::string UserMessage::GetRepeatedString(std::string pszFieldName, int index)
{
    GETCHECK_FIELD("");
    CHECK_FIELD_TYPE(STRING, "");
    CHECK_FIELD_REPEATED("");
    CHECK_REPEATED_ELEMENT(index, "");

    return this->msgBuffer->GetReflection()->GetRepeatedString(*this->msgBuffer, field, index);
}
void UserMessage::SetRepeatedString(std::string pszFieldName, int index, const char* value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(STRING);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    this->msgBuffer->GetReflection()->SetRepeatedString(this->msgBuffer, field, index, value);
}
void UserMessage::AddString(std::string pszFieldName, const char* value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(STRING);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddString(this->msgBuffer, field, value);
}
Color UserMessage::GetColor(std::string pszFieldName)
{
    GETCHECK_FIELD(Color(0, 0, 0, 0));
    CHECK_FIELD_TYPE(MESSAGE, Color(0, 0, 0, 0));
    CHECK_FIELD_NOT_REPEATED(Color(0, 0, 0, 0));

    const CMsgRGBA* msgRGBA = (const CMsgRGBA*)&this->msgBuffer->GetReflection()->GetMessage(*this->msgBuffer, field);

    return Color(msgRGBA->r(), msgRGBA->g(), msgRGBA->b(), msgRGBA->a());
}
void UserMessage::SetColor(std::string pszFieldName, const Color& value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    CMsgRGBA* msgRGBA = (CMsgRGBA*)this->msgBuffer->GetReflection()->MutableMessage(this->msgBuffer, field);
    msgRGBA->set_r(value.r());
    msgRGBA->set_g(value.g());
    msgRGBA->set_b(value.b());
    msgRGBA->set_a(value.a());
}
Color UserMessage::GetRepeatedColor(std::string pszFieldName, int index)
{
    GETCHECK_FIELD(Color(0, 0, 0, 0));
    CHECK_FIELD_TYPE(MESSAGE, Color(0, 0, 0, 0));
    CHECK_FIELD_REPEATED(Color(0, 0, 0, 0));
    CHECK_REPEATED_ELEMENT(index, Color(0, 0, 0, 0));

    const CMsgRGBA& msgRGBA = (const CMsgRGBA&)this->msgBuffer->GetReflection()->GetRepeatedMessage(*this->msgBuffer, field, index);
    return Color(msgRGBA.r(), msgRGBA.g(), msgRGBA.b(), msgRGBA.a());
}
void UserMessage::SetRepeatedColor(std::string pszFieldName, int index, const Color& value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    CMsgRGBA* msgRGBA = (CMsgRGBA*)this->msgBuffer->GetReflection()->MutableRepeatedMessage(this->msgBuffer, field, index);
    msgRGBA->set_r(value.r());
    msgRGBA->set_g(value.g());
    msgRGBA->set_b(value.b());
    msgRGBA->set_a(value.a());
}
void UserMessage::AddColor(std::string pszFieldName, const Color& value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();

    CMsgRGBA* msgRGBA = (CMsgRGBA*)this->msgBuffer->GetReflection()->AddMessage(this->msgBuffer, field);
    msgRGBA->set_r(value.r());
    msgRGBA->set_g(value.g());
    msgRGBA->set_b(value.b());
    msgRGBA->set_a(value.a());
}
Vector2D UserMessage::GetVector2D(std::string pszFieldName)
{
    GETCHECK_FIELD(Vector2D(0, 0));
    CHECK_FIELD_TYPE(MESSAGE, Vector2D(0, 0));
    CHECK_FIELD_NOT_REPEATED(Vector2D(0, 0));

    const CMsgVector2D* msgVec2d = (const CMsgVector2D*)&this->msgBuffer->GetReflection()->GetMessage(*this->msgBuffer, field);
    return Vector2D(msgVec2d->x(), msgVec2d->y());
}
void UserMessage::SetVector2D(std::string pszFieldName, Vector2D& vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    CMsgVector2D* msgVec2d = (CMsgVector2D*)this->msgBuffer->GetReflection()->MutableMessage(this->msgBuffer, field);
    msgVec2d->set_x(vec.x);
    msgVec2d->set_y(vec.y);
}
Vector2D UserMessage::GetRepeatedVector2D(std::string pszFieldName, int index)
{
    GETCHECK_FIELD(Vector2D(0, 0));
    CHECK_FIELD_TYPE(MESSAGE, Vector2D(0, 0));
    CHECK_FIELD_REPEATED(Vector2D(0, 0));
    CHECK_REPEATED_ELEMENT(index, Vector2D(0, 0));

    const CMsgVector2D& msgVec2d = (const CMsgVector2D&)this->msgBuffer->GetReflection()->GetRepeatedMessage(*this->msgBuffer, field, index);
    return Vector2D(msgVec2d.x(), msgVec2d.y());
}
void UserMessage::SetRepeatedVector2D(std::string pszFieldName, int index, Vector2D& vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    CMsgVector2D* msgVec2d = (CMsgVector2D*)this->msgBuffer->GetReflection()->MutableRepeatedMessage(this->msgBuffer, field, index);
    msgVec2d->set_x(vec.x);
    msgVec2d->set_y(vec.y);
}
void UserMessage::AddVector2D(std::string pszFieldName, Vector2D& vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();

    CMsgVector2D* msgVec2d = (CMsgVector2D*)this->msgBuffer->GetReflection()->AddMessage(this->msgBuffer, field);
    msgVec2d->set_x(vec.x);
    msgVec2d->set_y(vec.y);
}
Vector UserMessage::GetVector(std::string pszFieldName)
{
    GETCHECK_FIELD(Vector(0, 0, 0));
    CHECK_FIELD_TYPE(MESSAGE, Vector(0, 0, 0));
    CHECK_FIELD_NOT_REPEATED(Vector(0, 0, 0));

    const CMsgVector* msgVec = (const CMsgVector*)&this->msgBuffer->GetReflection()->GetMessage(*this->msgBuffer, field);
    return Vector(msgVec->x(), msgVec->y(), msgVec->z());
}
void UserMessage::SetVector(std::string pszFieldName, Vector& vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    CMsgVector* msgVec = (CMsgVector*)this->msgBuffer->GetReflection()->MutableMessage(this->msgBuffer, field);
    msgVec->set_x(vec.x);
    msgVec->set_y(vec.y);
    msgVec->set_z(vec.z);
}
Vector UserMessage::GetRepeatedVector(std::string pszFieldName, int index)
{
    GETCHECK_FIELD(Vector(0, 0, 0));
    CHECK_FIELD_TYPE(MESSAGE, Vector(0, 0, 0));
    CHECK_FIELD_REPEATED(Vector(0, 0, 0));
    CHECK_REPEATED_ELEMENT(index, Vector(0, 0, 0));

    const CMsgVector& msgVec = (const CMsgVector&)this->msgBuffer->GetReflection()->GetRepeatedMessage(*this->msgBuffer, field, index);
    return Vector(msgVec.x(), msgVec.y(), msgVec.z());
}
void UserMessage::SetRepeatedVector(std::string pszFieldName, int index, Vector& vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    CMsgVector* msgVec = (CMsgVector*)this->msgBuffer->GetReflection()->MutableRepeatedMessage(this->msgBuffer, field, index);
    msgVec->set_x(vec.x);
    msgVec->set_y(vec.y);
    msgVec->set_z(vec.z);
}
void UserMessage::AddVector(std::string pszFieldName, Vector& vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();

    CMsgVector* msgVec = (CMsgVector*)this->msgBuffer->GetReflection()->AddMessage(this->msgBuffer, field);
    msgVec->set_x(vec.x);
    msgVec->set_y(vec.y);
    msgVec->set_z(vec.z);
}
QAngle UserMessage::GetQAngle(std::string pszFieldName)
{
    GETCHECK_FIELD(QAngle(0, 0, 0));
    CHECK_FIELD_TYPE(MESSAGE, QAngle(0, 0, 0));
    CHECK_FIELD_NOT_REPEATED(QAngle(0, 0, 0));

    const CMsgQAngle* msgAng = (const CMsgQAngle*)&this->msgBuffer->GetReflection()->GetMessage(*this->msgBuffer, field);
    return QAngle(msgAng->x(), msgAng->y(), msgAng->z());
}
void UserMessage::SetQAngle(std::string pszFieldName, QAngle& vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    CMsgQAngle* msgAng = (CMsgQAngle*)this->msgBuffer->GetReflection()->MutableMessage(this->msgBuffer, field);
    msgAng->set_x(vec.x);
    msgAng->set_y(vec.y);
    msgAng->set_z(vec.z);
}
QAngle UserMessage::GetRepeatedQAngle(std::string pszFieldName, int index)
{
    GETCHECK_FIELD(QAngle(0, 0, 0));
    CHECK_FIELD_TYPE(MESSAGE, QAngle(0, 0, 0));
    CHECK_FIELD_REPEATED(QAngle(0, 0, 0));
    CHECK_REPEATED_ELEMENT(index, QAngle(0, 0, 0));

    const CMsgQAngle& msgAng = (const CMsgQAngle&)this->msgBuffer->GetReflection()->GetRepeatedMessage(*this->msgBuffer, field, index);
    return QAngle(msgAng.x(), msgAng.y(), msgAng.z());
}
void UserMessage::SetRepeatedQAngle(std::string pszFieldName, int index, QAngle& vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    CMsgQAngle* msgAng = (CMsgQAngle*)this->msgBuffer->GetReflection()->MutableRepeatedMessage(this->msgBuffer, field, index);
    msgAng->set_x(vec.x);
    msgAng->set_y(vec.y);
    msgAng->set_z(vec.z);
}
void UserMessage::AddQAngle(std::string pszFieldName, QAngle& vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE_VOID(MESSAGE);
    CHECK_FIELD_REPEATED();

    CMsgQAngle* msgAng = (CMsgQAngle*)this->msgBuffer->GetReflection()->AddMessage(this->msgBuffer, field);
    msgAng->set_x(vec.x);
    msgAng->set_y(vec.y);
    msgAng->set_z(vec.z);
}

UserMessage UserMessage::GetUMessage(std::string pszFieldName)
{
    GETCHECK_FIELD(UserMessage(""));
    CHECK_FIELD_TYPE(MESSAGE, UserMessage(""));
    CHECK_FIELD_NOT_REPEATED(UserMessage(""));

    auto msg = this->msgBuffer->GetReflection()->MutableMessage(this->msgBuffer, field);
    return UserMessage(msg);
}

UserMessage UserMessage::GetRepeatedMessage(std::string pszFieldName, int index)
{
    GETCHECK_FIELD(UserMessage(""));
    CHECK_FIELD_TYPE(MESSAGE, UserMessage(""));
    CHECK_FIELD_REPEATED(UserMessage(""));
    CHECK_REPEATED_ELEMENT(index, UserMessage(""));

    return UserMessage(this->msgBuffer->GetReflection()->MutableRepeatedMessage(this->msgBuffer, field, index));
}

UserMessage UserMessage::AddMessage(std::string pszFieldName)
{
    GETCHECK_FIELD(UserMessage(""));
    CHECK_FIELD_TYPE(MESSAGE, UserMessage(""));
    CHECK_FIELD_REPEATED(UserMessage(""));

    return UserMessage(this->msgBuffer->GetReflection()->AddMessage(this->msgBuffer, field));
}

void UserMessage::RemoveRepeatedFieldValue(std::string pszFieldName, int index)
{
    GETCHECK_FIELD();
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT_VOID(index);

    const google::protobuf::Reflection* pReflection = this->msgBuffer->GetReflection();
    for (int i = index; i < elemCount - 1; ++i)
        pReflection->SwapElements(this->msgBuffer, field, i, i + 1);

    pReflection->RemoveLast(this->msgBuffer, field);
}

int UserMessage::GetRepeatedFieldCount(std::string pszFieldName)
{
    const google::protobuf::FieldDescriptor* field = this->msgBuffer->GetDescriptor()->FindFieldByName(pszFieldName);
    if (!field)
        return -1;

    if (field->label() != google::protobuf::FieldDescriptor::LABEL_REPEATED)
        return -1;

    return this->msgBuffer->GetReflection()->FieldSize(*this->msgBuffer, field);
}

void UserMessage::AddClient(int playerId)
{
    if (!this->clients) return;

    uint64_t newcls = *this->clients;
    if (newcls & ((uint64_t)1 << playerId))
        newcls |= ((uint64_t)1 << playerId);

    memcpy(this->clients, &newcls, sizeof(newcls));
}

void UserMessage::RemoveClient(int playerId)
{
    if (!this->clients) return;

    uint64_t newcls = *this->clients;
    if (newcls & ((uint64_t)1 << playerId))
        newcls &= ~((uint64_t)1 << playerId);

    memcpy(this->clients, &newcls, sizeof(newcls));
}

void UserMessage::ClearClients()
{
    if (!this->clients) return;

    uint64_t newcls = 0;
    memcpy(this->clients, &newcls, sizeof(newcls));
}

void UserMessage::AddClients()
{
    if (!this->clients) return;

    uint64_t newcls = 0;
    for (int i = 0; i < 64; i++)
        newcls |= ((uint64_t)1 << i);

    memcpy(this->clients, &newcls, sizeof(newcls));
}

std::vector<int> UserMessage::GetClients()
{
    std::vector<int> clns;
    if (!this->clients) return clns;

    uint64_t cls = *this->clients;
    for (int i = 0; i < 64; i++)
        if (cls & ((uint64_t)1 << i))
            clns.push_back(i);

    return clns;
}

void UserMessage::SendToPlayer(int playerId)
{
    if (!this->internalMsg)
        return;

    if (!this->msgBuffer)
        return;

    CSingleRecipientFilter filter(playerId);
    g_pGameEventSystem->PostEventAbstract(-1, false, &filter, this->internalMsg, this->msgBuffer, 0);
}

void UserMessage::SendToAllPlayers()
{
    if (!this->internalMsg)
        return;

    if (!this->msgBuffer)
        return;

    CBroadcastRecipientFilter* filter = new CBroadcastRecipientFilter;
    g_pGameEventSystem->PostEventAbstract(-1, false, filter, this->internalMsg, this->msgBuffer, 0);
    delete filter;
}