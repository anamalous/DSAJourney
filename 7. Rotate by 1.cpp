#include <vector>
#include <iostream>
using std::vector;

void swap(vector<int> *arr,int i,int j){
    int temp=(*arr)[i];
    (*arr)[i]=(*arr)[j];
    (*arr)[j]=temp;
}
vector<int> rotate(vector<int> nums){
    for(int i=1;i<nums.size();i++){
        swap(&nums,i,i-1);
    }
    return nums;
}

int main(){
    vector<int> n={1,6,2,3,8,5,0};
    for(auto item:rotate(n)){
        std::cout<<item<<" ";
    }
}