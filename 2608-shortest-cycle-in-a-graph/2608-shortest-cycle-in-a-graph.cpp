class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MAX;

        for(int s = 0; s < n; s++){

            vector<int> dist(n,-1);
            queue<pair<int,int>> q;

            q.push({s,-1});
            dist[s] = 0;

            while(!q.empty()){

                auto [u,p] = q.front();
                q.pop();

                for(int v : adj[u]){

                    if(dist[v] == -1){
                        dist[v] = dist[u] + 1;
                        q.push({v,u});
                    }
                    else if(v != p){
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};