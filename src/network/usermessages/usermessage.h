#ifndef _network_messages_message_h
#define _network_messages_message_h

#include <core/entrypoint.h>
#include <string>
#include <vector>

#define INVALID_MESSAGE_ID -1

class UserMessage
{
private:
    int msgid = INVALID_MESSAGE_ID;
    INetworkMessageInternal* internalMsg = nullptr;
    uint64_t* clients = nullptr;

public:
    CNetMessagePB<google::protobuf::Message>* msgBuffer = nullptr;

    UserMessage(std::string msgname);
    UserMessage(INetworkMessageInternal* msg, CNetMessage* data, uint64_t* cls);
    UserMessage(google::protobuf::Message* msg);
    ~UserMessage();

    bool IsValidMessage();
    std::string GetMessageName();
    int GetMessageID();

    bool HasField(std::string pszFieldName);

    int32_t GetInt32(std::string pszFieldName);
    void SetInt32(std::string pszFieldName, int32_t value);
    int32_t GetRepeatedInt32(std::string pszFieldName, int index);
    void SetRepeatedInt32(std::string pszFieldName, int index, int32_t value);
    void AddInt32(std::string pszFieldName, int32_t value);

    int64_t GetInt64(std::string pszFieldName);
    void SetInt64(std::string pszFieldName, int64_t value);
    int64_t GetRepeatedInt64(std::string pszFieldName, int index);
    void SetRepeatedInt64(std::string pszFieldName, int index, int64_t value);
    void AddInt64(std::string pszFieldName, int64_t value);

    uint32_t GetUInt32(std::string pszFieldName);
    void SetUInt32(std::string pszFieldName, uint32_t value);
    uint32_t GetRepeatedUInt32(std::string pszFieldName, int index);
    void SetRepeatedUInt32(std::string pszFieldName, int index, uint32_t value);
    void AddUInt32(std::string pszFieldName, uint32_t value);

    uint64_t GetUInt64(std::string pszFieldName);
    void SetUInt64(std::string pszFieldName, uint64_t value);
    uint64_t GetRepeatedUInt64(std::string pszFieldName, int index);
    void SetRepeatedUInt64(std::string pszFieldName, int index, uint64_t value);
    void AddUInt64(std::string pszFieldName, uint64_t value);

    int64_t GetInt64OrUnsigned(std::string pszFieldName);
    void SetInt64OrUnsigned(std::string pszFieldName, int64_t value);
    int64_t GetRepeatedInt64OrUnsigned(std::string pszFieldName, int index);
    void SetRepeatedInt64OrUnsigned(std::string pszFieldName, int index, int64_t value);
    void AddInt64OrUnsigned(std::string pszFieldName, int64_t value);

    bool GetBool(std::string pszFieldName);
    void SetBool(std::string pszFieldName, bool value);
    bool GetRepeatedBool(std::string pszFieldName, int index);
    void SetRepeatedBool(std::string pszFieldName, int index, bool value);
    void AddBool(std::string pszFieldName, bool value);

    float GetFloat(std::string pszFieldName);
    void SetFloat(std::string pszFieldName, float value);
    float GetRepeatedFloat(std::string pszFieldName, int index);
    void SetRepeatedFloat(std::string pszFieldName, int index, float value);
    void AddFloat(std::string pszFieldName, float value);

    double GetDouble(std::string pszFieldName);
    void SetDouble(std::string pszFieldName, double value);
    double GetRepeatedDouble(std::string pszFieldName, int index);
    void SetRepeatedDouble(std::string pszFieldName, int index, double value);
    void AddDouble(std::string pszFieldName, double value);

    float GetFloatOrDouble(std::string pszFieldName);
    void SetFloatOrDouble(std::string pszFieldName, float value);
    float GetRepeatedFloatOrDouble(std::string pszFieldName, int index);
    void SetRepeatedFloatOrDouble(std::string pszFieldName, int index, float value);
    void AddFloatOrDouble(std::string pszFieldName, float value);

    std::string GetString(std::string pszFieldName);
    void SetString(std::string pszFieldName, const char* value);
    std::string GetRepeatedString(std::string pszFieldName, int index);
    void SetRepeatedString(std::string pszFieldName, int index, const char* value);
    void AddString(std::string pszFieldName, const char* value);

    Color GetColor(std::string pszFieldName);
    void SetColor(std::string pszFieldName, const Color& value);
    Color GetRepeatedColor(std::string pszFieldName, int index);
    void SetRepeatedColor(std::string pszFieldName, int index, const Color& value);
    void AddColor(std::string pszFieldName, const Color& value);

    Vector2D GetVector2D(std::string pszFieldName);
    void SetVector2D(std::string pszFieldName, Vector2D& vec);
    Vector2D GetRepeatedVector2D(std::string pszFieldName, int index);
    void SetRepeatedVector2D(std::string pszFieldName, int index, Vector2D& vec);
    void AddVector2D(std::string pszFieldName, Vector2D& vec);

    Vector GetVector(std::string pszFieldName);
    void SetVector(std::string pszFieldName, Vector& vec);
    Vector GetRepeatedVector(std::string pszFieldName, int index);
    void SetRepeatedVector(std::string pszFieldName, int index, Vector& vec);
    void AddVector(std::string pszFieldName, Vector& vec);

    QAngle GetQAngle(std::string pszFieldName);
    void SetQAngle(std::string pszFieldName, QAngle& vec);
    QAngle GetRepeatedQAngle(std::string pszFieldName, int index);
    void SetRepeatedQAngle(std::string pszFieldName, int index, QAngle& vec);
    void AddQAngle(std::string pszFieldName, QAngle& vec);

    UserMessage GetUMessage(std::string pszFieldName);
    UserMessage GetRepeatedMessage(std::string pszFieldName, int index);
    UserMessage AddMessage(std::string pszFieldName);

    void RemoveRepeatedFieldValue(std::string pszFieldName, int index);
    int GetRepeatedFieldCount(std::string pszFieldName);

    void AddClient(int playerId);
    void RemoveClient(int playerId);
    void ClearClients();
    void AddClients();
    std::vector<int> GetClients();

    void SendToPlayer(int playerId);
    void SendToAllPlayers();
};

#endif