#ifndef _usermessage_h
#define _usermessage_h

#include <google/protobuf/message.h>
#include <string>
#include "../common.h"
#include "cstrike15_usermessages.pb.h"
#include "netmessages.pb.h"
#include "usermessages.pb.h"
#include "networkbasetypes.pb.h"
#include "gameevents.pb.h"
#include "clientmessages.pb.h"
#include "te.pb.h"
#include "cs_gameevents.pb.h"
#include "cs_usercmd.pb.h"

#define INVALID_MESSAGE_ID -1

class UserMessage
{
private:
    int msgid = INVALID_MESSAGE_ID;
    google::protobuf::Message *msgBuffer = nullptr;
    INetworkSerializable *msgSerializable = nullptr;

public:
    UserMessage(std::string msgname);
    ~UserMessage()
    {
        this->msgid = INVALID_MESSAGE_ID;
        delete this->msgBuffer;
    }

    bool IsValidMessage() { return (this->msgid == INVALID_MESSAGE_ID); }
    std::string GetMessageName();
    int GetMessageID();
    bool HasField(const char *pszFieldName);
    bool GetInt32(const char *pszFieldName, int32 *out);
    bool SetInt32(const char *pszFieldName, int32 value);
    bool GetRepeatedInt32(const char *pszFieldName, int index, int32 *out);
    bool SetRepeatedInt32(const char *pszFieldName, int index, int32 value);
    bool AddInt32(const char *pszFieldName, int32 value);
    bool GetInt64(const char *pszFieldName, int64 *out);
    bool SetInt64(const char *pszFieldName, int64 value);
    bool GetRepeatedInt64(const char *pszFieldName, int index, int64 *out);
    bool SetRepeatedInt64(const char *pszFieldName, int index, int64 value);
    bool AddInt64(const char *pszFieldName, int64 value);
    bool GetUInt32(const char *pszFieldName, uint32 *out);
    bool SetUInt32(const char *pszFieldName, uint32 value);
    bool GetRepeatedUInt32(const char *pszFieldName, int index, uint32 *out);
    bool SetRepeatedUInt32(const char *pszFieldName, int index, uint32 value);
    bool AddUInt32(const char *pszFieldName, uint32 value);
    bool GetUInt64(const char *pszFieldName, uint64 *out);
    bool SetUInt64(const char *pszFieldName, uint64 value);
    bool GetRepeatedUInt64(const char *pszFieldName, int index, uint64 *out);
    bool SetRepeatedUInt64(const char *pszFieldName, int index, uint64 value);
    bool AddUInt64(const char *pszFieldName, uint64 value);
    bool GetInt64OrUnsigned(const char *pszFieldName, int64 *out);
    bool SetInt64OrUnsigned(const char *pszFieldName, int64 value);
    bool GetRepeatedInt64OrUnsigned(const char *pszFieldName, int index, int64 *out);
    bool SetRepeatedInt64OrUnsigned(const char *pszFieldName, int index, int64 value);
    bool AddInt64OrUnsigned(const char *pszFieldName, int64 value);
    bool GetBool(const char *pszFieldName, bool *out);
    bool SetBool(const char *pszFieldName, bool value);
    bool GetRepeatedBool(const char *pszFieldName, int index, bool *out);
    bool SetRepeatedBool(const char *pszFieldName, int index, bool value);
    bool AddBool(const char *pszFieldName, bool value);
    bool GetFloat(const char *pszFieldName, float *out);
    bool SetFloat(const char *pszFieldName, float value);
    bool GetRepeatedFloat(const char *pszFieldName, int index, float *out);
    bool SetRepeatedFloat(const char *pszFieldName, int index, float value);
    bool AddFloat(const char *pszFieldName, float value);
    bool GetDouble(const char *pszFieldName, double *out);
    bool SetDouble(const char *pszFieldName, double value);
    bool GetRepeatedDouble(const char *pszFieldName, int index, double *out);
    bool SetRepeatedDouble(const char *pszFieldName, int index, double value);
    bool AddDouble(const char *pszFieldName, double value);
    bool GetFloatOrDouble(const char *pszFieldName, float *out);
    bool SetFloatOrDouble(const char *pszFieldName, float value);
    bool GetRepeatedFloatOrDouble(const char *pszFieldName, int index, float *out);
    bool SetRepeatedFloatOrDouble(const char *pszFieldName, int index, float value);
    bool AddFloatOrDouble(const char *pszFieldName, float value);
    bool GetString(const char *pszFieldName, char *out);
    bool SetString(const char *pszFieldName, const char *value);
    bool GetRepeatedString(const char *pszFieldName, int index, char *out);
    bool SetRepeatedString(const char *pszFieldName, int index, const char *value);
    bool AddString(const char *pszFieldName, const char *value);
    bool GetColor(const char *pszFieldName, Color *out);
    bool SetColor(const char *pszFieldName, const Color &value);
    bool GetRepeatedColor(const char *pszFieldName, int index, Color *out);
    bool SetRepeatedColor(const char *pszFieldName, int index, const Color &value);
    bool AddColor(const char *pszFieldName, const Color &value);
    bool GetVector2D(const char *pszFieldName, Vector2D *out);
    bool SetVector2D(const char *pszFieldName, Vector2D &vec);
    bool GetRepeatedVector2D(const char *pszFieldName, int index, Vector2D *out);
    bool SetRepeatedVector2D(const char *pszFieldName, int index, Vector2D &vec);
    bool AddVector2D(const char *pszFieldName, Vector2D &vec);
    bool GetVector(const char *pszFieldName, Vector *out);
    bool SetVector(const char *pszFieldName, Vector &vec);
    bool GetRepeatedVector(const char *pszFieldName, int index, Vector *out);
    bool SetRepeatedVector(const char *pszFieldName, int index, Vector &vec);
    bool AddVector(const char *pszFieldName, Vector &vec);
    bool GetQAngle(const char *pszFieldName, QAngle *out);
    bool SetQAngle(const char *pszFieldName, QAngle &vec);
    bool GetRepeatedQAngle(const char *pszFieldName, int index, QAngle *out);
    bool SetRepeatedQAngle(const char *pszFieldName, int index, QAngle &vec);
    bool AddQAngle(const char *pszFieldName, QAngle &vec);
    bool RemoveRepeatedFieldValue(const char *pszFieldName, int index);
    int GetRepeatedFieldCount(const char *pszFieldName);
};

#endif