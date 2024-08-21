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

ll n,m;

vector<ll> ans;
ll solve(ll cnt,ll last)
{
    if(cnt==n)
    {
        // for(auto i:ans)
        //     cout << i << " ";
        // cout << endl;
        return 1;
    }
    ll res=0;
    for(ll i=1;i<=m;i++)
    {
        if(cnt==0)
        {
            ans.push_back(i);
            res+=solve(cnt+1,i);
            ans.pop_back();

        }
        else 
        {
            if(__gcd(last,i)==1)
            {            
                ans.push_back(i);
                res+=solve(cnt+1,i);
                ans.pop_back();
            }
        }
    }
    return res;
}
/*-----------------------------------------------------------------------------*/
int main()
{
    // files();
    needForSpeed
    cin >> n >> m;
    cout << solve(0,0) << endl;
    return 0;
}
