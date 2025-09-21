#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
bool wordBreak(string s,vector<string> dict,unordered_map<string,string>& memo){
    if(s.size()==0)
        return true;
    string curr,next;memo[""]="";
    for(int i=0;i<s.size();i++){
        curr=s.substr(0,i+1);
        if(find(dict.begin(),dict.end(),curr)!=dict.end()){
            memo[s]=curr;
            next=s.substr(i+1,s.size()-i+1);
            if(wordBreak(next,dict,memo)){
                memo[s]+=" "+memo[next];
                return true;
            }
        }
    }
    return false;
}

int main(){
    unordered_map<string,string> m;
    string s="catsanddogs";
    wordBreak(s,{"cats","and","donkey","dogs"},m);
    cout<<m[s];
}