#include "Menu.h"

void Menu::ProcessOptions()
{
    int pages = 0;
    int processedItems = 0;
    int totalProcessedItems = 0;
    std::vector<std::pair<std::string, std::string>> tempmap;
    for (std::unordered_map<std::string, std::string>::iterator it = this->options.begin(); it != this->options.end(); ++it)
    {
        ++processedItems;
        ++totalProcessedItems;
        tempmap.push_back({it->first, it->second});
        if (processedItems == (pages == 0 ? 4 : 3))
        {
            if (pages == 0 || (totalProcessedItems < options.size()))
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
        if ((pages == 0 && totalProcessedItems > 4) || (totalProcessedItems < options.size()))
            tempmap.push_back({"Next", "menunext"});
        if (pages != 0)
            tempmap.push_back({"Back", "menuback"});

        tempmap.push_back({"Exit", "menuexit"});

        processedItems = 0;
        this->processedOptions.push_back(tempmap);
        tempmap.clear();
    }
}

std::string Menu::GenerateItems(int page, int selected)
{
    std::string retval = "";
    retval += string_format("&nbsp;&nbsp;<div><font color=\"#%s\">%s</font></div><br/>", this->color.c_str(), this->title.c_str());
    int pg = ((page - 1) > 0 ? 0 : (page - 1));
    for (uint32_t i = 0; i < processedOptions[pg].size(); i++)
        retval += string_format("<div style=\"width: 768px;\"><font color=\"#%s\">%s%s</font></div><br/>", (i == selected ? this->color.c_str() : "ffffff"), (i == selected ? ">" : "&nbsp;&nbsp;"), processedOptions[pg][i].first.c_str());

    retval += "<div>SHIFT - Cycle | E - Select</div>";
    return retval;
}
