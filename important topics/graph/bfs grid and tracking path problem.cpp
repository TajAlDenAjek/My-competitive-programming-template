// O(V + E)


// bfs grid problems with tracking path


ll const N=1e3+2;
bool visited[N][N];
char parent[N][N];
char grid[N][N];
 
ll dirX[]={1,-1,0,0};
ll dirY[]={0,0,1,-1};
string dir="DURL";
 
ll n,m;
 
bool isValid(ll i,ll j)
{
    return i>=1&&i<=n&&j>=1&&j<=m&&grid[i][j]!='#';
}
 
void bfs(ll x,ll y)
{
    queue<pair<ll,ll>> q;
    q.push({x,y});
    parent[x][y]='*';
    visited[x][y]=true;
    while(!q.empty())
    {
        pair<ll,ll> cord=q.front();
        q.pop();
 
        for(ll d=0;d<4;d++)
        {
            ll tempX=cord.first+dirX[d];
            ll tempY=cord.second+dirY[d];
            if(isValid(tempX,tempY)&&!visited[tempX][tempY])
            {
                parent[tempX][tempY]=dir[d];
                q.push({tempX,tempY});
                visited[tempX][tempY]=true;
            }
        }
    }
}


// intiliazation

    cin >> n >> m;
    ll startI,startJ,endI,endJ;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            cin >> grid[i][j];
            if(grid[i][j]=='A')
            {
                startI=i;
                startJ=j;
            }
            if(grid[i][j]=='B')
            {
                endI=i;
                endJ=j;
            }
        }
    }
    bfs(startI,startJ);
    if(visited[endI][endJ])
    {
        cout << "YES" << endl;
        vector<char> ans;
        while(parent[endI][endJ]!='*')
        {
            ans.push_back(parent[endI][endJ]);
            if(ans.back()=='R')
            {
                endJ--;
            }
            if(ans.back()=='L')
            {
                endJ++;
            }
            if(ans.back()=='U')
            {
                endI++;
            }
            if(ans.back()=='D')
            {
                endI--;
            }
        }
        reverse(ans.begin(),ans.end());
        cout << ans.size() << endl;
        for(auto i:ans)
        {
            cout << i ;
        }
    }
    else
    {
        cout << "NO" << endl;
    }