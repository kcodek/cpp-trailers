#ifndef USER
#define USER

#include<iostream>
#include<string>

using std::ostream;
using std::string;

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
    float height_;
    uint internal_id_; //unique id
    Gender gender_;
    //<list of friends>

public:
    user(/* args */) = delete;
    user(string name, uint age=0, float height=0,Gender gender_ = Gender::kRatherNotSay, uint internal_id_=0);
    ~user();
    
    friend ostream& operator<<(ostream& os,const user&);

};

#endif