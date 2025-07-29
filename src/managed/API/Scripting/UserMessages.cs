using SwiftlyS2.Internal_API;
using static SwiftlyS2.API.SDK.CS2.CoreClasses;

namespace SwiftlyS2.API.Scripting
{
    public class UserMessages
    {
        public class UserMessage : ClassData
        {
            public UserMessage(string partial_message_name): base(Internal_API.Invoker.CallNative<IntPtr>("UserMessage", "UserMessage", CallKind.ClassFunction, partial_message_name))
            {
            }
            public bool IsValidMessage()
            {
                return Internal_API.Invoker.CallNative<bool>("UserMessage", "IsValidMessage", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public string GetMessageName()
            {
                return Internal_API.Invoker.CallNative<string>("UserMessage", "GetMessageName", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
            }
            public int GetMessageID()
            {
                return Internal_API.Invoker.CallNative<int>("UserMessage", "GetMessageID", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public bool HasField(string fieldName)
            {
                return Internal_API.Invoker.CallNative<bool>("UserMessage", "HasField", Internal_API.CallKind.ClassFunction, m_classData, fieldName);
            }
            public int GetInt32(string fieldName)
            {
                return Internal_API.Invoker.CallNative<int>("UserMessage", "GetInt32", Internal_API.CallKind.ClassFunction, m_classData, fieldName);
            }
            public void SetInt32(string fieldName, int value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetInt32", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public int GetRepeatedInt32(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<int>("UserMessage", "GetRepeatedInt32", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index);
            }
            public void SetRepeatedInt32(string fieldName, int index, int value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedInt32", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddInt32(string fieldName, int index)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddInt32", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index);
            }
            public long GetInt64(string fieldName)
            {
                return Internal_API.Invoker.CallNative<long>("UserMessage", "GetInt64", Internal_API.CallKind.ClassFunction, m_classData, fieldName);
            }
            public void SetInt64(string fieldName, long value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetInt64", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public long GetRepeatedInt64(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<long>("UserMessage", "GetRepeatedInt64", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index);
            }
            public void SetRepeatedInt64(string fieldName, int index, long value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedInt64", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddInt64(string fieldName, long value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddInt64", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public uint GetUInt32(string fieldName)
            {
                return Internal_API.Invoker.CallNative<uint>("UserMessage", "GetUInt32", Internal_API.CallKind.ClassFunction, m_classData, fieldName);
            }
            public void SetUInt32(string fieldName, uint value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetUInt32", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public uint GetRepeatedUInt32(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<uint>("UserMessage", "GetRepeatedUInt32", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index);
            }
            public void SetRepeatedUInt32(string fieldName, int index, uint value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedUInt32", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddUInt32(string fieldName, uint value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddUInt32", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public ulong GetUInt64(string fieldName)
            {
                return Internal_API.Invoker.CallNative<ulong>("UserMessage", "GetUInt64", Internal_API.CallKind.ClassFunction, m_classData, fieldName);
            }
            public void SetUInt64(string fieldName, ulong value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetUInt64", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public ulong GetRepeatedUInt64(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<ulong>("UserMessage", "GetRepeatedUInt64", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index);
            }
            public void SetRepeatedUInt64(string fieldName, int index, ulong value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedUInt64", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddUInt64(string fieldName, ulong value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddUInt64", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public long GetInt64OrUnsigned(string fieldName)
            {
                return Internal_API.Invoker.CallNative<long>("UserMessage", "GetInt64OrUnsigned", Internal_API.CallKind.ClassFunction, m_classData, fieldName);
            }
            public void SetInt64OrUnsigned(string fieldName, long value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetInt64OrUnsigned", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public long GetRepeatedInt64OrUnsigned(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<long>("UserMessage", "GetRepeatedInt64OrUnsigned", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index);
            }
            public void SetRepeatedInt64OrUnsigned(string fieldName, int index, long value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedInt64OrUnsigned", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddInt64OrUnsigned(string fieldName, long value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddInt64OrUnsigned", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public bool GetBool(string fieldName)
            {
                return Internal_API.Invoker.CallNative<bool>("UserMessage", "GetBool", Internal_API.CallKind.ClassFunction, m_classData, fieldName);
            }
            public void SetBool(string fieldName, bool value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetBool", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public bool GetRepeatedBool(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<bool>("UserMessage", "GetRepeatedBool", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index);
            }
            public void SetRepeatedBool(string fieldName, int index, bool value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedBool", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddBool(string fieldName, bool value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddBool", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public float GetFloat(string fieldName)
            {
                return Internal_API.Invoker.CallNative<float>("UserMessage", "GetFloat", Internal_API.CallKind.ClassFunction, m_classData, fieldName);
            }
            public void SetFloat(string fieldName, float value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetFloat", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public float GetRepeatedFloat(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<float>("UserMessage", "GetRepeatedFloat", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index);
            }
            public void SetRepeatedFloat(string fieldName, int index, float value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedFloat", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddFloat(string fieldName, float value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddFloat", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public double GetDouble(string fieldName)
            {
                return Internal_API.Invoker.CallNative<double>("UserMessage", "GetDouble", Internal_API.CallKind.ClassFunction, m_classData, fieldName);
            }
            public void SetDouble(string fieldName, double value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetDouble", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public double GetRepeatedDouble(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<double>("UserMessage", "GetRepeatedDouble", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index);
            }
            public void SetRepeatedDouble(string fieldName, int index, double value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedDouble", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddDouble(string fieldName, double value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddDouble", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public float GetFloatOrDouble(string fieldName)
            {
                return Internal_API.Invoker.CallNative<float>("UserMessage", "GetFloatOrDouble", Internal_API.CallKind.ClassFunction, m_classData, fieldName);
            }
            public void SetFloatOrDouble(string fieldName, float value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetFloatOrDouble", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public float GetRepeatedFloatOrDouble(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<float>("UserMessage", "GetRepeatedFloatOrDouble", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index);
            }
            public void SetRepeatedFloatOrDouble(string fieldName, int index, float value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedFloatOrDouble", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddFloatOrDouble(string fieldName, float value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddFloatOrDouble", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public string GetString(string fieldName)
            {
                return Internal_API.Invoker.CallNative<string>("UserMessage", "GetString", Internal_API.CallKind.ClassFunction, m_classData, fieldName) ?? "";
            }
            public void SetString(string fieldName, string value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetString", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public string GetRepeatedString(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<string>("UserMessage", "GetRepeatedString", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index) ?? "";
            }
            public void SetRepeatedString(string fieldName, int index, string value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedString", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddString(string fieldName, string value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddString", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public string GetBytes(string fieldName)
            {
                return Internal_API.Invoker.CallNative<string>("UserMessage", "GetBytes", Internal_API.CallKind.ClassFunction, m_classData, fieldName) ?? "";
            }
            public void SetBytes(string fieldName, string value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetBytes", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public string GetRepeatedBytes(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<string>("UserMessage", "GetRepeatedBytes", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index) ?? "";
            }
            public void SetRepeatedBytes(string fieldName, int index, string value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedBytes", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddBytes(string fieldName, string value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddBytes", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public Color GetColor(string fieldName)
            {
                return Internal_API.Invoker.CallNative<Color>("UserMessage", "GetColor", Internal_API.CallKind.ClassFunction, m_classData, fieldName) ?? new(0, 0, 0, 0);
            }
            public void SetColor(string fieldName, Color value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetColor", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public Color GetRepeatedColor(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<Color>("UserMessage", "GetRepeatedColor", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index) ?? new(0, 0, 0, 0);
            }
            public void SetRepeatedColor(string fieldName, int index, Color value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedColor", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddColor(string fieldName, Color value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddColor", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public Vector2D GetVector2D(string fieldName)
            {
                return Internal_API.Invoker.CallNative<Vector2D>("UserMessage", "GetVector2D", Internal_API.CallKind.ClassFunction, m_classData, fieldName) ?? new(0, 0);
            }
            public void SetVector2D(string fieldName, Vector2D value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetVector2D", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public Vector2D GetRepeatedVector2D(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<Vector2D>("UserMessage", "GetRepeatedVector2D", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index) ?? new(0, 0);
            }
            public void SetRepeatedVector2D(string fieldName, int index, Vector2D value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedVector2D", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddVector2D(string fieldName, Vector2D value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddVector2D", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public Vector GetVector(string fieldName)
            {
                return Internal_API.Invoker.CallNative<Vector>("UserMessage", "GetVector", Internal_API.CallKind.ClassFunction, m_classData, fieldName) ?? new(0, 0, 0);
            }
            public void SetVector(string fieldName, Vector value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetVector", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public Vector GetRepeatedVector(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<Vector>("UserMessage", "GetRepeatedVector", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index) ?? new(0, 0, 0);
            }
            public void SetRepeatedVector(string fieldName, int index, Vector value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedVector", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddVector(string fieldName, Vector value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddVector", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public QAngle GetQAngle(string fieldName)
            {
                return Internal_API.Invoker.CallNative<QAngle>("UserMessage", "GetQAngle", Internal_API.CallKind.ClassFunction, m_classData, fieldName) ?? new(0, 0, 0);
            }
            public void SetQAngle(string fieldName, QAngle value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetQAngle", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public QAngle GetRepeatedQAngle(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<QAngle>("UserMessage", "GetRepeatedQAngle", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index) ?? new(0, 0, 0);
            }
            public void SetRepeatedQAngle(string fieldName, int index, QAngle value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SetRepeatedQAngle", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index, value);
            }
            public void AddQAngle(string fieldName, QAngle value)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddQAngle", Internal_API.CallKind.ClassFunction, m_classData, fieldName, value);
            }
            public void RemoveRepeatedFieldValue(string fieldName, int index)
            {
                Internal_API.Invoker.CallNative("UserMessage", "RemoveRepeatedFieldValue", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index);
            }
            public int GetRepeatedFieldCount(string fieldName)
            {
                return Internal_API.Invoker.CallNative<int>("UserMessage", "GetRepeatedFieldCount", Internal_API.CallKind.ClassFunction, m_classData, fieldName);
            }
            public UserMessage GetMessage(string fieldName)
            {
                return Internal_API.Invoker.CallNative<UserMessage>("UserMessage", "GetMessage", Internal_API.CallKind.ClassFunction, m_classData, fieldName) ?? new("");
            }
            public UserMessage GetRepeatedMessage(string fieldName, int index)
            {
                return Internal_API.Invoker.CallNative<UserMessage>("UserMessage", "GetRepeatedMessage", Internal_API.CallKind.ClassFunction, m_classData, fieldName, index) ?? new("");
            }
            public UserMessage AddMessage(string fieldName)
            {
                return Internal_API.Invoker.CallNative<UserMessage>("UserMessage", "AddMessage", Internal_API.CallKind.ClassFunction, m_classData, fieldName) ?? new("");
            }
            public void SendToPlayer(int playerid)
            {
                Internal_API.Invoker.CallNative("UserMessage", "SendToPlayer", Internal_API.CallKind.ClassFunction, m_classData, playerid);
            }
            public void SendToAllPlayers()
            {
                Internal_API.Invoker.CallNative("UserMessage", "SendToAllPlayers", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public void AddClient(int playerid)
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddClient", Internal_API.CallKind.ClassFunction, m_classData, playerid);
            }
            public void RemoveClient(int playerid)
            {
                Internal_API.Invoker.CallNative("UserMessage", "RemoveClient", Internal_API.CallKind.ClassFunction, m_classData, playerid);
            }
            public void ClearClients()
            {
                Internal_API.Invoker.CallNative("UserMessage", "ClearClients", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public void AddClients()
            {
                Internal_API.Invoker.CallNative("UserMessage", "AddClients", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public int[] GetClients()
            {
                return Internal_API.Invoker.CallNative<int[]>("UserMessage", "GetClients", Internal_API.CallKind.ClassFunction, m_classData) ?? [];
            }
        }
    }
}