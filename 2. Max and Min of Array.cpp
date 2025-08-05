#include <chrono>
#include <iostream>

int naivemax(int* a,int size){
    int max=a[0];
    for(int i=0;i<size;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}

int naivemin(int* a,int size){
    int min=a[0];
    for(int i=1;i<size;i++){
        if(a[i]<min){
            min=a[i];
        }
    }
    return min;
}

int* minmax(int* a,int size){
    int* mima=new int[2]; //assigns memory on the heap
    //allocated on stack if assigned as {a,b};
    mima[0]=a[0];
    mima[1]=a[0];

    for(int i=1;i<size;i++){
        if(a[i]<mima[0])
            mima[0]=a[i];
        if(a[i]>mima[1])
            mima[1]=a[i];
    }
    return mima;
    //if stack allocated memory
    //this would become invalid on leaving the function - dangling pointer in main
    //and hence returning an error - returning needs dynamic stack variable
}

int main(){
    int arr[]={1,9,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    auto start1 = std::chrono::high_resolution_clock::now();
    int min=naivemin(arr,n);
    int max=naivemax(arr,n);
    auto stop1 = std::chrono::high_resolution_clock::now();
    std::cout<<min<<std::endl;
    std::cout<<max<<std::endl;
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop1 - start1);
    std::cout << "Time taken by naive: " << duration.count() << " nanoseconds" << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    int* res=minmax(arr,n);
    auto stop2 = std::chrono::high_resolution_clock::now();
    std::cout<<res[0]<<std::endl;
    std::cout<<res[1]<<std::endl;
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop2 - start2);
    std::cout << "Time taken by combined: " << duration.count() << " nanoseconds" << std::endl;
    
    return 0;
}