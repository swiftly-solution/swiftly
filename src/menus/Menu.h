#pragma once

#include <string>
#include <map>
#include <vector>

class Menu
{
private:
    std::string id;
    std::string title;
    std::string color;
    std::vector<std::pair<std::string, std::string>> options;
    std::vector<std::vector<std::pair<std::string, std::string>>> processedOptions;
    bool temporary;

    std::vector<std::string> generatedPages;

public:
    Menu(std::string id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options, bool tmp);
    ~Menu();

    std::string GetID();
    void ProcessOptions();
    std::string GeneratedItems(int page);
    void RegeneratePage(int page, int selected);

    std::string GetCommandFromOption(int page, int selected);
    size_t GetItemsOnPage(int page);
    bool IsTemporary();
};