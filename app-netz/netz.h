#ifndef NETZ
#define NETZ

#include "user.h"
#include<unordered_map>
#include<ctime>

using std::unordered_map;

/**
 * Util Functions
*/

int GetRandom(int max); // ToDo: use a UUID generator


class netz
{
private:
    /* data */
    unordered_map<int,user> userCollection;

public:
    netz(/* args */);
    ~netz();

    void add_user(user& u1);
    void remove_user(user& u1);

};

# endif