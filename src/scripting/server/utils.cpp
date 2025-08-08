#include <scripting/core.h>

#include <core/entrypoint.h>
#include <tools/crashreporter/callstack.h>
#include <plugins/manager.h>
#include <entities/system.h>

#include <utils/utils.h>
#include <utils/common.h>
#include <texttable/TextTable.h>
#include <sdk/schema.h>

#include <vector>
#include <map>

void GetPluginListFunc(FunctionContext* context) {
    std::vector<std::map<std::string, std::string>> returnMap;

    for (auto plugin : g_pluginManager.GetPluginsList()) {
        if (plugin->GetPluginState() == PluginState_t::Started) {
            std::string website = plugin->GetWebsite();

            returnMap.push_back({
                { "name", plugin->GetPlName() },
                { "id", plugin->GetName() },
                { "version", plugin->GetVersion() },
                { "author", plugin->GetAuthor() },
                { "website", (website == "") ? std::string("Not Present") : website },
                { "loaded", plugin->GetPluginState() == PluginState_t::Started ? "yes" : "no" },
                { "error", plugin->GetLoadError() }
            });
        }
    }

    context->SetReturn(returnMap);
}

LoadScriptingComponent(utils, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_FUNCTION("AddTimeout", [](FunctionContext* context) -> void {
        int64_t delay = context->GetArgumentOr<int64_t>(0, 0);
        EValue* cb = nullptr;
        EContext* ctx = context->GetPluginContext();
        if (ctx->GetKind() == ContextKinds::Dotnet) {
            std::string callback_id = context->GetArgument<std::string>(1);

            cb = new EValue(ctx, (void*)strdup(callback_id.c_str()), 17);
        }
        else {
            EValue callback = context->GetArgument<EValue>(1);
            if (!callback.isFunction()) return;
            cb = new EValue(callback);
        }

        g_Plugin.RegisterTimeout(delay, [cb, ctx]() -> void {
            auto pl = FetchPluginByState(ctx);
            if (pl == nullptr) return;
            if (cb->getContext() != pl->GetContext()) {
                cb->MarkNoFree();
                delete cb;
                return;
            }

            if (!cb->isFunction()) {
                delete cb;
                return;
            }

            try {
                cb->operator()();
            }
            catch (EException& e)
            {
                PLUGIN_PRINTF("RegisterTimeout", "An error has occured while trying to execute the timeout callback: %s\n", e.what());
            }
            delete cb;
        });
    });

    ADD_FUNCTION("GetPluginPath", [](FunctionContext* context) -> void {
        std::string plugin_name = context->GetArgumentOr<std::string>(0, "");
        auto plugin = g_pluginManager.FetchPlugin(plugin_name);
        if (!plugin) return context->SetReturn("");

        context->SetReturn(string_format("%s/%s", g_pluginManager.GetPluginBasePath(plugin_name).c_str(), plugin->GetName().c_str()));
    });

    ADD_FUNCTION("GetTime", [](FunctionContext* context) -> void {
        context->SetReturn(GetTime());
    });

    ADD_FUNCTION("IsWindows", [](FunctionContext* context) -> void {
        context->SetReturn(WIN_LINUX(true, false));
    });

    ADD_FUNCTION("IsLinux", [](FunctionContext* context) -> void {
        context->SetReturn(WIN_LINUX(false, true));
    });

    ADD_FUNCTION("GetOS", [](FunctionContext* context) -> void {
        context->SetReturn(WIN_LINUX("Windows", "Linux"));
    });

    ADD_FUNCTION("StateUpdate", [](FunctionContext* context) -> void {
        void* entityPtr = nullptr;
        auto classData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (classData) {
            if (classData->HasData("class_name")) {
                entityPtr = classData->GetData<void*>("class_ptr");
            }
            else if (classData->HasData("ptr")) {
                entityPtr = classData->GetData<void*>("ptr");
            }
        }
        else {
            auto strptr = context->GetArgumentOr<std::string>(0, "");
            if (starts_with(strptr, "0x")) {
                entityPtr = (void*)StringToPtr(strptr);
            }
            else entityPtr = (void*)nullptr;
        }

        std::string className = context->GetArgumentOr<std::string>(1, "");
        std::string fieldName = context->GetArgumentOr<std::string>(2, "");

        SetStateChanged((uintptr_t)entityPtr, className, fieldName, 0);
    });

    ADD_FUNCTION("GetUserMessage", [](FunctionContext* context) -> void {
        auto classData = context->GetArgumentOr<ClassData*>(0, nullptr);
        context->SetReturn(classData);
    });

    ADD_FUNCTION("GetPluginState", [](FunctionContext* context) -> void {
        std::string plugin_name = context->GetArgumentOr<std::string>(0, "");
        if (!g_pluginManager.PluginExists(plugin_name)) return context->SetReturn((int)PluginState_t::Stopped);
        auto plugin = g_pluginManager.FetchPlugin(plugin_name);
        if (!plugin) return context->SetReturn((int)PluginState_t::Stopped);

        context->SetReturn((int)plugin->GetPluginState());
    });

    ADD_FUNCTION("GetCCSGameRules", [](FunctionContext* context) -> void {
        context->SetReturn(MakeSDKClassInstance("CCSGameRules", gameRules, context->GetPluginContext()));
    });

    ADD_FUNCTION("CreateTextTable", [](FunctionContext* context) -> void {
        std::vector<std::vector<std::string>> data = context->GetArgumentOr<std::vector<std::vector<std::string>>>(0, {});
        TextTable tbl('-', '|', '+');

        for (auto vec : data) {
            for (std::string str : vec) {
                tbl.add(" " + str + " ");
            }

            tbl.endOfRow();
        }

        context->SetReturn(TableToString(tbl));
    });

    ADD_FUNCTION("RegisterCallstack", [](FunctionContext* context) -> void {
        std::string plugin_name = context->GetArgumentOr<std::string>(0, "");
        std::string stackmsg = context->GetArgumentOr<std::string>(1, "");

        if (plugin_name == "" || stackmsg == "") return context->SetReturn(0);
        context->SetReturn(g_callStack.RegisterPluginCallstack(plugin_name, stackmsg));
    });

    ADD_FUNCTION("UnregisterCallstack", [](FunctionContext* context) -> void {
        std::string plugin_name = context->GetArgumentOr<std::string>(0, "");
        uint64_t stackid = context->GetArgumentOr<uint64_t>(1, 0);
        if (stackid == 0) return;

        g_callStack.UnregisterPluginCallstack(plugin_name, stackid);
    });

    ADD_FUNCTION("GetPluginsList", GetPluginListFunc);
})