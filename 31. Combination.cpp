#include <iostream>

int nCr(int n, int r) {
    if(r>n)
        return 0;
    int arr[n+1][r+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<=std::min(i,r);j++){
            if(j==i||j==0)
                arr[i][j]=1;
            else
                arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
    } 
    return arr[n][r];
}

int main(){
    std::cout<<nCr(10,2);
}