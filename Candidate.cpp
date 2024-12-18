

#include "Candidate.h"
Candidate::Candidate() :User(){}
Candidate::~Candidate(){}
Candidate::Candidate(long Id,string first_name,string last_name,string mail,string birth,string phone,
                     int year_expe, string area, string diploma,int age, long salary,char type, char valid,long pass)

                     : User(Id,first_name,last_name,mail,birth,phone,pass) {}

char *Candidate::get_type() const
{
    return "Candidate";
}

void Candidate:: set_details(string first_name,string last_name,int year_expe, string area, string diploma,int age, long salary,char type, char valid)
{
    this->first_name=first_name;
    this->last_name=last_name;
    this-> year_expe=year_expe;
    this-> area=area;
    this-> diploma=diploma;
    this-> age=age;
    this-> salary=salary;
    this->type=type;
    this->valid= valid;

}

void Candidate::savetofile(const string &filename) const {
    ofstream file(filename,ios::app);
    if(file.is_open())
    {
        file<<first_name<<endl;
        file<<Id<<endl;
        file<<last_name<<endl;
        file<<mail<<endl;
        file<<birth<<endl;
        file<<phone<<endl;
        file<<year_expe<<endl;//year_exp
        file<<area<<endl;//area
        file<<diploma<<endl;//diplome
        file<<age<<endl;//age
        file<<salary<<endl;//salary
        file<<type<<endl;//type
        file<<valid<<endl;//valid/invalid
        file<<password<<endl;

        file<<"**********************"<<endl;
        file.close();
    }
    else{
        cout<<"no matching file to write in Candidate"<<endl;
    }
}

vector<Candidate> Candidate::readfromfile(const string &filename) {
    ifstream file(filename);
    vector<Candidate> candidates;

    if (file.is_open()) {
        cout << "File opened successfully: " << filename << endl;

        // משתנים זמניים עבור קריאת הנתונים
        long Id, password;
        string first_name, last_name, mail, birth, phone;
        int year_expe;
        string area, diploma;
        int age;
        long salary;
        char type, valid;

        while (file.peek() != EOF) { // בדיקה אם יש נתונים לקרוא
            string delimiter_line;
            getline(file, delimiter_line);

            if (delimiter_line != "**********************") {
                cout << "Warning: Missing delimiter line. Skipping record." << endl;
                continue;
            }

            // קריאת נתונים לפי הפורמט
            if (!(file >> Id)) break;
            file.ignore(); // דילוג על תו newline

            if (!getline(file, first_name) || !getline(file, last_name) ||
                !getline(file, mail) || !getline(file, birth) ||
                !getline(file, phone)) {
                cout << "Error: Incomplete data. Skipping record." << endl;
                continue;
            }

            if (!(file >> year_expe)) break;
            file.ignore();
            if (!getline(file, area) || !getline(file, diploma)) {
                cout << "Error: Incomplete data. Skipping record." << endl;
                continue;
            }

            if (!(file >> age >> salary >> type >> valid >> password)) break;
            file.ignore(); // דילוג על newline

            // יצירת אובייקט מועמד והוספה לוקטור
            candidates.emplace_back(Id, first_name, last_name, mail, birth, phone,
                                    year_expe, area, diploma, age, salary, type, valid, password);
        }

        file.close();
    } else {
        cout << "Error: Unable to open file: " << filename << endl;
    }

    return candidates;
}

void Candidate::print_candidate() const
{
    cout << "Candidate Information:" << endl;
    cout << "ID: " << Id << endl;
    cout << "Name: " << first_name << " " << last_name << endl;
    cout << "Email: " << mail << endl;
    cout << "Birth Date: " << birth << endl;
    cout << "Phone: " << phone << endl;
    cout << "Password: " << password << endl;

}
