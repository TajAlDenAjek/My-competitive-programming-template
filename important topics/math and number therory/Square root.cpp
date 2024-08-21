Square root 

ll squareRoot(ll x)
{
    ll ans=0,l=1,r=1e9;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(mid*mid<=x)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}