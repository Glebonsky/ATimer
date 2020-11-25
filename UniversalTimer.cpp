#include "UniversalTimer.h"

//returns millis from program start
unsigned long millisFromStart();

UniversalTimer::UniversalTimer(unsigned long interval)
    : _interval(interval)
{}

void UniversalTimer::start()
{
    _running = true;
    _lastTime = millisFromStart();
}

void UniversalTimer::setInterval(unsigned long interval)
{
    _interval = interval;
}

bool UniversalTimer::timeout()
{
    if (!_running) return false;

    auto currentTime = millisFromStart();
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


#include <Arduino.h>

unsigned long millisFromStart()
{
    return millis();
}