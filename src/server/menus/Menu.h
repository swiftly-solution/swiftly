#pragma once

#include <string>
#include <map>
#include <vector>
#include <public/Color.h>
#include "../translations/Translations.h"

class Menu
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
    Menu(std::string id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options, bool tmp);
    ~Menu();

    std::string GetID();
    void ProcessOptions();
    std::string GeneratedItems(int playerid, int page);
    std::string GenerateFooter(int page);
    void RegeneratePage(int playerid, int page, int selected);

    std::string GetCommandFromOption(int page, int selected);
    size_t GetItemsOnPage(int page);
    bool IsTemporary();

    Color GetColor();
};