#include <vector>
#include <iostream>
using std::vector;

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int unplaced=0;
    for(int i=0;i<fruits.size();i++){
        int j; int found=0;
        for(j=0;j<baskets.size();j++){
            if(baskets[j]>=fruits[i]){
                baskets.erase(baskets.begin()+j);
                found=1;
                break;
            }
        }
        if(found==0){
            unplaced++;
        }
    }
    return unplaced;     
}

int main(){
    vector<int> f={4};
    vector<int> b={4};
    std::cout<<numOfUnplacedFruits(f,b);
    return 0;
}