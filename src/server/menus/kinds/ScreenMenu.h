#ifndef _menus_kinds_screen_h
#define _menus_kinds_screen_h

#include "../Menu.h"

class ScreenMenu : public Menu
{
private:
    std::string id;
    std::string title;
    Color color;
    std::vector<std::pair<std::string, std::string>> options;
    std::vector<std::vector<std::pair<std::string, std::string>>> processedOptions;
    bool temporary;

    std::map<int, std::vector<std::string>> generatedPages;
public:
    ScreenMenu(std::string id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options, bool tmp);
    ~ScreenMenu();

    std::string GetID();
    void ProcessOptions();
    std::string GeneratedItems(int playerid, int page);
    std::string GenerateFooter(int page);
    void RegeneratePage(int playerid, int page, int selected);

    std::string GetCommandFromOption(int page, int selected);
    int GetItemsOnPage(int page);
    bool IsTemporary();

    Color GetColor();
    bool RenderEachTick();
    std::string GetKind();
};

#endif