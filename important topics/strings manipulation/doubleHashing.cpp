template<typename T>
struct DoubleHashing
{
    T const p1=31;
    T const p2=1337;
    T const Mod1=1e9+9;
    T const Mod2=1e9+7;
    T len;
    vector<T> power1,power2,hash1,hash2;

    DoubleHashing(string s)
    {
        len=s.size();
        power1.resize(len);
        power2.resize(len);
        hash1.resize(len);
        hash2.resize(len);
        //  pre calculate powers for better performance
        power1[0]=power2[0]=1;
        for(T i=1;i<len;i++)
        {
            power1[i]=((ll)power1[i-1]*p1)%Mod1;
            power2[i]=((ll)power2[i-1]*p2)%Mod2;
        }
        // hash 
        hash1[0]=s[0]%Mod1;
        hash2[0]=s[0]%Mod2;
        for(T i=1;i<len;i++)
        {
            hash1[i]=((ll)hash1[i-1]*p1+s[i])%Mod1;
            hash2[i]=((ll)hash2[i-1]*p2+s[i])%Mod2;
        }
    }

    pair<T,T> getHashVal(T l,T r)
    {
        if(l>r) swap(l,r);

        ll first=hash1[r];
        if(l)
            first-=(ll)hash1[l-1]*power1[r-l+1];
        first=(first%Mod1+Mod1)%Mod1;

        ll second=hash2[r];
        if(l)
            second-=((ll)hash2[l-1]*power2[r-l+1]);
        second=(second%Mod2+Mod2)%Mod2;;

        return {first,second};
    }
};
