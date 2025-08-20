#include <vector>
#include <iostream>
using std::vector;

int maxSubArray(vector<int> arr){
    int start=1,end=0,currsum=arr[0],max=currsum;
    while(start<=end&&end<arr.size()){
        if(currsum>currsum+arr[end]){
            start++;
            end++;
        }
        while(currsum<currsum+arr[end]){
            currsum+=arr[end];
            end++;
        }
        if(currsum>currsum-arr[start])
            start++;
        while(currsum<currsum-arr[start]){
            currsum-=arr[start];
            start++;
        }
        if(currsum>max){
            max=currsum;
        }
        start=end; currsum=0;
    }
    return max;
}

int simpleMax(vector<int> arr){
    int currsum=arr[0],max=currsum;
    for(int i=1;i<arr.size();i++){
        if(arr[i]<=0){
            if(currsum>max){
                max=currsum;
            }
            currsum=arr[i];
            continue;
        }
        if(arr[i-1]<=0)
            currsum-=arr[i-1];
        currsum+=arr[i];
        if(currsum>max)
            max=currsum;
    }
    return max;
}

int simplerMax(vector<int> arr){
    int currsum=arr[0],max=currsum;
    for(int i=1;i<arr.size();i++){
        currsum=std::max(arr[i],currsum+arr[i]);
        max=std::max(currsum,max);
    }
    return max;
}

int main(){
    vector<int> n={-1,-2,40,10,-5,-7,-6,-12,-8};
    std::cout<<simplerMax(n);
}