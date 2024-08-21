ll const N=1e4+2;
ll arr[N],segTree[4*N];

#define lft p<<1,l,(l+r)/2
#define rgt p<<1|1,(l+r)/2+1,r


ll build(ll p,ll l,ll r)
{
    if(l==r)
        return segTree[p]=arr[r];
    return segTree[p]=build(lft)+build(rgt);
}

ll query(ll p,ll l,ll r,ll i,ll j)
{
    if(j<l||r<i)
        return 0;
    if(i<=l&&r<=j)
        return segTree[p];
    return query(lft,i,j)+query(rgt,i,j);
}

ll update(ll p,ll l,ll r,ll i,ll j,ll v)
{
    if(j<l||r<i)
        return segTree[p];
    if(i<=l&&r<=j)
        return segTree[p]+=v;
    return segTree[p]=update(lft,i,j,v)+update(rgt,i,j,v);
}

ll lazy[4*N];

void push(ll p)
{
    if(!lazy[p])
        return;
    lazy[p<<1]+=lazy[p];
    lazy[p<<1|1]+=lazy[p];
    segTree[p<<1]+=lazy[p];
    segTree[p<<1|1]+=lazy[p];
    lazy[p]=0;
}

ll update(ll p,ll l,ll r,ll i,ll j,ll v)
{
    if(j<l||r<i)
        return segTree[p];
    if(i<=l&&r<=j)
        return lazy[p]+=v,segTree[p]+=v;
    push(p);
    return segTree[p]=min(update(lft,i,j,v),update(rgt,i,j,v));
}





/*
void push(ll p,ll l,ll r)
{
    if(!lazy[p])
        return;
    lazy[p<<1]+=lazy[p];
    lazy[p<<1|1]+=lazy[p];
    ll mid=(l+r)/2;
    segTree[p<<1]+=(lazy[p]*(mid-l+1));
    segTree[p<<1|1]+=lazy[p]*(r-mid);
    lazy[p]=0;
}
ll update(ll p,ll l,ll r,ll i,ll j,ll v)
{
    if(j<l||r<i)
        return segTree[p];
    if(i<=l&&r<=j)
    {
        // lazy[p]+=(v*(r-l+1));
        return lazy[p]+=v,segTree[p]+=(v*(r-l+1));
    }
    push(p,l,r);
    return segTree[p]=(update(lft,i,j,v)+update(rgt,i,j,v));
}
ll query(ll p,ll l,ll r,ll i,ll j)
{
    if(j<l||r<i)
        return 0;
    if(i<=l&&r<=j)
        return segTree[p];
    push(p,l,r);
    return query(lft,i,j)+query(rgt,i,j);
}

*/