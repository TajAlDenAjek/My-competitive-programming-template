//zero indexed;

template<typename T> 
class segmentTree
{
    public:
        T n;
        vector<T> segTree;
        #define lft p<<1,l,(l+r)/2
        #define rgt p<<1|1,(l+r)/2+1,r
    segmentTree(){}
    segmentTree(vector<T> &arr)
    {
        // zero-indexed segment tree
        n=arr.size();
        segTree.resize(4*n+4,0);
        build(1,0,n-1,arr);
    }
    void initialize(vector<T> &arr)
    {
        segTree.clear();
        n=arr.size();
        if(n<=0)
            return;
        segTree.resize(4*n+4,0);
        build(1,0,n-1,arr);
    }
    T build(T p,T l,T r,vector<T> &arr)
    {
        if(l==r)
            return segTree[p]=arr[r];
        return segTree[p]=build(lft,arr)+build(rgt,arr);
    }
    T query(T p,T l,T r,T i,T j)
    {
        if(j<l||r<i)
            return 0;
        if(i<=l&&r<=j)
            return segTree[p];
        return query(lft,i,j)+query(rgt,i,j);
    }
    T update(T p,T l,T r,T i,T j,T v)
    {
        if(j<l||r<i)
            return segTree[p];
        if(i<=l&&r<=j)
            return segTree[p]=v;
        return segTree[p]=update(lft,i,j,v)+update(rgt,i,j,v);
    }
    T query(T i,T j)
    {
       return query(1,0,n-1,i,j);
    }
    T update(T i,T j,T v)
    {
        update(1,0,n-1,i,j,v);
        return 0;
    }
    void clear()
    {
        n=0;
        segTree.clear();
    }
};


// one indexed

template<typename T> 
class segmentTree
{
    public:
        T n;
        vector<T> segTree;
        #define lft p<<1,l,(l+r)/2
        #define rgt p<<1|1,(l+r)/2+1,r
    segmentTree(){}
    segmentTree(vector<T> &arr)
    {
        // one-indexed segment tree
        n=arr.size()-1;
        segTree.resize(4*n+4,0);
        build(1,1,n,arr);
    }
    void initialize(vector<T> &arr)
    {
        segTree.clear();
        n=arr.size()-1;
        segTree.resize(4*n+4,0);
        build(1,1,n,arr);
    }
    T build(T p,T l,T r,vector<T> &arr)
    {
        if(l==r)
            return segTree[p]=arr[r];
        return segTree[p]=build(lft,arr)+build(rgt,arr);
    }
    T query(T p,T l,T r,T i,T j)
    {
        if(j<l||r<i)
            return 0;
        if(i<=l&&r<=j)
            return segTree[p];
        return query(lft,i,j)+query(rgt,i,j);
    }
    T update(T p,T l,T r,T i,T j,T v)
    {
        if(j<l||r<i)
            return segTree[p];
        if(i<=l&&r<=j)
            return segTree[p]=v;
        return segTree[p]=update(lft,i,j,v)+update(rgt,i,j,v);
    }
    void clear()
    {
        n=0;
        segTree.clear();
    }
};


// ll n,q;
//     cin >> n >> q;
//     vector<ll> arr(n+1,0);
//     for(ll i=1;i<=n;i++)
//         cin >> arr[i];
//     segmentTree<ll> seg(arr);
//     while(q--)
//     {
//         ll t,x,y;
//         cin >> t >> x >> y;
//         if(t==1)
//         {
//             seg.update(1,1,n,x,x,y);
//         }
//         else
//         {
//             cout << seg.query(1,1,n,x,y) << endl;
//         }
//     }