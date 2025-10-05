#include <vector>
#include <iostream>

using namespace std;

vector<int> findTwoElement(vector<int> arr) {
    int n=arr.size();
    int sum=0,sqsum=0;
    for(int i:arr){
        sum+=i;
        sqsum+=i*i;
    }
    int minus=sum-(n*(n+1))/2;
    int plus=sqsum-(n*(n+1)*(2*n+1))/6;
    plus/=minus;

    return {(plus+minus)/2,(plus-minus)/2};
}

int main(){
    for(auto i:findTwoElement({4,3,6,2,1,1}))
        cout<<i<<" ";
}