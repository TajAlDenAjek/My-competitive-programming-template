// time complexity O(n*m);
// detect cycle and print it
ll n,m; 
struct edge
{
    ll from,to,w;
    edge(ll a,ll b,ll c):from(a),to(b),w(c){}
};
ll inf=1e18;
ll ninf=-1e18;
 
void Bellman_ford(vector<edge> &edgeList,ll n,ll from)
{
    vector<ll> dist(n+1,inf),p(n+1,-1);
    dist[from]=0;
    ll lastNode=0;
    for(ll max_edges=0;max_edges<n;max_edges++)
    {
        lastNode=0;
        for(auto e:edgeList)
        {
            ll u=e.from,v=e.to,w=e.w;            
            if(dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                p[v]=u;
                lastNode=v;
            }
        }
    }
    if(!lastNode)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for(ll i=1;i<=n;i++)
            lastNode=p[lastNode];
        vector<ll> cycle;
        ll temp=lastNode;
        while(true)
        {
            cycle.push_back(temp);
            if(temp==lastNode&&cycle.size()>1)
                break;
            temp=p[temp];
        }
        reverse(cycle.begin(),cycle.end());
        for(auto i:cycle)
            cout << i << " ";
    }
}

//***************************************************

ll n,m; 
struct edge
{
    ll from,to,w;
    edge(ll a,ll b,ll c):from(a),to(b),w(c){}
};
ll inf=1e18;
ll ninf=-1e18;

void Bellman_ford(vector<edge> &edgeList,ll n,ll from)
{
    vector<ll> dist(n+1,inf);
    dist[from]=0;
    for(ll max_edges=0;max_edges<n;max_edges++)
    {
        for(auto e:edgeList)
        {
			ll u=e.from,v=e.to,w=e.w;            
            if(dist[u]==inf)
            	continue;
            dist[v]=min(dist[v],dist[u]+w);
        }
    }
}
//******************************************************
ll Bellman_ford(vector<edge> &edgeList,ll n,ll from)
{
    vector<ll> dist(n+1,inf);
    dist[from]=0;
    for(ll max_edges=0;max_edges<n;max_edges++)
    {
        for(auto e:edgeList)
        {
            ll u=e.from,v=e.to,w=e.w;            
            if(dist[u]==inf)
                continue;
            dist[v]=min(dist[v],dist[u]+w);
        }
    }
    for(ll max_edges=0;max_edges<n;max_edges++)
    {
        for(auto e:edgeList)
        {
            ll u=e.from,v=e.to,w=e.w;            
            if(dist[u]==inf)
                continue;
            if(dist[v]>dist[u]+w)
                dist[v]=ninf;
        }
    }
    return (dist[n]!=inf&&dist[n]!=ninf?-1*dist[n]:-1);
}