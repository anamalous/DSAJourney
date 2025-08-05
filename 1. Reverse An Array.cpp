#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

int* reversearray(int* a,int size){
    int temp;
    for(int i=0;i<size/2;i++){//only iterate half way to swap all
        temp=a[size-i-1];//in place swap
        a[size-i-1]=a[i];
        a[i]=temp;
        
    }
    return a;
}

int* twopointerrev(int* a,int size){
    int* beg=a;
    int* end=a+size-1; //we need to point to size-1
    int temp;
    while(beg!=end){
        temp=*beg;
        *beg=*end;
        *end=temp;
        beg++;end--;
    }
    return a;
}

int* builtinrev(int* a,int size){
    std::reverse(a,a+size); //NEEDS TO POINT ONE PAST LAST ELEMENT
    return a;
}

int main(){
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    auto start = std::chrono::high_resolution_clock::now();
    int* rev=reversearray(arr,n);
    auto stop = std::chrono::high_resolution_clock::now();
    
    for(int i=0;i<n;i++){
        std::cout<<rev[i]<<"\t"<<std::endl;
    }

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " nanoseconds" << std::endl;
    
    return 0;
}