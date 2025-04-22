#ifndef _engine_vgui_screentext_h
#define _engine_vgui_screentext_h

#include <string>
#include <server/player/player.h>
#include "ehandle.h"

class ScreenText
{
private:
    CHandle<CEntityInstance> pScreenEntity;
    CHandle<CEntityInstance> pRenderingTo;

    Color m_col;
    std::string m_font;
    int m_size;
    Player* m_player;
    float m_posX;
    float m_posY;
    std::string m_text;
    bool m_drawBackground;
    bool m_isMenu;

public:
    ~ScreenText();

    void Create(Color color, std::string font = "Sans Serif", int size = 35, bool drawBackground = false, bool isMenu = false);
    void SetupViewForPlayer(Player* player);
    void SetText(std::string text);
    void SetColor(Color color);
    void SetPosition(float posX = 0.0, float posY = 0.0);
    void SetRenderingTo(CEntityInstance* ent);
    void RegenerateText(bool recreate = true);

    bool IsValidEntity();
    Player* GetPlayer();
    int GetEntityIndex();
    bool IsRenderingTo(CHandle<CEntityInstance> renderingTo);
};

#endif