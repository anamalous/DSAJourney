#include <unordered_map>
#include <string>
#include <algorithm>

using std::unordered_map;
using std::string;
unordered_map<char,int> freqCount(string s){
    std::sort(s.begin(),s.end());int curr=1,ctr=1;char currchar=s[0];
    unordered_map<char,int> res;
    while(curr<s.length()){
        if(s[curr]!=currchar){
            if(ctr>1)
                res[currchar]=ctr;
            ctr=1;currchar=s[curr];
        }
        else
            ctr++;
        curr++;
    }
    return res;
}

