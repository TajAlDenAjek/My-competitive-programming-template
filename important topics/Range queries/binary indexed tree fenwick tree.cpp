template<typename T>
class fenwickTree
{
    public:
        T n;
        vector<T> BIT;
    fenwickTree(T n)
    {
        this->n=n;
        BIT.resize(n+1);
    }
    void update(T i,T v)
    {
        for(i++;i<=n;i+=i&-i)
            BIT[i]+=v;
    }
    T query(T l,T r)
    {
        T ans=0;
        for(r++;r;r-=r&-r)
            ans+=BIT[r];
        for(;l;l-=l&-l)
            ans-=BIT[l];
        return ans;
    }
};

// zero indexed 
template<typename T>
class fenwickTree
{
    public:
        T n;
        vector<T> BIT;
    fenwickTree(T n)
    {
        this->n=n;
        BIT.resize(n+1);
    }
    void update(T i,T v)
    {
        for(i++;i<=n;i+=i&-i)
            BIT[i]+=v;
    }
    // sum from 0 to i
    T query(T i)
    {
        T ans=0;
        for(i++;i>0;i-=i&-i)
            ans+=BIT[i];
        return ans;
    }
};