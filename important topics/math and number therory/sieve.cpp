ll const N=2e7+2;
bool isPrime[N];
vector<ll> primes;
void sieve()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1]=isPrime[0]=false;
    for(ll i=2;i<(ll)N;i++)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(ll j=i*i;j<(ll)N;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
}