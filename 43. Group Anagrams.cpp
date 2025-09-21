#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;
using std::unordered_map;

vector<vector<string>> groupAna(vector<string> strs){
    unordered_map<string,vector<string>> groups;
    vector<vector<string>> res;
    for(string s:strs){
        string copy=s;
        std::sort(copy.begin(),copy.end());
        if(groups.count(copy))
            groups[copy].push_back(s);
        else    
            groups[copy]={s};
    }
    for(auto pair:groups){
        res.push_back(pair.second);
    }
    return res;
}

int main(){
    for(auto ana:groupAna({"act", "god", "cat", "dog", "tac"})){
        for(auto s:ana)
            std::cout<<s<<" ";
        std::cout<<std::endl;
    }
}