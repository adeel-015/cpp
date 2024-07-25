#include<iostream>
using namespace std;

class Class_2;

class Class_1 {
private:
    int data1;

public:
    Class_1(int value) : data1(value) {}

    friend void swapData(Class_1& obj1, Class_2& obj2);

    void display() {
        cout << "Class_1 data: " << data1 << endl;
    }
};

class Class_2 {
private:
    int data2;

public:
    Class_2(int value) : data2(value) {}

    friend void swapData(Class_1& obj1, Class_2& obj2);

    void display() {
        cout << "Class_2 data: " << data2 << endl;
    }
};

void swapData(Class_1& obj1, Class_2& obj2) {
    int temp = obj1.data1;
    obj1.data1 = obj2.data2;
    obj2.data2 = temp;
}

int main() {
    Class_1 obj1(10);
    Class_2 obj2(20);

    cout << "Before swapping:" << endl;
    obj1.display();
    obj2.display();

    swapData(obj1, obj2);

    cout << "After swapping:" << endl;
    obj1.display();
    obj2.display();

    return 0;
}
