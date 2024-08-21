ll const N=2e5+2;
ll parent[N],weight[N];

void init(ll n)
{
    for(ll i=1;i<=n;i++)
        parent[i]=i,weight[i]=0;
}
ll root(ll i)
{
    if(parent[i]==i)
        return i;
    ll r=root(parent[i]);
    weight[i]=weight[parent[i]]+weight[i];
    return parent[i]=r;
}
bool Union(ll a,ll b,ll x)
{
    ll A=root(a);
    ll B=root(b);
    if(A==B)
        return (weight[b]-weight[a]==x);
    parent[A]=B;
    weight[A]=weight[b]-weight[a]-x;
    return true;
}

/*
    ll n,q; 
    cin >> n >> q;
    init(n);
    for(ll i=1;i<=q;i++)
    {
        ll a,b,d;
        cin >> a >> b >> d;
        if(Union(a,b,d))
            cout << i << " ";
    }
    */