ll const MOD=1e9+7;
ll fastPower(ll b,ll e,ll MOD)
{
    if(!e) return 1;
    ll res=fastPower(b,e/2,MOD)%MOD;res=(res*res)%MOD;
    if(e&1) return res=(res*b)%MOD;
    return res;
}



ll fastPower(ll b,ll e)
{
    if(!e) return 1;
    ll res=fastPower(b,e/2);res=(res*res);
    if(e&1) return res=(res*b);
    return res;
}