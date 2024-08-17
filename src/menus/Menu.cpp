#include "Menu.h"

#include "../utils/utils.h"
#include "../configuration/Configuration.h"

Menu::Menu(std::string id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options, bool tmp)
{
    this->id = id;
    this->color = color;
    this->options = options;
    this->title = title;
    this->temporary = tmp;

    ProcessOptions();
}

Menu::~Menu()
{
    this->id.clear();
    this->color.clear();
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

void Menu::ProcessOptions()
{
    int pages = 0;
    int processedItems = 0;
    int totalProcessedItems = 0;
    std::vector<std::pair<std::string, std::string>> tempmap;

    int maxProcessedItems = (g_Config->FetchValue<bool>("core.menu.buttons.exit.option") ? (pages == 0 ? 4 : 3) : (pages == 0 ? 5 : 4));
    for (const std::pair<std::string, std::string> entry : this->options)
    {
        ++processedItems;
        ++totalProcessedItems;
        tempmap.push_back({entry.first, entry.second});
        if (processedItems == maxProcessedItems)
        {
            if (options.size() - totalProcessedItems > 0)
                tempmap.push_back({g_translations->FetchTranslation("core.menu.next"), "menunext"});
            if (pages != 0)
                tempmap.push_back({g_translations->FetchTranslation("core.menu.back"), "menuback"});

            if (g_Config->FetchValue<bool>("core.menu.buttons.exit.option"))
                tempmap.push_back({g_translations->FetchTranslation("core.menu.exit"), "menuexit"});

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

    std::string stringPage = string_format("<div><font color=\"#%s\">&nbsp;&nbsp;&nbsp;%s</font></div><br/>", this->color.c_str(), this->title.c_str());
    for (int i = 0; i < processedOptions[page - 1].size(); i++)
        stringPage += string_format("<div><font color=\"#%s\">%s%s</font></div><br/>", (i == selected ? this->color.c_str() : "ffffff"), (i == selected ? (g_Config->FetchValue<std::string>("core.menu.navigation_prefix") + "&nbsp;").c_str() : "&nbsp;&nbsp;&nbsp;&nbsp;"), processedOptions[page - 1][i].first.c_str());
    std::string footer = replace(g_translations->FetchTranslation(g_Config->FetchValue<bool>("core.menu.buttons.exit.option") ? "core.menu.footer" : "core.menu.footer.nooption"), "{PAGE}", std::to_string(page));
    footer = replace(footer, "{MAXPAGES}", std::to_string(processedOptions.size()));
    footer = replace(footer, "{CYCLE_BUTTON}", str_toupper(g_Config->FetchValue<std::string>("core.menu.buttons.scroll")));
    footer = replace(footer, "{USE_BUTTON}", str_toupper(g_Config->FetchValue<std::string>("core.menu.buttons.use")));
    footer = replace(footer, "{EXIT_BUTTON}", str_toupper(g_Config->FetchValue<std::string>("core.menu.buttons.exit.button")));

    stringPage += string_format("<font class='fontSize-s'>%s</font>", footer.c_str());

    this->generatedPages[playerid][page - 1] = stringPage;
}

bool Menu::IsTemporary()
{
    return this->temporary;
}