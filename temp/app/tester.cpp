#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>


using std::cout;
using std::vector;
using std::unordered_multimap;
using std::unordered_set;

class User;
class MyHashFunction;

class Netz
{
private:
    /* data */
    // unordered_set<User> list_of_Users_;
    unordered_set<User, MyHashFunction  > list_of_users_;
    unordered_multimap<std::string,std::string> buddy_multi_map_;

public:
    Netz(/* args */);
    ~Netz();
    void add_user(User &);
    void remove_user(User &);
};

Netz::Netz(/* args */)
{
    cout<<"Netz ctor\n";
}

Netz::~Netz()
{
}

void Netz::add_user(User& u){
    //insert the User in the list_of_Users_    
    this->list_of_users_.insert(u);
    // cout<<"inserted user"<< u.get_name();
    //update the buddy_list_
}

void Netz::remove_user(User& C){
    //remove the User from the list_of_Users_
    //update the buddy_list_
}

//########################################################//
enum class enumGender{
    kMale,
    kFemale,
    kOthers
};


class MyHashFunction
{
public:
    // We use predfined hash functions of strings 
    // and define our hash function as XOR of the 
    // hash values. 
    size_t operator()(const std::string & unique_id) const
    { 
        std::hash<std::string> hash_func;
        return hash_func(unique_id); 
    } 


};

//########################################################//
class User
{
private:
    /* data */
    std::string name_;
    std::string unique_id_;
    uint age_;
    enumGender gender_;
    vector<std::string> hobbies_; 
    vector<std::string> buddy_list_;
public:
    User(/* args */)= delete;
    User(std::string& name,std::string unique_id, uint age, enumGender gender, vector<std::string> hobbies,vector<std::string> buddy_list)
        :  name_{name},unique_id_(unique_id),age_(age),gender_(gender),hobbies_{hobbies},buddy_list_{buddy_list}{};
        // :  name_{std::move(name)},unique_id_(std::move(unique_id)),age_(std::move(age)),gender_(std::move(gender)),hobbies_{std::move(hobbies)},buddy_list_{std::move(buddy_list)}{};


    //for inserting into unordered_set
    bool operator==(const User& other) const{
        return (unique_id_ == other.unique_id_) ;
    }

    

    // const std::string& get_name const (){
    //     return name_;
    // };
    ~User();
};

// User::User(/* args */)
// {
// }

User::~User()
{   
}

// const std::string& User::get_name const()
// {
    
// }
int main()
{

    // Netz n1;

    //dummy values
    std::string user_name{"lucky1"};
    std::string user_unique_id{"0000"};
    uint user_age{32};
    std::vector<std::string> user_hobbies{""};
    std::vector<std::string> user_buddy_list{""};


    //
    User u1{user_name,user_unique_id,user_age,enumGender::kMale,user_hobbies,user_buddy_list};

    return 0;
}