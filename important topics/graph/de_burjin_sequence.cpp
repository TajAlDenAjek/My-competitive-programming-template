unordered_map<string,bool> visited;
vector<ll> edges;
void dfs(string u,string &a)
{
    for(ll i=0;i<a.size();i++)
    {
        string temp=u+a[i];
        if(!visited[temp])
        {
            visited[temp]=true;
            dfs(temp.substr(1),a);
            edges.push_back(i);
        }
    }
}

void De_Burjin_Sequence(ll n,string &a)
{
    string startingNode=string(n-1,a[0]);
    dfs(startingNode,a);
    string sequence("");
    for(ll i=0;i<edges.size();i++)
        sequence.push_back(a[edges[i]]);
    sequence+=startingNode;
    cout << sequence << endl;
    return ;
}

// find euler circuit in the directed graph 

//  ll n; cin >> n;
// string a("01");
// De_Burjin_Sequence(n,a);