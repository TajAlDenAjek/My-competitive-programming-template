template<typename T>
class dinic
{
    public:
    struct flowEdge
    {
        T u,v,capacity,flow=0;
        flowEdge(T u,T v,T capacity):u(u),v(v),capacity(capacity){}
    };
    T const OO=1e18;
    vector<flowEdge> edges;
    vector<vector<T>> graph;
    T numberOfNodes,source,sink,m= 0;
    vector<T> level,ptr,route;
    vector<bool> visited;
    dinic(T numberOfNodes,T source,T sink)
    {
        this->numberOfNodes=numberOfNodes;
        this->source=source;
        this->sink=sink;
        graph.resize(numberOfNodes);
        level.resize(numberOfNodes);
        ptr.resize(numberOfNodes);
    }
    void addEdge(T u,T v,T c)
    {
        edges.push_back(flowEdge(u,v,c));
        edges.push_back(flowEdge(v,u,0));
        graph[u].push_back(m);
        graph[v].push_back(m+1);
        m+=2;
    }
    bool bfs()
    {
        fill(level.begin(),level.end(),-1);
        queue<T> q;
        level[source]=0;
        q.push(source);
        while(!q.empty())
        {
            T u=q.front();
            q.pop();
            for(auto id:graph[u])
            {
                if(edges[id].capacity-edges[id].flow<1)
                    continue;
                if(level[edges[id].v]!= -1)
                    continue;
                level[edges[id].v]=level[u]+1;
                q.push(edges[id].v);
            }
        }
        return (level[sink]!=-1);
    }
    T dfs(T u,T pushFlow)
    {
        if(!pushFlow||u==sink)
            return pushFlow;
        for(T& curId=ptr[u];curId<(T)graph[u].size();curId++)
        {
            T id=graph[u][curId];
            T v=edges[id].v;
            if(level[u]+1!=level[v]||edges[id].capacity-edges[id].flow<1)
                continue;
            T minimumCapacity=dfs(v,min(pushFlow,edges[id].capacity-edges[id].flow));
            if (minimumCapacity==0)
                continue;
            edges[id].flow+=minimumCapacity;
            edges[id^1].flow-=minimumCapacity;
            return minimumCapacity;
        }
        return 0;
    }
    T flow()
    {
        T flow=0;
        while(true)
        {
            if (!bfs())
                break;
            fill(ptr.begin(),ptr.end(),0);
            while(T pushed=dfs(source,OO))
                flow += pushed;
        }
        return flow;
    }
    void traceRoute(T node)
    {
        route.push_back(node);
        for(auto id:graph[node])
        {
            T v=edges[id].v;
            T capacity=edges[id].capacity;
            T flow=edges[id].flow;
            if(capacity!=0&&flow==capacity&&!visited[id])
            {
                visited[id]=true;
                traceRoute(v);
                return;
            }
        }
    }
    vector<T> getRoute()
    {
        route.clear();
        traceRoute(source);
        return route;
    }
};



    // ll n,m;
    // cin >> n >> m;
    // dinic<ll> graph(n+1,1,n);
    // for(ll i=1;i<=m;i++)
    // {
    //     ll a,b;
    //     cin >> a >> b;
    //     graph.addEdge(a,b,1);
    // }
    // ll ans=graph.flow();
    // graph.visited.resize(graph.edges.size(),false);
    // cout << ans << endl;
    // for(ll i=0;i<ans;i++)
    // {
    //     vector<ll> route=graph.getRoute();
    //     cout << route.size() << endl;
    //     for(auto i:route)
    //         cout << i << " ";
    //     cout << endl;
    // }