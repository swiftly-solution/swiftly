#include "../inc/TestComponent.h"
#include "../../../hooks/Hooks.h"

void TestComponent::LoadComponent()
{
    auto OnClientConnect = [](const OnClientConnected *e)
    {
        if (!g_SMAPI)
            return;

        PRINTF("TestComponent - Welcome", "%s (Slot %d) joined the server.\n", e->pszName, e->slot->Get());
    };

    auto OnCommand = [](const OnClientCommand *e)
    {
        if (!g_SMAPI)
            return;

        PRINTF("TestComponent - Commands", "Slot %d: %s\n", e->slot->Get(), e->args->GetCommandString());
    };

    hooks::on<OnClientConnected>(OnClientConnect);
    hooks::on<OnClientCommand>(OnCommand);
}