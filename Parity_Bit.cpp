#include <bits/stdc++.h>
using namespace std;

vector<string> parityBit(vector<string> data) {
  vector<string> result;
  for (string word : data) {
    int count = 0;
    for (char bit : word) {
      if (bit == '1') {
        count++;
      }
    }
    if (count % 2 == 0) {
      result.push_back(word + '0');
    } else {
      result.push_back(word + '1');
    }
  }
  return result;
}

int main() {
  vector<string> data = {"1010", "11101", "01010", "00111", "11001"};
  vector<string> result = parityBit(data);
  for (string word : result) {
    cout << word << " ";
  }
  cout << endl;
  return 0;
}
