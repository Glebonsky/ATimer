#pragma once

class UniversalTimer
{
public:
    explicit UniversalTimer(unsigned long interval);
    void start();
    void setPeriod(unsigned long interval);
    bool check();   
    void stop();

private:
    unsigned long _interval = 0;
    unsigned long _lastTime = 0;
    bool _running = false;
};