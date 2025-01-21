#pragma once

#include <string>
#include <map>
#include <vector>
#include <public/Color.h>
#include "../translations/Translations.h"

class Menu
{
public:
    virtual std::string GetID() = 0;
    virtual void ProcessOptions() = 0;
    virtual std::string GeneratedItems(int playerid, int page) = 0;
    virtual std::string GenerateFooter(int page) = 0;
    virtual void RegeneratePage(int playerid, int page, int selected) = 0;

    virtual std::string GetCommandFromOption(int page, int selected) = 0;
    virtual size_t GetItemsOnPage(int page) = 0;
    virtual bool IsTemporary() = 0;

    virtual Color GetColor() = 0;
    virtual bool RenderEachTick() = 0;
    virtual std::string GetKind() = 0;
};