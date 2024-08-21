
ll const N=1e6+1;
bool isPrime[N];
vector<ll> primes;
void sieve()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1]=false;
    for(ll i=2;i<N;i++)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(ll j=(ll)i*i;j<N;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
}
u64 binPower(u64 base, u64 e, u64 mod)
{
    u64 result = 1;
    base %= mod;
    while (e)
    {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s)
{
    u64 x = binPower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++)
    {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5)
{ 
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++)
    {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
bool isPrimeNumber(ll n)
{
    return MillerRabin(n);
}
bool isSquarePrime(ll n)
{
    ll t = round(sqrt(n));
    return (t * t == n && MillerRabin(t));
}
ll numberOfDivisors(ll n)
{
    ll ans=1;
    for(auto p:primes)
    {
        if(p*p*p>n)
            break;
        ll cnt=1;
        while(n%p==0)
        {
            cnt++;
            n/=p;
        }
        ans*=cnt;
    }
    if(isPrimeNumber(n))
        ans*=2;
    else if(isSquarePrime(n))
        ans*=3;
    else if(n!=1)
        ans*=4;
    return ans;
}


    sieve();
    ll n; cin >> n;
    cout << numberOfDivisors(n) << endl;
    return 0;

