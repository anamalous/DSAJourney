#include <string>
#include <iostream>

using std::string;

bool rotCheck(string s,string t){
    int p1=0,p2=0;
    while(p2<s.size()){
        if(p1>=s.size())
            return 1;
        if(s[p1]!=t[p2]){
            p2++;
            p1=0;
        }
        else{
            p2=(p2+1)%t.size();
            p1++;
        }
    }
    return 0;
}

int main(){
    std::cout<<rotCheck("hello","llohe");
}