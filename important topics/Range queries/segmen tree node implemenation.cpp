template<typename T>
class segmentTree
{
    public:
    struct node
    {
        T sum;
        node():sum(0){}
        node(T s):sum(s){}
        friend node operator+(const node &a,const node &b)
        {
            return a.sum+b.sum;
        }
    };
    T n;
    vector<T> *arr;
    vector<node> segTree;
    segmentTree(T n,vector<T> &a)
    {
        this->n=n;
        arr=&a;
        segTree.resize(4*n);
    }
    void build()
    {
        build(1,1,n);
    }
    void update(T index,T val)
    {
        update(index,val,1,1,n);
    }
    node query(T i,T j)
    {
        return query(i,j,1,1,n);
    }
    void build(T p,T l,T r)
    {
        if(l==r)
        {
            segTree[p]=node((*arr)[l]);
            return;
        }
        T mid=(l+r)>>1;
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
        segTree[p]=segTree[p<<1]+segTree[p<<1|1];
        return;       
    }
    void update(T index,T val,T p,T l,T r)
    {
        if(l==r)
        {
            segTree[p]=node(val);
            return;
        }
        T mid=(l+r)>>1;
        if(index<=mid)
            update(index,val,p<<1,l,mid);
        else
            update(index,val,p<<1|1,mid+1,r);
        segTree[p]=segTree[p<<1]+segTree[p<<1|1];
        return;
    }
    node query(T i,T j,T p,T l,T r)
    {
        if(r<i||j<l)
            return 0;
        if(i<=l&&r<=j)
            return segTree[p];
        T mid=(l+r)>>1;
        node lft=query(i,j,p<<1,l,mid);
        node rgt=query(i,j,p<<1|1,mid+1,r);
        return lft+rgt;
    }
};



    // ll n,q;
    // cin >> n >> q;
    // vector<ll> arr(n+1);
    // for(ll i=1;i<=n;i++)
    //     cin >> arr[i];
    // segmentTree<ll> st(n,arr);
    // st.build();
    // while(q--)
    // {
    //     ll t;
    //     cin >> t;
    //     if(t==1)
    //     {
    //         ll i,v;
    //         cin >> i >> v;
    //         st.update(i,v);
    //     }
    //     else
    //     {
    //         ll l,r;
    //         cin >> l >> r;
    //         cout << st.query(l,r).sum << endl;
    //     }
    // }

// lazy

template<typename T>
class segmentTree
{
    public:
    struct node
    {
        T sum;
        node():sum(0){}
        node(T s):sum(s){}
        friend node operator+(const node &a,const node &b)
        {
            return a.sum+b.sum;
        }
        friend bool operator!(const node &a)
        {
            return (a.sum==0);
        }
    };
    T n;
    vector<T> *arr;
    vector<node> segTree,lazy;
    segmentTree(T n,vector<T> &a)
    {
        this->n=n;
        arr=&a;
        segTree.resize(4*n);
        lazy.resize(4*n);
    }
    void push(ll p)
    {
        if(!lazy[p])
            return;
        lazy[p<<1]=lazy[p<<1]+lazy[p];
        lazy[p<<1|1]=lazy[p<<1|1]+lazy[p];
        segTree[p<<1]=segTree[p<<1]+lazy[p];
        segTree[p<<1|1]=segTree[p<<1|1]+lazy[p];
        lazy[p]=node(0);
    }
    void build()
    {
        build(1,1,n);
    }
    void update(T index,T val)
    {
        update(index,val,1,1,n);
    }
    node updateRange(T i,T j,T val)
    {
        return updateRange(i,j,val,1,1,n);
    }
    node query(T i,T j)
    {
        return query(i,j,1,1,n);
    }
    void build(T p,T l,T r)
    {
        if(l==r)
        {
            segTree[p]=node((*arr)[l]);
            return;
        }
        T mid=(l+r)>>1;
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
        segTree[p]=segTree[p<<1]+segTree[p<<1|1];
        return;       
    }
    void update(T index,T val,T p,T l,T r)
    {
        if(l==r)
        {
            segTree[p]=node(val);
            return;
        }
        T mid=(l+r)>>1;
        if(index<=mid)
            update(index,val,p<<1,l,mid);
        else
            update(index,val,p<<1|1,mid+1,r);
        segTree[p]=segTree[p<<1]+segTree[p<<1|1];
        return;
    }
    node updateRange(T i,T j,T val,T p,T l,T r)
    {
        if(j<l||r<i)
            return segTree[p];
        if(i<=l&&r<=j)
        {
            lazy[p]=lazy[p]+node(val);
            segTree[p]=segTree[p]+node(val);
            return segTree[p];
        }
        push(p);
        T mid=(l+r)>>1;
        node lft=updateRange(i,j,val,p<<1,l,mid);
        node rgt=updateRange(i,j,val,p<<1|1,mid+1,r);
        segTree[p]=lft+rgt;
        return segTree[p];
    }
    node query(T i,T j,T p,T l,T r)
    {
        if(r<i||j<l)
            return 0;
        if(i<=l&&r<=j)
            return segTree[p];
        push(p);
        T mid=(l+r)>>1;
        node lft=query(i,j,p<<1,l,mid);
        node rgt=query(i,j,p<<1|1,mid+1,r);
        return lft+rgt;
    }
};