#include <scripting/core.h>

#include <engine/vgui/vgui.h>
#include <server/player/manager.h>

LoadScriptingComponent(vgui, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("VGUI");

    ADD_CLASS_FUNCTION("VGUI", "VGUI", [](FunctionContext* context, ClassData* data) -> void {});

    ADD_CLASS_FUNCTION("VGUI", "ShowText", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(0);
        // int playerid = context->GetArgumentOr<int>(0, -1);
        // if(playerid == -1) return context->SetReturn(0);

        // ClassData* cdata = context->GetArgumentOr<ClassData*>(1, nullptr);
        // if(!cdata) return context->SetReturn(0);
        // if(!cdata->HasData("Color_ptr")) return context->SetReturn(0);
        // Color color = cdata->GetData<Color>("Color_ptr");

        // std::string text = context->GetArgumentOr<std::string>(2, "");

        // float x = context->GetArgumentOr<float>(3, 0.0);
        // float y = context->GetArgumentOr<float>(4, 0.0);

        // if(x < 0.0) x = 0.0;
        // if(x > 1.0) x = 1.0;

        // if(y < 0.0) y = 0.0;
        // if(y > 1.0) y = 1.0;

        // std::string font_name = context->GetArgumentOr<std::string>(5, "Sans Serif");
        // bool background = context->GetArgumentOr<bool>(6, false);

        // Player* player = g_playerManager.GetPlayer(playerid);
        // if(!player) return context->SetReturn(0);

        // uint64_t textID = g_VGUI.RegisterScreenText();
        // ScreenText* txt = g_VGUI.GetScreenText(textID);

        // txt->Create(color, font_name, 35, background);
        // txt->SetupViewForPlayer(player);
        // txt->SetText(text);
        // txt->SetPosition(x, y);

        // context->SetReturn(textID);
    });

    ADD_CLASS_FUNCTION("VGUI", "RemoveText", [](FunctionContext* context, ClassData* data) -> void {
        return;
        // uint64_t textID = context->GetArgumentOr<uint64_t>(0, 0);
        // if (textID == 0) return;

        // ScreenText* text = g_VGUI.GetScreenText(textID);
        // if (!text) return;

        // g_VGUI.DeleteScreenText(textID);
    });

    ADD_CLASS_FUNCTION("VGUI", "SetTextMessage", [](FunctionContext* context, ClassData* data) -> void {
        // uint64_t textID = context->GetArgumentOr<uint64_t>(0, 0);
        // if (textID == 0) return;

        // ScreenText* text = g_VGUI.GetScreenText(textID);
        // if (!text) return;

        // std::string str = context->GetArgumentOr<std::string>(1, "");
        // text->SetText(str);

        return;
    });

    ADD_CLASS_FUNCTION("VGUI", "SetTextPosition", [](FunctionContext* context, ClassData* data) -> void {
        // uint64_t textID = context->GetArgumentOr<uint64_t>(0, 0);
        // if (textID == 0) return;

        // ScreenText* text = g_VGUI.GetScreenText(textID);
        // if (!text) return;

        // float x = context->GetArgumentOr<float>(1, 0.0);
        // float y = context->GetArgumentOr<float>(1, 0.0);

        // if (x < 0.0) x = 0.0;
        // if (x > 1.0) x = 1.0;

        // if (y < 0.0) y = 0.0;
        // if (y > 1.0) y = 1.0;

        // text->SetPosition(x, y);
        return;
    });

    ADD_CLASS_FUNCTION("VGUI", "SetTextColor", [](FunctionContext* context, ClassData* data) -> void {
        // uint64_t textID = context->GetArgumentOr<uint64_t>(0, 0);
        // if (textID == 0) return;

        // ScreenText* text = g_VGUI.GetScreenText(textID);
        // if (!text) return;

        // ClassData* cdata = context->GetArgumentOr<ClassData*>(1, nullptr);
        // if (!cdata) return;
        // if (!cdata->HasData("Color_ptr")) return;

        // Color value = cdata->GetData<Color>("Color_ptr");
        // text->SetColor(value);
        return;
    });
})