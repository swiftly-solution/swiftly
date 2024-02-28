#include "Menu.h"

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
                tempmap.push_back({"Next", "menunext"});
            if (pages != 0)
                tempmap.push_back({"Back", "menuback"});

            tempmap.push_back({"Exit", "menuexit"});

            processedItems = 0;
            pages++;
            this->processedOptions.push_back(tempmap);
            tempmap.clear();
        }
    }
    if (tempmap.size() > 0)
    {
        if (this->processedOptions.size() != 0)
            tempmap.push_back({"Back", "menuback"});

        tempmap.push_back({"Exit", "menuexit"});

        processedItems = 0;
        this->processedOptions.push_back(tempmap);
        tempmap.clear();
    }

    /*
    @note Debug Function

    PRINTF("ProcessOption", "Menu %s\n", this->id.c_str());
    for (uint32_t i = 0; i < this->processedOptions.size(); i++)
    {
        PRINTF("ProcessOption", "Page %d.\n", i + 1);
        for (uint32_t j = 0; j < this->processedOptions[i].size(); j++)
        {
            PRINTF("ProcessOption", "%d. Option: %s | Command: %s\n", j + 1, this->processedOptions[i][j].first.c_str(), this->processedOptions[i][j].second.c_str());
        }
    }
    */
}

std::string Menu::GenerateItems(int page, int selected)
{
    std::string retval = "";
    retval += string_format("&nbsp;&nbsp;<div><font color=\"#%s\">%s</font></div><br/>", this->color.c_str(), this->title.c_str());
    for (uint32_t i = 0; i < processedOptions[page - 1].size(); i++)
        retval += string_format("<div style=\"width: 768px;\"><font color=\"#%s\">%s%s</font></div><br/>", (i == selected ? this->color.c_str() : "ffffff"), (i == selected ? ">" : "&nbsp;&nbsp;"), processedOptions[page - 1][i].first.c_str());

    retval += "<div>SHIFT - Cycle | E - Select</div>";
    return retval;
}
