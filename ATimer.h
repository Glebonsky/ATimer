class ATimer
{
  unsigned long _period;
  unsigned long _lastTime;
  bool _running;
  
public:
  ATimer(bool realTimeModule = false);
  void start();
  void setPeriod(unsigned long period);
  bool check();   
  void stop();
};
