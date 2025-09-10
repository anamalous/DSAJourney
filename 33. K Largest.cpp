#include <vector>
#include <iostream>

using std::vector;

vector<int> kLargest(vector<int> arr, int k) {
    vector<int> heap;
    int curr,temp;
    for(int i:arr){
        heap.push_back(i);
        curr=heap.size()-1;

        while(heap[curr]<heap[curr/2]){
            temp=heap[curr];
            heap[curr]=heap[curr/2];
            heap[curr/2]=temp;
            curr=curr/2;
        }   

        if(heap.size()>k){
            heap[0]=heap[heap.size()-1];
            heap.pop_back();

            curr=0;
            while(curr<heap.size()&&(heap[curr]>heap[2*curr]||heap[curr]>heap[2*curr+1])){
                if(heap[2*curr]<heap[2*curr+1]){
                    temp=heap[curr];
                    heap[curr]=heap[2*curr];
                    heap[2*curr]=temp;
                    curr=2*curr;
                }
                else{
                    temp=heap[curr];
                    heap[curr]=heap[2*curr+1];
                    heap[2*curr+1]=temp;
                    curr=2*curr+1;
                }
                
            }
        }
    }
    return heap;
}

int main(){
    for(int i:kLargest({10,4,12,787,1,23},2))
        std::cout<<i<<" ";
}