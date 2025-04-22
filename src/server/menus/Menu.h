#ifndef _server_menus_menu_h
#define _server_menus_menu_h

#include <string>
#include <map>
#include <vector>
#include <public/Color.h>
#include <server/translations/translations.h>
#include <server/commands/manager.h>

class Menu
{
public:
    virtual std::string GetID() = 0;
    virtual void ProcessOptions() = 0;
    virtual std::string GeneratedItems(int playerid, int page) = 0;
    virtual std::string GenerateFooter(int page) = 0;
    virtual void RegeneratePage(int playerid, int page, int selected) = 0;

    virtual std::string GetCommandFromOption(int page, int selected) = 0;
    virtual int GetItemsOnPage(int page) = 0;
    virtual bool IsTemporary() = 0;

    virtual Color GetColor() = 0;
    virtual bool RenderEachTick() = 0;
    virtual std::string GetKind() = 0;
};

#endif