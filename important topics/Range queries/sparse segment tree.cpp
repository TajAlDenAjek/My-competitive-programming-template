








ll const N=2e5+2;
ll arr[N];

struct node
{
    ll val;
    node *left,*right;
    node():val(0),left(NULL),right(NULL){}
};
 
void update(node* &segTree,ll l,ll r,ll i,ll j,ll v)
{
    if(segTree==NULL) segTree=new node();
    if(j<l||r<i)
        return;
    if(i<=l&&r<=j)
    {
        segTree->val=v;
        return;
    }
    ll mid=(l+r)/2;
    if(i<=mid)
        update(segTree->left,l,mid,i,j,v);
    else
        update(segTree->right,mid+1,r,i,j,v);
}

ll query(node* &segTree,ll l,ll r,ll i,ll j)
{
    if(segTree==NULL||j<l||r<i)
        return 0;
    if(i<=l&&r<=j)
        return segTree->val;
    ll mid=(l+r)/2;
    
    return query(segTree->left,l,mid,i,j)+query(segTree->right,mid+1,r,i,j);

}











struct SegNode
{
    int Val, Lazy;
    SegNode *Right;
    SegNode *Left;
    SegNode() {
        Lazy = 0;
        Right = Left = NULL;
    }
};
 
void PushLazy(SegNode* &Node) {
    if (!Node->Lazy) return ;
 
    Node->Val = Node->Lazy;
        
    if (Node->Left == NULL) Node->Left = new SegNode();
    if (Node->Right == NULL)Node->Right = new SegNode();
 
    Node->Left->Lazy = Node->Lazy;
    Node->Right->Lazy = Node->Lazy;
    Node->Lazy = 0;
}
 
void Update(int i, int j, int Val, SegNode* &Node, int L = 0, int R = 1e9)
{
    if (Node == NULL)   Node = new SegNode();
    PushLazy(Node);
 
    if (R < i || L > j) return;
    if (L >= i && R <= j){
        Node->Lazy = Val;
        PushLazy(Node);
        return;
    }
 
    int Mid = L + R >> 1;
 
    if (i <= Mid)   Update(i, j, Val, Node->Left, L, Mid);
    if (j > Mid)    Update(i, j, Val, Node->Right, Mid + 1, R);
 }
 
int Query(int i, int j, SegNode* &Node, int L = 0, int R = 1e9)
{
    if (Node == NULL) return 0;
    PushLazy(Node);
 
    if (R < i || L > j) return 0;
    if (L >= i && R <= j)
        return Node->Val;
 
    int Mid = L + R >> 1;
    int Q1 = 0, Q2 = 0;
 
    if (i <= Mid)   Q1 = Query(i, j, Node->Left, L, Mid);
    if (j > Mid)    Q2 = Query(i, j, Node->Right, Mid + 1, R);
 
    return max(Q1, Q2);
}

SegNode* Root = NULL;