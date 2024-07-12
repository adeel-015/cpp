// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

//Decimal to Binary (Time and Space Complexity: O(log n))
vector<int> decbinary(int n){
    vector<int> result;
    while (n>0){
        result.push_back(n % 2);
        n/=2;
    }
    return result;
}

// Binary to Decimal (Time Complexity: O(log n) | Space Complexity : O(1))
int bin(vector<int> n){
    int ans = 0, pow2 = 1;
    for (int i=0;i<n.size();i++){
        ans += n[i] * pow2;
        pow2 *= 2;
    }
    return ans;
}

int main() {
    // Write C++ code here
    vector<int> result = decbinary(5);
    
    for (int i : result){
        cout << i << " ";
    }
    cout << endl;
    
    int d = bin(result);
    cout << d;

    return 0;
}
