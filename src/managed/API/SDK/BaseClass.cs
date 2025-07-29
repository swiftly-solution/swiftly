using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.SDK
{
    public class Vector : ClassData
    {
        public Vector(float x = 0.0f, float y = 0.0f, float z = 0.0f): 
            base(Invoker.CallNative<IntPtr>("Vector", "Vector", CallKind.ClassFunction, x, y, z))
        {
        }

        public float X
        {
            get { return Invoker.CallNative<float>("Vector", "x", CallKind.ClassMember, m_classData); }
            set { Invoker.CallNative("Vector", "x", CallKind.ClassMember, m_classData, value); }
        }

        public float Y
        {
            get { return Invoker.CallNative<float>("Vector", "y", CallKind.ClassMember, m_classData); }
            set { Invoker.CallNative("Vector", "y", CallKind.ClassMember, m_classData, value); }
        }

        public float Z
        {
            get { return Invoker.CallNative<float>("Vector", "z", CallKind.ClassMember, m_classData); }
            set { Invoker.CallNative("Vector", "z", CallKind.ClassMember, m_classData, value); }
        }
    }
};
