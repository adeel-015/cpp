#include <iostream>
using namespace std;

class employee{
    public:
    int Employee_no;
    string Employee_name;
    float basic, DA, tax, gross_salary, net_salary;
    void readData(){
        cout << "-----Details of employee:----- " << endl;
        cout << "Enter Employee No.:- ";
        cin >> Employee_no;
        cin.ignore();
        cout << "Enter Employee Name:- ";
        getline(cin, Employee_name);
        cout << "Enter Basic:- ";
        cin >> basic;
    }
    int compute(){
        DA = basic * 0.62;
        gross_salary = basic + DA;
        tax = gross_salary * 0.30;
        net_salary = gross_salary - tax;
        return net_salary;
    }
};

int main(){
    int size;
    cout << "Enter no. of employees:- ";
    cin >> size;
    employee arr[size];
    for (int i=0;i<size;i++){
        arr[i].readData();
    }
    for (int i=0;i<size;i++){
        cout << "Net Salary of " << arr->Employee_name << " is " << arr[i].compute();
    }
}