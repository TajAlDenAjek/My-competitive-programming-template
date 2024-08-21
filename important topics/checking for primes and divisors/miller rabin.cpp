/*#####################################################################
#  ####        ###       ########       ##     ##    ##       ##      #
#  ##  #      #   #      #       #      ##   ##      ####     ##      #
#  ##   #    #     #     #       #      ## ##        ## ##    ##      #
#  ##   #   #########    ########       ####         ##  ##   ##      #
#  ##   #  #         #   #      #       ##  ##       ##   ##  ##      #
#  ##  #   #         #   #       #      ##    ##     ##    ## ##      #
#  ####    #         #   #        #     ##     ##    ##     ####      #
####################################################################### */
#include<bits/stdc++.h>
#define endlflush endl
#define debug(x) cout << #x << " " << x << endlflush;
#define endl '\n'
#define needForSpeed ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
typedef  long long int ll;
typedef  long double ld;
typedef unsigned long long int ull;
using namespace std;
void files()
{
    freopen("veryhard.in","r",stdin);
    freopen("veryhard.out","w",stdout);
}
/*-----------------------------------------------------------------------------*/
// Global
ll binPower(ll b,ll p,ll mod)
{
    ll res=1;
    b%=mod;
    while(p)
    {
        if(p&1)
        {
            res=((res%mod)*(b%mod))%mod;
        }
        b=((b%mod)*(b%mod))%mod;
        p/=2;
    }
    return res;
}

bool check_composite(ll n,ll a,ll d,ll s)
{
    ll x=binPower(a,d,n);
    if(x==1||x==n-1)
        return false;
    for(ll r=1;r<s;r++)
    {
        x=((x%n)*(x%n))%n;
        if(x==n-1)
            return false;
    }
    return true;
}
bool MillerRabin(ll n,ll iter=10)
{
    if(n<4)
        return (n==2||n==3);
    ll s=0;
    ll d=n-1;
    while((d&1)==0)
    {
        d>>=1;
        s++;
    }
    for(ll i=0;i<iter;i++)
    {
        ll a=2+rand()%(n-3);
        if(check_composite(n,a,d,s))
            return false;
    }
    return true;
}
bool MillerRabin2(ll n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
bool isSquarePrime(ll n)
{
    ll t = round(sqrt(n));
    return (t * t == n && MillerRabin2(t));
}
vector<ll> primes;
map<ll,bool> squareOfPrime;
ll const N=1e6+2;
bool isPrime[N];
void sieve()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1]=false;
    for(ll i=2;i<N;i++)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            squareOfPrime[i*i]=true;
            for(ll j=i*i;j<N;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
}

ll const N_=1e2+2;
ll arr[N],res[N];
map<ll,pair<bool,ll>> dp;
/*-----------------------------------------------------------------------------*/
int main()
{
    // files();
    needForSpeed
    sieve();
    ll n; cin >> n;
    for(ll i=1;i<=n;i++)
    {
        // arr[i]=1000000000000000000;
        cin >> arr[i];
    }
    for(ll i=1;i<=n;i++)
    {
        ll x=arr[i];
        if(dp[arr[i]].first)
        {
            res[i]=dp[arr[i]].second;
            continue;
        }
        ll ans=1;
        for(auto p:primes)
        {
            if(p*p*p>arr[i])
                break;
            ll cnt=1;
            while(arr[i]%p==0)
            {
                cnt++;
                arr[i]/=p;
            }
            ans*=cnt;
        }   
        if(MillerRabin2(arr[i]))
            ans*=2;
        else if(isSquarePrime(arr[i]))
            ans*=3;
        else if(arr[i]!=1)
            ans*=4;
        res[i]=ans%2;
        dp[x]={true,res[i]};
    }
    for(ll i=1;i<=n;i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
https://codeforces.com/gym/100142  problem A



using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}