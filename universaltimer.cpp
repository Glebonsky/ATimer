#include "universaltimer.h"

//returns millis from fixed time point
unsigned long milliseconds();

UniversalTimer::UniversalTimer(unsigned long interval)
    : _interval(interval)
{}

void UniversalTimer::start()
{
    _running = true;
    _lastTime = milliseconds();
}

void UniversalTimer::setInterval(unsigned long interval)
{
    _interval = interval;
}

bool UniversalTimer::timeout()
{
    if (!_running) return false;

    auto currentTime = milliseconds();
    if (currentTime - _lastTime >= _interval)
    {
        _lastTime = currentTime; 
        return true;
    }

    return false;
}

void UniversalTimer::stop()
{
    _running = false;
}


#ifdef PC
#include <time.h>
unsigned long milliseconds()
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    time_t fiftyYearsInSecs = 1576800000;
    return (now.tv_sec - fiftyYearsInSecs) * 1000ul + now.tv_nsec / 1000000ul;
}


#else
#include <Arduino.h>

unsigned long milliseconds()
{
    return millis();
}
#endif
