#include"user.h"
using std::ostream;

user::user(string name, uint age, float height,Gender gender, uint internal_id): name_(name),age_(age),height_(height),gender_(gender), internal_id_(internal_id) {}

user::~user()
{

}


ostream& operator<<(ostream& os, const user& u1)
{   
    os << "user info: \n " 
       << "name: " << u1.name_ << '\n';
    //    << "gender: " << u1.gender_ << '\n'
    //    << "height: " << u1.height_ << '\n'
    //    << "age: " << u1.age_ << '\n';
    return os;
}

