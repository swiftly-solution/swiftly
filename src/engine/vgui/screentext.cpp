#include "screentext.h"

#include <memory/virtual/virtual.h>
#include <server/configuration/configuration.h>
#include <sdk/schema.h>
#include <entities/system.h>

std::vector<CEntityKeyValues*> scheduleForDelete;

ScreenText::~ScreenText()
{
    if (pScreenEntity.IsValid()) {
        schema::SetProp<bool>(pScreenEntity.Get(), "CPointWorldText", "m_bEnabled", false);
        schema::SetProp<bool>(pScreenEntity.Get(), "CPointWorldText", "m_bDrawBackground", false);
    }
}

void ScreenText::Create(Color color, std::string font, int size, bool drawBackground, bool isMenu)
{
    m_col = color;
    m_font = font;
    m_size = size;
    m_drawBackground = drawBackground;
    m_isMenu = isMenu;

    pScreenEntity.Set((CEntityInstance*)(g_entSystem.CreateByName("point_worldtext")));
    if (!pScreenEntity) return;

    CEntityKeyValues* pMenuKV = new CEntityKeyValues();

    scheduleForDelete.push_back(pMenuKV);

    pMenuKV->SetBool("enabled", true);
    pMenuKV->SetFloat("world_units_per_pixel", (0.25 / 1050) * size);
    pMenuKV->SetInt("justify_horizontal", 0);
    pMenuKV->SetInt("justify_vertical", 2);
    pMenuKV->SetInt("reorient_mode", 0);
    pMenuKV->SetInt("fullbright", 1);
    pMenuKV->SetFloat("font_size", size);
    pMenuKV->SetString("font_name", font.c_str());
    pMenuKV->SetColor("color", color);

    if (drawBackground) {
        pMenuKV->SetBool("draw_background", true);

        if (isMenu) {
            pMenuKV->SetFloat("background_border_width", 0.2);
            pMenuKV->SetFloat("background_border_height", 0.15);
        }
        else {
            pMenuKV->SetFloat("background_border_width", g_Config.FetchValue<float>("core.vgui.textBackground.paddingX"));
            pMenuKV->SetFloat("background_border_height", g_Config.FetchValue<float>("core.vgui.textBackground.paddingY"));
        }

        pMenuKV->SetFloat("background_away_units", 0.04);
        pMenuKV->SetFloat("background_world_to_uv", 0.05);
    }

    g_entSystem.Spawn(pScreenEntity.Get(), pMenuKV);
}

void ScreenText::SetupViewForPlayer(Player* player)
{
    m_player = player;

    if (!pScreenEntity) return;
    if (!player) return;
    if (player->IsFakeClient()) return;

    void* pViewModel = player->EnsureCustomView(1);
    if (!pViewModel) return;

    g_entSystem.AcceptInput(pScreenEntity, "SetParent", pViewModel, nullptr, "!activator", 0);
    schema::SetProp<CHandle<CEntityInstance>>(pScreenEntity, "CBaseEntity", "m_hOwnerEntity", ((CEntityInstance*)(pViewModel))->GetRefEHandle());
}

void ScreenText::SetText(std::string text)
{
    m_text = text;

    if (!pScreenEntity) return;

    g_entSystem.AcceptInput(pScreenEntity.Get(), "SetMessage", nullptr, nullptr, m_text, 0);
    g_entSystem.AcceptInput(pScreenEntity.Get(), "Enable", nullptr, nullptr, "", 0);
}

