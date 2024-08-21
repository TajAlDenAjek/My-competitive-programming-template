struct Two_SAT
{
    int n;
    vector<vector<int>> graph,reversedGraph;
    vector<bool>visited,booleanValues;
    vector<int>componentId;
    stack<int>toplogicalSort;
    Two_SAT(int clauses=0)
    {
        n=clauses*2;
        graph.resize(n);
        reversedGraph.resize(n);
    }
    void addOR(int u,bool uBooleanState,int v,bool vBooleanState)
    {
        u+=u+(uBooleanState^1);
        v+=v+(vBooleanState^1);
        graph[u^1].push_back(v); 
        graph[v^1].push_back(u);   
        reversedGraph[v].push_back(u^1);
        reversedGraph[u].push_back(v^1);
    }
    void addXOR(int u,bool uBooleanState,int v,bool vBooleanState)
    {
        addOR(u,uBooleanState,v,vBooleanState);
        addOR(u,!uBooleanState,v,!vBooleanState);
    }
    void add(int u,bool uBooleanState,int v,bool vBooleanState)
    {
        u+=u+(uBooleanState^1);
        v+=v+(vBooleanState^1);
        graph[u].push_back(v);
        reversedGraph[v].push_back(u);
    }
    void dfs1(int u)
    {
        visited[u]=true;
        for(int v:graph[u])
            if(!visited[v])
                dfs1(v);
        toplogicalSort.push(u);
    }
    void dfs2(int u,int c)
    {
        componentId[u]=c;
        for(int v:reversedGraph[u]) 
            if(componentId[v]==-1) 
                dfs2(v,c);
    }
    bool isTwoSAT()
    {
        visited.resize(n,false);
        for(int i=0;i<n;i++)
            if(!visited[i])
                dfs1(i);
 
        int scc=0;
        componentId.resize(n,-1);
        while(!toplogicalSort.empty())
        {
            int u=toplogicalSort.top();
            toplogicalSort.pop();
            if(componentId[u]==-1)
              dfs2(u,scc++);
        }
        booleanValues.resize(n/2);
        for(int i=0;i<n;i+=2)
        {
            if(componentId[i]==componentId[i+1])
                return false;
            booleanValues[i/2]=(componentId[i]>componentId[i+1]);
        }
        return true;
    }
};


   // int n,m;
    // cin >> n >> m;
    // Two_SAT ts(m);
    // for(int i=0;i<n;i++)
    // {
    //     char x,y;
    //     int u,v;
    //     cin >> x >> u >> y >> v;
    //     --u;
    //     --v;
    //     bool uBooleanState,vBooleanState;
    //     uBooleanState=(x=='-');
    //     vBooleanState=(y=='-');
    //     ts.addOR(u,uBooleanState,v,vBooleanState);

    // }
    // if(!ts.isTwoSAT())
    // {
    //     cout << "IMPOSSIBLE" << endl;
    // }
    // else
    // {
    //     for(auto i:ts.booleanValues)
    //         cout << (i?"-":"+") << " ";

    // }
 



struct Two_SAT
{
    int n;  /// total size combining +, -. must be even.
    vector<vector<int>> graph,reversedGraph;    /// graph, transpose graph
    vector<bool>visited,booleanValues;  /// visited and resulting assignment
    vector<int>componentId;   /// component number
    stack<int>toplogicalSort;  /// topsort
 
    Two_SAT(int clauses=0) // edges
    {
        n=clauses*2;
        graph.resize(n);
        reversedGraph.resize(n);
    }
 
    ///zero indexed, be careful
    ///if you want to force variable u to be true in OR or XOR combination
    ///add addOR (u,1,u,1);
    ///if you want to force variable u to be false int OR or XOR combination
    ///add addOR (u,0,u,0);
    ///(x_u or (not x_v))-> uf=1,vf=0
    void addOR(int u,bool uf,int v,bool vf)
    {
        u+=u+(uf^1);
        v+=v+(vf^1);
        graph[u^1].push_back(v);    /// !u => v
        graph[v^1].push_back(u);    /// !v => u
        reversedGraph[v].push_back(u^1);
        reversedGraph[u].push_back(v^1);
    }
    ///(x_u or x_v)-> uf=0,vf=0
    void addXOR(int u,bool uf,int v,bool vf)
    {
        addOR(u,uf,v,vf);
        addOR(u,!uf,v,!vf);
    }
    ///add this type of condition->
    ///add(u,uf,v,vf) means if u is uf then v must need to be vf
    void add(int u,bool uf,int v,bool vf)
    {
        u+=u+(uf^1);
        v+=v+(vf^1);
        graph[u].push_back(v);
        reversedGraph[v].push_back(u);
    }
    void dfs1(int u)
    {
        visited[u]=true;
        for(int v:graph[u])
            if(!visited[v])
                dfs1(v);
        toplogicalSort.push(u);
    }
 
    void dfs2(int u,int c)
    {
        componentId[u]=c;
        for(int v:reversedGraph[u]) 
            if(componentId[v]==-1) 
                dfs2(v,c);
    }
    bool isTwoSAT()
    {
        visited.resize(n,false);
        for(int i=0;i<n;i++)
            if(!visited[i])
                dfs1(i);
 
        int scc=0;
        componentId.resize(n,-1);
        while(!toplogicalSort.empty())
        {
            int u=toplogicalSort.top();
            toplogicalSort.pop();
            if(componentId[u]==-1)
              dfs2(u,scc++);
        }
        booleanValues.resize(n/2);
        for(int i=0;i<n;i+=2)
        {
            if(componentId[i]==componentId[i+1])
                return false;
            booleanValues[i/2]=(componentId[i]>componentId[i+1]);
        }
        return true;
    }

    /*
    for(i=0;i<m;i++){
        cin>>u>>v>>k;
        --u;
        --v;
        if(k) ts.add(u,0,v,0),ts.add(u,1,v,1),ts.add(v,0,u,0),ts.add(v,1,u,1);
        else ts.add(u,0,v,1),ts.add(u,1,v,0),ts.add(v,0,u,1),ts.add(v,1,u,0);
    }
    k=ts.ok();
    if(!k) cout<<"Impossible\n";
    else{
        vi v;
        for(i=0;i<n;i++) if(ts.res[i]) v.eb(i);
        cout<<sz(v)<<nl;
        for(auto x:v) cout<<x+1<<' ';
        cout<<nl;
    }
    */
};
