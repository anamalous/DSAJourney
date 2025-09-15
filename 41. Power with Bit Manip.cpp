#include <bitset>
#include <cstdint>
#include <iostream>

using std::bitset;

int square(int num){
    bitset<32> bin1(num);
    int res=0;
    while(num>0){
        if(num%2==1)
            res+=(int)bin1.to_ulong();
        bin1=bin1<<1;
        num=num/2;
    }
    return res;
}

int main(){
    std::cout<<square(5);
}