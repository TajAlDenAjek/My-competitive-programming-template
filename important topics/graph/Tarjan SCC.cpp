ll reachTime,numberOfSCC;
vector<ll> dfsIndex,lowLink,componentId;       
vector<bool> inStack;
stack<ll> Stack;

void init(ll n)
{
    dfsIndex.resize(n+2);
    lowLink.resize(n+2);
    componentId.resize(n+2);
    inStack.resize(n+2);
}

void tarjan(ll u)
{
   dfsIndex[u]=lowLink[u]=++reachTime;
   Stack.push(u);
   inStack[u]=1;
   for(auto v:graph[u])
   {
      if(!dfsIndex[v])
      {
         tarjan(v);
         lowLink[u]=min(lowLink[u],lowLink[v]);
      }
      else if(inStack[v])
      { 
         lowLink[u]=min(lowLink[u],lowLink[v]);
      }
   }
   if(dfsIndex[u]==lowLink[u])
   {
      while(true)
      {
         ll v=Stack.top(); 
         Stack.pop();
         inStack[v]=0;
         componentId[v]=numberOfSCC;
         if(v==u)
            break;
      }
      numberOfSCC++;
   }
}




// Bridges and articulation points


int tick; // current time
vector<int> dsc, low;
vector<int> artic;
int bridge_cnt;
        
void dfs(int u, int par=-1) {
   int children = 0;
   artic[u] = 0;
   dsc[u] = low[u] = ++tick;
        
   for(auto v : adj[u]) {
      if(v==par) continue; // bi-directional edge
      if(!dsc[v]) { // Forward Edge
         children++;
        
         dfs(v, u);
        
         artic[u] |= low[v] >= dsc[u]; // branch (v) can not get back to earler node than u
        
         bridge_cnt += low[v] > dsc[u]; // Edge (u, v) is a Bridge
        
         low[u] = min(low[u], low[v]);
      }
      else { // Backward Edge
         low[u] = min(low[u], low[v]);
      }
   }
   // if u is the root of the DFS spanning tree, then it must have more than one branch in order to be an articulation point
   artic[u] &= par!=-1;  
   artic[u] |= par==-1 && children>1;
}