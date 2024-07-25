#include <iostream>
using namespace std;
class student{
    public:
    void disp(string name, string enrol, string course,string dept){
        cout << "Student Details:- " << endl;
        cout << name << endl << enrol << endl << course << endl << dept << endl;
    }
};

int main() {
    string name, enrol, course, dept;
    cout << "Enter student details:" << endl;
    cout << "<name>" << endl;
    getline(cin, name);
    cout << "<enroll>" << endl;
    cin >> enrol;
    cout << "<course>" << endl;
    cin >> course;
    cout << "<dept>" << endl;
    cin >> dept;
    cout << endl;
    student display;
    display.disp(name, enrol, course, dept);
    return 0;
}