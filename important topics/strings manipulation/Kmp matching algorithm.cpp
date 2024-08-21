vector<int> prefixFunction(string pat)
{
    int m=pat.length();
    vector<int> longestPrefix(m);
    for(int i=1,k=0;i<m;i++)
    {
        while(k>0&&pat[k]!=pat[i])
        {
            k=longestPrefix[k-1];   
        }
        if(pat[k]==pat[i])
          longestPrefix[i]=++k;
        else
          longestPrefix[i]=k;
    }
    return longestPrefix;
}

int kmp(string str,string pat)
{
    int n=str.length();
    int m=pat.length();
    int cnt=0;
    int last;
    vector<int> longestPrefix=prefixFunction(pat);
    for(int i=0,k=0;i<n;i++ )
    {
        while(k>0&&pat[k]!=str[i])
        {
            k=longestPrefix[k-1];
        }
        if(pat[k]==str[i])
            k++;
        if(k==m)
        {
            cnt++;
            last=i-m+1;
            k=longestPrefix[k-1];
        }
    }
    return last;
}