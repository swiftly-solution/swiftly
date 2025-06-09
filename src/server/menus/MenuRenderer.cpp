#include "MenuManager.h"
#include "MenuRenderer.h"

#include <server/configuration/configuration.h>
#include <engine/vgui/vgui.h>
#include <memory/gamedata/gamedata.h>
#include <server/commands/manager.h>
#include <server/player/manager.h>
#include <utils/utils.h>
#include <sdk/components/EmitSound_t.h>
#include <sdk/components/CSingleRecipientFilter.h>

typedef IGameEventListener2* (*GetLegacyGameEventListener)(CPlayerSlot slot);

typedef SndOpEventGuid_t(*CBaseEntity_EmitSoundFilter)(IRecipientFilter& filter, CEntityIndex ent, const EmitSound_t& params);

void EmitSoundFilter(int playerid, std::string sound_name, float pitch, float volume)
{
    auto player = g_playerManager.GetPlayer(playerid);
    if (!player) return;

    CEntityInstance* instance = (CEntityInstance*)player->GetController();
    if (!instance) return;

    EmitSound_t params;
    params.m_pSoundName = sound_name.c_str();
    params.m_flVolume = volume;
    params.m_nPitch = pitch;

    CBaseEntity_EmitSoundFilter filter = g_GameData.FetchSignature<CBaseEntity_EmitSoundFilter>("CBaseEntity_EmitSoundFilter");

    CSingleRecipientFilter playerfilter(playerid);
    filter(playerfilter, instance->m_pEntity->m_EHandle.GetEntryIndex(), params);
}

MenuRenderer::MenuRenderer(Player* player)
{
    m_player = player;
    menu = nullptr;
}

MenuRenderer::~MenuRenderer()
{
    HideMenu();
}

void MenuRenderer::ShowMenu(std::string menu_id)
{
    if (menu != nullptr) return;

    Menu* m = g_MenuManager.FetchMenu(menu_id);
    if (m == nullptr) return;

    menu = m;
    page = 1;
    selected = 0;

    menu->RegeneratePage(m_player->GetSlot(), page, selected);

    std::string kind = menu->GetKind();
    if (kind == "center") {
        RenderMenu();
    }
    else if (kind == "screen") {
        menuTextID = g_VGUI.RegisterScreenText();

        auto menuText = g_VGUI.GetScreenText(menuTextID);

        std::string menu_mode = g_Config.FetchValue<std::string>("core.menu.kind_settings.screen.mode");
        std::string font = g_Config.FetchValue<std::string>(string_format("core.menu.kind_settings.screen.modes.%s.font", menu_mode.c_str()));

        float posX = g_Config.FetchValue<float>(string_format("core.menu.kind_settings.screen.modes.%s.x", menu_mode.c_str()));
        float posY = g_Config.FetchValue<float>(string_format("core.menu.kind_settings.screen.modes.%s.y", menu_mode.c_str()));

        int fontSize = g_Config.FetchValue<int>(string_format("core.menu.kind_settings.screen.modes.%s.fontSize", menu_mode.c_str()));

        bool hasBackground = g_Config.FetchValue<bool>("core.menu.kind_settings.screen.drawBackground");

        menuText->Create(menu->GetColor(), font, fontSize, hasBackground, true);
        menuText->SetupViewForPlayer(m_player);
        RenderMenu();
        menuText->SetPosition(posX, posY);
    }
}

void MenuRenderer::HideMenu()
{
    if (menu == nullptr) return;

    page = 0;
    selected = 0;

    std::string kind = menu->GetKind();
    if (kind == "center") {
        if (centerMessageEvent) {
            centerMessageEvent->SetString("loc_token", "Exiting...");
            g_GameData.FetchSignature<GetLegacyGameEventListener>("LegacyGameEventListener")(m_player->GetSlot())->FireGameEvent(centerMessageEvent);
            g_gameEventManager->FreeEvent(centerMessageEvent);
        }
    }
    else if (kind == "screen") {
        g_VGUI.DeleteScreenText(menuTextID);
        menuTextID = 0;
    }

    if (menu->IsTemporary()) {
        std::string menuID = menu->GetID();
        g_MenuManager.UnregisterMenu(menuID);
    }
    menu = nullptr;
}

bool MenuRenderer::HasMenuShown()
{
    return (menu != nullptr);
}

Menu* MenuRenderer::GetMenu()
{
    return menu;
}

int MenuRenderer::GetPage()
{
    return page;
}

void MenuRenderer::SetPage(int pg)
{
    page = pg;
    selected = 0;
    menu->RegeneratePage(m_player->GetSlot(), page, selected);
    RenderMenu();
}

