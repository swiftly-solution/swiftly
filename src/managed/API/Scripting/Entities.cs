using SwiftlyS2.Internal_API;
using static SwiftlyS2.API.SDK.CoreClasses;

namespace SwiftlyS2.API.Scripting
{
    public class Entities
    {
        public class CEntityKeyValues : ClassData
        {
            public CEntityKeyValues(): base(Internal_API.Invoker.CallNative<IntPtr>("CEntityKeyValues", "CEntityKeyValues", CallKind.ClassFunction))
            {
            }
            public bool GetBool(string key)
            {
                return Internal_API.Invoker.CallNative<bool>("CEntityKeyValues", "GetBool", Internal_API.CallKind.ClassFunction, m_classData, key);
            }
            public int GetInt(string key)
            {
                return Internal_API.Invoker.CallNative<int>("CEntityKeyValues", "GetInt", Internal_API.CallKind.ClassFunction, m_classData, key);
            }
            public uint GetUint(string key)
            {
                return Internal_API.Invoker.CallNative<uint>("CEntityKeyValues", "GetUint", Internal_API.CallKind.ClassFunction, m_classData, key);
            }
            public long GetInt64(string key)
            {
                return Internal_API.Invoker.CallNative<long>("CEntityKeyValues", "GetInt64", Internal_API.CallKind.ClassFunction, m_classData, key);
            }
            public ulong GetUint64(string key)
            {
                return Internal_API.Invoker.CallNative<ulong>("CEntityKeyValues", "GetUint64", Internal_API.CallKind.ClassFunction, m_classData, key);
            }
            public float GetFloat(string key)
            {
                return Internal_API.Invoker.CallNative<float>("CEntityKeyValues", "GetFloat", Internal_API.CallKind.ClassFunction, m_classData, key);
            }
            public double GetDouble(string key)
            {
                return Internal_API.Invoker.CallNative<double>("CEntityKeyValues", "GetDouble", Internal_API.CallKind.ClassFunction, m_classData, key);
            }
            public string GetString(string key)
            {
                return Internal_API.Invoker.CallNative<string>("CEntityKeyValues", "GetString", Internal_API.CallKind.ClassFunction, m_classData, key) ?? "";
            }
            public Memory GetPtr(string key)
            {
                return Internal_API.Invoker.CallNative<Memory>("CEntityKeyValues", "GetPtr", Internal_API.CallKind.ClassFunction, m_classData, key) ?? new();
            }
            public uint GetStringToken(string key)
            {
                return Internal_API.Invoker.CallNative<uint>("CEntityKeyValues", "GetStringToken", Internal_API.CallKind.ClassFunction, m_classData, key);
            }
            public Color GetColor(string key)
            {
                return Internal_API.Invoker.CallNative<Color>("CEntityKeyValues", "GetColor", Internal_API.CallKind.ClassFunction, m_classData, key) ?? new(0,0,0,0);
            }
            public Vector GetVector(string key)
            {
                return Internal_API.Invoker.CallNative<Vector>("CEntityKeyValues", "GetVector", Internal_API.CallKind.ClassFunction, m_classData, key) ?? new(0, 0, 0);
            }
            public Vector2D GetVector2D(string key)
            {
                return Internal_API.Invoker.CallNative<Vector2D>("CEntityKeyValues", "GetVector2D", Internal_API.CallKind.ClassFunction, m_classData, key) ?? new(0, 0);
            }
            public Vector4D GetVector4D(string key)
            {
                return Internal_API.Invoker.CallNative<Vector4D>("CEntityKeyValues", "GetVector4D", Internal_API.CallKind.ClassFunction, m_classData, key) ?? new(0, 0, 0, 0);
            }
            public QAngle GetQAngle(string key)
            {
                return Internal_API.Invoker.CallNative<QAngle>("CEntityKeyValues", "GetQAngle", Internal_API.CallKind.ClassFunction, m_classData, key) ?? new(0, 0, 0);
            }
            public void SetBool(string key, bool value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetBool", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetInt(string key, int value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetInt", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetUint(string key, uint value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetUint", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetInt64(string key, long value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetInt64", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetUint64(string key, ulong value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetUint64", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetFloat(string key, float value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetFloat", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetDouble(string key, double value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetDouble", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetString(string key, string value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetString", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetPtr(string key, Memory value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetPtr", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetStringToken(string key, uint value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetStringToken", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetColor(string key, Color value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetColor", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetVector(string key, Vector value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetVector", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetVector2D(string key, Vector2D value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetVector2D", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetVector4D(string key, Vector4D value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetVector4D", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetQAngle(string key, QAngle value)
            {
                Internal_API.Invoker.CallNative("CEntityKeyValues", "SetQAngle", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
        }
    }
}