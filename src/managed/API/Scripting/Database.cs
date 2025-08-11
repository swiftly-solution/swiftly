using System.Text.Json;
using SwiftlyS2.API.Extensions;
using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class Database
    {
        private static bool _loaded = false;
        private static Dictionary<string, Action<string?, Dictionary<string, object>[]>> _callbacks = [];

        private static void InitializeContext()
        {
            if(_loaded) return;
            _loaded = true;

            Events.AddEventHandler("OnDatabaseActionPerformed", (Events.Event e, string reqID, string output, string error) =>
            {
                Action<string?, Dictionary<string, object>[]>? callback;
                if (!_callbacks.TryGetValue(reqID, out callback)) return EventResult.Continue;
                if(callback == null) return EventResult.Continue;

                ulong id = Generic.RegisterCallstack(Generic.GetCurrentPluginName(), "DatabaseCallback");
                callback(error, JsonSerializer.Deserialize<Dictionary<string, object>[]>(output) ?? []);
                Generic.UnregisterCallstack(Generic.GetCurrentPluginName(), id);

                return EventResult.Stop;
            });
        }

        public class DB : ClassData
        {
            public DB(string connection_name, bool? skip_default_connection): base(Internal_API.Invoker.CallNative<IntPtr>("DB", "DB", CallKind.ClassFunction, connection_name, skip_default_connection))
            {
                InitializeContext();
            }
            public bool IsConnected()
            {
                return Internal_API.Invoker.CallNative<bool>("DB", "IsConnected", Internal_API.CallKind.CoreClassFunction, m_classData);
            }
            public string GetVersion()
            {
                return Internal_API.Invoker.CallNative<string>("DB", "GetVersion", Internal_API.CallKind.CoreClassFunction, m_classData);
            }
            public QueryBuilderMySQL QueryBuilder()
            {
                return new(this);
            }
            public string EscapeString(string value)
            {
                return Internal_API.Invoker.CallNative<string>("DB", "EscapeString", Internal_API.CallKind.CoreClassFunction, m_classData, value) ?? "";
            }
            public void Query(string query, Action<string?, Dictionary<string, object>[]> callback)
            {
                var callbackUUID = Guid.NewGuid().ToString();
                while (_callbacks.ContainsKey(callbackUUID))
                {
                    callbackUUID = Guid.NewGuid().ToString();
                }

                _callbacks.Add(callbackUUID, callback);
                Internal_API.Invoker.CallNative("DB", "Query", Internal_API.CallKind.CoreClassFunction, m_classData, query, callbackUUID);
            }
            public void QueryParams(string query, Dictionary<string, object> param, Action<string?, Dictionary<string, object>[]> callback)
            {
                var has_ats = query.Contains('@');
                var has_brace = query.Contains('{');
                var has_bracket = query.Contains('[');

                foreach(var kvp in param)
                {
                    var key = kvp.Key;
                    var value = EscapeString(kvp.Value.ToString() ?? "");

                    if(has_ats) query = query.Replace($"@{key}", value);
                    if(has_ats) query = query.Replace("{"+ key + "}", value);
                    if(has_ats) query = query.Replace($"[{key}]", value);
                }

                Query(query, callback);
            }
        }
    }
}