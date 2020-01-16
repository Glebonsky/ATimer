#include "GTimer.h"
#include <Arduino.h>
//#ifdef GTimerRealTime
//  #include <DS1307.h>
//#endif
  
GTimer::GTimer(bool realTimeModule)
{
  _period = 0;
  _lastTime = 0;
  _running = false;
//#ifdef GTimerRealTime
//#endif

}

void GTimer::start()
{
  // if (_running) return;
  
  _running = true;
  _lastTime = millis();
}

void GTimer::setPeriod(unsigned long period)
{
  _period = period;
}

bool GTimer::check()
{
  if (!_running) return false;

  if (millis() - _lastTime >= _period)
  {
  _lastTime = millis(); 
  return true;
  }

  return false;
}

void GTimer::stop()
{
  _running = false;
}
