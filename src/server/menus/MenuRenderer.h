#ifndef _menus_menurenderer_h
#define _menus_menurenderer_h

#include <string>
#include <public/igameevents.h>
#include "Menu.h"

class Player;

class MenuRenderer
{
private:
    Player* m_player;

    Menu* menu = nullptr;
    int page = 0;
    int selected = 0;

    // Screen Kind
    uint64_t menuTextID = 0;

    // Center Kind
    IGameEvent* centerMessageEvent = nullptr;
    IGameEventListener2* playerListener = nullptr;

public:
    MenuRenderer(Player* player);
    ~MenuRenderer();

    void ShowMenu(std::string menu_id);

    void HideMenu();
    bool HasMenuShown();
    Menu* GetMenu();

    int GetPage();
    void SetPage(int pg);
    int GetSelection();
    void MoveSelection();

    void PerformMenuAction(std::string button);

    bool ShouldRenderEachTick();
    void RenderMenu();
    void RenderMenuTick();
};

#endif