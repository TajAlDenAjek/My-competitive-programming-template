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
using u64 = uint64_t;
using u128 = __uint128_t;
void files()
{
    freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
}
/*-----------------------------------------------------------------------------*/
struct segment
{
    ll L,R,len;
    segment():L(0),R(0),len(0)
    {
    }
    segment(ll l,ll r):L(l),R(r)
    {
        len=(R-L+1);
    }
    bool operator<(const segment &cur) const
    {
        if(this->len==cur.len)
            return this->L<cur.L;
        return this->len>cur.len;
    }
};

/*-----------------------------------------------------------------------------*/
int main()
{
    // files();
    needForSpeed
    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        set<segment> s;
        ll ans[n+1];
        s.insert({1,n});
        ll op=1;
        while(!s.empty())
        {
            auto temp=s.begin();
            ll L=temp->L;
            ll R=temp->R;
            s.erase(temp);
            ll index=((R-L+1)%2?(L+R)/2:(L+R-1)/2);
            ans[index]=op++;
            if((index-1)-L+1>=1)
                s.insert({L,index-1});
            if(R-(index+1)+1>=1)
                s.insert({index+1,R});
        }

        for(ll i=1;i<=n;i++)
            cout << ans[i] << (i==n?"\n":" ");
    }
    return 0;
}


