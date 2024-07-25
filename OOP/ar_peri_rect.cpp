#include <iostream>
using namespace std;

class SIZE {
    public:
    void area(int l, int b){
        int ar = l*b;
        cout << "Area of Rectangle: " << ar << endl;
    }
    void perimeter(int l, int b){
        int peri = 2*(l+b);
        cout << "Perimeter of Rectangle:- " << peri << endl;
    }
};

int main(){
    int l,b;
    cout << "Enter length:- ";
    cin >> l;
    cout << "Enter breadth:- ";
    cin >> b;
    SIZE rect;
    rect.area(l,b);
    rect.perimeter(l,b);
    return 0;
}