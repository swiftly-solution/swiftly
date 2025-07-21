using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API
{
    public class ClassData
    {
        protected IntPtr m_classData = IntPtr.Zero;

        public ClassData() { }

        public ClassData(IntPtr classData) => m_classData = classData;

        ~ClassData()
        {
            Invoker.FinalizeClassdata(m_classData);
        }
    }
}
