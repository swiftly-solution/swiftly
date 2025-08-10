#include <scripting/core.h>
#include <tools/resourcemonitor/monitor.h>

#include <set>

LoadScriptingComponent(profiler, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("Profiler");

    ADD_CLASS_FUNCTION("Profiler", "Profiler", [](FunctionContext* context, ClassData* data) -> void {});

    ADD_CLASS_FUNCTION("Profiler", "~Profiler", [](FunctionContext* context, ClassData* data) -> void {
        auto& plugin_name = FetchPluginName(context->GetPluginContext());
        std::set<std::string> timings = data->GetDataOr<std::set<std::string>>("timings", {});
        for (auto it = timings.begin(); it != timings.end(); ++it)
            g_ResourceMonitor.StopTime(plugin_name, *it);
    });

    ADD_CLASS_FUNCTION("Profiler", "Start", [](FunctionContext* context, ClassData* data) -> void {
        if (!g_ResourceMonitor.IsEnabled()) return;

        auto& plugin_name = FetchPluginName(context->GetPluginContext());
        std::string name = context->GetArgumentOr<std::string>(0, "");
        if (name == "") return;

        g_ResourceMonitor.StartTime(plugin_name, name);

        std::set<std::string> timings = data->GetDataOr<std::set<std::string>>("timings", {});
        timings.insert(name);
        data->SetData("timings", timings);
    });

    ADD_CLASS_FUNCTION("Profiler", "Stop", [](FunctionContext* context, ClassData* data) -> void {
        if (!g_ResourceMonitor.IsEnabled()) return;

        auto& plugin_name = FetchPluginName(context->GetPluginContext());
        std::string name = context->GetArgumentOr<std::string>(0, "");
        if (name == "") return;

        g_ResourceMonitor.StopTime(plugin_name, name);
        std::set<std::string> timings = data->GetDataOr<std::set<std::string>>("timings", {});
        if (timings.find(name) != timings.end()) timings.erase(name);
        data->SetData("timings", timings);
    });
})