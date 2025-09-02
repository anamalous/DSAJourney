#include <iostream>
#include <cstdint>

bool isNotSigned32BitInt(long long num) {
    return num < INT32_MIN && num > INT32_MAX;
}

int reverse(int x) {
    if((int)(-x)<-x){
        return 0;
    }
    long long rev=0;
    int sign=x<0?-1:1;
    x=std::abs(x);
    while(x>0){
        rev=rev*10+(x%10);
        std::cout<<rev<<" ";
        x=x/10;
    }
    rev=rev*sign;
    std::cout<<rev<<std::endl;
    if((int)rev<rev){
        return 0;
    }
    return rev;   
}

int main(){
    std::cout<<reverse(9646324351);
}