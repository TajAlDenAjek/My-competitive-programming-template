

template <typename T>
class centroidDecomposition
{
    private:
        T numberOfNodes,root,n;
        vector<T> sz,centroidTree;
        vector<vector<T>> tree;
        vector<bool> removed;
    public:
        centroidDecomposition(T n,T root,vector<vector<T>> &tree)
        {
            numberOfNodes=n+1;
            this->n=n;
            this->root=root;
            this->tree=tree;
            sz.resize(numberOfNodes,0);
            centroidTree.resize(numberOfNodes);
            removed.resize(numberOfNodes,false);
            subTreeSize(1,0);
        }
        void subTreeSize(T u,T p)
        {
            sz[u]=1;
            for(auto v:tree[u])
            {
                if(v==p||removed[v])
                    continue;
                subTreeSize(v,u);
                sz[u]+=sz[v];
            }
        }
        T centroid(T u,T p,T remainingSize)
        {
            for(auto v:tree[u])
            {
                if(v!=p&&!removed[v]&&sz[v]>remainingSize/2)
                    return centroid(v,u,remainingSize);
            }
            return u;
        }
        T buildTree(T u)
        {
            subTreeSize(u,0);
            T root=centroid(u,0,sz[u]);
            removed[root]=true;
            for(auto v:tree[root])
            {
                if(!removed[v])
                {
                    T subCentroid=buildTree(v);
                    centroidTree[subCentroid]=root;
                }
            }
            return root;
        }
        void update(T u)
        {
        }
        T query(T u)
        {
        }
        ~ centroidDecomposition()
        {
            tree.clear();
            sz.clear();
            centroidTree.clear();
            removed.clear();
            numberOfNodes=root=0;
        }
}; 