#include "../../scripting.h"
#include "../../../../engine/vgui/VGUI.h"
#include "../../../../player/playermanager/PlayerManager.h"

PluginVGUI::PluginVGUI(std::string plugin_name)
{
    m_plugin_name = plugin_name;
}

uint64_t PluginVGUI::ShowText(int playerid, Color color, std::string text, float posX, float posY)
{
    REGISTER_CALLSTACK(m_plugin_name, string_format("PluginVGUI::ShowText(playerid=%d,color=\"%d,%d,%d,%d\",text=\"%s\",posX=%f,posY=%f)", playerid, color.r(), color.g(), color.b(), color.a(), text.c_str(), posX, posY));

    Player* player = g_playerManager->GetPlayer(playerid);
    if(!player) return -1;

    if(posX < 0.0f) posX = 0.0f;
    if(posX > 1.0f) posX = 1.0f;

    if(posY < 0.0f) posY = 0.0f;
    if(posY > 1.0f) posY = 1.0f;

    uint64_t textID = g_pVGUI->RegisterScreenText();
    ScreenText* txt = g_pVGUI->GetScreenText(textID);

    txt->Create(color);
    txt->SetupViewForPlayer(player);
    txt->SetText(text);
    txt->SetPosition(posX, posY);

    return textID;
}

void PluginVGUI::RemoveText(uint64_t textID)
{
    REGISTER_CALLSTACK(m_plugin_name, string_format("PluginVGUI::RemoveText(textID=%llu)", textID));

    g_pVGUI->DeleteScreenText(textID);
}

void PluginVGUI::SetTextMessage(uint64_t textID, std::string text)
{
    REGISTER_CALLSTACK(m_plugin_name, string_format("PluginVGUI::SetTextMessage(textID=%llu,text=\"%s\")", textID, text.c_str()));

    ScreenText* txt = g_pVGUI->GetScreenText(textID);
    if(!txt) return;

    txt->SetText(text);
}

void PluginVGUI::SetTextPosition(uint64_t textID, float posX, float posY)
{
    REGISTER_CALLSTACK(m_plugin_name, string_format("PluginVGUI::SetTextPosition(textID=%llu,posX=%f,posY=%f)", textID, posX, posY));

    ScreenText* txt = g_pVGUI->GetScreenText(textID);
    if(!txt) return;
    
    txt->SetPosition(posX, posY);
}

uint64_t PluginVGUI::ShowPanel(int playerid, Color color, std::string text, float posX, float posY)
{
    REGISTER_CALLSTACK(m_plugin_name, string_format("PluginVGUI::ShowPanel(playerid=%d,color=\"%d,%d,%d,%d\",text=\"%s\",posX=%f,posY=%f)", playerid, color.r(), color.g(), color.b(), color.a(), text.c_str(), posX, posY));

    Player* player = g_playerManager->GetPlayer(playerid);
    if(!player) return -1;

    if(posX < 0.0f) posX = 0.0f;
    if(posX > 1.0f) posX = 1.0f;

    if(posY < 0.0f) posY = 0.0f;
    if(posY > 1.0f) posY = 1.0f;

    uint64_t textID = g_pVGUI->RegisterScreenPanel();
    ScreenPanel* panel = g_pVGUI->GetScreenPanel(textID);

    panel->Create(color);
    panel->SetupViewForPlayer(player);
    panel->SetText(text);
    panel->SetPosition(posX, posY);

    return textID;
}

void PluginVGUI::RemovePanel(uint64_t textID)
{
    REGISTER_CALLSTACK(m_plugin_name, string_format("PluginVGUI::RemovePanel(textID=%llu)", textID));

    g_pVGUI->DeleteScreenPanel(textID);
}

void PluginVGUI::SetPanelMessage(uint64_t textID, std::string text)
{
    REGISTER_CALLSTACK(m_plugin_name, string_format("PluginVGUI::SetPanelMessage(textID=%llu,text=\"%s\")", textID, text.c_str()));

    ScreenPanel* panel = g_pVGUI->GetScreenPanel(textID);
    if(!panel) return;

    panel->SetText(text);
}

void PluginVGUI::SetPanelPosition(uint64_t textID, float posX, float posY)
{
    REGISTER_CALLSTACK(m_plugin_name, string_format("PluginVGUI::SetPanelPosition(textID=%llu,posX=%f,posY=%f)", textID, posX, posY));

    ScreenPanel* panel = g_pVGUI->GetScreenPanel(textID);
    if(!panel) return;
    
    panel->SetPosition(posX, posY);
}