class GTimer
{
  unsigned long _period;
  unsigned long _lastTime;
  bool _running;
  
public:
  GTimer(bool realTimeModule = false);
  void start();
  void setPeriod(unsigned long period);
  bool check();   
  void stop();
};
