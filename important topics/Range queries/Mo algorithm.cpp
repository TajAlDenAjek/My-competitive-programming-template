ll const N=2e5+2;
ll arr[N],freq[N];
ll n,q,SQRT,ans=0;

struct query
{
    int l,r,queryIndex,blockIndex;
    query(){}
    query(int l,int r,int queryIndex):l(l),r(r),queryIndex(queryIndex)
    {
        blockIndex=l/SQRT;
    }
    bool operator<(const query &a) const
    {
        if(a.blockIndex!=blockIndex)
            return blockIndex<a.blockIndex;
        return r<a.r;
    }
};
vector<query> queries;
vector<ll> queryAns;
void add(int index)
{
    freq[arr[index]]++;
    if(freq[arr[index]]==1)
        ans++;
}
void remove(int index)
{
    freq[arr[index]]--;
    if(freq[arr[index]]==0)
        ans--;
}

void MO_Algorithm()
{
    sort(queries.begin(),queries.end());
    int curL=1,curR=0;
    for(int i=0;i<q;i++)
    {
        while(curL<queries[i].l) remove(curL++);
        while(curL>queries[i].l) add(--curL);
        while(curR<queries[i].r) add(++curR);
        while(curR>queries[i].r) remove(curR--);
        queryAns[queries[i].queryIndex]=ans;
    }
}

        // while(curR<queries[i].r) add(++curR);
        // while(curL<queries[i].l) remove(curL++);
        // while(curR>queries[i].r) remove(curR--);
        // while(curL>queries[i].l) add(--curL);

    // cin >>  n >> q;
    // for(int i=1;i<=n;i++)
    //     cin >> arr[i];
    // compress(n);
    // SQRT=(int)(sqrt(n))+1;
    // queryAns.resize(q);
    // for(int i=0;i<q;i++)
    // {
    //     int l,r;
    //     cin >> l >> r;
    //     queries.push_back({l,r,i});
    // }
    // queries.resize(q);
    // MO_Algorithm();
    // for(int i=0;i<q;i++)
    //     cout << queryAns[i] << endl;