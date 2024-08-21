template<typename T>
class dinicMaxMatchingBiprtateGraph
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
    T numberOfNodes,source,sink,biprtate= 0;
    vector<T> level,ptr;
    dinicMaxMatchingBiprtateGraph(T numberOfNodes,T source,T sink)
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
        graph[u].push_back(biprtate);
        graph[v].push_back(biprtate+1);
        biprtate+=2;
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
            for(auto biprtateId:graph[u])
            {
                if(edges[biprtateId].capacity-edges[biprtateId].flow<1)
                    continue;
                if(level[edges[biprtateId].v]!= -1)
                    continue;
                level[edges[biprtateId].v]=level[u]+1;
                q.push(edges[biprtateId].v);
            }
        }
        return (level[sink]!=-1);
    }
    T dfs(T u,T pushFlow)
    {
        if(!pushFlow||u==sink)
            return pushFlow;
        for(T& curBiprtateId=ptr[u];curBiprtateId<(T)graph[u].size();curBiprtateId++)
        {
            T biprtateId=graph[u][curBiprtateId];
            T v=edges[biprtateId].v;
            if(level[u]+1!=level[v]||edges[biprtateId].capacity-edges[biprtateId].flow<1)
                continue;
            T minimumCapacity=dfs(v,min(pushFlow,edges[biprtateId].capacity-edges[biprtateId].flow));
            if (minimumCapacity==0)
                continue;
            edges[biprtateId].flow+=minimumCapacity;
            edges[biprtateId^1].flow-=minimumCapacity;
            return minimumCapacity;
        }
        return 0;
    }
    T maxMatch()
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
};



    // ll boys,girls,pairs;
    // cin >> boys >> girls >> pairs;
    // ll source=0,sink=(boys+girls+1),nodes=(boys+girls+2);
    // dinicMaxMatchingBiprtateGraph<ll> graph(nodes,source,sink);
    // for(ll i=1;i<=pairs;i++)
    // {
    //     ll a,b;
    //     cin >> a >> b;
    //     graph.addEdge(a,b+boys,1);
    // }
    // for(ll i=1;i<=boys;i++)
    //     graph.addEdge(source,i,1);
    // for(ll i=1;i<=girls;i++)
    //     graph.addEdge(i+boys,sink,1);
    // cout << graph.maxMatch() << endl;
    // for(ll i=0;i<graph.edges.size();i++)
    // {
    //     if(graph.edges[i].u>0&&graph.edges[i].u<=boys&&graph.edges[i].flow==1)
    //         cout << graph.edges[i].u << " " <<  graph.edges[i].v-boys << endl;
    // }