#include <iostream>
#include <vector>

using std::vector;

vector<int> flOccur(vector<int> arr,int target){
    int first=-1,i;
    for(i=0;i<arr.size();i++){
        if(first==-1&&arr[i]==target)
            first=i;
        if(arr[i]>target){
            if(first==-1){
                return {-1,-1};
            }
            return {first,i-1};
        }
    }
    if(arr[i-1]==target)
        return {first,i-1};
    return {-1,-1};
}

vector<int> flBinOccur(vector<int> arr,int target){
    int begin=0,end=arr.size()-1,mid=(begin+end)/2;
    while(begin<=end&&arr[mid]!=target){
        if(target<=arr[mid])
            end=mid;
        if(target>arr[mid])
            begin=mid;
        mid=(begin+end)/2;
    }
    if(begin>end)
        return {-1,-1};
    int i=mid,j=mid;
    while(arr[i]==target)
        i--;
    while(arr[j]==target)
        j++;
    return {i+1,j-1};
}

int findFirstOccurrence(vector<int>& arr, int target) {
    int begin=0,end=arr.size()-1,first=-1;
    while (begin<=end) {
        int mid=begin+(end-begin)/2;
        if(arr[mid]==target){
            first=mid;
            end=mid-1;
        } 
        else if(arr[mid]<target)
            begin=mid+1;
        else
            end=mid-1;
    }
    return first;
}
int findLastOccurrence(vector<int>& arr, int target) {
    int begin=0,end=arr.size()-1,last=-1;
    while (begin<=end) {
        int mid=begin+(end-begin)/2;
        if(arr[mid]==target){
            last=mid;
            begin=mid+1;
        } 
        else if(arr[mid]<target)
            begin=mid+1;
        else
            end=mid-1;
    }
    return last;
}

int main(){
    vector<int> a={1,2,2,3,4,5,8};
    for(int ind:flBinOccur(a,2)){
        std::cout<<ind<<" ";
    }
    std::cout<<findFirstOccurrence(a,2)<<" "<<findLastOccurrence(a,2);

}