#include <scripting/core.h>

#include <server/configuration/configuration.h>
#include <server/menus/MenuManager.h>

#ifndef WIN_LINUX
#ifdef _WIN32
#define WIN_LINUX(win,linux) win
#else
#define WIN_LINUX(win,linux) linux
#endif
#endif

LoadScriptingComponent(menus, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("Menus");

    ADD_CLASS_FUNCTION("Menus", "Menus", [](FunctionContext* context, ClassData* data) -> void {});

    ADD_CLASS_FUNCTION("Menus", "Register", [](FunctionContext* context, ClassData* data) -> void {
        std::string menuid = context->GetArgumentOr<std::string>(0, "");
        std::string title = context->GetArgumentOr<std::string>(1, "");
        std::string color = context->GetArgumentOr<std::string>(2, "");
        std::vector<std::pair<std::string, std::string>> options = context->GetArgumentOr<std::vector<std::pair<std::string, std::string>>>(3, std::vector<std::pair<std::string, std::string>>{});
        std::string menuKind = WIN_LINUX("center", context->GetArgumentOr<std::string>(4, g_Config.FetchValue<std::string>("core.menu.kind")));

        g_MenuManager.RegisterMenu(FetchPluginName(context->GetPluginContext()), menuid, title, color, options, false, menuKind);
    });

    ADD_CLASS_FUNCTION("Menus", "RegisterTemporary", [](FunctionContext* context, ClassData* data) -> void {
        std::string menuid = context->GetArgumentOr<std::string>(0, "");
        std::string title = context->GetArgumentOr<std::string>(1, "");
        std::string color = context->GetArgumentOr<std::string>(2, "");
        std::vector<std::pair<std::string, std::string>> options = context->GetArgumentOr<std::vector<std::pair<std::string, std::string>>>(3, std::vector<std::pair<std::string, std::string>>{});
        std::string menuKind = WIN_LINUX("center", context->GetArgumentOr<std::string>(4, g_Config.FetchValue<std::string>("core.menu.kind")));

        g_MenuManager.RegisterMenu(FetchPluginName(context->GetPluginContext()), menuid, title, color, options, true, menuKind);
    });

    ADD_CLASS_FUNCTION("Menus", "Unregister", [](FunctionContext* context, ClassData* data) -> void {
        std::string menuid = context->GetArgumentOr<std::string>(0, "");

        g_MenuManager.UnregisterMenu(menuid);
    });
})