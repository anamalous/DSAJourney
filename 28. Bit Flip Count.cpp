#include <iostream>

int countBitsFlip(int a, int b) {
    int ctr=0;
    while(a>0&&b>0){
        if(a%2!=b%2)
            ctr++;
        a=a/2;b=b/2;
    }
    
    while(a>0){
        if(a%2==1)
            ctr++;  
        a=a/2;
    }
    while(b>0){
        if(b%2==1)
            ctr++;
        b=b/2;
    }
    return ctr;
}

int main(){
    std::cout<<countBitsFlip(4,47);
}