#include <iostream>
#include <algorithm>

int kthmin(int* arr,int k, int size){
    int temp,minind,min,i=0;
    while(i<k){
        min=arr[i];
        for(int j=i;j<size;j++){
            if(arr[j]<=min){
                min=arr[j];
                minind=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[minind];
        arr[minind]=temp;
        i+=1;
    }
    return arr[k-1];
}

int main(){
    int arr[]={7,2,3,6,5,2};
    std::cout<<kthmin(arr,4,6);
}