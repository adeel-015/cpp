#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int roll_no;
    char grade;
    void info()
    {
        cout << "----------------------" << endl;
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Roll_no: ";
        cin >> roll_no;
        cout << "Enter Grade: ";
        cin >> grade;
        cin.ignore();
        cout << "----------------------" << endl;
    }
    void disp()
    {
        cout << "Name:- " << name << endl;
        cout << "Roll_no.:- " << roll_no << endl;
        cout << "Grade:- " << grade << endl;
    }
};

int main()
{
    Student studs[10];
    for (int i = 0; i < 10; i++)
    {
        studs[i].info();
    }
    cout << "Details of the 10 students who appeared in Exams" << endl;
    for (int i = 0; i < 10; i++)
    {
        studs[i].disp();
        cout << "----------------------------" << endl;
    }
}