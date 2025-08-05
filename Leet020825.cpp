//fruit exchange to make baskets equal
#include<iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::vector;
using std::map;

void printvect(vector<int> v){
    for(int i:v){
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;
}

//vectors preferred: dynamic size, self-manage memory
long long minCost(vector<int>& basket1, vector<int>& basket2) {//long long: at least 64 bit
    if(basket1.size()!=basket2.size())
        return -1; //if not of equal size - swaps will solve nothing
    map<int,int> freq;

    int min=basket1[0];
    for(int i=0;i<basket1.size();i++){
        freq[basket1[i]]++;
        freq[basket2[i]]++;
    }//create a frequency map

    for(const auto& pair:freq){
        min=std::min(pair.first,min);
        
        if(pair.second%2!=0)
            return -1; //if elements not in pairs - cannot be divided
        else
            freq[pair.first]=pair.second/2; //this is how many should be in each basket
    }

    map<int,int> freq1=freq;
    vector<int> surp1, surp2;

    for(int i=0;i<basket1.size();i++){
        if(freq[basket1[i]]==0)
            surp1.push_back(basket1[i]); //surplus over the half expected
        else
            freq[basket1[i]]--; //otherwise decrease permitted remaining count
        if(freq1[basket2[i]]==0)
            surp2.push_back(basket2[i]);
        else
            freq1[basket2[i]]--;
    }

    std::sort(surp1.begin(),surp1.end()); //for greedy backward approach
    std::sort(surp2.begin(),surp2.end());

    long long totalcost=0;
    int mincost=min*2;

    for(int i=surp1.size()-1;i>=0;i--){
        int directcost=std::min(surp1[i],surp2[i]);
        totalcost+=std::min(directcost,mincost);
    }

    return totalcost;
}

int main(){
    vector<int> v1={4,4,3,1,1};
    vector<int> v2={2,2,3,5,5};
    int m=minCost(v1,v2);
    std::cout<<"min cost:"<<m<<std::endl;
    return 0;
}
