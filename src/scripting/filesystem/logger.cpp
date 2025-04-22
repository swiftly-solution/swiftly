#include <scripting/core.h>
#include <filesystem/logs/logger.h>

LoadScriptingComponent(logger, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("Logger");

    ADD_CLASS_FUNCTION("Logger", "Logger", [](FunctionContext* context, ClassData* data) -> void {
        std::string plugin_name = FetchPluginName(context->GetPluginContext());
        data->SetData("plugin_name", plugin_name);
        g_Logger.AddLogger(plugin_name, true);
    }); 

    ADD_CLASS_FUNCTION("Logger", "Write", [](FunctionContext* context, ClassData* data) -> void {
        std::string plugin_name = data->GetData<std::string>("plugin_name");
        
        int level = context->GetArgumentOr<int>(0, -1);
        if(level < 1 || level > 4) return;

        std::string message = context->GetArgumentOr<std::string>(1, "");

        auto logger = g_Logger.FetchLogger(plugin_name);
        if(!logger) return;

        logger->WriteLog((LogType_t)level, message);
    });
})