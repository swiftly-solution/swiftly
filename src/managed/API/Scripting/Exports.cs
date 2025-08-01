namespace SwiftlyS2.API.Scripting
{
    public static class Exports
    {
        public static void Call(string plugin_name, string name, params object[] args)
        {
            var output = Events.TriggerEvent($"export:{plugin_name}:{name}", args);
            if (output.Item1 != EventResult.Stop)
            {
                Console.WriteLine($"Export '{name}' is '{plugin_name}' doesn't exists.");
            }
        }

        public static T? Call<T>(string plugin_name, string name, params object[] args)
        {
            var output = Events.TriggerEvent($"export:{plugin_name}:{name}", args);
            if (output.Item1 != EventResult.Stop)
            {
                Console.WriteLine($"Export '{name}' is '{plugin_name}' doesn't exists.");
            }
            return output.Item2.GetReturn<T>();
        }

        public static void Register(string export_name, Delegate callback)
        {
            Events.AddEventHandler($"export:{Generic.GetCurrentPluginName()}:{export_name}", (Events.Event e, params object[] args) =>
            {
                object? val = callback.DynamicInvoke(args);
                if (val == null) return EventResult.Stop;
                e.SetReturn(val);
                return EventResult.Stop;
            });
        }
    }
}
