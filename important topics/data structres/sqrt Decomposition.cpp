int const N=2e5+2;
ll arr[N],blocks[int(sqrt(N))+1];
int n,q,len; 

void build()
{
    len=int(sqrt(n))+1;
    for(int i=0;i<n;i++)
        blocks[i/len]+=arr[i];
}

void update(int index,int value)
{
    blocks[index/len]-=arr[index];
    arr[index]=value;
    blocks[index/len]+=arr[index];
}

ll query(int l,int r)
{
    ll ans=0;
    for(int i=l;i<=r;)
    {
        if(i%len==0&&i+len-1<=r)
        {
            ans+=blocks[i/len];
            i+=len;
        }
        else
        {
            ans+=arr[i];
            i++;
        }
    }
    return ans;
}

// update min and max in O(sqrt(n));
void update(int index,int value)
{
    arr[index]=value;
    blocks[index/len]=1e18;
    int l=index/len*len;
    int r=index/len*len+len;
    for(int i=l;i<r;i++)
        blocks[index/len]=min(blocks[index/len],arr[i]);
}