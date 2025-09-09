#include <string>
#include <iostream>

using std::string;

bool palindrome(string s){
    int l=0,r=s.length()-1;
    while(l<=r){
        if(s[l]!=s[r])
            return false;
        l++;r--;
    }
    return true;
}

int main(){
    std::cout<<palindrome("madam");
}