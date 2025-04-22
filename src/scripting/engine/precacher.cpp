#include <scripting/core.h>
#include <engine/precacher/precacher.h>

void PrecacheItems(FunctionContext* context, ClassData* data) {
    g_precacher.AddItem(context->GetArgumentOr<std::string>(0, ""));
}

LoadScriptingComponent(precacher, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("Precacher");

    ADD_CLASS_FUNCTION("Precacher", "Precacher", [](FunctionContext*, ClassData*) -> void {});
    ADD_CLASS_FUNCTION("Precacher", "PrecacheModel", PrecacheItems);
    ADD_CLASS_FUNCTION("Precacher", "PrecacheSound", PrecacheItems);
    ADD_CLASS_FUNCTION("Precacher", "PrecacheItem", PrecacheItems);
})