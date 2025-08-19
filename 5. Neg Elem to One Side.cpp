#include <iostream>
int* negToOneSide(int* arr,int size){
    int temp,start=0,end=size-1;
    while(start<=end){
        if(arr[start]>=0&&arr[end]<0){
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;end--;
        }
        else {
            if(arr[start]<0)
                start++;
            if(arr[end]>=0)
                end--;
        }
    }
    return arr;
}
int main(){
    int arr[]={1,2,-1,6,2,-2,-3,8};
    int* res=negToOneSide(arr,8);
    for(int i=0;i<8;i++){
        std::cout<<res[i]<<" ";
    }
}