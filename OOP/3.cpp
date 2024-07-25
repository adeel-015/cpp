#include<iostream>
using namespace std;

class nest{
    int a;
    int square_num(){
        return a*a;
    }
    
    public:
    void input_num(){
        cout << "Enter a number: "; cin>>a;
    }

    int cube_num(){
        return a*a*a;
    }
    
    void disp_num(){
        int sq=square_num();      
        int cu=cube_num();
        cout << "The square of " << a << " is " << sq << endl;
        cout << "The cube of " << a << " is " << cu << endl;
    }
};

int main(){
      nest n1;
      n1.input_num();
      n1.disp_num();
      return 0;
}