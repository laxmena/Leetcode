class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        if(queries.size() == 0)
            return {};
        
        vector<vector<int>> adj(n);
        for(auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<bool> res;
        for(int i=0; i<queries.size(); i++)
        {
            vector<bool> visited(n, false);
            res.push_back(dfs(queries[i][0], queries[i][1], adj, visited));
        }
        
        return res;
    }
    
    bool dfs(int src, int dest, vector<vector<int>>& adj, vector<bool>& visited)
    {
        if(src == dest)
            return true;
        if(visited[src])
            return false;
        
        visited[src] = true;
        for(auto neigh : adj[src])
        {
            if(!visited[neigh])
            {
                if(dfs(neigh, dest, adj, visited))
                    return true;
            }
        }
        
        return false;
    }
};