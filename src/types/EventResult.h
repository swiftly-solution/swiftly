#pragma once

enum class EventResult
{
    // Continues to process the event until the end
    Continue = 0,
    // Stops processing the event and stops calling the code following by it.
    Stop = 1,
    // Stops processing the event but calls the code followed by it.
    Handled = 2,
};