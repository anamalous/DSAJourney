#include <vector>
#include <iostream>

using std::vector;

vector<int> kLargest(vector<int> arr, int k) {
    vector<int> heap;
    int curr,temp;
    for(int i:arr){
        heap.push_back(i);
        curr=heap.size()-1;

        while(heap.size()>1&&heap[curr]<heap[(curr-1)/2]){
            temp=heap[curr];
            heap[curr]=heap[(curr-1)/2];
            heap[(curr-1)/2]=temp;
            curr=(curr-1)/2;
        }   

        if(heap.size()>k){
            heap[0]=heap[heap.size()-1];
            heap.pop_back();

            curr=0;
            int currchild=heap[2*curr+1]<heap[2*curr+2]?2*curr+1:2*curr+2;
            while(curr<heap.size()&&(heap[curr]>heap[currchild])){
                temp=heap[curr];
                heap[curr]=heap[currchild];
                heap[currchild]=temp;
                curr=currchild;
                currchild=heap[2*curr+1]<heap[2*curr+2]?2*curr+1:2*curr+2;
            }
        }
    }
    return heap;
}

int main(){
    for(int i:kLargest({10,4,12,787,1,23},2))
        std::cout<<i<<" ";
}