#ifndef _swiftly_timers_h
#define _swiftly_timers_h

#include "swiftly_utils.h"
#include <string>
#include <thread>
#include <functional>
#include <chrono>

class Timer;

void ThreadFunction(Timer *timer);

class Timer
{
private:
    std::function<void()> m_function;
    uint64_t m_delay;
    uint64_t m_lastExecuted = 0;
    bool m_paused = false;
    bool m_destroyed = false;

public:
    Timer(std::function<void()> function, uint64_t delay) : m_function(function), m_delay(delay)
    {
        std::thread th(ThreadFunction, this);

        th.detach();
    }

    bool ShouldExecute()
    {
        if (this->m_paused)
            return false;

        return ((GetTime() - this->m_lastExecuted) > this->m_delay);
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

class Timers
{
private:
    uint64_t timerID = 0;
    std::map<uint64_t, Timer *> timers;

public:
    Timers(){};

    uint64_t RegisterTimer(uint64_t delay, const std::function<void()> &fn)
    {
        Timer *timer = new Timer(fn, delay);
        ++this->timerID;
        timers.insert(std::make_pair(this->timerID, timer));
        return this->timerID;
    }

    void PauseTimer(uint64_t timerID)
    {
        if (this->timers.find(timerID) == this->timers.end())
            return;

        Timer *timer = this->timers.at(timerID);
        timer->SetPaused(true);
    }

    void UnpauseTimer(uint64_t timerID)
    {
        if (this->timers.find(timerID) == this->timers.end())
            return;

        Timer *timer = this->timers.at(timerID);
        timer->SetPaused(false);
    }

    void DestroyTimer(uint64_t timerID)
    {
        if (this->timers.find(timerID) == this->timers.end())
            return;

        Timer *timer = this->timers.at(timerID);
        timer->SetPaused(true);
        timer->Destroy();
        delete timer;

        this->timers.erase(timerID);
    }
};

void ThreadFunction(Timer *timer)
{
    for (;;)
    {
        if (timer->IsDestroyed())
            break;

        if (timer->ShouldExecute())
            timer->Execute();

        // For Windows time needs to be halfed because sleep is dependent on System Clock Time.
        // Sometimes Windows randomly updates the System Clock Time and the wait time is irregular.
        std::this_thread::sleep_for(std::chrono::milliseconds(timer->GetDelay() / WIN_LINUX(2, 1)));
    }
}

extern Timers *timers;

#endif