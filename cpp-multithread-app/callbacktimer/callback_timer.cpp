#include "callback_timer.h"


CallBackTimer::~CallBackTimer() 
{
    if( _execute.load(std::memory_order_acquire) ) //atomically obtains the value of the atomic object 
    {
        stop();
    };
}

void CallBackTimer::stop(){
        _execute.store(false, std::memory_order_release);
        if( _thd.joinable() )
            _thd.join();
}


void CallBackTimer::start_2(int interval, std::function<void(void)> func)
{
    if( _execute.load(std::memory_order_acquire) ) {
        stop();
    };
    _execute.store(true, std::memory_order_release);
    _thd = std::thread([this, interval, func]()
    {
        while (_execute.load(std::memory_order_acquire)) {
            func();                   
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
    });
}


void CallBackTimer::start(int interval, std::function< int(int,int) > func,int l,int u)
{
    if( _execute.load(std::memory_order_acquire) ) {
        stop();
    };
    _execute.store(true, std::memory_order_release);
    int l1 = l;
    int u1 = u;

    _thd = std::thread([this, interval, func,l1,u1 ]()
    {
        while (_execute.load(std::memory_order_acquire)) {
            func(l1,u1);                   
            std::this_thread::sleep_for(
            std::chrono::milliseconds(interval));
        }
    });
}

bool CallBackTimer::is_running() const noexcept {
        return ( _execute.load(std::memory_order_acquire) && 
                 _thd.joinable() );
    }

/*

typedef enum memory_order {
    memory_order_relaxed,
    memory_order_consume,
    memory_order_acquire,
    memory_order_release,
    memory_order_acq_rel,
    memory_order_seq_cst
} memory_order;

memory_order_release: A store operation with this memory order performs the release operation: 
no reads or writes in the current thread can be reordered after this store. 
All writes in the current thread are visible in other threads that acquire the same atomic variable 
(see Release-Acquire ordering below) and writes that carry a dependency into the atomic variable become visible in other threads that consume the same atomic (see Release-Consume ordering below).

memory_order_acquire: A load operation with this memory order performs the acquire operation on the affected memory location: 
no reads or writes in the current thread can be reordered before this load. 
All writes in other threads that release the same atomic variable are visible in the current thread 
(see Release-Acquire ordering below)

*/