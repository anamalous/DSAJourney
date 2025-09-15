#include <vector>

using std::vector;

vector<int> bfs(vector<vector<int>> &adj) {
    vector<int> queue;
    vector<int> res;
    queue.push_back(0);int ctr=0,curr=0;
    while(ctr<queue.size()){
        curr=queue[ctr];
        res.push_back(curr);
        for(int neighbour:adj[curr])
            queue.push_back(neighbour);
        ctr++;
    }
    return res;
}