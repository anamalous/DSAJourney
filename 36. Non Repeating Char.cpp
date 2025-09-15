#include <string>
#include <iostream>
#include <algorithm>

using std::string;

string FirstNonRepeating(string s) {
    string res;char curr='#';
    for(char c:s){
        if(curr!=c)
            curr=c;
        else
            curr='#';
        res+=curr;
    }
    return res;
}

int main(){
    std::cout<<FirstNonRepeating("zz");
}