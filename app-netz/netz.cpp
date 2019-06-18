#include "netz.h"



int GetRandom(int max){
    srand(time(NULL));
    return rand() % max;
}


netz::netz(/* args */)
{
}

netz::~netz()
{
}

void netz::add_user(user& u1){ 
    int uniqueid = GetRandom(100); // the max no.of users is 100
    u1.setInternalId(uniqueid);
    this->userCollection.insert(std::pair <int, user> (uniqueid,u1));
}

