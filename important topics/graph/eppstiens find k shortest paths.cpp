ll const N=1e5+2;
vector<pair<ll,ll>> graph[N];
ll cnt[N];
vector<ll> ans;
ll n,m,k;
typedef pair<ll,ll> edge;
void dijkstra(ll u)
{
    // cost, node
    priority_queue<edge,vector<edge>,greater<edge>> pq;
    pq.push({0,u});
    vector<ll> dist(n+2,1e18);
    dist[1]=0;
    while(cnt[n]<k)
    {
        ll node=pq.top().second;
        ll cost=pq.top().first;
        pq.pop();
        if(cnt[node]==k)
            continue;
        cnt[node]++;
        if(node==n)
            ans.push_back(cost);
        for(auto [to,newCost]:graph[node])
        {
            pq.push({cost+newCost,to});
        }
    }
}