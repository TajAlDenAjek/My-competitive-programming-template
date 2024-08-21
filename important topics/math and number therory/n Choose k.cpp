ll nCk(ll n,ll k)
{
    if(k==0) return 1;
    return (n*nCk(n-1,k-1))/k;
}

 
ll nCk(ll n,ll k,ll MOD)
{
    ll ans=1;
    for(ll i=n;i>n-k;i--)
    {
        ans*=i;
        ans%=MOD;
    } 
    for(ll i=k;i>=1;i--)
    {
        ans*=fastPower(i,MOD-2,MOD);
        ans%=MOD;    
    } 
    return ans;
}

 
int const N =200;
int MOD = 998244353;
 
int Inv[N];
int Fact[N];
int iFact[N];
 
void add_self(int& x, int y)
{
    if((x += y) >= MOD) x -= MOD;
}
 
int add(int x, int y)
{
    return add_self(x, y), x;
}
 
void sub_self(int& x, int y)
{
    if((x -= y) < 0)    x += MOD;
}
 
int sub(int x, int y)
{
    return sub_self(x, y), x;
}
 
int mul(int x, int y)
{
    return (long long) x * y % MOD;
}
 
int nCk(int n, int r)
{
    if(n < 0 or r < 0 or n < r) return 0;
    return mul(Fact[n], mul(iFact[r], iFact[n - r]));
}
 
int fastPower(int b,int e)
{
    if(!e) return 1;
    int res=fastPower(b,e/2)%MOD;res=(res*res)%MOD;
    if(e&1) return res=(res*b)%MOD;
    return res;
}
 
 
 
void calculateFactorials()
{
    Inv[1] = 1;
    for(int i = 2; i < N; i++)  Inv[i] = sub(0, mul(MOD / i, Inv[MOD % i]));
    Fact[0] = iFact[0] = 1;
    for(int i = 1; i < N; i++)  Fact[i] = mul(i, Fact[i - 1]);
    for(int i = 1; i < N; i++)  iFact[i] = mul(Inv[i], iFact[i - 1]);
 
}







// pascal algorithm to solve nck
int C[N][N];

for(int i = 0; i < N; ++i){
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }