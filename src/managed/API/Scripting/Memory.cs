using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class Memory: ClassData
    {
        public Memory() : base(Internal_API.Invoker.CallNative<IntPtr>("Memory", "Memory", CallKind.ClassFunction))
        {
        }

        public bool AccessedVTable()
        {
            return Internal_API.Invoker.CallNative<bool>("Memory", "AccessedVTable", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public void AccessIndex(long index)
        {
            Internal_API.Invoker.CallNative("Memory", "AccessIndex", Internal_API.CallKind.ClassFunction, m_classData, index);
        }
        public void AccessIndexFromOffset(string offsetName)
        {
            Internal_API.Invoker.CallNative("Memory", "AccessIndexFromOffset", Internal_API.CallKind.ClassFunction, m_classData, offsetName);
        }
        public void AccessVTable(long offset)
        {
            Internal_API.Invoker.CallNative("Memory", "AccessVTable", Internal_API.CallKind.ClassFunction, m_classData, offset);
        }
        public void AccessVTableFromOffset(string offsetName)
        {
            Internal_API.Invoker.CallNative("Memory", "AccessVTableFromOffset", Internal_API.CallKind.ClassFunction, m_classData, offsetName);
        }
        public void AddOffset(long offset)
        {
            Internal_API.Invoker.CallNative("Memory", "AddOffset", Internal_API.CallKind.ClassFunction, m_classData, offset);
        }
        public void AddOffsetByName(string offsetName)
        {
            Internal_API.Invoker.CallNative("Memory", "AddOffsetByName", Internal_API.CallKind.ClassFunction, m_classData, offsetName);
        }
        public void Allocate(ulong size)
        {
            Internal_API.Invoker.CallNative("Memory", "Allocate", Internal_API.CallKind.ClassFunction, m_classData, size);
        }
        public void Clear()
        {
            Internal_API.Invoker.CallNative("Memory", "Clear", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public void Deallocate()
        {
            Internal_API.Invoker.CallNative("Memory", "Deallocate", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public void Dereference()
        {
            Internal_API.Invoker.CallNative("Memory", "Dereference", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public bool GetBool()
        {
            return Internal_API.Invoker.CallNative<bool>("Memory", "GetBool", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public double GetDouble()
        {
            return Internal_API.Invoker.CallNative<double>("Memory", "GetDouble", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public float GetFloat()
        {
            return Internal_API.Invoker.CallNative<float>("Memory", "GetFloat", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public int GetInt()
        {
            return Internal_API.Invoker.CallNative<int>("Memory", "GetInt", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public long GetInt64()
        {
            return Internal_API.Invoker.CallNative<long>("Memory", "GetInt64", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public string GetPtr()
        {
            return Internal_API.Invoker.CallNative<string>("Memory", "GetPtr", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
        }
        public uint GetUInt()
        {
            return Internal_API.Invoker.CallNative<uint>("Memory", "GetUInt", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public ulong GetUInt64()
        {
            return Internal_API.Invoker.CallNative<ulong>("Memory", "GetUInt64", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public bool IsValid()
        {
            return Internal_API.Invoker.CallNative<bool>("Memory", "IsValid", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public void LoadFromAddress(string address)
        {
            Internal_API.Invoker.CallNative("Memory", "LoadFromAddress", Internal_API.CallKind.ClassFunction, m_classData, address);
        }
        public void LoadFromSignature(string library, string signature)
        {
            Internal_API.Invoker.CallNative("Memory", "LoadFromSignature", Internal_API.CallKind.ClassFunction, m_classData, library, signature);
        }
        public void LoadFromSignatureName(string signature)
        {
            Internal_API.Invoker.CallNative("Memory", "LoadFromSignatureName", Internal_API.CallKind.ClassFunction, m_classData, signature);
        }
        public void RemoveOffset(long offset)
        {
            Internal_API.Invoker.CallNative("Memory", "RemoveOffset", Internal_API.CallKind.ClassFunction, m_classData, offset);
        }
        public void RemoveOffsetByName(string offsetName)
        {
            
            Internal_API.Invoker.CallNative("Memory", "RemoveOffsetByName", Internal_API.CallKind.ClassFunction, m_classData, offsetName);
        }
        public void SetBool(bool value)
        {
            Internal_API.Invoker.CallNative("Memory", "SetBool", Internal_API.CallKind.ClassFunction, m_classData, value);
        }
        public void SetDouble(double value)
        {
            Internal_API.Invoker.CallNative("Memory", "SetDouble", Internal_API.CallKind.ClassFunction, m_classData, value);
        }
        public void SetFloat(float value)
        {
            Internal_API.Invoker.CallNative("Memory", "SetFloat", Internal_API.CallKind.ClassFunction, m_classData, value);
        }
        public void SetInt(int value)
        {
            Internal_API.Invoker.CallNative("Memory", "SetInt", Internal_API.CallKind.ClassFunction, m_classData, value);
        }
        public void SetInt64(long value)
        {
            Internal_API.Invoker.CallNative("Memory", "SetInt64", Internal_API.CallKind.ClassFunction, m_classData, value);
        }
        public void SetUInt(uint value)
        {
            Internal_API.Invoker.CallNative("Memory", "SetUInt", Internal_API.CallKind.ClassFunction, m_classData, value);
        }
        public void SetUInt64(ulong value)
        {
            Internal_API.Invoker.CallNative("Memory", "SetUInt64", Internal_API.CallKind.ClassFunction, m_classData, value);
        }
    }
}