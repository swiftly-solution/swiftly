#include <scripting/core.h>

#include <engine/convars/manager.h>

LoadScriptingComponent(convars, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("Convars");

    ADD_CLASS_FUNCTION("Convars", "Convars", [](FunctionContext* context, ClassData* data) -> void {});

    ADD_CLASS_FUNCTION("Convars", "AddFlags", [](FunctionContext* context, ClassData* data) -> void {
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");
        if(cvarname == "") return;

        ConVarRefAbstract cvar(cvarname.c_str());
        if(!cvar.IsValidRef()) return;
        
        int64_t flags = context->GetArgumentOr<int64_t>(1, 0);
        cvar.AddFlags(flags);
    });

    ADD_CLASS_FUNCTION("Convars", "RemoveFlags", [](FunctionContext* context, ClassData* data) -> void {
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");
        if(cvarname == "") return;

        ConVarRefAbstract cvar(cvarname.c_str());
        if(!cvar.IsValidRef()) return;
        
        int64_t flags = context->GetArgumentOr<int64_t>(1, 0);
        cvar.RemoveFlags(flags);
    });

    ADD_CLASS_FUNCTION("Convars", "GetFlags", [](FunctionContext* context, ClassData* data) -> void {
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");
        if(cvarname == "") return context->SetReturn(0);

        ConVarRefAbstract cvar(cvarname.c_str());
        if(!cvar.IsValidRef()) return context->SetReturn(0);
        
        context->SetReturn(cvar.GetFlags());
    });

    ADD_CLASS_FUNCTION("Convars", "HasFlags", [](FunctionContext* context, ClassData* data) -> void {
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");
        if(cvarname == "") return context->SetReturn(false);

        ConVarRefAbstract cvar(cvarname.c_str());
        if(!cvar.IsValidRef()) return context->SetReturn(false);
        
        int64_t flags = context->GetArgumentOr<int64_t>(1, 0);
        context->SetReturn(cvar.IsFlagSet(flags));
    });

    ADD_CLASS_FUNCTION("Convars", "Exists", [](FunctionContext* context, ClassData* data) -> void {
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");
        if(cvarname == "") return context->SetReturn(false);

        ConVarRefAbstract cvar(cvarname.c_str());
        context->SetReturn(cvar.IsValidRef());
    });

    ADD_CLASS_FUNCTION("Convars", "ExistsFake", [](FunctionContext* context, ClassData* data) -> void {
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");
        if(cvarname == "") return context->SetReturn(false);

        ConVarRefAbstract cvar(cvarname.c_str());
        context->SetReturn(cvar.IsValidRef());
    });

    ADD_CLASS_FUNCTION("Convars", "Get", [](FunctionContext* context, ClassData* data) -> void {
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");
        if(cvarname == "") return;

        context->SetReturn(g_cvarManager.GetConvarValue(cvarname));
    });

    ADD_CLASS_FUNCTION("Convars", "GetType", [](FunctionContext* context, ClassData* data) -> void {
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");
        if(cvarname == "") return context->SetReturn((int)(EConVarType::EConVarType_Invalid));

        context->SetReturn((int)(g_cvarManager.GetConvarType(cvarname)));
    });

    ADD_CLASS_FUNCTION("Convars", "Set", [](FunctionContext* context, ClassData* data) -> void {
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");
        if(cvarname == "") return;

        std::string value = context->GetArgumentOr<std::string>(1, "");

        ConVarRefAbstract cvar(cvarname.c_str());
        if(!cvar.IsValidRef()) return;

        cvar.SetString(value.c_str());
    });

    ADD_CLASS_FUNCTION("Convars", "CreateFake", [](FunctionContext* context, ClassData* data) -> void {
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");
        if(cvarname == "") return;

        int type = context->GetArgumentOr<int>(1, -1);
        if(type == -1) return;

        std::any defaultValue = context->GetArgument<std::any>(2);

        g_cvarManager.CreateConvar(cvarname, (EConVarType)type, "Swiftly Fake Convar", FCVAR_NONE, defaultValue, false, nullptr, false, nullptr);
    });

    ADD_CLASS_FUNCTION("Convars", "Create", [](FunctionContext* context, ClassData* data) -> void {
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");
        if(cvarname == "") return;

        std::string description = context->GetArgumentOr<std::string>(1, "");
        if(description == "") return;

        int type = context->GetArgumentOr<int>(2, -1);
        if(type == -1) return;

        int flags = context->GetArgumentOr<int>(3, 0);

        std::any defaultValue = context->GetArgument<std::any>(4);
        std::any minValue = context->GetArgument<std::any>(5);
        std::any maxValue = context->GetArgument<std::any>(6);

        g_cvarManager.CreateConvar(cvarname, (EConVarType)type, description, flags, defaultValue, minValue.has_value(), minValue, maxValue.has_value(), maxValue);
    });

    ADD_CLASS_FUNCTION("Convars", "DeleteFake", [](FunctionContext* context, ClassData* data) -> void {
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");
        if(cvarname == "") return;

        g_cvarManager.DeleteConvar(cvarname);
    });

    ADD_CLASS_FUNCTION("Convars", "Delete", [](FunctionContext* context, ClassData* data) -> void {
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");
        if(cvarname == "") return;

        g_cvarManager.DeleteConvar(cvarname);
    });
})