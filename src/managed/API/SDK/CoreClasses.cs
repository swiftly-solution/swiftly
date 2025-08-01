using SwiftlyS2.API.Scripting;
using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.SDK
{
    public static class CoreClasses
    {
        public class CCheckTransmitInfo : ClassData
        {
            public CCheckTransmitInfo(CCheckTransmitInfo ptr_or_cchectransmitinfo) : base(Internal_API.Invoker.CallNative<IntPtr>("CCheckTransmitInfo", "CCheckTransmitInfo", CallKind.ClassFunction, ptr_or_cchectransmitinfo))
            {
            }
            public CCheckTransmitInfo(Memory ptr_or_cchectransmitinfo) : base(Internal_API.Invoker.CallNative<IntPtr>("CCheckTransmitInfo", "CCheckTransmitInfo", CallKind.ClassFunction, ptr_or_cchectransmitinfo))
            {
            }
            public CCheckTransmitInfo() { }
            public Dictionary<int, int> GetPlayers()
            {
                return Internal_API.Invoker.CallNative<Dictionary<int, int>>("CCheckTransmitInfo", "GetPlayers", Internal_API.CallKind.ClassFunction, m_classData) ?? [];
            }
            public int[] GetEntities()
            {
                return Internal_API.Invoker.CallNative<int[]>("CCheckTransmitInfo", "GetEntities", Internal_API.CallKind.ClassFunction, m_classData) ?? [];
            }
            public void SetEntities(int[] value)
            {
                Internal_API.Invoker.CallNative("CCheckTransmitInfo", "SetEntities", Internal_API.CallKind.ClassFunction, m_classData, (object)value);
            }
            public void AddEntityIndex(int entityIndex)
            {
                Internal_API.Invoker.CallNative("CCheckTransmitInfo", "AddEntityIndex", Internal_API.CallKind.ClassFunction, m_classData, entityIndex);
            }
            public void RemoveEntityIndex(int entityIndex)
            {
                Internal_API.Invoker.CallNative("CCheckTransmitInfo", "RemoveEntityIndex", Internal_API.CallKind.ClassFunction, m_classData, entityIndex);
            }
            public void Clear()
            {
                Internal_API.Invoker.CallNative("CCheckTransmitInfo", "Clear", Internal_API.CallKind.ClassFunction, m_classData);
            }
        }
        public class CHandle : ClassData
        {
            public CHandle(string ptr) : base(Internal_API.Invoker.CallNative<IntPtr>("CHandle", "CHandle", Internal_API.CallKind.ClassFunction, ptr))
            {
            }
            public string GetPtr()
            {
                return Internal_API.Invoker.CallNative<string>("CHandle", "GetPtr", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
            }
            public void SetPtr(string ptr)
            {
                Internal_API.Invoker.CallNative("CHandle", "SetPtr", Internal_API.CallKind.ClassFunction, m_classData, ptr);
            }
            public string GetHandlePtr()
            {
                return Internal_API.Invoker.CallNative<string>("CHandle", "GetHandlePtr", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
            }
            public bool IsValid()
            {
                return Internal_API.Invoker.CallNative<bool>("CHandle", "IsValid", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public int GetEntryIndex()
            {
                return Internal_API.Invoker.CallNative<int>("CHandle", "GetEntryIndex", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public int GetSerialNumber()
            {
                return Internal_API.Invoker.CallNative<int>("CHandle", "GetSerialNumber", Internal_API.CallKind.ClassFunction, m_classData);
            }
        }
        public class Color : ClassData
        {
            public Color(byte r, byte g, byte b, byte a) : base(Internal_API.Invoker.CallNative<IntPtr>("Color", "Color", CallKind.ClassFunction, r, g, b, a))
            {
            }
            public string GetPtr()
            {
                return Internal_API.Invoker.CallNative<string>("Color", "GetPtr", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
            }
            public byte r
            {
                get { return Invoker.CallNative<byte>("Color", "r", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("Color", "r", CallKind.ClassMember, m_classData, value); }
            }
            public byte g
            {
                get { return Invoker.CallNative<byte>("Color", "g", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("Color", "g", CallKind.ClassMember, m_classData, value); }
            }
            public byte b
            {
                get { return Invoker.CallNative<byte>("Color", "b", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("Color", "b", CallKind.ClassMember, m_classData, value); }
            }
            public byte a
            {
                get { return Invoker.CallNative<byte>("Color", "a", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("Color", "a", CallKind.ClassMember, m_classData, value); }
            }
        }
        public class QAngle : ClassData
        {
            public QAngle(float x, float y, float z) : base(Internal_API.Invoker.CallNative<IntPtr>("QAngle", "QAngle", CallKind.ClassFunction, x, y, z))
            {
            }
            public string GetPtr()
            {
                return Internal_API.Invoker.CallNative<string>("QAngle", "GetPtr", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
            }
            public float x
            {
                get { return Invoker.CallNative<float>("QAngle", "x", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("QAngle", "x", CallKind.ClassMember, m_classData, value); }
            }
            public float y
            {
                get { return Invoker.CallNative<float>("QAngle", "y", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("QAngle", "y", CallKind.ClassMember, m_classData, value); }
            }
            public float z
            {
                get { return Invoker.CallNative<float>("QAngle", "z", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("QAngle", "z", CallKind.ClassMember, m_classData, value); }
            }
        }
        public class Vector : ClassData
        {
            public Vector(float x, float y, float z) : base(Internal_API.Invoker.CallNative<IntPtr>("Vector", "Vector", CallKind.ClassFunction, x, y, z))
            {
            }
            public string GetPtr()
            {
                return Internal_API.Invoker.CallNative<string>("Vector", "GetPtr", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
            }
            public float x
            {
                get { return Invoker.CallNative<float>("Vector", "x", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("Vector", "x", CallKind.ClassMember, m_classData, value); }
            }
            public float y
            {
                get { return Invoker.CallNative<float>("Vector", "y", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("Vector", "y", CallKind.ClassMember, m_classData, value); }
            }
            public float z
            {
                get { return Invoker.CallNative<float>("Vector", "z", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("Vector", "z", CallKind.ClassMember, m_classData, value); }
            }
        }
        public class Vector2D : ClassData
        {
            public Vector2D(float x, float y) : base(Internal_API.Invoker.CallNative<IntPtr>("Vector2D", "Vector2D", CallKind.ClassFunction, x, y))
            {
            }
            public string GetPtr()
            {
                return Internal_API.Invoker.CallNative<string>("Vector2D", "GetPtr", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
            }
            public float x
            {
                get { return Invoker.CallNative<float>("Vector2D", "x", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("Vector2D", "x", CallKind.ClassMember, m_classData, value); }
            }
            public float y
            {
                get { return Invoker.CallNative<float>("Vector2D", "y", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("Vector2D", "y", CallKind.ClassMember, m_classData, value); }
            }
        }
        public class Vector4D : ClassData
        {
            public Vector4D(float x, float y, float z, float w) : base(Internal_API.Invoker.CallNative<IntPtr>("Vector4D", "Vector4D", CallKind.ClassFunction, x, y, z, w))
            {
            }
            public string GetPtr()
            {
                return Internal_API.Invoker.CallNative<string>("Vector4D", "GetPtr", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
            }
            public float x
            {
                get { return Invoker.CallNative<float>("Vector4D", "x", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("Vector4D", "x", CallKind.ClassMember, m_classData, value); }
            }
            public float y
            {
                get { return Invoker.CallNative<float>("Vector4D", "y", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("Vector4D", "y", CallKind.ClassMember, m_classData, value); }
            }
            public float z
            {
                get { return Invoker.CallNative<float>("Vector4D", "z", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("Vector4D", "z", CallKind.ClassMember, m_classData, value); }
            }
            public float w
            {
                get { return Invoker.CallNative<float>("Vector4D", "w", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("Vector4D", "w", CallKind.ClassMember, m_classData, value); }
            }
        }
    }
}