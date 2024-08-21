
template <typename T>
class LCA
{
    private:
        T numberOfNodes,maxDepth,root,timer;
        vector<vector<T>> parents;
        vector<T> depth,timeIn,timeOut;
        vector<vector<T>> tree;
        T LOG=30;
    public:
        LCA(T n,T root,vector<vector<T>> &tree)
        {
            numberOfNodes=n+1;
            maxDepth=(T)(65);
            this->root=root;
            this->tree=tree;
            timer=0;
            parents.resize(n+2,vector<T>(maxDepth));
            depth.resize(numberOfNodes);
            timeIn.resize(numberOfNodes);
            timeOut.resize(numberOfNodes);
            dfs(root,0,0);
            preProcess();
        }
        void dfs(T u,T p,T level)
        {
            parents[u][0]=p;
            depth[u]=level;
            timeIn[u]=timer++;
            for(auto v:tree[u])
            {
                if(v!=p)
                    dfs(v,u,level+1);
            }
            timeOut[u]=timer++;
        }
        void preProcess()
        {
            for(T j=1;j<maxDepth;j++)
                for(T i=1;i<numberOfNodes;i++)
                    parents[i][j]=parents[parents[i][j-1]][j-1];
        }
        T k_thParent(T node,T k)
        {
            T p=node;
            for(T i=LOG;i>=0;i--)
                if(k&(1<<i))
                    p=parents[p][i];
            return p;
        }
        T query(T u,T v)
        {
            if(depth[u]>depth[v])
                swap(u,v);
            T dif=depth[v]-depth[u];
            v=k_thParent(v,dif);
            if(u==v) 
                return u;
            T lca=0;
            for (T i=LOG;i>=0;i--)
            {
                if (parents[u][i]!=parents[v][i])
                {
                    u=parents[u][i];
                    v=parents[v][i];
                }
            }
            lca=parents[u][0];
            return lca;
        }
        T distance(T u,T v)
        {
            return depth[u]+depth[v]-2*depth[query(u,v)];
        }
        ~ LCA()
        {
            tree.clear();
            depth.clear();
            parents.clear();
            timeIn.clear();
            timeOut.clear();
            numberOfNodes=root=maxDepth=timer=0;
        }
}; 



    // int n,q; cin >> n >> q;
    // vector<vector<int>> tree(n+1,vector<int>({}));
    // for(int i=2;i<=n;i++)
    // {
    //     int a,b;
    //     cin >> a;
    //     b=i;
    //     tree[a].push_back(b);
    //     tree[b].push_back(a);
    // }
    // LCA<int> lca(n,1,tree);
    // while(q--)
    // {
    //     int a,k;
    //     cin >> a >> k;
    //     int bos=lca.k_thParent(a,k);
    //     if(k-1>=1&&bos==lca.k_thParent(a,k-1)||bos==a)
    //     {
    //         cout << -1 << endl;
    //         continue;
    //     }
    //     cout << bos << endl;
    // }