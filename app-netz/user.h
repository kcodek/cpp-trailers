#ifndef USER
#define USER

#include<iostream>
#include<string>
#include<forward_list>

using std::ostream;
using std::string;
using std::forward_list;


enum class Gender{
    kRatherNotSay, 
    kMale,
    kFemale,
    kOthers    
};

class user
{
private:
    /* data */
    string name_; 
    uint age_;
    int internal_id_; //unique id
    Gender gender_;
    forward_list<string> hobbies_;
    //<list of friends>
    

public:
    user(/* args */) = delete;
    user(string name, uint age=0, Gender gender_ = Gender::kRatherNotSay, int internal_id_=0, forward_list<string> hobbies_={0});
    ~user();    
    void setInternalId(int uid);
    friend ostream& operator<<(ostream& os,const user&);
};

#endif