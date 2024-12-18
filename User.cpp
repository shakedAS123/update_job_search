//
// Created by benbu on 12/12/2024.
//

#include "User.h"

using namespace std;
User::User() {
}
User::User(long Id,string first_name,string last_name,string mail,string birth,string phone,long pass)  {
    this->Id=Id;
    this->first_name=first_name;
    this->last_name=last_name;
    this->mail=mail;
    this->birth=birth;
    this->phone=phone;
    password=pass;
}
User::~User() {}
long User::get_Id() const {
    return Id;
}
string User::get_first_name() const {
    return first_name;
}
string User::get_last_name() const {
    return last_name;
}
long User::get_password() const {
    return password;
}
