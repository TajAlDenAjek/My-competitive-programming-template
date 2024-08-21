/* :::::::         ::.     .:::::::.    ::.    .:^:       .::     ::
  .#@#BB#&#Y:     ?@@G.    J@&#BBB##5: .#@J  .Y&&Y:       5@&Y   :&&^
  .&@Y ..^G@#:   !@#G@P    Y@&.   ~@@J .&@J.J&&Y^         5@@@G: :@@~
  .&@J    ^@@7  :&@~ B@J   Y@@PPPPB&G^ .&@B#@@P           5@GJ@&~:&@~
  .&@J    ~@@! .B@&YYB@@7  Y@&??P@&J   .&@&J^G@B^   YBGG5 5@P !&@Y&@~
  .&@P~~!?#@5  P@B?JJJ5@@~ Y@&.  !&@G^ .&@Y   Y@@J  ~!!!~ 5@P  ^B@@@~
  .PGGGGGGY~  !BG^     YB5 7BP.   :5BP:.PB7    ?BB?       JBJ   .YBG^
*/
#include<bits/stdc++.h>
#define endlflush endl
#define debug(x) cout << #x << " " << x << endlflush;
#define endl '\n'
#define needForSpeed ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
typedef  long long int ll;
typedef  long double ld;
typedef unsigned long long int ull;
using namespace std;
// using u64 = uint64_t;
// using u128 = __uint128_t;
void files()
{
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
}
/*-----------------------------------------------------------------------------*/

ll const N=102,MOD=1e9+7;
ll n,m;

ll fastPower(ll b,ll e,ll MOD)
{
    if(!e) return 1;
    ll res=fastPower(b,e/2,MOD)%MOD;res=(res*res)%MOD;
    if(e&1) return res=(res*b)%MOD;
    return res;
}


/*-----------------------------------------------------------------------------*/
int main()
{
    // files();
    needForSpeed
    cin >> n >> m;
    if(n==1)
    {
        cout << m << endl;
        return 0;
    }
    ll ans=fastPower(m,n,MOD);
    ll rest=fastPower(m,n-2,MOD);
    for(ll i=m;i>=1;i--)
    {
        for(ll j=m;j>=1;j--) if(__gcd(i,j)!=1)
        {
            ll temp=((n-1)%MOD*(rest%MOD))%MOD;
            ans-=temp;
            ans%=MOD;
            ans+=MOD;
            ans%=MOD;            
            if(i==j)
            {
                ans+=(n);
                ans%=MOD;
                ans+=MOD;
                ans%=MOD;            
            }
        }
    }
    /*
        1 2 
        2 1 
        3 1 
        1 3 
        1 1 
        2 3 
        3 2 


        2 2 
        3 3 
    */

    cout << ans << endl;
    return 0;
}
