ll const N=5e2+2;
ll capacity[N][N];
vector<ll> graph[N];

ll fordFulkerson(ll source,ll sink)
{
    ll flow=0;
    bool thereIsPath=true;
    while(thereIsPath)
    {
        // start bfs search for path from source to sink
        vector<ll> parent(sink+1,-1);
        queue<ll> q;
        q.push(source);
        while(!q.empty())
        {
            ll node=q.front();
            q.pop();
            for(auto v:graph[node])
            {
                if(parent[v]==-1&&capacity[node][v]>0)
                {
                    parent[v]=node;
                    q.push(v);
                }
            }
        }
        if(parent[sink]==-1)
        {
            thereIsPath=false;
            break;
        }
        // we have the path 
        ll minCapacity=1e18;
        for(ll v=sink;v!=source;v=parent[v])
        {
            ll node=parent[v];
            minCapacity=min(minCapacity,capacity[node][v]);
        }
        for(ll v=sink;v!=source;v=parent[v])
        {
            ll node=parent[v];
            capacity[node][v]-=minCapacity;
            capacity[v][node]+=minCapacity;            
        }
        flow+=minCapacity;
    }
    return flow;
}


    // ll n,m;
    // cin >> n >> m;
    // for(ll i=1;i<=m;i++)
    // {
    //     ll a,b,c;
    //     cin >> a >> b >> c;
    //     graph[a].push_back(b);
    //     capacity[a][b]+=c;
    //     // reversed edge to get the original capacity
    //     graph[b].push_back(a);
    //     capacity[b][a]=0;
    // }
    // cout << fordFulkerson(1,n) << endl;