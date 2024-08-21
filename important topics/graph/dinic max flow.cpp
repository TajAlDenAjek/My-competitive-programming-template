template <typename T> 
class dinicMaxFlow
{
    private:
        struct edge
        {
            T to,flowCapacity,reverse;
            edge(T a,T c,T rev):to(a),flowCapacity(c),reverse(rev){}
        };
        vector<vector<edge>> graph;
        vector<T> level;
        T const OO=1e18;
        T numberOfNodes;
    public:
        dinicMaxFlow(T numberOfNodes)
        {
            this->numberOfNodes=numberOfNodes;
            graph.resize(numberOfNodes+1,vector<edge>({}));
            level.resize(numberOfNodes+1,-1);
        }
        void addEdge(T u,T v,T c)
        {
            graph[u].push_back({v,c,(T)graph[v].size()});
            graph[v].push_back({u,(T)0,(T)graph[u].size()-1});
            return;
        }
        void bfs(T source,T sink)
        {
            fill(level.begin(),level.end(),-1);
            queue<T> q;
            q.push(source);
            level[source]=0;
            while(!q.empty())
            {
                T node=q.front();
                q.pop();
                if(node==sink)
                    break;
                for(auto v:graph[node])
                {
                    if(level[v.to]==-1&&v.flowCapacity>0)
                    {
                        level[v.to]=level[node]+1;
                        q.push(v.to);
                    }
                }
              
            }
        }
        T dfs(T node,T sink,T flow)
        {
            if(node==sink||!flow)
                return flow;
            if(level[node]==-1)
                return 0;
            T curLevel=level[node];
            level[node]=-1;
            for(auto &v:graph[node])
            {
                if(level[v.to]<=curLevel)
                    continue;
                T minimumCapacity=dfs(v.to,sink,min(flow,v.flowCapacity));
                if(!minimumCapacity)
                    continue;
                v.flowCapacity-=minimumCapacity;
                graph[v.to][v.reverse].flowCapacity+=minimumCapacity;
                level[node]=curLevel;
                return minimumCapacity;
            }
            return 0;
        }
        T getMaxFlow(T source,T sink)
        {
            T findNewPaths=-1,flow=0;
            while(findNewPaths)
            {
                findNewPaths=0;
                bfs(source,sink);
                T pushFlow=-1;
                while(pushFlow)
                {
                    pushFlow=0;
                    pushFlow=dfs(source,sink,OO);
                    flow+=pushFlow;
                    if(pushFlow)
                        findNewPaths=1;
                }
            }
            return flow;
        }
};  


    // set<pair<T,T>> minCut(T source,T sink)
    // {
    //     set<pair<T,T>> cuts;
    //     bfs(source,sink);
    //     for(T u=1;u<=numberOfNodes;u++)
    //     {
    //         for(auto v:graph[u])
    //         {
    //             if(level[u]!=-1&&level[v.to]==-1)
    //                 cuts.insert({u,v.to});
    //         }
    //     }
    //     return cuts;
    // }


    // ll n,m;
    // cin >> n >> m;
    // dinicMaxFlow<ll> graph(n);
    // for(ll i=1;i<=m;i++)
    // {
    //     ll a,b,c;
    //     cin >> a >> b >> c;
    //     graph.addEdge(a,b,c);
    // }
    // cout << graph.getMaxFlow(1,n) << endl;