ll const N=2e5+2;
set<ll> graph[N];
vector<ll> track;
bool visited[N];


void dfs(ll u)
{
    visited[u]=true;
    while(!graph[u].empty())
    {
        ll v=*(graph[u].begin());
        graph[u].erase(v);
        graph[v].erase(u);
        dfs(v);
    }
    track.push_back(u);
}


bool hasEulerCycle(ll n)
{
    for(ll i=1;i<=n;i++)
    {
        if(graph[i].size()%2)
            return false;
    }
    dfs(1);
    for(ll i=1;i<=n;i++)
    {
        if(!visited[i]&&graph[i].size())
        {
            return false;
        }
    }
    return true;
}
    ll n,m;
    cin >> n >> m;
    for(ll i=0;i<m;i++)
    {
        ll a,b; 
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    if(hasEulerCycle(n))
    {
        for(auto i:track)
            cout << i << " ";
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }