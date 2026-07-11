class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int &nodes, int &edges) {

        vis[node] = 1;
        nodes++;

        edges += adj[node].size();

        for(int it : adj[node]) {
            if(!vis[it])
                dfs(it, adj, vis, nodes, edges);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);

        int res = 0;

        for(int i = 0; i < n; i++) {

            if(!vis[i]) {

                int nodes = 0;
                int edge = 0;

                dfs(i, adj, vis, nodes, edge);

                edge = edge / 2;

                if(edge == nodes * (nodes - 1) / 2)
                    res++;
            }
        }

        return res;
    }
};