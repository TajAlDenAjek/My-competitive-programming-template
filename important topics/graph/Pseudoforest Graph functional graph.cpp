int tick = 0;
vector<int> to;
vector<int> dsc, anc, reach;

int dfs(int u) {
   dsc[u] = ++tick;
   int v = to[u]; // the  outgoing edge of u

   if(reach[v]) { // already visited
      reach[u] = reach[v] + 1;
      return -1;
   }
   else if(anc[v]) { // on stack => backward edge
      reach[u] = dsc[u] - dsc[v] + 1; // cycle size
      return v; // the start of the cycle
   }

   anc[u] = 1;
   int x = dfs(v);
   anc[u] = 0;

   if(x == -1) {
      reach[u] = reach[v] + 1;
      return -1;
   }
   else {
      reach[u] = reach[v];
      return x==u ? -1 : x;
   }
}

int32_t main()
{

   int tc; cin>>tc;
   for(int t=1 ; t<=tc ; t++) {
      int n; cin>>n;
      dsc = anc = reach = to = vector<int>(n);

      for(int i=0 ; i<n ; i++) {
         int u, v; cin>>u>>v; u--; v--;
         to[u] = v;
      }

      for(int i=0 ; i<n ; i++) {
         if(!reach[i]) dfs(i);
      }

      cout << "Case " << t << ": " << max_element(reach.begin(), reach.end()) - reach.begin() + 1 << endl;
   }
}