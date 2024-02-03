#ifndef _swiftly_menu_h
#define _swiftly_menu_h

#include <string>
#include <unordered_map>
#include <vector>
#include "../utils.h"

class Menu
{
private:
    std::string id;
    std::string title;
    std::string color;
    std::unordered_map<std::string, std::string> options;
    std::vector<std::vector<std::pair<std::string, std::string>>> processedOptions;

public:
    Menu(std::string id, std::string title, std::string color, std::unordered_map<std::string, std::string> options)
    {
        this->id = id;
        this->color = color;
        this->options = options;
        this->title = title;

        ProcessOptions();
    }

    ~Menu()
    {
        this->id.clear();
        this->color.clear();
        this->title.clear();
        this->options.clear();
        this->processedOptions.clear();
    }

    void ProcessOptions();
    std::string GenerateItems(int page, int selected);

    std::string GetCommandFromOption(int page, int selected)
    {
        if (page < 1)
            return "";

        return processedOptions[page - 1][selected].second;
    }

    size_t GetItemsOnPage(int page)
    {
        if (page < 1)
            return 0;

        return processedOptions[page - 1].size();
    }
};

#endif