#include <iostream>
#include <vector>

using std::vector;

int smallestSubWithSum(int x, vector<int> arr) {
        int len=0,sum=arr[0],first=0;
        int l=0,r=1;
        while(r<arr.size()){
            sum+=arr[r];
            std::cout<<l<<" "<<r<<" "<<sum<<" "<<std::endl;
            if(sum>x){
                if(first==0){
                    len=r-l+1;first=1;
                }
                len=std::min(r-l+1,len);
                while(sum>x&&l<=r){
                    std::cout<<l<<" "<<r<<" "<<sum<<" "<<std::endl;
                    len=std::min(r-l+1,len);
                    sum-=arr[l];
                    l++;
                }
            }
            r++;
        }
        return len;
}

int main(){
    std::cout<<smallestSubWithSum(1,{0,1,10000});
}