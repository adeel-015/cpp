#include <iostream>
#include <vector>

using namespace std;

//SORTING!!

//1. selection_sort | Time complexity: O(n²) | Space Complexity: O(1)
void selection_sort(vector<int> &arr, int n) {
  // selection sort
  for (int i = 0; i < n - 1; i++) {
    int mini = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }
}

//2. Bubble_sort | Time complexity: O(n²) (Worst/Avg) / O(n) (Best) | Space Complexity: O(1)
void bubble_sort(vector<int> &arr, int n) {
    // bubble sort
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//3. Bubble_sort_recursion | Time complexity: O(n²) (Worst/Avg) / O(n) (Best) | Space Complexity: O(n)
void bubble_sort_recursion(vector<int> &arr, int n) {
    // Base Case: range == 1.
    if (n == 1) return;

    int didSwap = 0;
    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            didSwap = 1;
        }
    }

    // if no swapping happens.
    if (didSwap == 0) return;

    //Range reduced after recursion:
    bubble_sort_recursion(arr, n - 1);
}

//4. Insertion_sort | Time complexity: O(n²) (Worst/Avg) / O(n) (Best) | Space Complexity: O(1)
void insertion_sort(vector<int> &arr, int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

//5. Insertion_sort_recursion | Time complexity: O(n²) (Worst/Avg) / O(n) (Best) | Space Complexity: O(n)
void insertion_sort_recursion(vector<int> &arr, int i, int n) {

    // Base Case: i == n.
    if (i == n) return;

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }

    insertion_sort_recursion(arr, i + 1, n);
}

//6. Merge_sort | Time complexity: O(n log n) | Space Complexity: O(n)
void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    
    while (left<=mid && right<=high){
        if (arr[left]<=arr[right]){
            temp.emplace_back(arr[left]);
            left++;
        }
        else {
            temp.emplace_back(arr[right]);
            right++;
        }
    }
    
    while (left<=mid){
        temp.emplace_back(arr[left]);
        left++;
    }
    
    while (right<=high){
        temp.emplace_back(arr[right]);
        right++;
    }
    
    for (int i = low; i<=high; i++){
        arr[i] = temp[i - low];
    }
}

void merge_sort(vector<int> &arr, int low, int high){
    if (low>=high) return;
    int mid = (low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

//7. Quick_sort | Time complexity: O(n²) (Worst) / O(n log n) (Best/Avg) | Space Complexity: O(n)
int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j){
        if (arr[i] <= pivot && i <= high - 1){
            i++;
        }
        
        if (arr[j] > pivot && j >= low + 1){
            j--;
        }
        
        if (i < j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high){
    if (low < high){
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> &arr){
    qs(arr, 0, arr.size()-1);
    return arr;
}

// Uncomment whatever sorting method you want to use.

int main(){
    vector<int> arr={34, 45, 32, 3, 4, 0};
    /* 1. */ // selection_sort(arr, arr.size());
    /* 2. */ // bubble_sort(arr, arr.size());
    /* 3. */ // bubble_sort_recursion(arr, arr.size());
    /* 4. */ // insertion_sort(arr, arr.size());
    /* 5. */ // insertion_sort_recursion(arr, 0 , arr.size());
    /* 6. */ // merge_sort(arr, 0, arr.size()-1);
    /* 7. */ // quickSort(arr);
    for (int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    return 0;
}
