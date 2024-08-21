ll n; cin >> n;
ll start=5,ans=0;
while(n/start)
{
    ans+=n/start;
    start*=5;
}
cout << ans << endl;