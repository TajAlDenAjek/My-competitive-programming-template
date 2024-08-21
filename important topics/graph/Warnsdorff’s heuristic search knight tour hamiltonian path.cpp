int const N=9;
int chessBoard[N][N];
bool visited[N][N];
int dirX[]={-2,-1,-2,-1,1,1,2,2};
int dirY[]={-1,-2,1,2,-2,2,-1,1};
int timer=2;

int countAdjecentCells(int x,int y)
{
    int cnt=0;
    for(int d=0;d<8;d++)
    {
        int newX=x+dirX[d];
        int newY=y+dirY[d];
        if(newX>=1&&newX<=8&&newY>=1&&newY<=8&&!visited[newX][newY])
            cnt++;
    }
    return cnt;     
}

void solve(int x,int y,int visitedCells)
{
    if(visitedCells==64)
    {
        for(int i=1;i<N;i++)
            for(int j=1;j<N;j++)
                cout << chessBoard[i][j] << (j==N-1?"\n":" ");
        exit(0);
    }  
    vector<pair<int,pair<int,int>>> v;
    for(int d=0;d<8;d++)
    {
        int newX=x+dirX[d];
        int newY=y+dirY[d];
        if(newX>=1&&newX<=8&&newY>=1&&newY<=8&&!visited[newX][newY])
        {
            v.push_back({countAdjecentCells(newX,newY),{newX,newY}});
        }
    }
    sort(v.begin(),v.end());
    for(auto i:v)
    {
        int newX=i.second.first;
        int newY=i.second.second;
        chessBoard[newX][newY]=timer;
        timer++;
        visited[newX][newY]=true;
        solve(newX,newY,visitedCells+1);
        visited[newX][newY]=false;
        timer--;
        chessBoard[newX][newY]=0;
    }
    
    return ;
}


    int x,y;
    cin >> y >> x;
    visited[x][y]=true;
    chessBoard[x][y]=timer-1;
    solve(x,y,1);   