#include"user.h"
using std::ostream;

user::user(string name, uint age,Gender gender, int internal_id, forward_list<string> hobbies): name_(name),age_(age),gender_(gender), internal_id_(internal_id),hobbies_(hobbies) {}

user::~user()
{

}

void user::setInternalId(int uid)
{
    this->internal_id_ = uid;
}
ostream& operator<<(ostream& os, const user& u1)
{   
    os << "user info: \n " 
       << "name: " << u1.name_ << "\n";
    //    << "gender: " << u1.gender_ << "\n";
    //    << "age: " << u1.age_ <<  "\n";
    return os;
}

