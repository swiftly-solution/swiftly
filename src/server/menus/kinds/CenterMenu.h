#ifndef _menus_kinds_center_h
#define _menus_kinds_center_h

#include "../Menu.h"

class CenterMenu: public Menu
{
private:
    std::string id;
    std::string title;
    std::string color;
    std::vector<std::pair<std::string, std::string>> options;
    std::vector<std::vector<std::pair<std::string, std::string>>> processedOptions;
    bool temporary;

    std::map<int, std::vector<std::string>> generatedPages;
public:
    CenterMenu(std::string id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options, bool tmp);
    ~CenterMenu();

    std::string GetID();
    void ProcessOptions();
    std::string GeneratedItems(int playerid, int page);
    std::string GenerateFooter(int page);
    void RegeneratePage(int playerid, int page, int selected);

    std::string GetCommandFromOption(int page, int selected);
    size_t GetItemsOnPage(int page);
    bool IsTemporary();

    Color GetColor();
    bool RenderEachTick();
    std::string GetKind();
};

#endif