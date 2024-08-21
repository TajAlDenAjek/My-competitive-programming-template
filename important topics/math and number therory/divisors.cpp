vector<int> divisors(int x)
{
    vector<int> ans;
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            ans.push_back(i);
            if(i!=x/i)
            {
                ans.push_back(x/i);
            }
        }
    }
    return ans;
}

// long long
vector<ll> divisors(ll x)
{
    vector<ll> ans;
    for(ll i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            ans.push_back(i);
            if(i!=x/i)
            {
                ans.push_back(x/i);
            }
        }
    }
    return ans;
}