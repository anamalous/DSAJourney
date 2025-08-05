//pluck fruits on the X-axis with k steps from startPos
#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

int stepCount(int l, int r, int startpos){
        if(r>=startpos&&l<=startpos){
            return std::min((startpos-l)+(r-l),(r-startpos)+(r-l));
        }
        else{
            return std::max(r-startpos,startpos-l);
        }
    }
int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int l=0, r=0;
        int currfruit=0,maxfruit=0;
        while(r<=fruits.size()-1){
            currfruit+=fruits[r][1];
            while(stepCount(fruits[l][0],fruits[r][0],startPos)>k&&l<r){
                currfruit-=fruits[l][1];
                l+=1;
            }
            if(stepCount(fruits[l][0],fruits[r][0],startPos)<=k&&currfruit>maxfruit){
                maxfruit=currfruit;
            }
            r+=1;
        }
        return maxfruit;
}
        
int main(){
    vector<vector<int>> f={{2,8},{6,3},{8,6}};
    //vector<vector<int>> f={{0,9},{4,1},{5,7},{6,2},{7,4},{10,9}};
    //vector<vector<int>> f={{0,3},{6,4},{8,5}};
    //vector<vector<int>> f={{2000,10000}};
    int fruits=maxTotalFruits(f,5,4);
    std::cout<<fruits;
}