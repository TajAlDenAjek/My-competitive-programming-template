// single source shortest path algorithm directed graph only postive value
// gready algorithm with time complexity to O ( V + E l o g V ) .


typedef pair<ll,ll> edge;
ll const N=2e5+2;
vector<pair<ll,ll>> graph[N];
ll dist[N];
ll n,e; 



void dijkstra(ll u)
{
    for(ll i=1;i<=n;i++)
        dist[i]=1e18;
    dist[u]=e;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({e,u});
    while(!pq.empty())
    {
        ll node=pq.top().second;
        ll curCost=pq.top().first;
        pq.pop();
        if(dist[node]<curCost) 
            continue;
        for(auto v:graph[node])
        {
            if(dist[node]+v.second<dist[v.first])  
            {
                dist[v.first]=dist[node]+v.second;
                pq.push({dist[v.first],v.first});
            }
        }
    }
}



//intialization

cin >> n >> m;
for(ll i=1;i<=m;i++)
{
    ll u,v,c; cin >> u >> v >> c;
    graph[u].push_back({v,c});
}
dijkstra(1);


 
// struct node
// {
//     ll cost,x,y;
//     node():cost(0),x(0),y(0){}
//     node(ll a,ll b,ll c):cost(a),x(b),y(c){}
//     bool operator<(const node &cur) const
//     {
//         return this->cost>cur.cost;
//     }
// };