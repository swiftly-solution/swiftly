#include "../inc/TestComponent.h"
#include "../../../hooks/Hooks.h"

void TestComponent::LoadComponent()
{
    auto OnClientConnect = [](const OnClientConnectedEvent *e)
    {
        if (!g_SMAPI)
            return;

        g_SMAPI->ConPrintf("%s (Slot %d) joined the server", e->pszName, e->slot->Get());
    };

    auto OnCommand = [](const OnClientCommand *e)
    {
        if (!g_SMAPI)
            return;

        g_SMAPI->ConPrintf("Slot %d: %s", e->slot->Get(), e->args->GetCommandString());
    };

    hooks::on<OnClientConnectedEvent>(OnClientConnect);
    hooks::on<OnClientCommand>(OnCommand);
}