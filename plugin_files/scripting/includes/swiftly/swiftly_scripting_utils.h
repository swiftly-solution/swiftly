#ifndef _swiftly_scripting_utils_h
#define _swiftly_scripting_utils_h

#include "swiftly_utils.h"
#include "playermanager.h"

#include <functional>
#include <thread>

int GetPlayerId(const char *str, bool matchbots = false);
void CreateThread(std::function<void()> fn);

#endif