void ScreenText::SetPosition(float posX, float posY)
{
    m_posX = posX;
    m_posY = posY;

    if (!m_player) return;
    if (m_player->IsFakeClient()) return;
    if (!pScreenEntity) return;

    auto pawn = m_player->GetPlayerPawn();
    if (!pawn) return;

    if (schema::GetProp<uint32_t>(pawn, "CBaseEntity", "m_lifeState") == 2) {
        auto controller = m_player->GetController();
        if (!controller) return;
        if (schema::GetProp<bool>(controller, "CCSPlayerController", "m_bControllingBot")) return;

        auto observerServices = schema::GetProp<void*>(pawn, "CBasePlayerPawn", "m_pObserverServices");
        if (!observerServices) return;

        CHandle<CEntityInstance> observerTarget = schema::GetProp<CHandle<CEntityInstance>>(observerServices, "CPlayer_ObserverServices", "m_hObserverTarget");
        if (!observerTarget) return;

        auto observerController = schema::GetProp<CHandle<CEntityInstance>>(observerTarget.Get(), "CCSPlayerPawnBase", "m_hOriginalController");
        if (!observerController) return;

        CHandle<CEntityInstance> pawnHandle = schema::GetProp<CHandle<CEntityInstance>>(observerController, "CCSPlayerController", "m_hPlayerPawn");
        if (!pawnHandle) return;
        pawn = (void*)(pawnHandle.Get());
    }

    if (!pawn) return;

    QAngle eyeAngles = schema::GetProp<QAngle>(pawn, "CCSPlayerPawnBase", "m_angEyeAngles");
    Vector fwd, right, up;
    AngleVectors(eyeAngles, &fwd, &right, &up);

    Vector eyePos(0.0, 0.0, 0.0);
    eyePos += fwd * 7;
    eyePos += right * (-9.2 + (posX * 18.35));
    eyePos += up * (-4.9 + (posY * 10.13));

    QAngle ang(0, eyeAngles.y + 270, 90 - eyeAngles.x);

    void* bodyComponent = schema::GetProp<void*>(pawn, "CBaseEntity", "m_CBodyComponent");
    if (!bodyComponent) return;

    void* sceneNode = schema::GetProp<void*>(bodyComponent, "CBodyComponent", "m_pSceneNode");
    if (!sceneNode) return;

    void* camServices = schema::GetProp<void*>(pawn, "CBasePlayerPawn", "m_pCameraServices");
    if (!camServices) return;

    float oldZ = schema::GetProp<float>(camServices, "CPlayer_CameraServices", "m_flOldPlayerViewOffsetZ");

    eyePos += schema::GetProp<Vector>(sceneNode, "CGameSceneNode", "m_vecAbsOrigin") + Vector(0, 0, oldZ);

    CALL_VIRTUAL(void, g_GameData.GetOffset("CBaseEntity_Teleport"), pScreenEntity.Get(), &eyePos, &ang, nullptr);
}

void ScreenText::SetColor(Color color)
{
    m_col = color;

    if (!pScreenEntity) return;
    schema::SetProp(pScreenEntity.Get(), "CPointWorldText", "m_Color", color);
}

bool ScreenText::IsValidEntity()
{
    return pScreenEntity.IsValid();
}

void ScreenText::RegenerateText(bool recreate)
{
    if (recreate) {
        if (pScreenEntity.IsValid()) g_entSystem.Despawn(pScreenEntity.Get());

        Create(m_col, m_font, m_size, m_drawBackground, m_isMenu);
        SetupViewForPlayer(m_player);
        SetText(m_text);
        SetPosition(m_posX, m_posY);
    }
    else {
        SetupViewForPlayer(m_player);
        SetPosition(m_posX, m_posY);
    }
}

Player* ScreenText::GetPlayer()
{
    return m_player;
}

int ScreenText::GetEntityIndex()
{
    if (!pScreenEntity) return 0;

    return pScreenEntity->GetEntityIndex().Get();
}

bool ScreenText::IsRenderingTo(CHandle<CEntityInstance> renderingTo)
{
    return renderingTo == pRenderingTo;
}

void ScreenText::SetRenderingTo(CEntityInstance* ent)
{
    pRenderingTo.Set(ent);
}

void EraseScheduledCEntKeyVals() {
    // for (auto e : scheduleForDelete) {
    //     delete e;
    // }
    scheduleForDelete.clear();
}