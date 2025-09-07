#include <iostream>
#include <vector>

using std::vector;

void travMatrix(vector<vector<int>> mat){
    int top=0,bottom=mat.size()-1,left=0,right=mat[0].size()-1;
    while(top<=bottom&&left<=right){
        for(int i=left;i<=right;i++)
            std::cout<<mat[top][i]<<" ";
        top++;
        for(int i=top;i<=bottom;i++)
            std::cout<<mat[i][right]<<" ";
        right--;
        for(int i=right;i>=left;i--)
            std::cout<<mat[bottom][i]<<" ";   
        bottom--;
        for(int i=bottom;i>=top;i--)
            std::cout<<mat[i][left]<<" ";
        left++;
    }
}
int main(){
    vector<vector<int>> n={{1,2,3,4},{5,6,3,2},{3,5,7,9}};
    travMatrix(n);
}