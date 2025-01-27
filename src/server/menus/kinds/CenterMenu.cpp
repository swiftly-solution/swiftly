#include "CenterMenu.h"

#include "../../../utils/utils.h"
#include "../../../server/configuration/Configuration.h"

#include <regex>

CenterMenu::CenterMenu(std::string id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options, bool tmp)
{
    this->id = id;
    this->color = color;
    this->options = options;
    this->title = title;
    this->temporary = tmp;

    fprintf(stdout, "Begin center\n");
    ProcessOptions();
    fprintf(stdout, "End center\n");
}

CenterMenu::~CenterMenu()
{
    this->id.clear();
    this->title.clear();
    this->color.clear();
    this->options.clear();
    this->processedOptions.clear();
}

std::string CenterMenu::GetID()
{
    return this->id;
}

std::string CenterMenu::GetCommandFromOption(int page, int selected)
{
    if (page < 1)
        return "";

    return processedOptions[page - 1][selected].second;
}

size_t CenterMenu::GetItemsOnPage(int page)
{
    if (page < 1)
        return 0;

    return processedOptions[page - 1].size();
}

void CenterMenu::ProcessOptions()
{
    int pages = 0;
    int processedItems = 0;
    int totalProcessedItems = 0;
    std::vector<std::pair<std::string, std::string>> tempmap;

    int reservedItems = g_Config->FetchValue<bool>("core.menu.buttons.exit.option") ? 3 : 2;
    int allowedItems = g_Config->FetchValue<int>("core.menu.kind_settings.center.itemsPerPage") - reservedItems;

    for (const std::pair<std::string, std::string> entry : this->options)
    {
        ++processedItems;
        ++totalProcessedItems;
        tempmap.push_back({entry.first, entry.second});
        if (processedItems == allowedItems)
        {
            if (options.size() - totalProcessedItems > 0) tempmap.push_back({g_translations->FetchTranslation("core.menu.next"), "menunext"});
            if (pages != 0) tempmap.push_back({g_translations->FetchTranslation("core.menu.back"), "menuback"});
            if (reservedItems == 3) tempmap.push_back({g_translations->FetchTranslation("core.menu.exit"), "menuexit"});

            processedItems = 0;
            pages++;
            this->processedOptions.push_back(tempmap);
            tempmap.clear();
        }
    }

    if (tempmap.size() > 0)
    {
        if (this->processedOptions.size() != 0) tempmap.push_back({g_translations->FetchTranslation("core.menu.back"), "menuback"});
        if (reservedItems == 3) tempmap.push_back({g_translations->FetchTranslation("core.menu.exit"), "menuexit"});

        processedItems = 0;
        this->processedOptions.push_back(tempmap);
        tempmap.clear();
    }
}

std::string CenterMenu::GeneratedItems(int playerid, int page)
{
    return this->generatedPages[playerid][page - 1];
}

void CenterMenu::RegeneratePage(int playerid, int page, int selected)
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
    std::string footer = replace(g_translations->FetchTranslation(g_Config->FetchValue<bool>("core.menu.buttons.exit.option") ? "core.menu.center.footer" : "core.menu.center.footer.nooption"), "{PAGE}", std::to_string(page));
    footer = replace(footer, "{MAXPAGES}", std::to_string(processedOptions.size()));
    footer = replace(footer, "{CYCLE_BUTTON}", str_toupper(g_Config->FetchValue<std::string>("core.menu.buttons.scroll")));
    footer = replace(footer, "{USE_BUTTON}", str_toupper(g_Config->FetchValue<std::string>("core.menu.buttons.use")));
    footer = replace(footer, "{EXIT_BUTTON}", str_toupper(g_Config->FetchValue<std::string>("core.menu.buttons.exit.button")));

    stringPage += string_format("<font class='fontSize-s'>%s</font>", footer.c_str());

    this->generatedPages[playerid][page - 1] = stringPage;
}

bool CenterMenu::IsTemporary()
{
    return this->temporary;
}

Color CenterMenu::GetColor()
{
    return Color(0,0,0);
}

std::string CenterMenu::GenerateFooter(int page)
{
    return "";
}

bool CenterMenu::RenderEachTick()
{
    return true;
}

std::string CenterMenu::GetKind()
{
    return "center";
}