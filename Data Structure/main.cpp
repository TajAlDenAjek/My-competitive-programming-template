#include <iostream>
#include <cassert>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
using namespace std;

const int Max_Element=100;
const int Max=5;
// stack implementation depending on array with certain size
//last IN first OUT LIFO
template<class t>
class arrayStack
{
    /* | top |
       |     |
       |     |
       | --- |  */
    private:
        int top=0;
        int items[Max_Element];
    public:
        arrayStack():top(-1)
        {

        }
        void push(t element)
        {
            if(top>=100-1)
            {
                cout << "The Stack is full" << endl;
            }
            else
            {
                top++;
                items[top]=element;
            }
        }
        bool isEmpty()
        {
            if(top==-1)
            {
                return true;
            }
            return false;
        }
        void pop()
        {
            if(isEmpty())
            {
                cout << "The stack is empty" << endl;
            }
            else
            {
                top--;
            }
        }
        void pop(t &element)
        {
            if(isEmpty())
            {
                cout << "The stack is empty" << endl;
            }
            else
            {
                element=items[top];
                top--;
            }
        }
        t getTop()
        {
            if(isEmpty())
            {
                cout << "The stack is empty" << endl;
            }
            else
            {
                return items[top];
            }
        }
        void print()
        {
            cout << "The stack Shape be like" << endl;
            for(int i=top;i>=0;i--)
            {
                cout << "\t" <<  items[i] << endl;
            }
        }
};
//stack implementation depending on list with dynamic size
//Last In First Out LIFO
template<class t>
class linkedStack
{
    private:
        struct node             // node [value|pointer]
        {
            t item;
            node *next;
        };
        node *top;
        node *current;
    public:
        linkedStack():top(NULL)
        {

        }
        void push(t newItem)
        {
            node *newItemPtr=new node;
            if(newItemPtr==NULL)
            {
                cout << "Error you can't allocate in memory" << endl;
            }
            else
            {
                newItemPtr->item=newItem;
                newItemPtr->next=top;
                top=newItemPtr;
            }
        }
        bool isEmpty()
        {
            return top==NULL;
        }
        void pop()
        {
            if(isEmpty())
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                node *temp=new node;
                temp=top;
                top=top->next;
                temp=temp->next=NULL;
                delete temp;
            }
        }
        void pop(t &StackTop)
        {
            if(isEmpty())
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                StackTop=top->item;
                node *temp=new node;
                temp=top;
                top=top->next;
                temp=temp->next=NULL;
                delete temp;
            }
        }
        t getTop()
        {
            if(isEmpty())
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                return top->item;
            }
        }
        void print()
        {
            current=top;
            while(current!=NULL)
            {
                cout <<"\t" << current->item << endl;
                current=current->next;
            }
        }
};
//solving problem of Balance Parentheses {([])}  using the stack
bool arePair(char open,char close);
bool areBalanced(string exp)
{
    linkedStack<char> s;
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        {
            s.push(exp[i]);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
        {
            if(s.isEmpty()|| !arePair(s.getTop(),exp[i]))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return s.isEmpty();
}
bool arePair(char open,char close)
{
    if(open=='(' && close==')')
    {
        return true;
    }
    else if(open=='{'&& close=='}')
    {
        return true;
    }
    else if(open=='['&&close==']')
    {
        return true;
    }
    else
    {
        return false;
    }
}
//****************************************************
//How compiler deal with the calculations and Expression Evaluation
// solving problems of Expression Evaluation on stack
// convert from infix -> 5+5=10 to postfix(suffix) -> 5 5 +   // prefix -> + 5 5
// the useful way to use postfix that it's does not use parentheses and it's too fast
// the parentheses is like a new block don't see the operator behind
string infixToPostfix(string infix)
{
    stack<char>s;
    string ans;
    int n=infix.length();
    for(int i=0;i<n;i++)
    {
        if(infix[i]!='*'&&infix[i]!='/'&&infix[i]!='+'&&infix[i]!='-'&&infix[i]!='('&&infix[i]!=')')
        {
            ans+=infix[i];
        }
        else
        {
            if(s.empty())
            {
                s.push(infix[i]);
            }
            else if(infix[i]==')' || infix[i]=='(')
            {
                if(infix[i]=='(')
                {
                    s.push(infix[i]);
                }
                else if(infix[i]==')')
                {
                    s.pop();
                    while(s.top()!='(')
                    {
                        ans+=s.top();
                        s.pop();
                    }
                }
            }
            else
            {
                char top=s.top();
                if((infix[i]=='-')||(infix[i]=='+'))
                {
                    ans+=top;
                    s.pop();
                    s.push(infix[i]);
                }
                else if(((infix[i]=='*')||(infix[i]=='/'))&&(top=='+')||(top=='-'))
                {
                    s.push(infix[i]);
                }
                else
                {
                    ans+=top;
                    s.pop();
                    s.push(infix[i]);
                }
            }
        }
    }
    while(!s.empty())
    {
        ans+=s.top();
        s.pop();
    }
    return ans;
}
//try to use numbers with one digit -> To not (يفرش الكود )
int gettingAnswer(string s)
{
    int ans=0;
    stack<int>st;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]!='*'&&s[i]!='/'&&s[i]!='+'&&s[i]!='-')
        {
            int x;
            x=(int)s[i]-48;
            st.push(x);
        }
        else
        {
            int temp1,temp2;
            temp1=st.top();
            st.pop();
            temp2=st.top();
            st.pop();
            char opr;
            int temp3=0;
            switch(opr)
            {
                case('*'):
                    temp3=temp1*temp2;
                    break;
                case('/'):
                    temp3=temp1/temp2;
                    break;
                case('+'):
                    temp3=temp1+temp2;
                    break;
                case('-'):
                    temp3=temp1-temp2;
                    break;
            }
            st.push(temp3);
        }
    }
    ans=st.top();
    return ans;
}
//*********************************************************************************************
//Queue implementation depending on circular Queue
//First in First Out  FIFO
//Queue shape be like |front | | | | | | | | rear|
//Time complexity add and remove front back O(1)    search O(n)
template<class t>
class circularQueue
{
    private:
        int frnt;   //start//front
        int rear;   //end
        int cnt;    //count
        t arr[Max]; //array with fixed size
        //if you want it to be a dynamic array you should do this
        // t *arr;
        //inside the constructor you will pass the size and make
        // arr = new int [sizeThat you passed]
    public:
        circularQueue()
        {
            frnt=0;
            rear=Max-1;
            cnt=0;
        }
        bool isEmpty()
        {
            return cnt==0;
        }
        bool isFull()
        {
            return cnt==Max;
        }
        void push(t element)
        {
            if(isFull())
            {
                cout << "Queue is Full  " << endl;
            }
            else
            {
                rear=(rear+1)%Max;
                arr[rear]=element;
                cnt++;
            }
        }
        void pop()
        {
            if(isEmpty())
            {
                cout << "Queue is Empty " << endl;
            }
            else
            {
                frnt=(frnt+1)%Max;
                cnt--;
            }
        }
        t getFront()
        {
            //we can use assert(condition function ) to Excptation Handling (try catch ) #include<cassert>
            //if true it will continue normally else it will break the program and give the number of row error
            //assert(!isEmpty());
            if(isEmpty())
            {
                cout << "Queue is Empty " << endl;
            }
            else
            {
                return arr[frnt];
            }
        }
        t getRear()
        {
            if(isEmpty())
            {
                cout << "Queue is Empty " << endl;
            }
            else
            {
                return arr[rear];
            }
        }
        void print()
        {   //there is a problem here solve it if you can :)  c++ Queue
            if(isEmpty())
            {
                cout << "Queue is Empty  " << endl;
            }
            else
            {
            /*  for(int i=frnt;i!=rear;i=(i+1)%Max)
                {
                    cout << arr[i] << " ";
                }
                cout << arr[rear];*/


             /* int i=frnt-1;
                while(i!=rear)
                {
                    i=(i+1)%Max;
                    cout << arr[i] << " " ;
                }*/
                while(!isEmpty())
                {
                    cout << getFront() << endl;
                    pop();
                }

            }
        }
        int searchh(t element)
        {
            //return -1 if it was not exist
            int pos=-1;
            if(!isEmpty())
            {
                for(int i=frnt;i!=rear;i=(i+1)%Max)
                {
                    if(arr[i]==element)
                    {
                        pos=i;
                        break;
                    }
                }
                if(pos==-1)
                {
                    if(arr[rear]==element)
                    {
                        pos=rear;
                    }
                }
            }
            else
            {
                cout << "Queue is Empty" << endl;
            }
            return pos;
        }
};
//********************************************************
//Linked Queue No fixed size
template<class t>
class linkedQueue
{
    private:
        struct node
        {
            t item;
            node *next;
        };
        node *frnt;//front first
        node *rear;//rear last
        int length;
    public:
        linkedQueue():frnt(NULL),rear(NULL),length(0){ }// constructor with value initializing

