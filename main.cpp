#include <iostream>
#include "Job.h"
#include "Employer.h"
#include "Candidate.h"
#include "fstream"
#include "string"
#include "vector"

#define EMPLOYERFILE "Employer.txt"
#define CANDIDATEFILE "Candidate.txt"
#define JOBFILE "Job.txt"
using namespace std;

int sereal_num;//שומר את המיקום של האובייקט במערך


vector<Employer> Employers=Employer::readfromfile(EMPLOYERFILE);
vector<Candidate> Candidates=Candidate::readfromfile(CANDIDATEFILE);
vector<Job> Jobs=Job::readfromfile(JOBFILE);

void save_all_data(){
    ofstream file1(EMPLOYERFILE,ios::out);
    if(!file1){
        cout<<"cant open the file"<<EMPLOYERFILE<<endl;
        return;
    }
    file1.close();
    ofstream file2(CANDIDATEFILE,ios::out);
    if(!file2){
        cout<<"cant open the file"<<CANDIDATEFILE<<endl;
        return;
    }
    file2.close();
    ofstream file3(JOBFILE,ios::out);
    if(!file3){
        cout<<"cant open the file"<<JOBFILE<<endl;
        return;
    }
    file3.close();
    for(int i=0;i<Employers.size();i++) {
        Employers[i].savetofile(EMPLOYERFILE);
    }
    for(int i=0;i<Candidates.size();i++) {
        Candidates[i].savetofile(CANDIDATEFILE);
    }
    for(int i=0;i<Jobs.size();i++) {
        Jobs[i].savetofile(JOBFILE);
    }
}

void create_profile()
{
    string first_name;
    string last_name;
    long password;
    int year_expe;
    string area;
    string diploma;
    int age;
    long salary;
    char type;
    char valid;

    cout<<"Enter password";
    cin >>password;

    cout << "Enter your first name: ";
    cin >> first_name;

    cout << "Enter your last name: ";
    cin >> last_name;

    cout << "Enter years of experience: ";
    cin >> year_expe;

    cout << "Enter your area of expertise: ";
    cin >>area;
    /*
    cin.ignore(); // התעלמות מהתווים הקודמים לפני getline
    getline(cin, area);*/

    cout << "Enter your diploma title: ";
    cin>>diploma;
    /*getline(cin, diploma);*/

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter desired salary: ";
    cin >> salary;

    cout << "Enter your type (H(half)/F(full)): ";
    cin >> type;

    cout << "Is this valid? (Y/N): ";
    cin >> valid;


    Candidates[sereal_num].set_details (first_name,last_name,year_expe,area,diploma,age,salary,type,valid);
    ofstream delete_file(CANDIDATEFILE, ios::trunc);
    for(int i=0;i<Candidates.size();i++)
    {
        Candidates[i].savetofile(CANDIDATEFILE);
    }
}


void candidate_menu()
{
    int choice;
    cout<<"Choose an option "<<endl;
    cout <<"1.Create profile"<<endl;
    cout<<"2.Watch all jobs"<<endl;//HERER OPTIONS OF FILTERS- eden wrote
    cout<<"3.Watch submissions"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 1:
        {
            create_profile();
            break;
        }
    }

}
void employees_menu()
{
    cout<<"1.Publish a new job "<<endl;
    cout<<"2.Watch published job "<<endl;//eden wrote
    cout<<"3.Watch candidates applications"<<endl;
    cout<<"4.Search relevant candidates"<<endl;//show all the candidates and then filter
    cout<<"5.Search similar jobs "<<endl;
}




void login_Employer() {
    long Id, password;
    bool flag = false;

    for (int j = 0; j < 3; j++)
    {
        if (!flag)
        {
            cout << "Enter your ID " << endl;
            cin >> Id;
            cout << "Enter your password" << endl;
            cin >> password;

            for (int i = 0; i < Employers.size(); i++) {
                if (Employers[i].get_Id() == Id && Employers[i].get_password() == password) {
                    cout << "login sucsufully\n" << endl;
                    employees_menu();
                    flag = true;
                    sereal_num=i;//שומר את האינדקס של המיקום של האובייקט

                }
            }
        }

        if(!flag)
        {
            cout << "Number of attemps " << j + 1 << "/" << "3" << endl;
        }

    }
}


void login_candidate()
{
    long Id, password;
    bool flag = false;

    for (int j = 0; j < 3; j++)
    {
        if (!flag)
        {
            cout << "Enter your ID " << endl;
            cin >> Id;
            cout << "Enter your password" << endl;
            cin >> password;

            for (int i = 0; i < Candidates.size(); i++) {
                if (Candidates[i].get_Id() == Id && Candidates[i].get_password() == password) {
                    cout << "login sucsufully\n" << endl;

                    candidate_menu();
                    flag = true;
                    sereal_num=i;//שומר את האינדקס של המיקום של האובייקט
                }
            }
        }

        if(!flag)
        {
            cout << "Number of attemps " << j + 1 << "/" << "3" << endl;
        }

    }
}


