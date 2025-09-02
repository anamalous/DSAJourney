#include <iostream>
#include <vector>
using std::vector;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merge;
    int p1=0,p2=0;
    while(p1<nums1.size()&&p2<nums2.size()){
        if(nums1[p1]<=nums2[p2]){
            merge.push_back(nums1[p1]);
            p1++;
        }
        else{
            merge.push_back(nums2[p2]);
            p2++;
        }
    }
    while(p1<nums1.size()){
        merge.push_back(nums1[p1]);
        p1++;
    }
    while(p2<nums2.size()){
        merge.push_back(nums2[p2]);
        p2++;
    }
    if(merge.size()%2==0)
        return (double)(merge[(merge.size()/2)-1]+merge[merge.size()/2])/2;
    else
        return merge[(merge.size()+1)/2-1];   

}

int main(){
    vector<int> n1={1,3};
    vector<int> n2={2,4};
    std::cout<<findMedianSortedArrays(n1,n2);
}