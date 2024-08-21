//Noob version
void compress(ll n)
{
    map<ll,ll> m;
    vector<ll> v;
    for(ll i=1;i<=n;i++)
        v.push_back(arr[i]);
    sort(v.begin(),v.end());
    ll cnt=1;
    for(auto i:v)
    {
        if(m.count(i))
        {
            continue;
        }
        else
        {
            m[i]=cnt;
            cnt++;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        arr[i]=m[arr[i]];
    }
}