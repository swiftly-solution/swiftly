#pragma once
#include "platform.h"
#include "../utils.h"

#define CALL_VIRTUAL(retType, idx, ...) CallVFunc<retType>(idx, __VA_ARGS__)