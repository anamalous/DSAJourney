#include <iostream>

int* sortArray(int* arr,int size){
    int* ret=new int[size]; int c0=0,c1=0,c2=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0)
            c0++;
        if(arr[i]==1)
            c1++;
        if(arr[i]==2)
            c2++;
    }
    int ind=0;
    while(ind<c0){
        ret[ind]=0; ind++;
    }
    while(ind<c0+c1){
        ret[ind]=1;ind++;
    }
    while(ind<c0+c1+c2){
        ret[ind]=2;ind++;
    }
    return ret;
}

int* inPlaceSort(int* arr,int size){
    int temp; int last0;
    for(int i=0;i<size;i++){
        if(arr[i]==0){
            continue;last0=i;}
        for(int j=i+1;j<size;j++)
            if(arr[j]==0){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                last0=i;
                break;
            }   
    }
    for(int i=last0+1;i<size;i++){
        if(arr[i]==1){
            continue;}
        for(int j=i+1;j<size;j++)
            if(arr[j]==1){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                break;
            }   
    }
    return arr;
}

int main(){
    int arr[]={0,2,1,2,1,0,1,0};
    int* res=inPlaceSort(arr,8);
    for(int i=0;i<8;i++){
        std::cout<<res[i]<<"\t";
    }
}
