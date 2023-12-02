#ifndef _swiftly_timers_h
#define _swiftly_timers_h

#include "swiftly_utils.h"
#include <string>
#include <thread>
#include <functional>
#include <chrono>
#include <map>

class Timer;
std::map<uint64_t, Timer *> m_timers;

class Timer
{
private:
    std::function<void()> m_function;
    uint64_t m_delay;
    uint64_t m_lastExecuted = 0;
    bool m_paused = false;
    bool m_destroyed = false;

public:
    Timer(std::function<void()> function, uint64_t delay) : m_function(function), m_delay(delay) {}

    bool ShouldExecute(uint64_t time)
    {
        if (this->m_paused)
            return false;

        return ((time - this->m_lastExecuted) > this->m_delay);
    }

    void SetPaused(bool paused)
    {
        this->m_paused = paused;
    }

    void Execute()
    {
        this->m_function();
        this->m_lastExecuted = GetTime();
    }

    void Destroy()
    {
        this->m_destroyed = true;
    }

    bool IsDestroyed() { return this->m_destroyed; }
    uint64_t GetDelay() { return this->m_delay; }
};

void ThreadFunction()
{
    uint64_t time = GetTime();

    for (auto it = m_timers.begin(); it != m_timers.end(); ++it)
    {
        if (it->second->IsDestroyed())
            continue;

        if (it->second->ShouldExecute(time))
            it->second->Execute();
    }
}

class Timers
{
private:
    uint64_t timerID = 0;

public:
    Timers(){};

    uint64_t RegisterTimer(uint64_t delay, const std::function<void()> &fn)
    {
        Timer *timer = new Timer(fn, delay);
        ++this->timerID;
        m_timers.insert(std::make_pair(this->timerID, timer));
        return this->timerID;
    }

    void PauseTimer(uint64_t timerID)
    {
        if (m_timers.find(timerID) == m_timers.end())
            return;

        Timer *timer = m_timers.at(timerID);
        timer->SetPaused(true);
    }

    void UnpauseTimer(uint64_t timerID)
    {
        if (m_timers.find(timerID) == m_timers.end())
            return;

        Timer *timer = m_timers.at(timerID);
        timer->SetPaused(false);
    }

    void DestroyTimer(uint64_t timerID)
    {
        if (m_timers.find(timerID) == m_timers.end())
            return;

        Timer *timer = m_timers.at(timerID);
        timer->SetPaused(true);
        timer->Destroy();
        delete timer;

        m_timers.erase(timerID);
    }
};

extern Timers *timers;

#endif