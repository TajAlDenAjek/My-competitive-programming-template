ll n,k;
ll const MOD=1e9+7;
ll fastPower(ll b,ll e,ll MOD)
{
    if(!e) return 1;
    ll res=fastPower(b,e/2,MOD)%MOD;res=(res*res)%MOD;
    if(e&1) return res=(res*b)%MOD;
    return res;
}


ll sumofGCD(ll n,ll k)
{
 
    vector<ll> count(k+1,0);
    for(ll g=k;g>=1;g--)
    {
        ll count_multiples=k/g;
        ll temp=fastPower(count_multiples,n,MOD);
        temp %=MOD;
        ll extra=0;
        for (ll j=g*2;j<=k;j+=g)
        {
            extra=(extra+count[j]);
            extra%=MOD;
        }
        count[g]=(temp-extra+MOD);
        count[g]%=MOD;
    }
    ll sum=0;
    ll add;
    for (ll i=1;i<=k;++i)
    {
        add=(count[i]%MOD*i%MOD);
        add%=MOD;
        sum+=add;
        sum%=MOD;
    }
    return sum;
}
