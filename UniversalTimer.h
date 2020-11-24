#pragma once

class UniversalTimer
{
public:
    explicit UniversalTimer(unsigned long interval);
    void start();
    void setInterval(unsigned long interval);
    bool timeout();   
    void stop();

private:
    unsigned long _interval = 0;
    unsigned long _lastTime = 0;
    bool _running = false;
};
