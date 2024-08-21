template<typename T>
class fenwickTree2D
{
    public:
        T n;
        vector<vector<T>> BIT;
    fenwickTree2D(T n)
    {
        this->n=n;
        BIT.resize(n+1,vector<T>(n+1,0));
    }
    void update(T x,T y,T v)
    {
        for(;x<=n;x+=x&-x)
            for(T j=y;j<=n;j+=j&-j)
                BIT[x][j]+=v;
    }
    T query(T x,T y)
    {
        T ans=0;
        for(;x>0;x-=x&-x)
            for(T j=y;j>0;j-=j&-j)
                ans+=BIT[x][j];
        return ans;
    }
};