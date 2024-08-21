void grayCode(int n,string ans="")
{
    if(n==0)
    {
        string subAns="";
        subAns+=ans[0];
        string c=(ans[1]==ans[0]?"0":"1");
        for(int i=1;c=(ans[i]==ans[i-1]?"0":"1"),i<ans.size();i++)
            subAns+=c;
        cout << subAns << endl;
        return;
    }
    grayCode(n-1,ans+"0");
    grayCode(n-1,ans+"1");
}