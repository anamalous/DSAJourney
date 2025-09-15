#include <vector>
#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::vector;

vector<string> powerset(string s){
    string res="";
    vector<string> ret;
    for(int i=0;i<pow(2,s.size());i++){
        res="";int curr=i;
        for(char c:s){
            if(curr<=0)
                break;
            if(curr%2==1)
                res+=c;
            curr/=2;
        }
        ret.push_back(res);
    }
    return ret;
}

vector<string> powerset2(string s){
    string res="";
    vector<string> ret;
    for(int i=0;i<pow(2,s.size());i++){
        res="";
        for(int j=0;j<s.size();j++)
            if(i>>j&1)
                res+=s[j];
        ret.push_back(res);
    }
    return ret;
}

int main(){
    for(auto s:powerset2("abcd")){
        std::cout<<s<<" ";
    }
}