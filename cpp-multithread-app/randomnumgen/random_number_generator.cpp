#include "random_number_generator.h"
int random_num_gen(int lower_limit=1,int upper_limit=6, int random_num_count=20)
{
    std::srand(std::time(nullptr)); // use current time as seed for random generator
   
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: "  << random_variable << '\n';
 
    // roll a 6-sided die 20 times
    for (int n=0; n != random_num_count; ++n) {
        int x = upper_limit+1;
        while(x > upper_limit) 
            x = lower_limit + std::rand()/((RAND_MAX + 1u)/upper_limit);  // Note: 1+rand()%6 is biased
        std::cout << x << ' ';
    }
    return 0;
}


int single_random_num(int lower_limit=1,int upper_limit=100)
{
    std::srand(std::time(nullptr)); // use current time as seed for random generator
   
    std::rand();// without this gives the same random number always???

    int x = lower_limit + std::rand()/((RAND_MAX + 1u)/upper_limit);  // Note: 1+rand()%6 is biased

    return x;
}


//ToDo : int frequency in msec or random as argument


// class  RandomNumberGenerator{

// };