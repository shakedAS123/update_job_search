//
// Created by benbu on 12/12/2024.
//

#include "Job.h"
using namespace std;
Job::Job() {}
Job::Job(string name, float salary,string area, float expirence,string degree,string time,string publish) {
    this->name=name;
    this->salary=salary;
    this->area=area;
    this->expirence=expirence;
    this->degree=degree;
    this->time=time;
    publisher=publish;
}
Job::~Job() {
}

string Job::get_area() const {
    return area;
}

string Job::get_name() const {
    return name;
}

float Job::get_exp() const {
    return expirence;
}

string Job::get_time() const {
    return time;
}

string Job::get_degree() const {
    return degree;
}

float Job::get_salary() const {
    return salary;
}

string Job::get_publisher() const {
    return publisher;
}

void Job::set_publisher(const string publish) {
    publisher=publish;
}

void Job::set_name(const string name) {
this->name=name;
}

void Job::set_area(const string area) {
    this->area=area;
}

void Job::set_degree(const string degree) {
    this->degree=degree;
}

void Job::set_exp(const float exp) {
    expirence=exp;
}
void Job::set_salary(const float salary) {
    this->salary=salary;
}

void Job::set_time(const string time) {
    this->time=time;
}

Job &Job::operator=(const Job &other) {
    name=other.name;
    salary=other.salary;
    area=other.area;
    expirence=other.expirence;
    degree=other.degree;
    time=other.time;
    return *this;
}

void Job::savetofile(const string &filename) const {
    ofstream file(filename,ios::app);
    if(file.is_open())
    {
        file<<name<<endl;
        file<<salary<<endl;
        file<<area<<endl;
        file<<expirence<<endl;
        file<<degree<<endl;
        file<<time<<endl;
        file<<publisher<<endl;
        file<<"**********************"<<endl;
    }
    else
        cout<<"no matching file to write in Job"<<endl;
}

vector<Job> Job::readfromfile(const string &filename) {
    ifstream file(filename);
    vector<Job> Jobs;
    if(file.is_open())
    {
        cout<<"file opened succesfully"<<filename<<endl;
        float expirence,salary;
        string name,area,degree,time,publisher;
        while(getline(file,name))
        {
            if(name=="**********************")
                continue;
            file>>salary;
            file.ignore();
            getline(file,area);
            file>>expirence;
            file.ignore();
            getline(file,degree);
            getline(file,time);
            getline(file,publisher);
            Jobs.push_back(Job(name,salary,area,expirence,degree,time,publisher));
        }
        file.close();
    }
    else {
        cout << "no matching file to open Job" << endl;
    }
return Jobs;
}