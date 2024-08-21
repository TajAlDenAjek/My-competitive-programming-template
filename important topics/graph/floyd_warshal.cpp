// all pair shortest path problems directed graphs postive and negative cost
// time complexity O(n^3);
// code
ll const N=5e2+2;
ll dist[N][N];
ll n,m;
 
void floyd_warshall()
{
    for(ll k=1;k<=n;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}



//intilization

cin >> n >> m ;
for(ll i=1;i<=n;i++)
    for(ll j=1;j<=n;j++)
        dist[i][j]=(i==j?0:1e15);
for(ll i=1;i<=m;i++)
{
    ll a,b,c; cin >> a >> b >> c;
    dist[a][b]=dist[b][a]=min(dist[a][b],c);
}