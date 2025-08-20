#include <cstdint>
#include <iostream>

int reverse(int x) {
    long long res=0;
    int sign=x>0?1:-1;
    long long a=x>0?x:x*(-1);    
    while(a>0){
        res=res*10+(a%10);
        a=(int)a/10;
    }
    res*=sign;
    if(res>=INT32_MIN&&res<=INT32_MAX)
        return res;
    return 0;
}

int main(){
    std::cout<<reverse(123);
}