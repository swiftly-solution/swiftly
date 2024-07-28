#include "Menu.h"

#include "../utils/utils.h"

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

// TODO: Translation for Next, Back, Exit (Maybe a file called Generic for generic translations?)
void Menu::ProcessOptions()
{
    int pages = 0;
    int processedItems = 0;
    int totalProcessedItems = 0;
    std::vector<std::pair<std::string, std::string>> tempmap;

    for (const std::pair<std::string, std::string> entry : this->options)
    {
        ++processedItems;
        ++totalProcessedItems;
        tempmap.push_back({entry.first, entry.second});
        if (processedItems == (pages == 0 ? 4 : 3))
        {
            if (options.size() - totalProcessedItems > 0)
                tempmap.push_back({g_translations->FetchTranslation("core.menu.next"), "menunext"});
            if (pages != 0)
                tempmap.push_back({g_translations->FetchTranslation("core.menu.back"), "menuback"});

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

        tempmap.push_back({g_translations->FetchTranslation("core.menu.exit"), "menuexit"});

        processedItems = 0;
        this->processedOptions.push_back(tempmap);
        tempmap.clear();
    }
}

std::string Menu::GeneratedItems(int page)
{
    return this->generatedPages[page - 1];
}

void Menu::RegeneratePage(int page, int selected)
{
    while (this->generatedPages.size() < page)
    {
        this->generatedPages.push_back("");
    }

    std::string stringPage = string_format("<div><font color=\"#%s\">&nbsp;&nbsp;&nbsp;%s</font></div><br/>", this->color.c_str(), this->title.c_str());
    for (int i = 0; i < processedOptions[page - 1].size(); i++)
        stringPage += string_format("<div><font color=\"#%s\">%s%s</font></div><br/>", (i == selected ? this->color.c_str() : "ffffff"), (i == selected ? "➤&nbsp;" : "&nbsp;&nbsp;&nbsp;&nbsp;"), processedOptions[page - 1][i].first.c_str());

    stringPage += string_format("<font class='fontSize-s'>%s</font>", replace(replace(g_translations->FetchTranslation("core.menu.footer"), "{PAGE}", std::to_string(page)), "{MAXPAGES}", std::to_string(processedOptions.size())).c_str());

    this->generatedPages[page - 1] = stringPage;
}

bool Menu::IsTemporary()
{
    return this->temporary;
}