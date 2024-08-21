template<typename T>
class segmentTree
{
    public:
    struct lazyInfo
    {
        T type,val;
        lazyInfo():type(0),val(0){}
        lazyInfo(T a,T b):type(a),val(b){}
        friend lazyInfo operator+(const lazyInfo &a,const lazyInfo &b)
        {
            if(b.type==1)
                return {a.type?a.type:1,a.val+b.val};
            return b.type?b:a;
        }
    };
    struct node
    {
        T sum;
        lazyInfo lazy;
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
    void push(T p,T l,T r)
    {
        if(segTree[p].lazy.type==1)
            segTree[p].sum+=segTree[p].lazy.val*(r-l+1);
        if(segTree[p].lazy.type==2)
            segTree[p].sum=((r-l+1)*segTree[p].lazy.val);
        if(l!=r)
        {
            for(auto child:{p<<1,p<<1|1})
                segTree[child].lazy=segTree[child].lazy+segTree[p].lazy;
        }
        segTree[p].lazy=lazyInfo();
    }
    void build()
    {
        build(1,1,n);
    }
    void update(T i,T j,lazyInfo lazy)
    {
        update(i,j,lazy,1,1,n);
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
    void update(T i,T j,lazyInfo lazy,T p,T l,T r)
    {
        push(p,l,r);
        if(r<i||j<l)
            return;
        if(i<=l&&r<=j)
        {
            segTree[p].lazy=segTree[p].lazy+lazy;
            push(p,l,r);
            return ;
        }
        T mid=(l+r)>>1;
        update(i,j,lazy,p<<1,l,mid);
        update(i,j,lazy,p<<1|1,mid+1,r);
        segTree[p]=segTree[p<<1]+segTree[p<<1|1];
    }
    node query(T i,T j,T p,T l,T r)
    {
        push(p,l,r);
        if(r<i||j<l)
            return node(0);
        if(i<=l&&r<=j)
            return segTree[p];
        T mid=(l+r)>>1;
        node lft=query(i,j,p<<1,l,mid);
        node rgt=query(i,j,p<<1|1,mid+1,r);
        return lft+rgt;
    }
};