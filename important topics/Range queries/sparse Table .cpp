#define log(x) (31^__builtin_clz(x))
 
int const N=1e6+2;
int arr[N];
int sp[log(1e9)+1][N];
 
void build(int n)
{
    for(int i=0;i<n;i++)
        sp[0][i]=arr[i];
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=0;i+(1<<j)<=n;i++)
        {
            sp[j][i]=min(sp[j-1][i],sp[j-1][i+(1<<(j-1))]);
        }
    }
}
int inline query(int l,int r)
{
    int k=log(r-l+1);
    return min(sp[k][l],sp[k][r-(1<<k)+1]);
}