#include "Menu.h"

#include "../../utils/utils.h"
#include "../../server/configuration/Configuration.h"

#include <regex>

Menu::Menu(std::string id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options, bool tmp)
{
    int r=255,g=255,b=255,a=255;
    try {
        r = std::stoi(color.substr(0,2), nullptr, 16);
    } catch(std::exception& e) {}

    try {
        g = std::stoi(color.substr(2,2), nullptr, 16);
    } catch(std::exception& e) {}

    try {
        b = std::stoi(color.substr(4,2), nullptr, 16);
    } catch(std::exception& e) {}

    if(color.length() >= 8) {
        try {
            a = std::stoi(color.substr(6,2), nullptr, 16);
        } catch(std::exception& e) {}
    }

    this->id = id;
    this->color.SetColor(r,g,b,a);
    this->options = options;
    this->title = title;
    this->temporary = tmp;

    ProcessOptions();
}

Menu::~Menu()
{
    this->id.clear();
    this->title.clear();
    this->options.clear();
    this->processedOptions.clear();
}

std::string Menu::GetID()
{
    return this->id;
}

std::string Menu::GetCommandFromOption(int page, int selected)
{
    if (page < 1)
        return "";

    return processedOptions[page - 1][selected].second;
}

size_t Menu::GetItemsOnPage(int page)
{
    if (page < 1)
        return 0;

    return processedOptions[page - 1].size();
}

std::string stringWithSplit(std::string text, int maxCharsPerRow) {
    std::vector<std::string> result;

    int start = 0;
    while(start < text.length()) {
        int remaining = text.length() - start;
        int count = (remaining > maxCharsPerRow) ? maxCharsPerRow : remaining;

        std::string row = text.substr(start, count);
        if(remaining > maxCharsPerRow) row += "...";

        result.push_back(row);
        start += count;
    }

    return implode(result, "\n ");
}

std::string RemoveHtmlTags(std::string input) {
    std::regex pattern("<(/?)(div|font)[^>]*>");

    return std::regex_replace(input, pattern, "");
}

void Menu::ProcessOptions()
{
    int pages = 0;
    int processedItems = 0;
    int totalProcessedItems = 0;
    std::vector<std::pair<std::string, std::string>> tempmap;

    int maxProcessedItems = (g_Config->FetchValue<bool>("core.menu.buttons.exit.option") ? (pages == 0 ? 8 : 7) : (pages == 0 ? 9 : 8));
    for (const std::pair<std::string, std::string> entry : this->options)
    {
        ++processedItems;
        ++totalProcessedItems;
        tempmap.push_back({stringWithSplit(RemoveHtmlTags(entry.first), 30), entry.second});
        if (processedItems == maxProcessedItems)
        {
            if (options.size() - totalProcessedItems > 0)
                tempmap.push_back({stringWithSplit(RemoveHtmlTags(g_translations->FetchTranslation("core.menu.next")), 30), "menunext"});
            if (pages != 0)
                tempmap.push_back({stringWithSplit(RemoveHtmlTags(g_translations->FetchTranslation("core.menu.back")), 30), "menuback"});

            if (g_Config->FetchValue<bool>("core.menu.buttons.exit.option"))
                tempmap.push_back({stringWithSplit(RemoveHtmlTags(g_translations->FetchTranslation("core.menu.exit")), 30), "menuexit"});

            processedItems = 0;
            pages++;
            this->processedOptions.push_back(tempmap);
            tempmap.clear();
        }
    }

    if (tempmap.size() > 0)
    {
        if (this->processedOptions.size() != 0)
            tempmap.push_back({g_translations->FetchTranslation("core.menu.back"), "menuback"});

        if (g_Config->FetchValue<bool>("core.menu.buttons.exit.option"))
            tempmap.push_back({g_translations->FetchTranslation("core.menu.exit"), "menuexit"});

        processedItems = 0;
        this->processedOptions.push_back(tempmap);
        tempmap.clear();
    }
}

std::string Menu::GeneratedItems(int playerid, int page)
{
    return this->generatedPages[playerid][page - 1];
}

void Menu::RegeneratePage(int playerid, int page, int selected)
{
    if (this->generatedPages.find(playerid) == this->generatedPages.end())
        this->generatedPages.insert({playerid, {}});

    while (this->generatedPages[playerid].size() < page)
    {
        this->generatedPages[playerid].push_back("");
    }

    std::string stringPage = string_format("%s\n", this->title.c_str());
    for (int i = 0; i < processedOptions[page - 1].size(); i++) {
        stringPage += string_format("\n%s%s", (i == selected ? (g_Config->FetchValue<std::string>("core.menu.navigation_prefix")).c_str() : " "), processedOptions[page - 1][i].first.c_str());
    }

    this->generatedPages[playerid][page - 1] = stringPage;
}

bool Menu::IsTemporary()
{
    return this->temporary;
}

Color Menu::GetColor()
{
    return this->color;
}

std::string Menu::GenerateFooter(int page)
{
    std::string footer = replace(g_translations->FetchTranslation(g_Config->FetchValue<bool>("core.menu.buttons.exit.option") ? "core.menu.footer" : "core.menu.footer.nooption"), "{PAGE}", std::to_string(page));
    footer = replace(footer, "{MAXPAGES}", std::to_string(processedOptions.size()));
    footer = replace(footer, "{CYCLE_BUTTON}", str_toupper(g_Config->FetchValue<std::string>("core.menu.buttons.scroll")));
    footer = replace(footer, "{USE_BUTTON}", str_toupper(g_Config->FetchValue<std::string>("core.menu.buttons.use")));
    footer = replace(footer, "{EXIT_BUTTON}", str_toupper(g_Config->FetchValue<std::string>("core.menu.buttons.exit.button")));
    return footer;
}