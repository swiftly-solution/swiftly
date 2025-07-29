using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class Files
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("Files", "Files", CallKind.ClassFunction);
        }
        public static void Append(string path, string content, bool hasdate)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Files", "Append", Internal_API.CallKind.ClassFunction, _ctx, path, content, hasdate);
        }
        public static bool Compress(string path, string output)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<bool>("Files", "Compress", Internal_API.CallKind.ClassFunction, _ctx, path, output);
        }
        public static bool CreateDirectory(string path)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<bool>("Files", "CreateDirectory", Internal_API.CallKind.ClassFunction, _ctx, path);
        }
        public static bool Decompress(string path, string output)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<bool>("Files", "Decompress", Internal_API.CallKind.ClassFunction, _ctx, path, output);
        }
        public static void Delete(string path)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Files", "Delete", Internal_API.CallKind.ClassFunction, _ctx, path);
        }
        public static bool ExistsPath(string path)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<bool>("Files", "ExistsPath", Internal_API.CallKind.ClassFunction, _ctx, path);
        }
        public static string[] FetchDirectories(string path)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<string[]>("Files", "FetchDirectories", Internal_API.CallKind.ClassFunction, _ctx, path);
        }
        public static string[] FetchFileNames(string path)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<string[]>("Files", "FetchFileNames", Internal_API.CallKind.ClassFunction, _ctx, path);
        }
        public static string GetBase(string path)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<string>("Files", "GetBase", Internal_API.CallKind.ClassFunction, _ctx, path);
        }
        public static bool IsDirectory(string path)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<bool>("Files", "IsDirectory", Internal_API.CallKind.ClassFunction, _ctx, path);
        }
        public static string Read(string path)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<string>("Files", "Read", Internal_API.CallKind.ClassFunction, _ctx, path);
        }
        public static void Write(string path, string content, bool hasdate)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Files", "Write", Internal_API.CallKind.ClassFunction, _ctx, path, content, hasdate);
        }
    }
}