bool valid_id(long id)
{
    for(int i=0;i<Employers.size();i++)
        if(Employers[i].get_Id()==id)
            return true;
    for(int i=0;i<Candidates.size();i++)
        if(Candidates[i].get_Id()==id)
            return true;
    return false;
}
Employer register_Employer()
{
    string first_name,last_name,mail,phone,birth;
    long Id,password;
    cout<<"***************Register Employer***************"<<endl;
    cout<<"enter your Id"<<endl;
    cin>>Id;
    while(valid_id(Id))
    {
        cout<<"this ID is already Existing in the data try onther ID"<<endl;
        cin>>Id;
    }
    cout<<"now lest enter a password digits only"<<endl;
    cin>>password;
    cout<<endl;
    cout<<"enter first name"<<endl;
    cin>>first_name;
    cout<<endl;
    cout<<"enter last name"<<endl;
    cin>>last_name;
    cout<<endl;
    cout<<"enter phone number"<<endl;
    cin>>phone;
    cout<<endl;
    cout<<"enter mail"<<endl;
    cin>>mail;
    cout<<endl;
    cout<<"enter you birth in the following format (day/month/year)"<<endl;
    cin>>birth;
    //save by main
    Employer register_emplyoer(Id,first_name,last_name,mail,birth,phone,password);
    register_emplyoer.savetofile(EMPLOYERFILE);
    return register_emplyoer;
}



Candidate register_candidate()
{
    string first_name,last_name,mail,phone,birth;
    long Id,password;
    cout<<"***************Register Employer***************"<<endl;
    cout<<"enter your Id"<<endl;
    cin>>Id;
    while(valid_id(Id))
    {
        cout<<"this ID is already Existing in the data try onther ID"<<endl;
        cin>>Id;
    }
    cout<<"now lest enter a password digits only"<<endl;
    cin>>password;
    cout<<endl;
    cout<<"enter first name"<<endl;
    cin>>first_name;
    cout<<endl;
    cout<<"enter last name"<<endl;
    cin>>last_name;
    cout<<endl;
    cout<<"enter phone number"<<endl;
    cin>>phone;
    cout<<endl;
    cout<<"enter mail"<<endl;
    cin>>mail;
    cout<<endl;
    cout<<"enter you birth in the following format (day/month/year)"<<endl;
    cin>>birth;

    //save by main
    Candidate register_candidate(Id,first_name,last_name,mail,birth,phone,0," "," ",0,0,' ',' ',password);

    register_candidate.savetofile(CANDIDATEFILE);
    return register_candidate;
}


int main()
{
    int choice;
    save_all_data();
    int sereal_num;
    long id,password;
    string firstname,lastname,mail,birth,phone;

    cout<<"                                                     "<<endl;
    cout <<"***************WELCOME TO JOB MASTER***************"<<endl;
    cout<<"                                                     "<<endl;

    cout<<"                      Choose:                         "<<endl;
    cout<<"1.Are you an Employer\n2.Are a Candidate\n"<<endl;
    cin>>choice;

    switch (choice)
    {
        case 1://Employers register/login (forgot password)
        {
            int seconde_choice;
            cout << "                                                     " << endl;
            cout << "***************WELCOME TO login/register(Employer)***************" << endl;
            cout << "                                                     " << endl;

            cout << "                           choose:                         " << endl;
            cout << "1.login\n2.register\n" << endl;
            cin >> seconde_choice;


            switch (seconde_choice)
            {

                case 1://login an Employer
                {
                    login_Employer();
                    break;
                }
                case 2://register an Employer
                {
                    Employers.push_back(register_Employer());
                    cout << "Registered succesfully" << endl;
                    employees_menu();
                    break;
                }
                case 3://wrong input 3 times or more
                {
                    cout << "******************forgot password******************" << endl;
                    cout << "enter your ID which you want to get his password" << endl;
                    cin >> id;
                    if (valid_id(id))
                        cout << "There is no such ID in the data base" << endl;
                    else
                        cout << "sended mail to the relevant account"
                             << endl;//here we need to send a mail with the password
                    break;
                }

            }
            break;

        }

        case 2:
        {
            int seconde_choice;
            cout << "                                                     " << endl;
            cout << "***************WELCOME TO login/register(Candidate)***************" << endl;
            cout << "                                                     " << endl;

            cout << "                           choose:                         " << endl;
            cout << "1.login\n2.register\n" << endl;
            cin >> seconde_choice;

            switch (seconde_choice)
            {
                case 1://login an candidate
                {
                    login_candidate();
                    break;
                }
                case 2://register an Employer
                {
                    Candidates.push_back(register_candidate());
                    cout << "Registered succesfully" << endl;
                    candidate_menu();
                    break;
                }
                case 3://wrong input 3 times or more
                {
                    cout << "******************forgot password******************" << endl;
                    cout << "enter your ID which you want to get his password" << endl;
                    cin >> id;
                    if (valid_id(id))
                        cout << "There is no such ID in the data base" << endl;
                    else
                        cout << "sended mail to the relevant account"
                             << endl;//here we need to send a mail with the password
                    break;
                }

            }
        break;
        }
        default:
        {
            cout<< "Error, open system again";
        }



    }
    return 0;
}
