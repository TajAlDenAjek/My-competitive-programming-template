ll const N=1e6+2;
ll smallestPrime[N];
void sieve()
{
    smallestPrime[1]=1;
    for(ll i=2;i<N;i++)
        smallestPrime[i]=i;
    for(ll i=4;i<N;i+=2)
        smallestPrime[i]=2;
    for(ll i=3;i*i<N;i++)
    {
        if(smallestPrime[i]==i)
        {
            for(ll j=i*i;j<N;j+=i)
            {
                if(smallestPrime[j]==j)
                    smallestPrime[j]=i;
            }
        }
    }
}
vector<ll> getFactorization(ll x)
{
    vector<ll> factors;
    while(x!=1)
    {
        factors.push_back(smallestPrime[x]);
        x/=smallestPrime[x];
    }
    return factors;
}

ll numberOfDivisors(ll x)
{
    ll ans=1,cnt=0,last=smallestPrime[x];
    while(x!=1)
    {
        if(last!=smallestPrime[x])
        {
            ans*=(cnt+1);
            cnt=1;
            last=smallestPrime[x];
        }
        else
            cnt++;
        x/=smallestPrime[x];
    }
    ans*=(cnt+1);
    return ans;
}