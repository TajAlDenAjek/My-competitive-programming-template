template<typename T> 
class DynamicSegmentTree
{
    public:
    struct node
    {
        node *left,*right;
        T value,lazy;
        node():value(0),lazy(0),left(NULL),right(NULL){}
        node(node *l,node *r,T val,T lazy):left(l),right(r),value(val),lazy(lazy){}
    };
    T n;
    node *root;
    vector<T> *arr;
    DynamicSegmentTree(T n,vector<T> &a)
    {
        this->n=n;
        root=new node();
        arr=&a;
    }
    T Merge(T lft,T rgt)
    {
        return lft+rgt;
    }
    T Merge(node *lft,node *rgt)
    {
        return lft->value+rgt->value;
    }
    void push(node *p)
    {
        if(p->left==NULL)
            p->left=new node();
        if(p->right==NULL)
            p->right=new node();
        if(!p->lazy)
            return;
        p->left->value=Merge(p->left->value,p->lazy);
        p->right->value=Merge(p->right->value,p->lazy);
        p->left->lazy=Merge(p->left->lazy,p->lazy);
        p->right->lazy=Merge(p->right->lazy,p->lazy);
        p->lazy=0;
    }
    void build()
    {
        build(root,1,n);
    }
    T query(T i,T j)
    {
        return query(i,j,root,1,n);
    }
    void update(T i,T j,T val)
    {
        update(i,j,val,root,1,n);
    }
    void build(node *p,T l,T r)
    {
        if(l==r)
        {
            p->value=(*arr)[l];
            return;
        }
        T mid=(l+r)>>1;
        p->left=new node();
        p->right=new node();
        build(p->left,l,mid);
        build(p->right,mid+1,r);
        p->value=Merge(p->left,p->right);
    }
    T query(T i,T j,node *p,T l,T r)
    {
        if(p==NULL)
            return 0;
        if(r<i||j<l)
            return 0;
        if(i<=l&&r<=j)
            return p->value;
        push(p);
        T mid=(l+r)>>1;
        T lft=query(i,j,p->left,l,mid);
        T rgt=query(i,j,p->right,mid+1,r);
        return Merge(lft,rgt);
    }
    void update(T i,T j,T val,node *p,T l,T r)
    {
        if(p==NULL)
            p=new node();
        if(r<i||j<l)
            return;
        if(i<=l&&r<=j)
        {
            p->lazy+=val;
            p->value+=val;
            return;
        }
        push(p);
        T mid=(l+r)>>1;
        if(j<=mid)
            update(i,j,val,p->left,l,mid);
        else if(i>mid)
            update(i,j,val,p->right,mid+1,r);
        else
        {
            update(i,mid,val,p->left,l,mid);
            update(mid+1,j,val,p->right,mid+1,r);
        }
        p->value=Merge(p->left,p->right);
    }
};
    // void updateACopy(node *rootOfCopy,T i,T j,T val)
    // {
    //     updateACopy(rootOfCopy,i,j,val,root,1,n);
    // }


    // void updateACopy(node *rootOfCopy,T i,T j,T val,node *p,T l,T r)
    // {
    //     if(rootOfCopy==NULL)
    //         rootOfCopy=new node();
    //     if(r<i||j<l)
    //         return;
    //     if(i<=l&&r<=j)
    //     {
    //         rootOfCopy->value=val;
    //         rootOfCopy->lazy=val;
    //         return;
    //     }
    //     push(rootOfCopy);
    //     T mid=(l+r)>>1;
    //     if(j<=mid)
    //     {
    //         rootOfCopy->right=p->right;
    //         rootOfCopy->left=new node();
    //         updateACopy(rootOfCopy->left,i,j,val,p->left,l,mid);
    //     }
    //     else if(i>mid)
    //     {
    //         rootOfCopy->left=p->left;
    //         rootOfCopy->right=new node();
    //         updateACopy(rootOfCopy->right,i,j,val,p->right,mid+1,r);
    //     }
    //     rootOfCopy->value=Merge(rootOfCopy->left,rootOfCopy->right);
    // }