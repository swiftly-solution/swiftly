#include "ScreenPanel.h"

ScreenPanel::ScreenPanel()
{
}

ScreenPanel::~ScreenPanel()
{
    if(pScreenEntity.IsValid()) {
        pScreenEntity->Despawn();
    }
}

void ScreenPanel::Create(Color color, int size)
{
    m_col = color;
    m_size = size;

    pScreenEntity.Set((CPointWorldText*)(CreateEntityByName("point_worldtext").GetPtr()));
    if(!pScreenEntity) return;

    CEntityKeyValues* pMenuKV = new CEntityKeyValues();

    pMenuKV->SetBool("enabled", false);
    pMenuKV->SetFloat("world_units_per_pixel", (0.25 / 300) * size);
    pMenuKV->SetFloat("depth_render_offset", 0.125);
    pMenuKV->SetInt("justify_horizontal", 0);
    pMenuKV->SetInt("justify_vertical", 2);
    pMenuKV->SetInt("reorient_mode", 0);
    pMenuKV->SetInt("fullbright", 1);
    pMenuKV->SetFloat("font_size", size);
    pMenuKV->SetColor("color", color);

    pScreenEntity->DispatchSpawn(pMenuKV);
}

void ScreenPanel::SetupViewForPlayer(Player* player)
{
    if(!pScreenEntity) return;
    if(!player) return;
    if(player->IsFakeClient()) return;

    CBaseViewModel* pViewModel = player->EnsureCustomView(1);
    if(!pViewModel) return;

    pScreenEntity->SetParent(pViewModel);
    pScreenEntity->m_hOwnerEntity(pViewModel->GetRefEHandle());

    m_player = player;
}

void ScreenPanel::SetText(std::string text)
{
    if(!pScreenEntity) return;

    m_text = text;

    pScreenEntity->SetText(m_text.c_str());
    pScreenEntity->Enable();
}

void ScreenPanel::SetPosition(float posX, float posY)
{
    if(!m_player) return;
    if(m_player->IsFakeClient()) return;
 
    CCSPlayerPawn* pawn = m_player->GetPlayerPawn();
    if(pawn->m_lifeState() == 2) {
        auto pPawn = m_player->GetPawn();
        if(!pPawn) return;

        auto observerPawn = pPawn->m_pObserverServices->m_hObserverTarget();
        if(!observerPawn) return;

        auto observerController = ((CCSPlayerPawn*)(observerPawn.Get()))->m_hOriginalController();
        if(!observerController) return;

        auto observer = g_playerManager->GetPlayer(observerController->entindex() - 1);
        if(!observer) return;
        pawn = observer->GetPlayerPawn();
    }
    if(!pawn) return;
    
    QAngle eyeAngles = pawn->m_angEyeAngles();
    Vector fwd, right, up;
    AngleVectors(eyeAngles, &fwd, &right, &up);

    Vector eyePos(0.0, 0.0, 0.0);
    eyePos += fwd * 7;
    eyePos += right * (-9.15 + (posX * 18.35));
    eyePos += up * (-4.65 + (posY * 10.2));

    QAngle ang(0, eyeAngles.y + 270, 90 - eyeAngles.x);

    eyePos += pawn->m_CBodyComponent->m_pSceneNode->m_vecAbsOrigin() + Vector(0, 0, pawn->m_vecViewOffset->m_vecZ());

    pScreenEntity->Teleport(&eyePos, &ang, nullptr);

    m_posX = posX;
    m_posY = posY;
}

bool ScreenPanel::IsValidEntity()
{
    return pScreenEntity.IsValid();
}

void ScreenPanel::RegeneratePanel(bool recreate)
{
    if(recreate) {
        if(pScreenEntity.IsValid()) pScreenEntity->Despawn();
    
        Create(m_col, m_size);
        SetupViewForPlayer(m_player);
        SetText(m_text);
        SetPosition(m_posX, m_posY);
    } else {
        SetupViewForPlayer(m_player);
        SetPosition(m_posX, m_posY);
    }
}

Player* ScreenPanel::GetPlayer()
{
    return m_player;
}

int ScreenPanel::GetEntityIndex()
{
    if(!pScreenEntity) return 0;

    return pScreenEntity->GetEntityIndex().Get();
}

bool ScreenPanel::IsRenderingTo(CHandle<CBaseEntity> renderingTo)
{
    return renderingTo == pRenderingTo;
}

void ScreenPanel::SetRenderingTo(CBaseEntity* ent)
{
    pRenderingTo.Set(ent);
}