#include <cmath>

bool isPowerOfFour(int n) {
    if(n==0)
        return(false);
    else if(ceil(log(n)/log(4))==log(n)/log(4))
        return(true);
    else
        return(false);
}

bool powerFourBit(int n){
    return n>0?(n&(n-1))==0?(n&0x55555555)==n?true:false:false:false;
}
