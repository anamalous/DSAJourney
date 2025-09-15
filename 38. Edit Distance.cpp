#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

int EditDistance(string s,string t){
    vector<vector<int>> dist(s.size()+1,vector<int>(t.size()+1,0));
    for(int i=0;i<s.size()+1;i++){
        dist[i][0]=i;
    }
    for(int j=0;j<t.size()+1;j++){
        dist[0][j]=j;
    }
    for(int i=1;i<s.size()+1;i++){
        for(int j=1;j<t.size()+1;j++){
            if(s[i-1]==t[j-1])
                dist[i][j]=dist[i-1][j-1];
            else    
                dist[i][j]=std::min(dist[i-1][j],std::min(dist[i][j-1],dist[i-1][j-1]))+1;
        }
    }
    return dist[s.size()][t.size()];
}

int main(){
    std::cout<<EditDistance("abcd","bcfe");
}