#ifndef _engine_vgui_screentext_h
#define _engine_vgui_screentext_h

#include <string>
#include "../../plugins/core/scripting.h"
#include "../../player/playermanager/PlayerManager.h"

#include <public/entity2/entitykeyvalues.h>
#include "../../sdk/entity/CPointWorldText.h"
#include "../../sdk/entity/CBaseViewModel.h"

class ScreenText
{
private:
    CHandle<CPointWorldText> pScreenEntity;
    CHandle<CBaseEntity> pRenderingTo;

    Color m_col;
    std::string m_font;
    int m_size;
    Player* m_player;
    float m_posX;
    float m_posY;
    std::string m_text;

public:
    ScreenText();
    ~ScreenText();

    void Create(Color color, std::string font = "Verdana", int size = 35);
    void SetupViewForPlayer(Player* player);
    void SetText(std::string text);
    void SetPosition(float posX = 0.0, float posY = 0.0);
    void SetRenderingTo(CBaseEntity* ent);
    void RegenerateText(bool recreate = true);

    bool IsValidEntity();
    Player* GetPlayer();
    int GetEntityIndex();
    bool IsRenderingTo(CHandle<CBaseEntity> renderingTo);
};

#endif