#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &arr) {
    int pivot = -1; 
    for(int i=arr.size()-2;i>=0;i--)
        if(arr[i]<arr[i+1]){//rightmost elements in order
            pivot = i;
            break;
        }

    if(pivot==-1){
        reverse(arr.begin(), arr.end()); //if elements in descending - reverse
        return;
    }

    for(int i=arr.size()-1;i>pivot;i--)
        if(arr[i]>arr[pivot]){
            swap(arr[i],arr[pivot]); //swap rightmost element before pivot greater than it
            break;
        }

    reverse(arr.begin() + pivot + 1, arr.end()); //reverse all elements to the right of the swap
}

int main() {
    vector<int> arr={2,4,1,7,5,0};
    nextPermutation(arr);    
    for(int x:arr) 
        cout<<x<<" ";    
}