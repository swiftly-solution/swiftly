using SwiftlyS2.API.SDK;
using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class SoundEvent: ClassData
    {
        public SoundEvent() : base(Invoker.CallNative<IntPtr>("SoundEvent", "SoundEvent", CallKind.ClassFunction))
        {
        }

        public uint Emit()
        {
            return Invoker.CallNative<uint>("SoundEvent", "Emit", CallKind.ClassFunction, m_classData);
        }
        public string GetName()
        {
            return Invoker.CallNative<string>("SoundEvent", "GetName", CallKind.ClassFunction, m_classData) ?? "";
        }

        public void SetName(string name)
        {
            Invoker.CallNative("SoundEvent", "SetName", CallKind.ClassFunction, m_classData, name);
        }

        public int GetSourceEntityIndex()
        {
            return Invoker.CallNative<int>("SoundEvent", "GetSourceEntityIndex", CallKind.ClassFunction, m_classData);
        }

        public void SetSourceEntityIndex(int ent_idx)
        {
            Invoker.CallNative("SoundEvent", "SetName", CallKind.ClassFunction, m_classData, ent_idx);
        }
        public void AddClient(int playerid)
        {
            Invoker.CallNative("SoundEvent", "AddClient", CallKind.ClassFunction, m_classData, playerid);
        }
        public void RemoveClient(int playerid)
        {
            Invoker.CallNative("SoundEvent", "RemoveClient", CallKind.ClassFunction, m_classData, playerid);
        }
        public void ClearClients()
        {
            Invoker.CallNative("SoundEvent", "ClearClients", CallKind.ClassFunction, m_classData);
        }
        public void AddClients()
        {
            Invoker.CallNative("SoundEvent", "AddClients", CallKind.ClassFunction, m_classData);
        }
        public int[] GetClients()
        {
            return Invoker.CallNative<int[]>("SoundEvent", "GetClients", CallKind.ClassFunction, m_classData) ?? [];
        }
        public bool HasField(string name)
        {
            return Invoker.CallNative<bool>("SoundEvent", "HasField", CallKind.ClassFunction, m_classData, name);
        }
        public bool GetBool(string name)
        {
            return Invoker.CallNative<bool>("SoundEvent", "GetBool", CallKind.ClassFunction, m_classData, name);
        }
        public void SetBool(string name, bool value)
        {
            Invoker.CallNative("SoundEvent", "SetBool", CallKind.ClassFunction, m_classData, name, value);
        }
        public int GetInt(string name)
        {
            return Invoker.CallNative<int>("SoundEvent", "GetInt", CallKind.ClassFunction, m_classData, name);
        }
        public void SetInt(string name, int value)
        {
            Invoker.CallNative("SoundEvent", "SetInt", CallKind.ClassFunction, m_classData, name, value);
        }
        public uint GetUInt32(string name)
        {
            return Invoker.CallNative<uint>("SoundEvent", "GetUInt32", CallKind.ClassFunction, m_classData, name);
        }
        public void SetUInt32(string name, uint value)
        {
            Invoker.CallNative("SoundEvent", "SetUInt32", CallKind.ClassFunction, m_classData, name, value);
        }
        public ulong GetUInt64(string name)
        {
            return Invoker.CallNative<ulong>("SoundEvent", "GetUInt64", CallKind.ClassFunction, m_classData, name);
        }
        public void SetUInt64(string name, ulong value)
        {
            Invoker.CallNative("SoundEvent", "SetUInt64", CallKind.ClassFunction, m_classData, name, value);
        }
        public float GetFloat(string name)
        {
            return Invoker.CallNative<float>("SoundEvent", "GetFloat", CallKind.ClassFunction, m_classData, name);
        }
        public void SetFloat(string name, float value)
        {
            Invoker.CallNative("SoundEvent", "SetFloat", CallKind.ClassFunction, m_classData, name, value);
        }
        public CoreClasses.Vector GetFloat3(string name)
        {
            return Invoker.CallNative<CoreClasses.Vector>("SoundEvent", "GetFloat3", CallKind.ClassFunction, m_classData, name) ?? new(0,0,0);
        }
        public void SetFloat3(string name, CoreClasses.Vector value)
        {
            Invoker.CallNative("SoundEvent", "SetFloat3", CallKind.ClassFunction, m_classData, name, value);
        }
    }
}
