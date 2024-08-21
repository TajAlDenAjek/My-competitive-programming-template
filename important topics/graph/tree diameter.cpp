ll const N=2e5+2;
vector<ll> tree[N];
ll n;
pair<ll,ll> dfs(ll u,ll p)
{
    ll ans=0;
    ll node=u;
    dist[node]=ans;
    for(auto v:tree[u])
    {
        if(v!=p)
        {
            pair<ll,ll> temp=dfs(v,u);
            temp.first+=1;
            if(ans<temp.first)
            {
                ans=temp.first;
                node=temp.second;
            }
        }
    }
    return {ans,node};
}
ll diameter(ll u,ll p)
{
    ll node=dfs(u,p).second;
    return dfs(node,p).first;
}