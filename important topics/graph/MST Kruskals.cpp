ll const N=2e5+2;
struct Edge
{
    ll u,v,c;
    Edge(){}
    Edge(ll U,ll V,ll C):u(U),v(V),c(C){}
};
bool comp(Edge &f,Edge &s)
{
    return f.c<s.c;
}

vector<Edge> edges;
ll p[N];
ll n,m,MST,numberOfEdges;
 
void init()
{
    for(ll i=1;i<=n;i++)
    {
        p[i]=i;
    }
}
 
ll findp(ll u)
{
    if(p[u]==u)
        return u;
    return p[u]=findp(p[u]);
}
 
bool Union(ll u,ll v)
{
    ll x=findp(u);
    ll y=findp(v);
    if(x!=y)
    {
        p[x]=y;
        return true;
    }
    return false;
}
void Kruskals()
{
    sort(edges.begin(),edges.end(),comp);
    init();
    for(auto i:edges)
    {
        if(Union(i.u,i.v))
        {
            numberOfEdges--;
            MST+=i.c;
        }
    }
}