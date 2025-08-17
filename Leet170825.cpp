/* new 21 game
draw until points exceed k - while loop runs on this
draw in range of 1 to maxpts
prob(points<=n)
for k=1
    p=n/maxpts because any draw will satisfy k=1
for k=2
    either you get a 1 with probability 1/maxpts
    and then any value from 1 to n-1 with p(n-1/maxpts)
for any k
    we need probability that first draw is between 1 to k = d1
    second draw is between d1 to k
    third draw... and so on
    and the final draw is between dn to n so that total points remain less than n
maybe we need recursion?
for each first draw we call the function on the second draw with a different range?
to the main draw prob function we pass: maxpts, begin, end
and in the range of begin to end we call the function recursively as maxpts, i, end
yes definitely recursion

LOGIC, maxpts always passed, k is current value left to cover
n=begin-end for current throw

params: maxpts, points left, begin, end
base case: k==1
    return (end-begin)/maxpts

for throw 1: maxpts, k, 1, n //end always remains n
    prob=0
    for i in range(begin,end)
        prob+=((i-begin)/maxpts)*drawProb(maxpts, k-i,begin+i, n) 
    return prob


    can pass only n,k,maxpts so we can pass (n,k-i,maxpts)
    from this 
*/  

#include <iostream>
using std::cout;

double new21Game(int n, int k, int maxPts, int begin=1) {
    if(k<1)
        return 1;
    if(k==1){
        if(n+1-begin>=maxPts)
            return 1;
        return (double)((n+1-begin)/(double)maxPts);
    }
    double prob=0;
    for(int i=begin+1;i<=n+1;i++){
        if((i-begin)<=maxPts)
            prob+=(1/(double)maxPts)*new21Game(n,k-(i-begin),maxPts,i);
    }
    return prob;      
}

double new21Game2(int n, int k, int maxPts) {
    if(n<0)
        return 0;
    if(k<1)
        return 1;
    if(k==1){
        if(n>=maxPts)
            return 1;
        return (double)(n/(double)maxPts);
    }
    double prob=0;
    for(int i=1;i<=maxPts;i++){
        prob+=new21Game2(n-i,k-i,maxPts);
    }
    return prob*(1/(double)maxPts);      
}

double dynProgSol(int n, int k, int maxPts) {
    int lim=k+maxPts-1<n?k+maxPts-1:n;
    double* dp=new double[lim+1];
    double curr=1;double res=0;
    dp[0]=1;
    //probability of a score of i is getting i-1*1/maxpts+getting i-2*1/maxpts and so on
    //p of getting 0=1
    //of getting 1 is 1/maxpts ie dp[1-1]/maxpts
    //of getting 2 is dp[2-1]/maxpts+dp[2-2]/maxpts = dp[2-1](1+1/maxpts)
    //so curr should track: sum of last maxpts dps
    //at each iter add dp[i-1]
    //then update dp[i] as curr/maxpts
    //then subtract dp[k-maxpts] - current last
    for(int i=1;i<=lim;i++){
        dp[i]=curr/(double)maxPts;
        cout<<dp[i]<<" ";
        curr+=i<k?dp[i]:0;
        if(i>=maxPts)
            curr-=dp[i-maxPts];
        if(i>=k)
            res+=dp[i];
    }
    cout<<std::endl;
    return res;
}

int main(){
    cout<<dynProgSol(21,17,10);
}

