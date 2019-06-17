#include "user.h"

// User::User(/* args */);
// {
//     cout<<"default ctor"<<endl;
// }

User::User(std::string name, std::string internal_id, uint8_t age, Gender gender, std::vector<std::string> hobbies, std::unordered_set <std::string> list_of_friends)
    : name_{name}, internal_id_{internal_id}, age_{age},gender_{gender}, hobbies_{hobbies}, list_of_friends_{list_of_friends}
{
    cout<<"User::ctor with parameters"<<endl;
}


User::~User()
{
    // cout<<"User::dtor"<<endl;
}