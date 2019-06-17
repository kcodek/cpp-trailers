#ifndef NETZ
#define NETZ

#include "user.h"
#include<unordered_set>


using std::unordered_set;

class netz
{
private:
    /* data */
    // unordered_set<user> userCollection;

public:
    netz(/* args */);
    ~netz();

    void add_user(user& u1);
    void remove_user(user& u1);

};

# endif