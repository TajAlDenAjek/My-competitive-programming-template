struct example{
   int height;
   int weight;
};

struct comp{
        bool operator()(struct example a, struct example b){
         //Sorting on the basis of height(Just for example)
            return (a.height > b.height); // these give you (max priority queue)
	    return (a.height < b.height); // these give you (min priority queue)
        }
    };

// And here comes your priority queue
 priority_queue<struct example, vector<struct example>, comp> pq;
struct example your_obj;
pq.push(your_obj);

notice we have the priorty for the b not for the a keep it in mind


struct state
    {
        bool isUsed;
        ll cost,node;
        state(bool a,ll b,ll c):isUsed(a),cost(b),node(c){}
        bool operator<(const state &cur) const
        {
            return this->cost>cur.cost;
        }
    };
    priority_queue<state> pq;
    pq.push({1,2,5});
    pq.push({1,52,3});
    pq.push({1,4,5});
    pq.push({1,2,5});
    pq.push({1,22,5});
    while(!pq.empty())
    {
        cout << pq.top().cost << endl;
        pq.pop();
    }