#include <vector>
#include <iostream>

using std::vector;

bool binSearch(vector<int>& arr,int elem){
    int f=0,l=arr.size()-1,mid=f+(l-f)/2;
    while(f<=l){
        if(elem<arr[mid])
            l=mid-1;
        if(elem>arr[mid])
            f=mid+1;
        if(elem==arr[mid])
            return true;
        mid=f+(l-f)/2;
    }
    return false;
}
bool searchMat(vector<vector<int>> mat, int elem){
    if(mat.size()==1)
        return binSearch(mat[0],elem);
    int i;
    for(i=0;i<mat.size()-1;i++){
        if(elem>=mat[i][0]&&elem<mat[i+1][0])
            break;
    }
    return binSearch(mat[i],elem);
}

int main(){
    vector<vector<int>> a={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    std::cout<<searchMat({{1},{3}},3);

}