int MenuRenderer::GetSelection()
{
    return selected;
}

void MenuRenderer::MoveSelection()
{
    if (page == 0)
        return;

    int itemsPerPage = menu->GetItemsOnPage(page);
    ++selected;
    if (itemsPerPage == selected)
        selected = 0;

    menu->RegeneratePage(m_player->GetSlot(), page, selected);
    RenderMenu();
}

void MenuRenderer::RenderMenu() {
    if (!menu) return;
    std::string kind = menu->GetKind();
    if (kind == "center") {
        centerMessageEvent = g_gameEventManager->CreateEvent("show_survival_respawn_status", true);
        centerMessageEvent->SetUint64("duration", 1);
        centerMessageEvent->SetInt("userid", m_player->GetSlot());
        centerMessageEvent->SetString("loc_token", menu->GeneratedItems(m_player->GetSlot(), page).c_str());
    }
    else if (kind == "screen") {
        auto menuText = g_VGUI.GetScreenText(menuTextID);
        if (!menuText) return;

        menuText->SetText(menu->GeneratedItems(m_player->GetSlot(), page));
    }
}

void MenuRenderer::RenderMenuTick()
{
    if (!menu) return;
    if (!menu->RenderEachTick()) return;

    std::string kind = menu->GetKind();
    if (kind == "center") {
        auto listener = g_GameData.FetchSignature<GetLegacyGameEventListener>("LegacyGameEventListener")(m_player->GetSlot());
        if (!listener) return;
        if (!centerMessageEvent) return;
        listener->FireGameEvent(centerMessageEvent);
    }
}

bool MenuRenderer::ShouldRenderEachTick()
{
    if (!menu) return false;
    return menu->RenderEachTick();
}

void MenuRenderer::PerformMenuAction(std::string button)
{
    if (!HasMenuShown())
        return;

    int playerid = m_player->GetSlot();

    if (button == g_Config.FetchValue<std::string>("core.menu.buttons.scroll"))
    {
        EmitSoundFilter(playerid, g_Config.FetchValue<std::string>("core.menu.sound.scroll.name"), 1.0, g_Config.FetchValue<double>("core.menu.sound.scroll.volume"));

        MoveSelection();
    }
    else if (!g_Config.FetchValue<bool>("core.menu.buttons.exit.option") && button == g_Config.FetchValue<std::string>("core.menu.buttons.exit.button"))
    {
        EmitSoundFilter(playerid, g_Config.FetchValue<std::string>("core.menu.sound.exit.name"), 1.0, g_Config.FetchValue<double>("core.menu.sound.exit.volume"));

        HideMenu();
    }
    else if (button == g_Config.FetchValue<std::string>("core.menu.buttons.use"))
    {
        std::string cmd = GetMenu()->GetCommandFromOption(GetPage(), GetSelection());

        if (cmd != "menuexit")
            EmitSoundFilter(playerid, g_Config.FetchValue<std::string>("core.menu.sound.use.name"), 1.0, g_Config.FetchValue<double>("core.menu.sound.use.volume"));

        if (cmd == "menunext")
        {
            SetPage(GetPage() + 1);
        }
        else if (cmd == "menuback")
        {
            SetPage(GetPage() - 1);
        }
        else if (g_Config.FetchValue<bool>("core.menu.buttons.exit.option") && cmd == "menuexit")
        {
            EmitSoundFilter(playerid, g_Config.FetchValue<std::string>("core.menu.sound.exit.name"), 1.0, g_Config.FetchValue<double>("core.menu.sound.exit.volume"));

            HideMenu();
        }
        else if (g_MenuManager.FetchMenu(cmd))
        {
            HideMenu();
            ShowMenu(cmd);
        }
        else if (starts_with(cmd, "sw_"))
        {
            CCommand tokenizedArgs;
            tokenizedArgs.Tokenize(cmd.c_str());
            if (tokenizedArgs.ArgC() <= 0) return;

            std::string commandName = (tokenizedArgs[0] + 3);

            std::vector<std::string> argsplit = TokenizeCommand(cmd.c_str());
            if (argsplit.size() > 0) argsplit.erase(argsplit.begin());

            if (g_commandsManager.FetchCommand(commandName) == nullptr)
                return;

            Command* command = g_commandsManager.FetchCommand(commandName);
            if (!command)
                return;

            command->Execute(m_player->GetSlot(), argsplit, true, "sw_");
        }
        else if (cmd != "")
            m_player->PerformCommand(cmd);
    }
}