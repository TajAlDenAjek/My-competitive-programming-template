//Bottom up
vector<int> topSort(const vector<vector<int>> &graph)
{
    int n=graph.size();
    vector<int> inDegree(n,0);
    vector<int> sortedNodes;
    for(int i=0;i<n;i++)
    {
        for(auto j:graph[i])
        {
            inDegree[j]++;
        }
    }
    for(int i=0;i<n;i++) if(inDegree[i]==0)
        sortedNodes.push_back(i);
    int cur=0;
    while(cur<sortedNodes.size())
    {
        int node=sortedNodes[cur];
        cur++;

        for(auto v:graph[node])
        {
            if(--inDegree[v]==0)
                sortedNodes.push_back(v);
        }
    }
    return sortedNodes;
}


// top Down

ll const N=1e5+2;
int visited[N];
vector<ll> graph[N],topSort;
ll n,m;
bool haveCycle=false;

void dfs(ll u)
{
    visited[u]=1;
    if(haveCycle)
        return;
    for(auto v:graph[u])
    {
        if(visited[v]==0)
        {
            dfs(v);
            if(haveCycle)
                return;
        }
        else if(visited[v]==1)
        {
            haveCycle=true;
            return;
        }
    }
    topSort.push_back(u);
    visited[u]=2;
}

// don't forget to reverse the top sort vector