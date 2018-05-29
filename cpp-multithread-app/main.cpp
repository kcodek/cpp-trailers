#include<iostream>
#include "randomnumgen/random_number_generator.h"
#include "callbacktimer/callback_timer.h"

#include<future>
#include<thread>

using std::cout;
using std::endl;


int main(){
    
    // auto handle = std::async(std::launch::async,single_random_num,1,100);
    while(1)
    {
        int interval = single_random_num(1,3);
        // std::cout<< interval<<" ";
        
        auto handle = std::async(std::launch::async,[interval](){
            
            std::this_thread::sleep_for(std::chrono::seconds(interval));
            return single_random_num(100,500);
        });

        std::cout<< handle.get()<<endl;;
    }
    
    return 0;
}