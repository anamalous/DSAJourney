#include <vector>
#include <iostream>
using std::vector;
int totalFruit(vector<int>& fruits){
    int l=0,r=0,f1=0,f2=0,currfruit=0,maxfruit=0,recent=0;
    while(r<fruits.size()){
        if(fruits[r]==fruits[f1]||fruits[r]==fruits[f2]||(f1==f2&&fruits[r]!=fruits[f1])){
            currfruit++;
            if(f1==f2&&fruits[r]!=fruits[f1])
                f2=r;
        }
        //update recent to r if fruits[r]!=fruits[recent]
        if(l<r&&fruits[r]!=fruits[f1]&&fruits[r]!=fruits[f2]){
            currfruit-=(recent-l-1);
            l=recent; 
            if(fruits[f1]==fruits[recent]){
                f2=r;
            }
            if(fruits[f2]==fruits[recent]){
                f1=r;
            }
        }
        if(fruits[r]!=fruits[recent]){
                recent=r;
        }
        if(currfruit>maxfruit)
            maxfruit=currfruit;
        std::cout<<l<<"\t"<<r<<"\t"<<f1<<"\t"<<f2<<"\t"<<recent<<"\t"<<currfruit<<std::endl;
        r++;
    }
    return maxfruit;
}

int main(){
    vector<int> fruits={1,2,2,1,3,2,2};
    //vector<int> fruits={0,1,2,2};
    //vector<int> fruits={1,2,1};
    //vector<int> fruits={1,0,3,4,3};
    std::cout<<totalFruit(fruits)<<std::endl;
    return 0;
}