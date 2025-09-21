#include <vector>
#include <iostream>

using namespace std;

void permutations(vector<vector<int>>& res, vector<int> arr, int idx) {
    if (idx==arr.size()) {
        res.push_back(arr); //if reached end of array - add 
        return;
    }
    for (int i=idx;i<arr.size();i++) {
        swap(arr[idx],arr[i]); //first iteration: no swaps
        permutations(res,arr,idx+1);
        swap(arr[idx],arr[i]); //swaps back what was changed before recursion call
        //call 1: idx and i will be equal at ech iteration - nothing changes
        //original array is first permutation
        //when returned from (res,arr,3)
        //swaps back 2,2 (no change)
        //now i=3 and idx=2 so go back to call where idx=1
        //swap back changes nothing
        //next iteration is idx=1 and i=2
        //swaps items at index 1 and 2 and calls perm again on idx=2 which swaps 2 and 2 
        //changes nothing and appends
        //when returned to the idx=1 and i=2 we exit loop
        //return to call idx=0 and i=1 - swap 0 and 1 (213)
        //again swap nothing and so on
        //builds solution one swap at a time
        //swaps accumulate when low idx calls build up higher
    }
}

int main() {
    vector<int> arr={1,2,3};
    vector<vector<int>> res;

    permutations(res,arr,0);

    for (auto x : res) {
        for (auto y : x) 
            cout << y << " ";
        cout << endl;
    }
}