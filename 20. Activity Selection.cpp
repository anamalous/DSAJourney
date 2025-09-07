#include <vector>
#include <iostream>

using std::vector;

void swap(vector<int> arr,int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int maxMeetings(vector<int>& start, vector<int>& end) {
    int min=0;
    for(int i=0;i<end.size();i++){
        min=i;
        for(int j=i+1;j<end.size();j++){
            if(end[j]<end[min])
                min=j;
        }
        swap(end,min,i);
        swap(start,min,i);
    } 

    int currend=end[0],ctr=1;
    for(int i=1;i<start.size();i++){
        if(start[i]>currend){
            currend=end[i];
            ctr++;
        }
    }
    return ctr;
}

int main(){
    vector<int> start={1, 3, 0, 5, 8, 5};
    vector<int> end={2, 4, 6, 7, 9, 9};
    std::cout<<maxMeetings(start,end);
}