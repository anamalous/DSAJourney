#include <iostream>
#include <string>
#include <cstdint>

using std::string;

int myAtoi(string s) {
    int sign=1,i=0; long long res=0;
    while(s[i]==' '){
        i++;continue;
    }
    if(s[i]=='-'){
        sign=-1;i++;
    }
    else if(s[i]=='+')
        i++;
    while(s[i]=='0'){
        i++;continue;
    }
    while(s[i]>='0'&&s[i]<='9'){
        res=res*10+(s[i]-'0');i++;
    }       
    res=res*sign;
    if(res < INT32_MIN)
        return INT32_MIN;
    if(res > INT32_MAX)
        return INT32_MAX;
    return res;
}

int main(){
    std::cout<<myAtoi("-91283472332");
}