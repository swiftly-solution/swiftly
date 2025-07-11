#include <scripting/core.h>
#include <tools/crashreporter/crashreporter.h>
#include <memory/gamedata/gamedata.h>
#include <sdk/game.h>
#include <utils/utils.h>

extern std::map<std::string, std::string> gameEventsRegister;
EValue SerializeData(std::any data, EContext* state);

typedef IGameEventListener2* (*GetLegacyGameEventListener)(CPlayerSlot slot);

LoadScriptingComponent(events, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_FUNCTION("AddGlobalEvents", [](FunctionContext* context) -> void {
        if (context->GetArgumentsCount() != 1) return;

        auto func = context->GetArgument<EValue>(0);
        if (!func.isFunction()) return;

        auto plugin = g_pluginManager.FetchPlugin(FetchPluginName(context->GetPluginContext()));
        if (!plugin) return;

        plugin->RegisterEventHandler(new EValue(func));
    });

    ADD_FUNCTION("AddGlobalEventsJSON", [](FunctionContext* context) -> void {
        if (context->GetArgumentsCount() != 1) return;

        auto func = context->GetArgument<EValue>(0);
        if (!func.isFunction()) return;

        auto plugin = g_pluginManager.FetchPlugin(FetchPluginName(context->GetPluginContext()));
        if (!plugin) return;

        plugin->RegisterEventHandlerJSON(new EValue(func));
    });

    ADD_FUNCTION("RegisterEventHandlerPlugin", [](FunctionContext* context) -> void {
        if (context->GetArgumentsCount() != 1) return;

        auto event_name = context->GetArgumentOr<std::string>(0, "");

        auto plugin = g_pluginManager.FetchPlugin(FetchPluginName(context->GetPluginContext()));
        if (!plugin) return;

        plugin->RegisterEventHandling(event_name);
    });

    ADD_FUNCTION("RemoveEventHandlerPlugin", [](FunctionContext* context) -> void {
        if (context->GetArgumentsCount() != 1) return;

        auto event_name = context->GetArgumentOr<std::string>(0, "");

        auto plugin = g_pluginManager.FetchPlugin(FetchPluginName(context->GetPluginContext()));
        if (!plugin) return;

        plugin->UnregisterEventHandling(event_name);
    });

    ADD_FUNCTION("TriggerEventInternal", [](FunctionContext* context) -> void {
        if (context->GetArgumentsCount() != 2) return;

        auto event_name = context->GetArgumentOr<std::string>(0, "");
        auto event_data = context->GetArgumentOr<std::string>(1, "[]");

        ClassData* evObject = new ClassData({ { "plugin_name", FetchPluginName(context->GetPluginContext()) }, { "should_mark_freeable", true } }, "Event", nullptr);
        std::vector<std::any> returnValues;

        returnValues.push_back((int)(g_pluginManager.ExecuteEventJSON(FetchPluginName(context->GetPluginContext()), event_name, event_data, evObject)));
        returnValues.push_back(evObject);

        context->SetReturn(returnValues);
    });

    ADD_CLASS("Event");

    ADD_CLASS_FUNCTION("Event", "Event", [](FunctionContext* context, ClassData* data) -> void {
        if (context->GetArgumentOr<std::string>(0, "") == "") return;
        std::string event_name = context->GetArgument<std::string>(0);

        for (auto it = gameEventsRegister.begin(); it != gameEventsRegister.end(); ++it) {
            if (it->second == event_name) {
                auto gameEvent = g_gameEventManager->CreateEvent(it->first.c_str());
                data->SetData("event_data", gameEvent);
                data->SetData("should_free", true);
                break;
            }
        }
    });

    ADD_CLASS_FUNCTION("Event", "~Event", [](FunctionContext* context, ClassData* data) -> void {
        if (data->HasData("should_free") && data->GetData<bool>("should_free") && data->GetDataOr<IGameEvent*>("event_data", nullptr)) {
            g_gameEventManager->FreeEvent(data->GetData<IGameEvent*>("event_data"));
        }
    });

    ADD_CLASS_FUNCTION("Event", "GetInvokingPlugin", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetDataOr<std::string>("plugin_name", "unknown"));
    });

    ADD_CLASS_FUNCTION("Event", "IsGameEvent", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->HasData("event_data"));
    });

    ADD_CLASS_FUNCTION("Event", "SetBool", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("event_data")) return;
        data->GetData<IGameEvent*>("event_data")->SetBool(context->GetArgumentOr<std::string>(0, "").c_str(), context->GetArgumentOr<bool>(1, false));
    });

    ADD_CLASS_FUNCTION("Event", "SetInt", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("event_data")) return;
        data->GetData<IGameEvent*>("event_data")->SetInt(context->GetArgumentOr<std::string>(0, "").c_str(), context->GetArgumentOr<int>(1, 0));
    });

    ADD_CLASS_FUNCTION("Event", "SetUint64", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("event_data")) return;
        data->GetData<IGameEvent*>("event_data")->SetUint64(context->GetArgumentOr<std::string>(0, "").c_str(), context->GetArgumentOr<uint64_t>(1, 0));
    });

    ADD_CLASS_FUNCTION("Event", "SetFloat", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("event_data")) return;
        data->GetData<IGameEvent*>("event_data")->SetFloat(context->GetArgumentOr<std::string>(0, "").c_str(), context->GetArgumentOr<float>(1, 0.0f));
    });

    ADD_CLASS_FUNCTION("Event", "SetString", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("event_data")) return;
        data->GetData<IGameEvent*>("event_data")->SetString(context->GetArgumentOr<std::string>(0, "").c_str(), context->GetArgumentOr<std::string>(1, "").c_str());
    });

    ADD_CLASS_FUNCTION("Event", "GetBool", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("event_data") || !data->GetData<IGameEvent*>("event_data")->HasKey(context->GetArgumentOr<std::string>(0, "").c_str())) {
            context->SetReturn(false);
            return;
        }
        context->SetReturn(data->GetData<IGameEvent*>("event_data")->GetBool(context->GetArgumentOr<std::string>(0, "").c_str()));
    });

    ADD_CLASS_FUNCTION("Event", "GetInt", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("event_data") || !data->GetData<IGameEvent*>("event_data")->HasKey(context->GetArgumentOr<std::string>(0, "").c_str())) {
            context->SetReturn(0);
            return;
        }
        context->SetReturn(data->GetData<IGameEvent*>("event_data")->GetInt(context->GetArgumentOr<std::string>(0, "").c_str()));
    });

    ADD_CLASS_FUNCTION("Event", "GetUint64", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("event_data") || !data->GetData<IGameEvent*>("event_data")->HasKey(context->GetArgumentOr<std::string>(0, "").c_str())) {
            context->SetReturn(0);
            return;
        }
        context->SetReturn(data->GetData<IGameEvent*>("event_data")->GetUint64(context->GetArgumentOr<std::string>(0, "").c_str()));
    });

    ADD_CLASS_FUNCTION("Event", "GetFloat", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("event_data") || !data->GetData<IGameEvent*>("event_data")->HasKey(context->GetArgumentOr<std::string>(0, "").c_str())) {
            context->SetReturn(0.0f);
            return;
        }
        context->SetReturn(data->GetData<IGameEvent*>("event_data")->GetFloat(context->GetArgumentOr<std::string>(0, "").c_str()));
    });

    ADD_CLASS_FUNCTION("Event", "GetString", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("event_data") || !data->GetData<IGameEvent*>("event_data")->HasKey(context->GetArgumentOr<std::string>(0, "").c_str())) {
            context->SetReturn("");
            return;
        }
        context->SetReturn(data->GetData<IGameEvent*>("event_data")->GetString(context->GetArgumentOr<std::string>(0, "").c_str()));
    });

    ADD_CLASS_FUNCTION("Event", "FireEvent", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("event_data")) return;

        g_gameEventManager->FireEvent(data->GetData<IGameEvent*>("event_data"), context->GetArgumentOr<bool>(0, false));
    });

    ADD_CLASS_FUNCTION("Event", "FireEventToClient", [](FunctionContext* context, ClassData* data) -> void {
        if (!data->HasData("event_data")) return;
        if (!data->GetDataOr<IGameEvent*>("event_data", nullptr)) return;

        int slot = context->GetArgumentOr<int>(0, -1);
        if (slot < 0 || slot >= GetMaxGameClients()) return;

        IGameEventListener2* playerListener = g_GameData.FetchSignature<GetLegacyGameEventListener>("LegacyGameEventListener")(slot);
        if (!playerListener) {
            ReportPreventionIncident("Fire Event", string_format("Tried to fire event '%s' but the client isn't having a listener.", data->GetData<IGameEvent*>("event_data")->GetName()));
            return;
        }

        if (!g_gameEventManager->FindListener(playerListener, data->GetData<IGameEvent*>("event_data")->GetName())) {
            ReportPreventionIncident("Fire Event", string_format("Tried to fire event '%s' but the client isn't listening to this event.", data->GetData<IGameEvent*>("event_data")->GetName()));
            return;
        }

        playerListener->FireGameEvent(data->GetData<IGameEvent*>("event_data"));
    });

    ADD_CLASS_FUNCTION("Event", "SetReturn", [](FunctionContext* context, ClassData* data) -> void {
        if (context->GetArgumentsCount() < 1) return;

        std::any val = context->GetArgument<std::any>(0);
        data->SetData("event_return", val);
    });

    ADD_CLASS_FUNCTION("Event", "GetReturn", [](FunctionContext* context, ClassData* data) -> void {
        if (data->HasData("event_return")) {
            context->SetReturn(data->GetAnyData("event_return"));
        }
    });

    ADD_CLASS_FUNCTION("Event", "SetNoBroadcast", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("dontBroadcast", context->GetArgumentOr<bool>(0, false));
    });

    ADD_CLASS_FUNCTION("Event", "GetNoBroadcast", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetDataOr<bool>("dontBroadcast", false));
    });

    if (ctx->GetKind() == ContextKinds::JavaScript) ADD_VARIABLE("_G", "PEvent", EValue::getGlobal(ctx, "Event"));
})