bool dfs(int u,vector<int> &visited,const vector<vector<int>> &graph)
{
    visited[u]=1;
    for(auto v:graph[u])
    {
        if(!visited[v])
        {
            bool ok=dfs(v,visited,graph);
            if(ok)
                return true;
        }
        else if(visited[v]==1)
        {
            return true;
        }
    }
    visited[u]=2;
    return false;
}

bool detectCycle(const vector<vector<int>> &graph)
{
    int n=graph.size();
    vector<int> visited;
    visited.resize(n);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bool haveCycle=dfs(i,visited,graph);
            if(haveCycle)
                return true;
        }
    }
    return false;
}