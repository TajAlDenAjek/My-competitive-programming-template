ll const N=1e5+2;
vector<ll> graph[N];
ll inDegree[N],outDegree[N];
vector<ll> path;
ll n,m;



void Hierholzer(ll u)
{
    stack<ll> s;
    s.push(u);
    while(!s.empty())
    {
        ll u=s.top();
        if(!graph[u].empty())
        {
            ll v=graph[u].back();
            graph[u].pop_back();
            s.push(v);
        }
        else
        {
            path.push_back(u);
            s.pop();
        }
    }
    reverse(path.begin(),path.end());
}
