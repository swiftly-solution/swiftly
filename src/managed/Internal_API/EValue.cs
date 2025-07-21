using System.Numerics;
using System.Security;

namespace SwiftlyS2.Internal_API
{
    public class EValue
    {
        protected object m_value;

        internal object Value => m_value;

        private EValue(object value)
        {
            m_value = value;
        }

        public override string ToString()
        {
            return m_value.ToString() ?? "";
        }

        public static implicit operator EValue(bool value)
        {
            return new EValue(value);
        }

        public static implicit operator EValue(sbyte value)
        {
            return new EValue(value);
        }

        public static implicit operator EValue(byte value)
        {
            return new EValue(value);
        }

        public static implicit operator EValue(short value)
        {
            return new EValue(value);
        }

        public static implicit operator EValue(ushort value)
        {
            return new EValue(value);
        }

        public static implicit operator EValue(int value)
        {
            return new EValue(value);
        }

        public static implicit operator EValue(uint value)
        {
            return new EValue(value);
        }

        public static implicit operator EValue(long value)
        {
            return new EValue(value);
        }

        public static implicit operator EValue(ulong value)
        {
            return new EValue(value);
        }

        public static implicit operator EValue(float value)
        {
            return new EValue(value);
        }

        public static implicit operator EValue(double value)
        {
            return new EValue((float)value);
        }

        public static implicit operator EValue(Enum value)
        {
            return new EValue(value);
        }

        public static implicit operator EValue(string value)
        {
            return new EValue(value);
        }

        [SecurityCritical]
        public static implicit operator EValue(IntPtr value)
        {
            return new EValue(value);
        }

        [SecurityCritical]
        public static unsafe implicit operator EValue(void* value)
        {
            return new EValue(new IntPtr(value));
        }
    }
}
