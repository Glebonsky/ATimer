#include "UniversalTimer.h"
#include <Arduino.h>
//#ifdef GTimerRealTime
//  #include <DS1307.h>
//#endif
  
ATimer::ATimer(bool realTimeModule)
{
  _period = 0;
  _lastTime = 0;
  _running = false;
//#ifdef GTimerRealTime
//#endif

}

void ATimer::start()
{
  // if (_running) return;
  
  _running = true;
  _lastTime = millis();
}

void ATimer::setPeriod(unsigned long period)
{
  _period = period;
}

bool ATimer::check()
{
  if (!_running) return false;

  if (millis() - _lastTime >= _period)
  {
  _lastTime = millis(); 
  return true;
  }

  return false;
}

void ATimer::stop()
{
  _running = false;
}
