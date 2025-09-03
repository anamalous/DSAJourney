#include <vector>
#include <iostream>
#include <cstdint>


using std::vector;

int getMinDiff(vector<int> heights,int k){
    int min=INT32_MAX;int max=0;
    double mean=0;
    for(int h:heights)
        mean+=h;
    mean=(double)mean/heights.size();
    for(int i=0;i<heights.size();i++){
        if(heights[i]<k){
            heights[i]+=k;
        }
        else if(heights[i]<mean){
            heights[i]+=k;
        }
        else{
            heights[i]-=k;
        }
        min=std::min(min,heights[i]);
        max=std::max(max,heights[i]);
    }
    return (max-min);
}

int getMinDiffSort(vector<int> heights, int k){
    int min=0,temp=0,max=0;
    for(int i=0;i<heights.size();i++){
        min=i;
        for(int j=i;j<heights.size();j++){
            min=heights[j]<heights[min]?j:min;
        }
        temp=heights[min];
        heights[min]=heights[i];
        heights[i]=temp;
    } //sorted
    for(int i:heights){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    int diff=heights[heights.size()-1]-heights[0];
    int last=heights.size()-1;
    for(int i=1;i<heights.size();i++){
        if(heights[i]<k)
            continue;
        max=std::max(heights[last]-k,heights[i-1]+k);
        min=std::min(heights[0]+k,heights[i]<k?heights[i]+k:heights[i]-k);
        std::cout<<i<<" "<<max<<" "<<min<<" "<<max-min<<std::endl;
        diff=std::min(diff,max-min);
    }
    return diff;
}

int main(){
    vector<int> hei={1,8,10,6,4,6,9,1};
    std::cout<<getMinDiffSort(hei,7);
}