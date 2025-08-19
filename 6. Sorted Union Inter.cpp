#include <vector>
#include <iostream>

std::vector<int> arrayUnion(int* a,int asize,int* b, int bsize){
    int ai=0,bi=0;
    std::vector<int> uni,inter;
    while(ai<asize&&bi<bsize){
        if(a[ai]>b[bi]){
            uni.push_back(b[bi]);
            bi++;
        }
        if(a[ai]<b[bi]){
            uni.push_back(a[ai]);
            ai++;
        }
        if(a[ai]==b[bi]){
            //inter.push_back(a[ai]);
            uni.push_back(a[ai]);
            ai++;bi++;
        }
    }
    for(int i=ai;i<asize;i++){
        uni.push_back(a[i]);
    }
    for(int i=bi;i<bsize;i++){
        uni.push_back(b[i]);
    }
    return uni;
}

int main(){
    int a[]={2,5,5,7,9,15};
    int b[]={1,3,4,5,8,11,14,16,20};
    for(auto item:arrayUnion(a,5,b,9))
        std::cout<<item<<" ";
}