using System.Text;

namespace SwiftlyS2.API.Scripting
{
    public class ConsoleWriter : TextWriter
    {
        public override Encoding Encoding => Encoding.UTF8;
        private readonly TextWriter originalOut;

        public ConsoleWriter(TextWriter originalOut)
        {
            this.originalOut = originalOut;
        }

        private void MyWriteLine(string text)
        {
            if(Plugin.PluginContext == IntPtr.Zero)
            {
                originalOut.WriteLine(text);
            }
            else
            {
                Internal_API.Invoker.CallNative("Console", "WriteLine", Internal_API.CallKind.Function, text);
            }
        }

        public override void WriteLine() => MyWriteLine(string.Empty);

        public override void WriteLine(char value) => MyWriteLine(value.ToString());

        public override void WriteLine(string? value) => MyWriteLine(value ?? string.Empty);

        public override void WriteLine(object? value) => MyWriteLine(value?.ToString() ?? string.Empty);

        public override void WriteLine(char[] buffer, int index, int count) =>
            MyWriteLine(new string(buffer, index, count));

        public override void WriteLine(bool value) => MyWriteLine(value.ToString());

        public override void WriteLine(int value) => MyWriteLine(value.ToString());

        public override void WriteLine(uint value) => MyWriteLine(value.ToString());

        public override void WriteLine(long value) => MyWriteLine(value.ToString());

        public override void WriteLine(ulong value) => MyWriteLine(value.ToString());

        public override void WriteLine(float value) => MyWriteLine(value.ToString());

        public override void WriteLine(double value) => MyWriteLine(value.ToString());

        public override void WriteLine(decimal value) => MyWriteLine(value.ToString());

        public override void WriteLine(string format, object? arg0) =>
            MyWriteLine(string.Format(format, arg0));

        public override void WriteLine(string format, object? arg0, object? arg1) =>
            MyWriteLine(string.Format(format, arg0, arg1));

        public override void WriteLine(string format, object? arg0, object? arg1, object? arg2) =>
            MyWriteLine(string.Format(format, arg0, arg1, arg2));

        public override void WriteLine(string format, params object?[] arg) =>
            MyWriteLine(string.Format(format, arg));
    }
}
