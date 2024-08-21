
// need a zero indexed segment tree

template<typename T> 
class heavyLightDecomposition
{
    public:
        vector<vector<T>> tree,chain;
        vector<T> head,sz,parent,index,depth,cost;
        vector<segmentTree<T>> segmentTrees;
    heavyLightDecomposition(){}
    heavyLightDecomposition(T n,vector<vector<T>> &tree,vector<T> &cost)
    {
        this->tree=tree;
        this->cost=cost;
        sz.resize(n);
        parent.resize(n);
        index.resize(n);
        head.resize(n);
        chain.resize(n);
        depth.resize(n);
        segmentTrees.resize(n);
    }
    void initialize(T u,T p,T level)
    {
        depth[u]=level;
        sz[u]=1;
        parent[u]=p;
        for(auto v:tree[u])
        {
            if(v==p)
                continue;
            initialize(v,u,level+1);
            sz[u]+=sz[v];
        }
    }
    void dfs(T u,T p,T topOfChain,T val)
    {
        T bigChild=-1;
        head[u]=topOfChain;
        index[u]=chain[topOfChain].size();
        chain[topOfChain].push_back(val);
        for(auto v:tree[u])
        {
            if(v==p)
                continue;
            if(bigChild==-1||sz[v]>sz[bigChild])
            {
                bigChild=v;
                val=cost[v];
            }
        }
        if(bigChild!=-1)
        {
            dfs(bigChild,u,topOfChain,val);
        }
        for(auto v:tree[u])
        {
            if(v==p||bigChild==v)
                continue;
            dfs(v,u,v,cost[v]);
        }
    }
    void decompose(T root,T n)
    {
        initialize(root,root,0);
        dfs(root,root,root,cost[root]);
        for(T i=0;i<n;i++)
        {
            if(head[i]==i)
            {
                segmentTrees[i].initialize(chain[i]);
            }
        }
    }
    T query(T u,T v)
    {
        T ans=0;
        while(head[u]!=head[v])
        {
            if(depth[head[v]]<depth[head[u]])
                swap(u,v);
            ans+=segmentTrees[head[v]].query(0,index[v]);
            v=parent[head[v]];
        }
        if(depth[v]<depth[u])
            swap(u,v);
        ans+=segmentTrees[head[v]].query(index[u],index[v]);
        return ans;
    }
    void update(T u,T val)
    {
        segmentTrees[head[u]].update(index[u],index[u],val);
        chain[head[u]][index[u]]=val;
        return;
    }
};




//     ll n,q;
//     cin >> n >> q;
//     vector<ll> cost(n,0);
//     vector<vector<ll>> tree(n);
//     for(ll i=0;i<n;i++)
//         cin >> cost[i];
//     for(ll i=1;i<n;i++)
//     {
//         ll a,b;
//         cin >> a >> b;
//         a--;
//         b--;
//         tree[a].push_back(b);
//         tree[b].push_back(a);
//     }
//     heavyLightDecomposition<ll> HLD(n,tree,cost);
//     HLD.decompose(0,n);
//     while(q--)
//     {
//         ll t; cin >> t;
//         if(t==1)
//         {
//             ll u,v;
//             cin >> u >> v;
//             u--;
//             HLD.update(u,v);
//         }
//         else
//         {
//             ll u; cin >> u;
//             u--;
//             cout << HLD.query(0,u) <<endl;
//         }
//     }