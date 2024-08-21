ll t; cin >> t;
    while(t--)
    {
        ll l=2,r=999;
        ll ans=0;
        while(l<=r)
        {
            ll mid1=l+(r-l)/3;
            ll mid2=r-(r-l)/3;
            cout << "? " << mid1 << " " << mid2 << endlflush;
            ll x;
            cin >> x;
            if(mid1*mid2==x)
            {
                l=mid2+1;
            }
            else if(mid1*(mid2+1)==x)
            {
                ans=mid2;
                l=mid1+1;
                r=mid2-1;
            }
            else
            {
                ans=mid1;
                r=mid1-1;
            }
        }
        cout << "! " << ans << endlflush;
    }