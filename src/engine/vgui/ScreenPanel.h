#ifndef _engine_vgui_screenpanel_h
#define _engine_vgui_screenpanel_h

#include <string>
#include "../../plugins/core/scripting.h"
#include "../../player/playermanager/PlayerManager.h"

#include <public/entity2/entitykeyvalues.h>
#include "../../sdk/entity/CPointWorldText.h"
#include "../../sdk/entity/CBaseViewModel.h"

class ScreenPanel
{
private:
    CHandle<CPointWorldText> pScreenEntity;
    CHandle<CBaseEntity> pRenderingTo;

    Color m_col;
    int m_size;
    Player* m_player;
    float m_posX;
    float m_posY;
    std::string m_text;

public:
    ScreenPanel();
    ~ScreenPanel();

    void Create(Color color, int size = 80);
    void SetupViewForPlayer(Player* player);
    void SetText(std::string text);
    void SetPosition(float posX = 0.0, float posY = 0.0);
    void SetRenderingTo(CBaseEntity* ent);
    void RegeneratePanel(bool recreate = true);
    
    bool IsValidEntity();
    Player* GetPlayer();
    int GetEntityIndex();
    bool IsRenderingTo(CHandle<CBaseEntity> renderingTo);
};

#endif