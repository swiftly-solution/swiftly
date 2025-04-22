#include <scripting/core.h>

#include <server/translations/translations.h>

LoadScriptingComponent(translations, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_FUNCTION("FetchTranslation", [](FunctionContext* context) -> void {
        context->SetReturn(g_translations.FetchTranslation(context->GetArgumentOr<std::string>(0, ""), context->GetArgumentOr<int>(1, -1)));
    });
})