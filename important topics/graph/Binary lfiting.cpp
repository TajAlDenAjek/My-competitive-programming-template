
ll const N=2e5+2;
ll const MAX_JUMPS=30; // (ll)log2(1e9);

ll parent[N][MAX_JUMPS];

ll jump(ll a,ll b)
{
    if(b<=0)
        return a;
    for(ll i=0;i<MAX_JUMPS;i++)
    {
        if(b&(1<<i))
            a=parent[a][i];
    }
    return a;
}




    ll n,q; 
    cin >> n >> q;
    // intiliaze with first parent
    for(ll i=1;i<=n;i++)
    {
        cin >> parent[i][0];
    }
    // jump 30 jumps and store the new parenet in the ith jump
    for(ll d=1;d<MAX_JUMPS;d++)
    {
        for(ll i=1;i<=n;i++)
        {
            parent[i][d]=parent[parent[i][d-1]][d-1];
        }
    }
    while(q--)
    {
        ll a,b;
        cin >> a >> b;
        cout << jump(a,b) << endl;
    }