ll fastPower(ll b,ll e,ll MOD)
{
    if(!e) return 1;
    ll res=fastPower(b,e/2,MOD)%MOD;res=(res*res)%MOD;
    if(e&1) return res=(res*b)%MOD;
    return res;
}
ll sumOfDivisors(ll x,ll MOD)
{
    map<ll,ll> primeFactors;
    for(ll i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            x/=i;
            primeFactors[i]++;
        }
    }
    if(x>1)
        primeFactors[x]++;
    ll ans=1;
    for(auto i:primeFactors)
    {
        ans*=(fastPower(i.first,(i.second+1),MOD)-1);
        ans/=(i.first-1);
        ans%=MOD;
    }
    return ans;
}