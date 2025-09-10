#include <iostream>
#include <vector>

using std::vector;

int medOfSort(vector<int> a1,vector<int> a2){
    int size=a1.size()+a2.size(),oddeve=size%2,ctr=0;
    int p1=0,p2=0,wait=0,med=0,curr=0;
    while(true){
        if(a1[p1]<a2[p2]){
            curr=a1[p1];
            p1++;ctr++;
        }
        else{
            curr=a2[p2];
            p2++;ctr++;
        }
        if(ctr>=size/2){
            if(wait==0){
                if(oddeve==0){
                    med+=curr;
                }
                wait=1;
            }
            else{
                if(oddeve==0)
                    return (med+curr)/2;
                else    
                    return curr;
            }
        }
    }
}

int main(){
    vector<int> a={-5, 3, 6, 12, 15},b={-12, -10, -6, -3, 4, 10};
    std::cout<<medOfSort(a,b);
}