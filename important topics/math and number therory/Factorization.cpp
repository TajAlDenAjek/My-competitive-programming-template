vector <ll> Factorization(ll x)  
{
    vector<ll> v;
    for(ll i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            x/=i;
            v.push_back(i);
        }
    }
    if(x>1)
        v.push_back(x);
    return v;
}