        bool isEmpty()
        {
            return rear==NULL;
        }
        void push(t element)
        {
            if(isEmpty())
            {
                frnt=new node;
                frnt->item=element;
                frnt->next=NULL;
                rear=frnt;
                length++;
            }
            else
            {
                node *newPtr=new node;
                newPtr->item=element;
                newPtr->next=NULL;
                rear->next=newPtr;
                rear=newPtr;
                length++;
            }
        }
        void pop()
        {
            if(isEmpty())
            {
                cout << "Queue is Empty" << endl;
            }
            else
            {
                node *temp=frnt;
                if(frnt==rear)
                {
                    frnt=rear=NULL;
                    length--;
                }
                else
                {
                    frnt=frnt->next;
                    temp->next=NULL;
                    free(temp); //delete temp;
                    length--;
                }
            }
        }
        t getFront()
        {
            assert(!isEmpty());
            return frnt->item;
        }
        t getRear()
        {
            assert(!isEmpty());
            return rear->item;
        }
        void clearQueue()
        {
            node *cur;
            while(frnt!=NULL)
            {
                cur=frnt;
                frnt=frnt->next;
                delete cur;
            }
            rear=NULL;
            length=0;
        }
        void print()
        {
            node *cur=frnt;
            while(cur!=NULL)
            {
                cout << cur->item << endl;
                cur=cur->next;
            }
        }
        int getSize()
        {
            return length;
        }
};
//****************************************************
// Array based list -> list based on dynamic array;
template<class t>
class arrayList
{
    private:
        t *arr;
        int maxSize;
        int length;
    public:
        arrayList(int s)
        {
            if(s<0)
            {
                maxSize=10;
            }
            else
            {
                maxSize=s;
            }
            length=0;
            arr=new t[maxSize];
        }
        bool isEmpty()
        {
            return length==0;
        }
        bool isFull()
        {
            return length==maxSize;
        }
        int getSize()
        {
            return length;
        }
        int Search(t element)
        {
            for(int i=0;i<length;i++)
            {
                if(arr[i]==element)
                {
                    return i;
                }
            }
            return -1;
        }
        void print()
        {
            for(int i=0;i<length;i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        void insertAtPos(int pos,t element)
        {
            if(isFull())
            {
                cout << "array is Full ! " << endl;
            }
            else if(pos<0 || pos > length)
            {
                cout << "Out of Range " << endl;
            }
            else
            {
                for(int i=length;i>pos;i--)
                {
                    arr[i]=arr[i-1];
                }
                arr[pos]=element;
                length++;
            }
        }
        void insertAtEnd(t element)
        {
            if(isFull())
            {
                cout << "Array is Full " << endl;
            }
            else
            {
                arr[length]=element;
                length++;
            }
        }
        void insertNoDuplicate(t element)
        {
            if(Search(element)==-1)
            {
                insertAtEnd(element);
            }
            else
            {
                cout << "The number is exist so we did't add it" << endl;
            }
        }
        void update(int pos,t element)
        {
            if(pos<0 || pos>=length)
            {
                cout << "Out of Range" << endl;
            }
            else
            {
                arr[pos]=element;
            }
        }
        t getElement(int pos)
        {
            if(pos<0 || pos>=length)
            {
                cout << "Out of Range" << endl;
            }
            else
            {
                return arr[pos];
            }
        }
        void removeAt(int pos)
        {
            if(isEmpty())
            {
                cout << "Array is Empty" << endl;
            }
            else if(pos<0 || pos>=length)
            {
                cout << "Out of Range" << endl;
            }
            else
            {
                for(int i=pos;i<length;i++)
                {
                    arr[i]=arr[i+1];
                }
                length--;
            }
        }
        void clean()
        {
            length=0;
        }
        ~arrayList()
        {
            delete[]arr;
        }
};
//***********************************************************************
// Linked List with head and tail
// add in the head and the tail with O(1) and in the center with O(n)
template<class t>
class linkedList
{
    private:
        struct node
        {
            t item;
            node *next;
        };
        node *head;
        node *tail;
        int length;
    public:
        linkedList():head(NULL),tail(NULL),length(0)
        {
        }
        bool isEmpty()
        {
            return length==0;
        }
        void insertFirst(t element)
        {
            node *newNode=new node;
            newNode->item=element;
            if(length==0)
            {
                head=tail=newNode;
                newNode->next=NULL;
            }
            else
            {
                newNode->next=head;
                head=newNode;
            }
            length++;
        }
        void insertLast(t element)
        {
            node *newNode=new node;
            newNode->item=element;
            if(length==0)
            {
                head=tail=newNode;
                newNode->next=NULL;
            }
            else
            {
                tail->next=newNode;
                newNode->next=NULL;
                tail=newNode;
            }
            length++;
        }
        void insertAtPos(int pos,t element)
        {
            if(pos<0 || pos>length)
            {
                cout << "Out of Range" << endl;
            }
            else
            {
                node *newNode=new node;
                newNode->item=element;
                if(pos==0)
                {
                    insertFirst(element);
                }
                else if(pos==length)
                {
                    insertLast(element);
                }
                else
                {
                    node *cur=head;
                    for(int i=1;i<pos;i++)
                    {
                        cur=cur->next;
                    }
                    newNode->next=cur->next;
                    cur->next=newNode;
                    length++;
                }
            }
        }
        void print()
        {
            node *temp=head;
            while(temp!=NULL)
            {
                cout << temp->item << " ";
                temp=temp->next;
            }
            cout << endl;
        }
        void removeFirst()
        {
            if(length==0)
            {
                cout << "The list is Empty" << endl;
            }
            else if(length==1)
            {
                delete head;
                head=tail=NULL;
                length--;
            }
            else
            {
                node *temp=head;
                head=head->next;
                delete temp;
                length--;
            }
        }
        void removeLast()
        {
            if(length==0)
            {
                cout << "The list is Empty" << endl;
            }
            else if(length==1)
            {
                delete head;
                head=tail=NULL;
                length--;
            }
            else
            {
                node *cur,*prev;
                cur=head->next;
                prev=head;
                while(cur->next!=NULL)
                {
                    prev=cur;
                    cur=cur->next;
                }
                delete cur;
                prev->next=NULL;
                tail=prev;
                length--;
            }
        }
        void removee(t element)
        {
            if(isEmpty())
            {
                cout << "The list is Empty" << endl;
                return ;
            }
            node *cur,*prev;
            if(head->item==element)
            {
                cur=head;
                head=head->next;
                delete cur;
                length--;
                if(length==0)
                {
                    tail=NULL;
                }
            }
            else
            {
                cur=head->next;
                prev=head;
                while(cur!=NULL && cur->item!=element)
                {
                    prev=cur;
                    cur=cur->next;
                }
                if(cur==NULL)
                {
                    cout << "The element not found" << endl;
                }
                else
                {
                    prev->next=cur->next;
                    if(tail==cur)
                    {
                        tail=prev;
                    }
                    delete cur;
                    length--;
                }
            }
        }
        void reversee()
        {
            node *prev,*cur,*next;
            prev=NULL;
            cur=head;
            next=cur->next;
            while(next!=NULL)
            {
                next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
            }
            head=prev;
        }
        int searchh(t element)
        {
            node *temp=head;
            int pos=0;
            while(temp!=NULL)
            {
                if(temp->item==element)
                {
                    return pos;
                }
                else
                {
                    temp=temp->next;
                    pos++;
                }
            }
            return -1;
        }
};
//*************************************************************************
//Doubly linked list every node got two pointers one in the previous and the other refer to the next node
//you can loop from two destination
//the only bad thing that the doubly linked list take a lot of memory because every node has two pointers
template<class t>
class doublyLinkedList
{
    private:
        struct node
        {
            t item;
            node *prev;
            node *next;
        };
        node *first;
        node *last;
        int length;
    public:
        doublyLinkedList():first(NULL),last(NULL),length(0)
        {
        }
        bool isEmpty()
        {
            return (first==NULL);
        }
        void insertFirst(t element)
        {
            node *newNode=new node;
            newNode->item=element;
            if(length==0)
            {
                first=last=newNode;
                newNode->next=newNode->prev=NULL;
            }
            else
            {
                newNode->next=first;
                newNode->prev=NULL;
                first->prev=newNode;
                first=newNode;
            }
            length++;
        }
        void insertLast(t element)
        {
            node *newNode=new node;
            newNode->item=element;
            if(length==0)
            {
                first=last=newNode;
                newNode->next=newNode->prev=NULL;
            }
            else
            {
                newNode->prev=last;
                newNode->next=NULL;
                last->next=newNode;
                last=newNode;
            }
            length++;
        }
        void insertAtPos(int pos,t element)
        {
            if(pos<0 || pos>length)
            {
                cout << "Out of Range ..! " << endl;
            }
            else
            {
                node *newNode=new node;
                newNode->item=element;
                if(pos==0)
                {
                    insertFirst(element);
                }
                else if(pos==length)
                {
                    insertLast(element);
                }
                else
                {
                    node *cur=first;
                    for(int i=1;i<pos;i++)
                    {
                        cur=cur->next;
                    }
                    newNode->next=cur->next;
                    newNode->prev=cur;
                    cur->next=newNode;
                    cur->next->prev=newNode;
                    length++;
                }
            }
        }
        void removeFirst()
        {
            if(length==0)
            {
                cout << "Empty" << endl;
            }
            else if(length==1)
            {
                delete first;
                first=last=NULL;
                length--;
            }
            else
            {
                node *cur=first;
                first=first->next;
                first->prev=NULL;
                delete cur;
                length--;
            }
        }
        void removeLast()
        {
            if(length==0)
            {
                cout << "Empty List" << endl;
            }
            else if(length==1)
            {
                delete last;
                last=first=NULL;
                length--;
            }
            else
            {
                node *cur=last;
                last=last->prev;
                last->next=NULL;
                delete cur;
                length--;
            }
        }
        void removee(t element)
        {
            if(length==0)
            {
                cout << "The list is Empty " << endl;
                return ;
            }
            if(first->item==element)
            {
                removeFirst();
            }
            else
            {
                node *cur=first->next;
                while(cur!=NULL)
                {
                    if(cur->item==element)
                    {
                        break;
                    }
                    cur=cur->next;
                }
                if(cur==NULL)
                {
                    cout << "Element not found" << endl;
                }
                else if(cur->next==NULL)
                {
                    removeLast();
                }
                else
                {
                    cur->prev->next=cur->next;
                    cur->next->prev=cur->prev;
                    delete cur;
                    length--;
                }
            }
        }
        void display()
        {
            node *cur=first;
            while(cur!=NULL)
            {
                cout << cur->item << " ";
                cur=cur->next;
            }
            cout << "\n";
        }
        void displayReverse()
        {
            node *cur=last;
            while(cur!=NULL)
            {
                cout << cur->item << " ";
                cur=cur->prev;
            }
            cout << "\n";
        }
        void clean()
        {
            node *temp;
            while(first!=NULL)
            {
                temp=first;
                first=first->next;
                delete temp;
            }
            last=NULL;
            length=0;
        }
        ~doublyLinkedList()
        {
            node *temp;
            while(first!=NULL)
            {
                temp=first;
                first=first->next;
                delete temp;
            }
            last=NULL;
            length=0;
        }
};
//**************************************************************
//trees very fast data structures with O(log n)
//binary search tree
template<class t>
class binarySearchTree
{
    private:
        struct node
        {
            t item;
            node *left;
            node *right;
        };
        node *root;
        int max(int x,int y)
        {
            if(x>=y)
            {
                return x;
            }
            else
            {
                return y;
            }
        }

        int height(node *p)
        {
            if(p==NULL)
            {
                return 0;
            }
            else
            {
                return 1+max(height(p->left),height(p->right));
            }
        }
        void inorder(node *p)
        {
            if(p!=NULL)
            {
                inorder(p->left);
                cout << p->item << " ";
                inorder(p->right);
            }
        }
        void preorder(node *p)
        {
            if(p!=NULL)
            {
                cout << p->item << " ";
                preorder(p->left);
                preorder(p->right);
            }
        }
        void postorder(node *p)
        {
            if(p!=NULL)
            {
                postorder(p->left);
                postorder(p->right);
                cout << p->item << " ";
            }
        }
        int nodeCount(node *p)
        {
            if(p==NULL)
            {
                return 0;
            }
            else
            {
                return 1+nodeCount(p->left)+nodeCount(p->right);
            }
        }
        int leavesCount(node *p)
        {
            if(p==NULL)
            {
                return 0;
            }
            else if((p->left==NULL)&&(p->right==NULL))
            {
                return 1;
            }
            else
            {
                return leavesCount(p->left) + leavesCount(p->right);
            }
        }
        void clear(node* &p)
        {
            if(p!=NULL)
            {
                clear(p->left);
                clear(p->right);
                delete p;
                p=NULL;
            }
        }
        bool searchRecPrivate(node *p,t element)
        {
            if(p==NULL)
                return false;
            else if(p->item == element)
                return true;
            else if(p->item > element)
                return searchRecPrivate(p->left,element);
            else
                return searchRecPrivate(p->right,element);
        }
        void deleteFromTree(node* &p)
        {
            node *cur;      //pointer to traverse the tree
            node *trailCur; //pointer behind the current
            node *temp;     //pointer to delete the node
            if(p->left==NULL && p->right==NULL) // a leaf node or a tree with single node which is root
            {
                delete p;
                p=NULL;
            }
            else if(p->left==NULL)
            {
                temp=p;
                p=p->right;
                delete temp;
            }
            else if(p->right==NULL)
            {
                temp=p;
                p=p->left;
                delete p;
            }
            else
            {
                cur=p->left;
                trailCur=NULL;
                while(cur->right!=NULL)
                {
                    trailCur=cur;
                    cur=cur->right;
                }
                p->item=cur->item;
                if(trailCur==NULL)      //cur did not move
                {                       //cur==p->left; adjust p
                    p->left=cur->left;
                }
                else
                {
                    trailCur->right=cur->left;
                }
                delete cur;
            }
        }
    public:
        binarySearchTree():root(NULL)
        {
        }
        bool isEmpty()
        {
            return root==NULL;
        }
        int treeHeight()
        {
            return height(root);
        }
        void inorderTraversal() // left root right
        {
            return inorder(root);
            cout << endl;
        }
        void preorderTraversal()// root left right
        {
            return preorder(root);
            cout << endl;
        }
        void postorderTraversal()// left right root
        {
            return postorder(root);
            cout << endl;
        }
        int treeNodeCount()
        {
            return nodeCount(root);
        }
        int treeLeavesCount()
        {
            return leavesCount(root);
        }
        void clearTree()
        {
            return clear(root);
        }
        bool search(t element)
        {
            node *current = root;
            while(current != NULL)
            {
                if(current->item == element)
                    return true;
                else if(current->item > element)
                    current = current->left;
                else
                    current = current->right;
            }
            return false;
        }
        bool searchRec(t element)
        {
            return searchRecPrivate(root,element);
        }
        void add(t element)
        {
            node *cur;      // pointer to traverse the tree
            node *trailCur; // pointer behind the cur pointer
            node *newNode;  // pointer to create the node
            newNode=new node;
            assert(newNode!=NULL);
            newNode->item=element;
            newNode->left=NULL;
            newNode->right=NULL;
            if(root==NULL)
            {
                root=newNode;
                return ;
            }
            else
            {
                cur=root;
                while(cur!=NULL)
                {
                    trailCur=cur;
                    if((cur->item)==element)
                    {
                        cout << "The element is already exist " << endl;
                        cout << "The duplicates elements are not allowed to be here" << endl;
                        return ;
                    }
                    else
                    {
                        if((cur->item)>element)
                        {
                            cur=cur->left;
                        }
                        else
                        {
                            cur=cur->right;
                        }
                    }
                }
            }
            if(trailCur->item>element)
            {
                trailCur->left=newNode;
            }
            else
            {
                trailCur->right=newNode;
            }
        }
        //this function only determines the node to be deleted
        void remove(t element)
        {
            node *cur;      //pointer to traverse the tree
            node *trailCur; //pointer behind the current pointer
            if(root==NULL)      // if(isEmpty())
            {
                cout << "Cannot delete from empty tree" << endl;
                return ;
            }
            if(root->item==element)
            {
                deleteFromTree(root);
                return ;
            }
            // if we get here,then the item to be deleted is not root
            trailCur=root;
            if(root->item>element)
            {
                cur=root->left;
            }
            else
            {
                cur=root->right;
            }
            //search for the element to be deleted
            while(cur!=NULL)
            {
                if(cur->item==element)
                {
                    break;
                }
                else
                {
                    trailCur=cur;
                    if(cur->item>element)
                    {
                        cur=cur->left;
                    }
                    else
                    {
                        cur=cur->right;
                    }
                }
            }// the cur pointer will be NULL or another pointer
            if(cur==NULL)
            {
                cout << "The element is not exist in the tree" << endl;
            }
            else if(trailCur->item>element)
            {
                deleteFromTree(trailCur->left);
            }
            else
            {
                deleteFromTree(trailCur->right);
            }
        }
        ~binarySearchTree()
        {
            clear(root);
        }
};
//*******************************************************************8
//Sorting algorithms
//first Selection sort algorithm
//O(n^2) , no extra space , space complexity O(1) , depends on In-Place , usually used with small arrays
void selectionSort(int arr[],int n)
{
    int minInd;
    for(int i=0;i<n-1;i++)
    {
        minInd=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minInd]) // if you want a decreasing order just put > instead of <
            {
                minInd=j;
            }
        }
        swap(arr[minInd],arr[i]);
    }
}
//Second Bubble sort algorithm
//O(n^2) ,In-Place ,no extra space
void bubbleSort(int arr[],int n)
{
    bool flag=true;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag=false;
            }
        }
        if(flag)
        {
            break;
        }
    }
}
//third Insertion Sort simple sort algorithm
//In-place no extra space , depends on shifting // which do good with linked list but in arrays take a lot of time
//O(n^2) // maximum #passes n-1
//works the way we sort playing cards in our hands
void insertionSort(int arr[],int n)
{
    int key,j;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
//fourth merge sort algorithm (divide and conquer) ->big problem ->sub problems ->sub solutions -> solution  (recursive)
//Time complexity O(n log n) /space complexity : O(n)
void mergee(int arr[],int l,int m,int r) // m=l+(r-1) /2    l= index in left  / r = index in right
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int *L=new int[n1];
    int *R=new int[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j]=arr[m+1+j];
    }
    i=j;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[i])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        mergee(arr,l,m,r);
    }
}//there is bug try to fix it :)
//fifth Quick sort algorithm (divide and conquer)
//Time complexity :O(n log2 n)  & space complexity : O(1)
int part(int arr[],int L,int H)
{
    int p=arr[L];
    int i=L;
    int j=H;
    while(i<j)
    {
        do
        {
            i++;
        }while(arr[i]<=p);
        do
        {
            j--;
        }
        while(arr[j]>p);
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[L],arr[j]);
    return j;
}
void quickSort(int arr[],int L,int H)
{
    if(L<H)
    {
       int piv=part(arr,L,H);
       quickSort(arr,L,piv-1);
       quickSort(arr,piv+1,H);
    }
}// there is a bug try to fix it  hint in the partition function :)
//sixth Heap Sort algorithm (complete binary tree)
//Time complexity : O(n log n) , space complexity : O(1);
//we make an array be like a tree if we start the index at 0 the right left child will be left(i)=2*i; / right(i)=2*i+1; /parent(i)=i/2 to the floor
//if we start the index at 1 ->  left(i)=2*i +1 , /right(i)=2*i+2/parent(i)=i/2-1 to the floor
//we make heap then get a max heap(every parent more than his childes) or a min heap (every parent less than his childes)
//nearly the best sort algorithm take the positive points of merge and quick sort algorithms
void heapify(int arr[],int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int max=i;
    if(l<n && arr[l]>arr[max])
    {
        max=l;
    }
    if(r<n && arr[r]>arr[max])
    {
        max=r;
    }
    if(max!=i)
    {
        swap(arr[i],arr[max]);
        heapify(arr,n,max);
    }
}
void buildHeap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}
void heapSort(int arr[],int n)
{
    buildHeap(arr,n);
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
//**********************************************************************************
//Searching algorithms
//first the linear search : O(n)
int linearSearch(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}
//second Binary search (half-interval search) (logarithmic search) (divide and conquer)
//if you are trying to find a page in book what you will do ? -> it's the same thing in the binary search
//Time complexity : O(log n) | space complexity : O(1)
int binarySearch(int arr[],int l,int h,int key)
{
    while(l<=h)
    {
        int m=(l+h)/2;
        if(arr[m]==key)
        {
            return m;
        }
        if(arr[m]>key)
        {
            h=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    return -1;
}//there is a bug try to fix it :)
//**********************************************************************
//There is also another searching algorithms like BFS & DFS and dijkstra's algorithm we use those algorithms in graphs and trees
//**********************************************************************
//Segment trees very good data structures
class sumSegmentTree
{
    private:
        int getMid(int s,int e)
        {
            return s+(e-s)/2;
        }
        int constructingUtil(int arr[],int startIndex,int endIndex,int *segTree,int curIndex)
        {
           if(startIndex==endIndex)
           {
               segTree[curIndex]= arr[startIndex];
               return arr[startIndex];
           }
           int mid=getMid(startIndex,endIndex);
           segTree[curIndex]=constructingUtil(arr,startIndex,mid,segTree,curIndex*2+1) + constructingUtil(arr,mid+1,endIndex,segTree,curIndex*2+2);
           return segTree[curIndex];
        }
        void updateValUtil(int *segTree,int startIndex,int endIndex,int i,int diff,int curIndex)
        {
            if(i<startIndex||i>endIndex)
                return ;
            segTree[curIndex]+=diff;
            if(startIndex!=endIndex)
            {
                int mid=getMid(startIndex,endIndex);
                updateValUtil(segTree,startIndex,mid,i,diff,curIndex*2+1);
                updateValUtil(segTree,mid+1,endIndex,i,diff,curIndex*2+2);
            }
        }
        int getSumUtil(int *segTree,int startIndex,int endIndex,int left,int right,int curIndex)
        {
            if(left<=startIndex&&right>=endIndex)
            {
                return segTree[curIndex];
            }
            if(endIndex<left||startIndex>right)
            {
                return 0;
            }
            int mid=getMid(startIndex,endIndex);
            return getSumUtil(segTree,startIndex,mid,left,right,curIndex*2+1)+getSumUtil(segTree,mid+1,endIndex,left,right,curIndex*2+2);
        }
    public:
        int *constructing(int arr[],int n)
        {
            int height=(int)(ceil(log2(n)));
            int max_size=2*(int)pow(2,height)-1;
            int *segTree=new int[max_size];
            constructingUtil(arr,0,n-1,segTree,0);
            return segTree;
        }
        void updateVal(int arr[],int *segTree,int n,int i,int v)
        {
            if(i<0||i>n-1)
            {
                cout << "Out of Range" << endl;
                return ;
            }
            int diff=v-arr[i];
            arr[i]=v;
            updateValUtil(segTree,0,n-1,i,diff,0);
        }
        int getSum(int *segTree,int n,int left,int right)
        {
            if(left<0||right>n-1||left>right)
            {
                cout << "Out of Range , Invalid range  " << endl;
                return -1;
            }
            return getSumUtil(segTree,0,n-1,left,right,0);
        }
};
//**************
class maxSegmentTree
{
    private:
       int getMid(int s,int e)
       {
           return s+(e-s)/2;
       }
       int constructSTUtil(int arr[], int startIndex, int endIndex,int* segTree, int curIndex)
        {
            if (startIndex == endIndex)
            {
                segTree[curIndex] = arr[startIndex];
                return arr[startIndex];
            }
            int mid = getMid(startIndex,endIndex);
            segTree[curIndex]=max(constructSTUtil(arr,startIndex,mid,segTree,curIndex*2+1),constructSTUtil(arr, mid + 1,endIndex,segTree,curIndex*2+2));
            return segTree[curIndex];
        }
        int MaxUtil(int* st,int ss,int se,int l,int r, int node)
        {
            if (l <= ss && r >= se)
                return st[node];
            if (se < l || ss > r)
                return -1;
            int mid = getMid(ss, se);
            return max(MaxUtil(st,ss,mid,l,r, 2 * node + 1),MaxUtil(st,mid + 1,se,l,r,2 * node + 2));
        }
    public:
        int* constructST(int arr[], int n)
        {
            int height = (int)(ceil(log2(n)));
            int max_size = 2 * (int)pow(2,height) - 1;
            int* st = new int[max_size];
            constructSTUtil(arr,0,n-1,st,0);
            return st;
        }
        void updateValue(int arr[], int* st, int ss, int se,int index, int value, int node)
        {
            if (index < ss || index > se)
            {
                cout << "Invalid Input" << endl;
                return;
            }
            if (ss == se)
            {
                arr[index] = value;
                st[node] = value;
            }
            else
            {
                int mid = getMid(ss, se);
                if (index >= ss && index <= mid)
                    updateValue(arr, st,ss,mid,index, value, 2 * node + 1);
                else
                    updateValue(arr,st,mid + 1,se,index,value, 2 * node + 2);
                st[node] = max(st[2 * node + 1], st[2 * node + 2]);
            }
            return;
        }
        int getMax(int* st, int n, int l, int r)
        {
            if (l < 0 || r > n - 1 || l > r)
            {
                printf("Invalid Input");
                return -1;
            }
            return MaxUtil(st, 0, n - 1, l, r, 0);
        }
};
//*********
class minSegmentTree
{
    private:
       int getMid(int s,int e)
       {
           return s+(e-s)/2;
       }
       int constructSTUtil(int arr[], int startIndex, int endIndex,int* segTree, int curIndex)
        {
            if (startIndex == endIndex)
            {
                segTree[curIndex] = arr[startIndex];
                return arr[startIndex];
            }
            int mid = getMid(startIndex,endIndex);
            segTree[curIndex]=min(constructSTUtil(arr,startIndex,mid,segTree,curIndex*2+1),constructSTUtil(arr, mid + 1,endIndex,segTree,curIndex*2+2));
            return segTree[curIndex];
        }
        int MinUtil(int* st,int ss,int se,int l,int r, int node)
        {
            if (l <= ss && r >= se)
                return st[node];
            if (se < l || ss > r)
                return -1;
            int mid = getMid(ss, se);
            return min(MinUtil(st,ss,mid,l,r, 2 * node + 1),MinUtil(st,mid + 1,se,l,r,2 * node + 2));
        }
    public:
        int* constructST(int arr[], int n)
        {
            int height = (int)(ceil(log2(n)));
            int max_size = 2 * (int)pow(2,height) - 1;
            int* st = new int[max_size];
            constructSTUtil(arr,0,n-1,st,0);
            return st;
        }
        void updateValue(int arr[], int* st, int ss, int se,int index, int value, int node)
        {
            if (index < ss || index > se)
            {
                cout << "Invalid Input" << endl;
                return;
            }
            if (ss == se)
            {
                arr[index] = value;
                st[node] = value;
            }
            else
            {
                int mid = getMid(ss, se);
                if (index >= ss && index <= mid)
                    updateValue(arr, st,ss,mid,index, value, 2 * node + 1);
                else
                    updateValue(arr,st,mid + 1,se,index,value, 2 * node + 2);
                st[node] = min(st[2 * node + 1], st[2 * node + 2]);
            }
            return;
        }
        int getMin(int* st, int n, int l, int r)
        {
            if (l < 0 || r > n - 1 || l > r)
            {
                printf("Invalid Input");
                return -1;
            }
            return MinUtil(st, 0, n - 1, l, r, 0);
        }
};
//if you need the implementation you must search and find it Good bye
int main()
{
    cout << "Hello Data Structure for Beginners  " << endl;
    int n,q,t,l,r,i,v;
    cin >> n >> q;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >>arr[i];
    }
    sumSegmentTree sum;
    minSegmentTree mini;
    maxSegmentTree maxo;
    int *sumTree=sum.constructing(arr,n);
    int *minTree=mini.constructST(arr,n);
    int *maxoTree=maxo.constructST(arr,n);
    while(q--)
    {
        cin >> t;
        if(t==1)
        {
            cin >> l >> r;
            l--;
            r--;
            cout << mini.getMin(minTree,n,l,r) << endl;
        }
        else
        {
            cin >> i >> v;
            i--;
            sum.updateVal(arr,sumTree,n,i,v);
            mini.updateValue(arr,minTree,0,n-1,i,v,0);
            maxo.updateValue(arr,maxoTree,0,n-1,i,v,0);
        }
    }
    return 0;
}

