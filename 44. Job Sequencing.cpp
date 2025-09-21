#include <vector>
#include <iostream>

using std::vector;

int jobSeq(vector<int> deadlines,vector<int> profit){
    int prof=0,temp=0;;
    for(int i=0;i<deadlines.size();i++){
        for(int j=i+1;j<deadlines.size();j++){
            if(profit[j]>profit[i]){
                temp=deadlines[i];
                deadlines[i]=deadlines[j];
                deadlines[j]=temp;

                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;
            }
        }
    }
    vector<int> slots(deadlines.size(),-1);
    for(int i=0;i<profit.size();i++){
        for(int j=deadlines[i]-1;j>=0;j--){
            if(slots[j]==-1){
                slots[j]=i;
                prof+=profit[i];
                break;
            }
        }
    }
}

int main(){
    std::cout<<jobSeq({2,1,2,1,1},{100,19,27,25,15});
}