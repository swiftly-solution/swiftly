#include "../inc/TestComponent.h"
#include "../../../hooks/Hooks.h"

void TestComponent::LoadComponent()
{
    auto OnCommand = [](const OnClientCommand *e)
    {
        if (!g_SMAPI)
            return;

        PRINTF("TestComponent - Commands", "Slot %d: %s\n", e->slot->Get(), e->args->GetCommandString());
    };

    hooks::on<OnClientCommand>(OnCommand);
}