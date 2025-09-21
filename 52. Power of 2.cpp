#include <iostream>

using namespace std;

bool isPowerofTwo(int n) {
    if(n&n-1)
        return false;
    else   
        return true;        
}

int main(){
    cout<<isPowerofTwo(3);
}