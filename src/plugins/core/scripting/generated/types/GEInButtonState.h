#ifndef _geinbuttonstate_h
#define _geinbuttonstate_h

enum class EInButtonState : uint64_t
{
    IN_BUTTON_UP = 0x0,
    IN_BUTTON_DOWN = 0x1,
    IN_BUTTON_DOWN_UP = 0x2,
    IN_BUTTON_UP_DOWN = 0x3,
    IN_BUTTON_UP_DOWN_UP = 0x4,
    IN_BUTTON_DOWN_UP_DOWN = 0x5,
    IN_BUTTON_DOWN_UP_DOWN_UP = 0x6,
    IN_BUTTON_UP_DOWN_UP_DOWN = 0x7,
    IN_BUTTON_STATE_COUNT = 0x8,
};

#endif