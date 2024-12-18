//
// Created by benbu on 12/12/2024.
//

#include "Employer.h"
Employer::Employer() :User(){
}
Employer::Employer(long Id,string first_name,string last_name,string mail,string birth,string phone,long password): User(Id,first_name,last_name,mail,birth,phone,password) {
}
Employer::~Employer(){}

char *Employer::get_type() const {
    return "Employer";
}

void Employer::savetofile(const string &filename) const {
    ofstream file(filename,ios::app);
    if(file.is_open()){
        file<<first_name<<endl;
        file<<Id<<endl;
        file<<last_name<<endl;
        file<<mail<<endl;
        file<<birth<<endl;
        file<<phone<<endl;
        file<<password<<endl;
        file<<"**********************"<<endl;
    }
    else{
        cout<<"no mtching file to write in"<<endl;
    }
}

vector<Employer> Employer::readfromfile(const string &filename) {
    ifstream file(filename);
    vector<Employer> employers;
    if(file.is_open())
    {
        cout<<"file opened succesfully"<<filename<<endl;
        long Id,password;
        string first_name,last_name,mail,birth,phone;
        while(getline(file, first_name)){
            if(first_name=="**********************")
                continue;
            file>>Id;
            file.ignore();
            getline(file,last_name);
            getline(file,mail);
            getline(file,birth);
            getline(file,phone);
            file>>password;
            file.ignore();
            employers.push_back(Employer(Id,first_name,last_name,mail,birth,phone,password));
        }
        file.close();
    }
    else{
        cout<<"no such file to open Employer"<<endl;
    }
    return employers;
}