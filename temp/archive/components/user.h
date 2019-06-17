#pragma once
// #include <bits/stdc++.h>  // replace this with appropriate headers
#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>

using std::cout;
using std::endl;


enum class Gender{
    kRatherNotSay, 
    kMale,
    kFemale,
    kOthers    
};



class User
{
private:
    /* data */
    std::string  name_;
    std::string internal_id_;//use an uuid  - external lib / so or from utils 
    uint8_t age_;
    Gender gender_;
    std::vector<std::string> hobbies_;
    std::unordered_set <std::string> list_of_friends_; // list of friends - for the ease of look up
    
public:
    User(/* args */) = delete; // to make the passing of 'name' while creation as mandotory

    // User( std::string name, std::string internal_id, int age, Gender gender /* , std::vector<std::string> hobbies, std::unordered_set <std::string> list_of_friends*/);
    User(std::string name, std::string internal_id="", uint8_t age=18, Gender gender=Gender::kRatherNotSay , std::vector<std::string> hobbies={}, std::unordered_set <std::string> list_of_friends={});

    ~User();

    // friend Compartor;
};

/*
class Compartor{
    bool operator()(const User &lhs, const User& rhs)
    {
        return lhs.internal_id_ == rhs.internal_id_;    
    }
};
*/