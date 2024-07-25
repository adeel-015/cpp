#include <iostream>
using namespace std;

class MyClass{
    public:
        MyClass(){
            cout << "This is a constructor!" << endl;
        }
        
        ~MyClass(){
            cout << "This is a destructor!" << endl;
        }
};

int main(){
    MyClass obj;
    return 0;
}