
// disjoint set Union
// time complexity O(N);
ll const N=1e5+2;
ll p[N];
ll n,m;
 
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
 
void Union(ll u,ll v)
{
    ll x=findp(u);
    ll y=findp(v);
    if(x!=y)
        p[x]=y;
}
 


// intiliazation 

cin >> n >> m;
init();
for(ll i=1;i<=m;i++)
{
    ll a,b; cin >> a >> b;
    Union(a,b);
}



// with size optimization


ll const N=1e5+2;
ll p[N];
ll sz[N];
ll n,m;
 
void init()
{
    for(ll i=1;i<=n;i++)
    {
        p[i]=i;
        sz[i]=1;
    }
}
 
ll findp(ll u)
{
    if(p[u]==u)
        return u;
    return p[u]=findp(p[u]);
}
 
void Union(ll u,ll v)
{
    ll x=findp(u);
    ll y=findp(v);
    if(x!=y)
    {
        if(sz[x]>sz[y])
            swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        sz[x]=0;
    }
}
