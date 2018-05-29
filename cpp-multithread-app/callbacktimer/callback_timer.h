#include <iostream>
#include <thread>
using namespace std;


class CallBackTimer
{
public:
    CallBackTimer():_execute(false){}
    ~CallBackTimer();
    void stop();
    // void start(int interval, std::function<int(void)> func);

    void start_2(int interval, std::function<void(void)> func);
    void start(int interval, std::function< int(int,int) > func, int l, int u);
    bool is_running() const noexcept;

private:
    std::atomic<bool> _execute;
    std::thread _thd;
};

