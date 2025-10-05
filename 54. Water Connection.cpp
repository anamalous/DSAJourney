#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d){
    unordered_map<int,vector<int>> outpipe;
    vector<int> inpipe(n+1,0);
    vector<vector<int>> res;
    inpipe[0]=1;
    for(int i:b)
        inpipe[i]=1; //mark non-roots as 1
    for(int i=0;i<p;i++)
        outpipe[a[i]]={b[i],d[i]};

    for(int i=1;i<=p;i++){
        if(inpipe[i]==0){ //i is a source
            int tank=i,tap=outpipe[i][0],cap=outpipe[i][1];
            while(outpipe.count(tap)){
                cap=min(cap,outpipe[tap][1]);
                tap=outpipe[tap][0];
            }
            res.push_back({tank,tap,cap});
        }
    }
    cout<<res.size()<<endl;

    return res;
}

int main(){
    vector<vector<int>> r=solve(9,6,{7,5,4,2,9,3},{4,9,6,8,7,1},{98,72,10,22,17,66});
    for(auto p:r){
        for(auto i:p)
            cout<<i<<" ";
        cout<<endl;
    }
        
}