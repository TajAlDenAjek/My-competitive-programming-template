template<typename T> 
class Trie
{
    public:
    struct node
    {
        map<char,node*> alphabet;
        T numberOfPrefixes;
        T wordFreq;
        node():numberOfPrefixes(0),wordFreq(0){}
        node(T a,T b):numberOfPrefixes(a),wordFreq(b){}
    };
    node *root;
    Trie()
    {
        root=new node();
    }
    void insert(string &s)
    {
        node *cur=root;
        for(T i=0;i<(T)s.size();i++)
        {
            char c=s[i];
            node *child=cur->alphabet[c];
            if(!child)
            {
                child=new node();
                cur->alphabet[c]=child;
            }
            cur=child;
            cur->numberOfPrefixes++;
        }
        cur->wordFreq++;
    }
    bool search(string &s)
    {
        node *cur=root;
        for(T i=0;i<(T)s.size();i++)
        {
            char c=s[i];
            node *child=cur->alphabet[c];
            if(!child)
            {
                return false;
            }
            cur=child;
        }
        return (cur->wordFreq>=1?true:false);
    }
    T count(string &s)
    {
        node *cur=root;
        for(T i=0;i<(T)s.size();i++)
        {
            char c=s[i];
            node *child=cur->alphabet[c];
            if(!child)
            {
                return 0;
            }
            cur=child;
        }
        return cur->wordFreq;
    }
    void erase(string &s)
    {
        node *cur=root;
        for(T i=0;i<(T)s.size();i++)
        {
            char c=s[i];
            node *child=cur->alphabet[c];
            if(!child)
            {
                return;
            }
            cur=child;
            cur->numberOfPrefixes--;
        }
        cur->wordFreq--;
    }
    T countPrefixes(string &s)
    {
        node *cur=root;
        for(T i=0;i<(T)s.size();i++)
        {
            char c=s[i];
            node *child=cur->alphabet[c];
            if(!child)
            {
                return 0;
            }
            cur=child;
        }
        return cur->numberOfPrefixes;
    }
};

 