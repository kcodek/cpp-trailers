#include "netz.h"

Netz::Netz(/* args */)
{
}

Netz::~Netz()
{
}

vector<string> searchUserByName(const std::string user_name_)
{
    User user1("default");
    // vector<string> result_by_name = {user1.internal_id_};
    vector<string> result_by_name = {"user1.internal_id_"};

    return result_by_name;
    
} 
// const vector<string> searchUserByAge(const uint8_t user_age_); // returns user.internal_id_
//     // searchUserByHobbies({"Jogging", "Football", "Tennis"}); 
// const vector<string> searchUserByHobbies(const std::string user_hobbies); //comma separated string 
// const vector<string> getFriendsOfUser(const string user_id_ );