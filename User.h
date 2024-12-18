//
// Created by benbu on 12/12/2024.
//

#ifndef JOBSEARCH_USER_H
#define JOBSEARCH_USER_H
#include "string"

using namespace std;

class User {
protected:
    long Id;
    string birth;
    string first_name;
    string last_name;
    string mail;
    string phone;
    long password;
    int year_expe;
    string area;
    string diploma;
    int age;
    long salary;
    char type;
    char valid;
public:
    User();
    User(long Id,string first_name,string last_name,string mail,string birth,string phone,long pass);
    ~User();
    long get_Id()const;
    string get_first_name()const;
    string get_last_name()const;
    virtual char* get_type()const=0;
    long get_password() const;

};


#endif //JOBSEARCH_USER_H
