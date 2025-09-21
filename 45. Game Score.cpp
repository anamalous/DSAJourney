#include <vector>
#include <iostream>

using std::vector;

long long int count(long long int n) {
    vector<int> moves={3,5,10};
    vector<int> scores(n+1,0);
    scores[0]=1;
    for(int i:moves)
        for(int j=i;j<=n;j++)
            scores[j]+=scores[j-i];
    return scores[n];
}

int main(){
    std::cout<<count(10);
}