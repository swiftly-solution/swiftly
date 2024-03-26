#include "timers.h"

std::map<uint64_t, Timer *> m_timers;

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

bool Timer::ShouldExecute(uint64_t time)
{
    return ((time - this->m_lastExecuted) > this->m_delay);
}

void Timer::Execute()
{
    this->m_function();
    this->m_lastExecuted = GetTime();
}

void Timer::Destroy()
{
    this->m_destroyed = true;
}

uint64_t Timers::RegisterTimer(uint64_t delay, const std::function<void()> &fn)
{
    Timer *timer = new Timer(fn, delay);
    ++this->timerID;
    m_timers.insert(std::make_pair(this->timerID, timer));
    return this->timerID;
}

void Timers::DestroyTimer(uint64_t timerID)
{
    if (m_timers.find(timerID) == m_timers.end())
        return;

    Timer *timer = m_timers.at(timerID);
    timer->Destroy();
    delete timer;

    m_timers.erase(timerID);
}