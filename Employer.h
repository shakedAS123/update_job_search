

#ifndef JOBSEARCH_EMPLOYER_H
#define JOBSEARCH_EMPLOYER_H
#include "User.h"
#include "Job.h"
#include "vector"
#include "fstream"
#include "iostream"

class Employer :public User{
private:
    vector<Job>Jobs;
public:
    Employer();
    Employer(long Id,string first_name,string last_name,string mail,string birth,string phone,long password);
    ~Employer();
    char* get_type()const;
    void savetofile(const string&filename)const;
    static vector<Employer> readfromfile(const string &filename);
    vector<Job> get_jobs()const;
    void add_job(const Job& other);
};


#endif //JOBSEARCH_EMPLOYER_H