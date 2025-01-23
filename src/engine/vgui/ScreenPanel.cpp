#include "ScreenPanel.h"

ScreenPanel::ScreenPanel()
{
}

ScreenPanel::~ScreenPanel()
{
    if (pScreenEntity.IsValid()) {
        pScreenEntity->Despawn();
    }
}

void ScreenPanel::Create(Color color, int size)
{
    m_col = color;
    m_size = size;

    pScreenEntity.Set((CPointWorldText*)(CreateEntityByName("point_worldtext").GetPtr()));
    if (!pScreenEntity) return;

    CEntityKeyValues* pMenuKV = new CEntityKeyValues();

    pMenuKV->SetBool("enabled", false);
    pMenuKV->SetFloat("world_units_per_pixel", (0.25 / 300) * size);
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
    m_player = player;

    if (!pScreenEntity) return;
    if (!player) return;
    if (player->IsFakeClient()) return;

    CBaseViewModel* pViewModel = player->EnsureCustomView(1);
    if (!pViewModel) return;

    pScreenEntity->SetParent(pViewModel);
    pScreenEntity->m_hOwnerEntity(pViewModel->GetRefEHandle());
}

void ScreenPanel::SetText(std::string text)
{
    m_text = text;

    if (!pScreenEntity) return;

    pScreenEntity->SetText(m_text.c_str());
    pScreenEntity->Enable();
}

void ScreenPanel::SetPosition(float posX, float posY)
{
    m_posX = posX;
    m_posY = posY;

    if (!m_player) return;
    if (m_player->IsFakeClient()) return;
    if(!pScreenEntity) return;

    CCSPlayerPawn* pawn = m_player->GetPlayerPawn();
    if (!pawn) return;
    if (pawn->m_lifeState() == 2) {
        if (m_player->GetPlayerController()->m_bControllingBot()) {
            return;
        }
        else {
            auto pPawn = m_player->GetPawn();
            if (!pPawn) return;

            auto observerPawn = pPawn->m_pObserverServices->m_hObserverTarget();
            if (!observerPawn) return;

            auto observerController = ((CCSPlayerPawn*)(observerPawn.Get()))->m_hOriginalController();
            if (!observerController) return;

            auto observer = g_playerManager->GetPlayer(observerController->entindex() - 1);
            if (!observer) return;
            pawn = observer->GetPlayerPawn();
        }
    }
    if (!pawn) return;

    QAngle eyeAngles = pawn->m_angEyeAngles();
    Vector fwd, right, up;
    AngleVectors(eyeAngles, &fwd, &right, &up);

    Vector eyePos(0.0, 0.0, 0.0);
    eyePos += fwd * 7.12;
    eyePos += right * (-9.3 + (posX * 18.66));
    eyePos += up * (-4.82 + (posY * 10.47));

    QAngle ang(0, eyeAngles.y + 270, 90 - eyeAngles.x);

    eyePos += pawn->m_CBodyComponent->m_pSceneNode->m_vecAbsOrigin() + Vector(0, 0, pawn->m_pCameraServices->m_flOldPlayerViewOffsetZ());

    pScreenEntity->Teleport(&eyePos, &ang, nullptr);
}

bool ScreenPanel::IsValidEntity()
{
    return pScreenEntity.IsValid();
}

void ScreenPanel::RegeneratePanel(bool recreate)
{
    if (recreate) {
        if (pScreenEntity.IsValid()) pScreenEntity->Despawn();

        Create(m_col, m_size);
        SetupViewForPlayer(m_player);
        SetText(m_text);
        SetPosition(m_posX, m_posY);
    }
    else {
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
    if (!pScreenEntity) return 0;

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