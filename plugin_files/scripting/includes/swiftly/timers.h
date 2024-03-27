#ifndef _swiftly_timers_h
#define _swiftly_timers_h

#include "swiftly_utils.h"
#include <string>
#include <thread>
#include <functional>
#include <chrono>
#include <map>

class Timer
{
private:
    std::function<void()> m_function;
    uint64_t m_delay;
    uint64_t m_lastExecuted = 0;
    bool m_destroyed = false;

public:
    Timer(std::function<void()> function, uint64_t delay) : m_function(function), m_delay(delay) {}

    bool ShouldExecute(uint64_t time);
    void Execute();
    void Destroy();

    bool IsDestroyed() { return this->m_destroyed; }
    uint64_t GetDelay() { return this->m_delay; }
};

void ThreadFunction();

class Timers
{
private:
    uint64_t timerID = 0;

public:
    Timers(){};

    uint64_t RegisterTimer(uint64_t delay, const std::function<void()> &fn);
    void DestroyTimer(uint64_t timerID);
};

extern Timers *timers;

#endif