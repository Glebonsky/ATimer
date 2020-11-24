#include "UniversalTimer.h"

//returns millis from program start
unsigned long millis();

UniversalTimer::UniversalTimer(unsigned long interval)
    : _interval(interval)
{}

void UniversalTimer::start()
{
    _running = true;
    _lastTime = millis();
}

void UniversalTimer::setPeriod(unsigned long interval)
{
    _interval = interval;
}

bool UniversalTimer::check()
{
    if (!_running) return false;

    if (millis() - _lastTime >= _interval)
    {
        _lastTime = millis(); 
        return true;
    }

    return false;
}

void UniversalTimer::stop()
{
    _running = false;
}


#include <Arduino.h>