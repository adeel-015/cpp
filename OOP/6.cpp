#include <iostream>
using namespace std;

class MyClass {
private:
    int data;

public:
    MyClass(int value) : data(value) {}
    MyClass(const MyClass &other) : data(other.data) {}
    void display() {
        cout << "Data: " << data << endl;
    }
};

int main() {
    MyClass obj1(42);
    MyClass obj2 = obj1;
    cout << "Object 1:" << endl;
    obj1.display();
    cout << "Object 2 (copied from Object 1):" << endl;
    obj2.display();
    return 0;
}
