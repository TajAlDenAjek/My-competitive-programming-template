ll const N=1e5+2;
set<ll> graph[N];
ll inDegree[N],outDegree[N];
vector<ll> track;
bool visited[N];


void dfs(ll u)
{
    visited[u]=true;
    while(!graph[u].empty())
    {
        ll v=*(graph[u].begin());
        graph[u].erase(v);
        dfs(v);
    }
    track.push_back(u);
}

ll n,m;



void Hierholzer(ll u)
{
    stack<ll> s;
    s.push(u);
    while(!s.empty())
    {
        ll u=s.top();
        if(!graph[u].empty())
        {
            ll v=graph[u].back();
            graph[u].pop_back();
            s.push(v);
        }
        else
        {
            path.push_back(u);
            s.pop();
        }
    }
}






    // cin >> n >> m;
    // for(ll i=0;i<m;i++)
    // {
    //     ll a,b;
    //     cin >> a >> b;
    //     graph[a].insert(b);
    //     outDegree[a]++;
    //     inDegree[b]++;
    // }
    // ll start=0,end=0,others=0,startingNode,endingNode;
    // for(ll i=1;i<=n;i++)
    // {
    //     if(outDegree[i]==inDegree[i])
    //         others++;
    //     else if(inDegree[i]-outDegree[i]==1)
    //     {
    //         endingNode=i;
    //         end++;
    //     }
    //     else if(outDegree[i]-inDegree[i]==1)
    //     {
    //         startingNode=i;
    //         start++;
    //     }
    // }
    // bool ok=true;
    // ok&=(end==1&&start==1&&others==(n-2));
    // if(!ok)
    // {
    //     cout << "IMPOSSIBLE" << endl;
    //     return 0;        
    // }