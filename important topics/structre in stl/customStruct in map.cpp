struct point
{
    ll x,y;
    string dir;
    point(ll a,ll b,string s):x(a),y(b),dir(s){}
};
struct comp
{
    bool operator()(point a,point b) const
    {
        if(a.x==b.x)
        {
            if(a.y==b.y)
                return a.dir<b.dir;
            return a.y<b.y;            
        }
        return a.x<b.x;
    }    
};


map<point,bool,comp> visited; 


struct point
{
    ll x,y;
    string dir;
    point(ll a,ll b,string s):x(a),y(b),dir(s){}
    bool operator<(const point &cur) const
    {
        if(this->x==cur.x)
        {
            if(this->y==cur.y)
                return this->dir>cur.dir;
            return this->y>cur.y;
        }
        return this->x>cur.x;
    }   
};

map<point,bool> visited; 