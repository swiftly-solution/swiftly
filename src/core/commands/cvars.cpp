#include "commands.h"

void SwiftlyConvarsManager(CPlayerSlot slot, int page)
{
    auto fakeConvars = FetchFakeConvars();

    PrintToClientOrConsole(slot, "Convars", "There are %d convars created by plugins.\n", fakeConvars.size());
    PrintToClientOrConsole(slot, "Convars", "Below will be shown a list of all the convars:\n");

    if (page < 1)
        page = 1;
    else if (static_cast<unsigned int>(page) * 10 > fakeConvars.size())
        page = int(ceil(double(fakeConvars.size()) / 10.0));

    auto it = fakeConvars.begin();
    for (int i = 0; i < (page - 1) * 10; i++)
        ++it;

    for (uint32 i = 0; i < 10; i++)
    {
        if (it == fakeConvars.end())
            break;
        PrintToClientOrConsole(slot, "Convars", "%s\n", it->first.c_str());
        ++it;
    }

    if (static_cast<unsigned int>(page) * 10 < fakeConvars.size())
        PrintToClientOrConsole(slot, "Convars", "To see more please use swiftly cvars %d\n", page + 1);
}