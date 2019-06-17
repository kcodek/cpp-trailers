#include "user.h"
#include<unordered_set>
#include<vector>

using std::string;
using std::vector;

// bool Compartor(const User &lhs, const User& rhs)
// {
//     return lhs.internal_id_ == rhs.internal_id_;
// }

class Netz
{
private:
    /* data */
    std::unordered_set<User,Compartor> user_base;

public:
    Netz(/* args */);
    ~Netz();
    void addUser();
    void deleteUser();
    vector<string> searchUserByName(const std::string user_name_); // returns user.internal_id_
    // vector<string> searchUserByAge(const uint8_t user_age_); // returns user.internal_id_
    // // searchUserByHobbies({"Jogging", "Football", "Tennis"}); 
    // vector<string> searchUserByHobbies(const std::string user_hobbies); //comma separated string 
    // vector<string> getFriendsOfUser(const string user_id_ );
};
