#include <string>
#include <iostream>
#include <algorithm>

using std::string;

bool validShuffle(string a,string b,string c){
    if(a.length()+b.length()!=c.length())
        return false;
    std::sort(a.begin(),a.end());
    std::sort(b.begin(),b.end());
    std::sort(c.begin(),c.end());
    int p=0,q=0,r=0;
    while(r<c.size()){
        if(c[r]==a[p])
            p++;
        else if(c[r]==b[q])
            q++;
        else    
            return false;
        r++;
    }
    if(a.size()-p>0||b.size()-q>0)
        return false;
    return true;
}

int main(){
    std::cout<<validShuffle("hello","obg","olbelgoh");
}