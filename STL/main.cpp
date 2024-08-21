#include <iostream>
#include <string>

//the STL
#include <algorithm>
//iterator is a pointer to an address whenever we want to print the value we put * behind the iterator
#include <iterator>
// The containers
//sequence containers
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
//simple containers
#include <utility> //for pair
#include <tuple>
// a tuple is an object that stores more than one variable in different data types

//Associative container
#include <set>
#include <map>
//Unordered Associative containers
#include <unordered_set>
#include <unordered_map>
//Adapter sequence containers
#include <stack>
#include <queue>
//using a special algorithm for comparing
template<typename type>
struct com
{
    bool operator()(const type &first,const type &second)const
    {
        return first>second;
    }
    //map<int,string,com<int>>mp;
    //map<int,string,greater<int>>mp;
};
//NameSpace ("work station");
using namespace std;

//Main Function
int main()
{

    //The array how to use
    //defining data type nameOfArray and [] or [][] or [][]...[] ;
    //linear container ||.||.||.||
    cout << "The array" << endl;

    int a[10]={0,1,2,3,4,5,6,7,8,9};
    a[3]=59;
    sort(a,a+10);
    reverse(a,a+10);
    cout << sizeof(a) << endl;
    cout << sizeof(a)/sizeof(a[0]) << endl;
    for(int i=0;i<10;i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n****************************" << endl;


    //The vector how to use
    // defining vector <data type> nameOfTheVector or nameOfTheVector(size);
    //By default the Initial value of any vector is Zero (0)
    //you can make initial value by v(numberOfElements,Initial value)
    //dynamic size
    //linear container ||.||.||.||
    // adding and deleting from back only  with O(1)
    //support the random access v[] || v.at(index)
    cout << "The Vector" << endl;

    //defining
    vector <int> v,v1;
    //iterators
    vector <int> ::iterator regularIterator=v.begin();                        //v.end();
    vector <int> ::const_iterator constantIterator=v.cbegin();                //v.cend();  we usually use the constant
    vector <int> ::reverse_iterator reverseIterator=v.rbegin();               //v.rend();  when we are building an algorithm
    vector <int> ::const_reverse_iterator constantReverseIterator=v.crbegin();//v.crend();
    auto it=v.begin(); //this auto will define the iterator depending on the type of the Iterator
    //adding to the vector
    v.push_back(6);
    v.insert(v.begin(),5); // add in any place you want O(1) -> O(N)
    v.insert(v.begin(),3,2); //v.insert(place,numberOfTimes,value);
    /*Function emplace() :is a new function used in c++ 20 version
        syntax                      vectorName.emplace(place,value);
        also we can write like      v.emplace(place,numberOfTimes,value);
        we can use the way          v.emplace_back(value);
        which it's another option instead of using push_back
     the befits of the emplace function are better space using and faster than the other common function */
    //Random Access
    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << v.at(2) << endl;
    cout << v[4] << endl;
    //deleting from vector    (remember always try to work with iterator cuz it's so fast)
    v.pop_back();
    v.erase(v.end()-1);           //giving a certain place
    v.erase(v.end()-2,v.end());   //giving a range
    //another functions
    v.swap(v1);
    v1.swap(v);
    cout << v.size() << endl;      // function   v.resize(newSize); new Size without destruction for elements
    // function v.shrink_to_fit(newSize) new Size with destruction for elements
    cout << v.capacity() << endl;  //when we add an element the vector will assign bigger size
    cout << v.max_size() << endl;  //the max number we can let it in the memory
    cout << v.empty() << endl;     //return 1 if it was empty and 0 if it has one element at least

    //some algorithms with vector
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    cout <<  *min_element(v.begin(),v.end()) << endl;
    cout <<  *max_element(v.begin(),v.end()) << endl;
    auto pairV=minmax_element(v.begin(),v.end());
    cout << *pairV.first << endl;
    cout << *pairV.second << endl;
    v.clear(); //destroy everything */
  //  find_if(v.begin(),v.end(),function); we but our condition inside the function
    vector <int> NewV{1,2,3,4,5};
  // ways to output the elements inside a vector
    for(int i=0;i<NewV.size();i++)
    {
        cout << NewV[i] << " ";
        if(i==NewV.size()-1)
        {
            cout << "\n" ;
        }
    }
    for(auto someThingLikeIndex:NewV)
    {
        cout << someThingLikeIndex << " ";
    }
    cout << endl;
    for(auto iteratorV=NewV.begin();iteratorV!=NewV.end();iteratorV++)
    {
        cout << *iteratorV << " ";
    }
    cout << endl;
    copy(NewV.begin(),NewV.end(),ostream_iterator<int>(cout," "));

    cout << "\n********************************************************" << endl;
    //The Deque
    cout << "The Deque" << endl;
    //fast adding and deleting from front and end with complexity O(1)
    //syntax deque <dataType> nameOfDeque
    deque <int> d{1,2,3,4,5,6};
    //adding
    d.push_back(7);
    d.push_front(0);
    d.insert(d.end(),8);
    d.insert(d.begin(),2,0);
    d.emplace_back(4);
    // 0 0 0 1 2 3 4 5 6 7 8 4

    //deleting
    d.pop_back();
    d.pop_front();
    d.erase(d.end());
    d.erase(d.end()-3,d.end());

    //place or random access
    cout << d.front() << endl;
    cout << d.back() << endl;
    cout << d[0] << endl;
    //another functions
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    //swap two deques d1.swap(d2);
    cout << d.size() << endl;
    cout << d.max_size() << endl;
    d.resize(2);
    d.shrink_to_fit();
    cout << d.empty() << endl;
    //ways to output a deque
    for(int i=0;i<d.size();i++)
    {
        cout << d[i] << " ";
    }
    for(auto iteratorD=d.begin();iteratorD!=d.end();iteratorD++)
    {
        cout << *iteratorD << " ";
    }
    for(auto someThingLikeIndex:d)
    {
        cout << someThingLikeIndex << " ";
    }
    d.clear();
    cout << "\n******************************************************************\n";
    //The list
    cout << "The List" << endl;
    //No random access L[] / L.at()
    //dual linked list
    //So fast in operation adding deleting searching in all places
    //everyElement has two pointers one before and one after
    //defining list <dataType> nameOfList;
    // in the list we can't do operation like + - on the iterator directly so we do the operation before we use
    // auto it=something,  it-- it++ until we reach to the place we want

    list <int> L{1,2,3,4,5};

    //adding
    L.push_back(6);
    L.push_front(0);
    L.emplace_back(7);  //L.emplace(certain place);
    L.insert(L.end(),7);//L.insert(place,times,value);
    //0 1 2 3 4 5 6 7 7
    L.assign(4,0);      //L.assign(times,InitialValue);
    // 0 0 0 0
    //deleting
    L.pop_front();
    L.pop_back();
    L.remove(7);     //delete all values that equal to seven
    L.erase(L.begin());//also we can but range
    L.remove_if([](int x){return x%2;}); //removing with a certain condition we but the condition inside a function
    //[] means that function don't have a name
    //another functions
    L.sort();
    L.sort(greater<int>());
    L.reverse();
    cout << L.front() << " " << L.back() << endl;
    cout << L.size() << " " << L.empty() << endl;
    L.resize(3);
    list<int> L2{1,2,3,4,5},L3{1,2,3};
    L.merge(L2);         //merging the two lists into one list which it's L and destroy L2
    L.splice(L.end(),L3);//merging in certain place
    // 0 0 0 1 2 3 4 5 1 2 3
    L.unique();         //delete duplicates in  a row
    // 0 1 2 3 4 5 1 2 3
    L.remove_if([](int x){return x%2;});
    // 0 2 4 2
    // a trick for random access we use the iterator
    auto Iterator=L.begin();  //L[1]=5;
    Iterator++;
    *Iterator=5;
    // 0 5 4 2
    L.clear();

    cout << "\n*****************************\n" << endl;
    //Forward List
    cout << "The Forward List" <<endl;
    //single linked list with one pointer for each element each pointer refer to the address after the element
    //high speed with adding and deleting and good with space(storage)
    //we can add and delete with push_front and pop_front from front only there aren't functions like push_back() or pop_back()
    //syntax forward_list<dataType> NameOfForwardList;
    //No Random access fl[] ,fl.at()  fl.front()  fl.back()
    forward_list <int> fl{1,2,3};
    //New Special iterator
    forward_list <int>::iterator iteratorFl;
    iteratorFl=fl.before_begin(); //refer to the place before the first value
    //adding
    fl.push_front(0);
    fl.assign({1,2,3,4}); //fl.assign(numberOfElements,value);
    fl.insert_after(iteratorFl,5);
    fl.emplace_after(iteratorFl,6);
    //6 5 1 2 3 4
    //deleting
    fl.pop_front();
    fl.erase_after(fl.begin());
    fl.remove(4);
    fl.remove_if([](int x){return x%2;});
    // 2
    //another way to output a forward list linking the address with contain
    for(int &i:fl)
    {
        cout << i << " ";
    }
    //accessing to the contain
    //next(fl.begin(),2);  //next(iterator,timesToMove);
    forward_list <int> fl1{1,2},fl2{1,2,3};
    fl.merge(fl1);                            //merging fl1 in fl and destroy fl1
    fl.splice_after(fl.before_begin(),fl2);   //fl.splice_after(fl.begin(),fl2,iteratorInFl2WhereToStartCoping);
    //another functions
    fl.sort();
    fl.sort(greater<int>());
    fl.reverse();
    fl.unique();
    fl.resize(4);
    //fl.swap(fl2);
    cout << fl.max_size() << " " << fl.empty() << endl;
    fl.clear();

    cout << "\n***************************************\n" ;
    //The Pair
    //a Variable that store two variables with different data type
    // syntax pair<firstDataType,SecondDataType> nameOfPair;
    cout << "The Pair" << endl;
    pair <int,string> p;
    //assigning values  There is three different ways
    p={1,"wow"};
    p=make_pair(2,"taj");
    p.first=10;
    p.second="amazing";
    //values (10,"amazing")
    //access
    cout << p.first << " " << p.second << endl;
    //we can use nested pairs like
    pair<string,pair<int,double>>nestedPair("hello",{1,2.1});
    cout << nestedPair.first << " " << nestedPair.second.first << " " << nestedPair.second.first  << endl;
    //The useful thing in using pair is use pair inside a vector
    vector <pair<string,int>> vp;
    vp.push_back(make_pair("taj",1));
    vp.push_back({"najem",2});
    //vp[0].first     vp[0].second
    for(auto ivp=vp.begin();ivp!=vp.end();ivp++)
    {
        cout << ivp->first << " " << ivp->second <<endl;
    }
    cout << "\n*********************************\n" << endl;
    //the tuple
    //syntax tuple<datatype,......datatype>nameOftuple;
    cout << "The tuple" << endl;
    tuple<int,char,string>tup;
    //assigning values we can assign value through the constructor
    tup=make_tuple(1,'3',"hi");
    //access   get<index    0,1,..,n> nameOfTuple
    //calculating size
    cout << tuple_size<decltype(tup)>::value << endl;
    //there is swap function ->  tuple1.swap(tuple2);
    //assigning values of tuple to variables
    int aa;
    char b;
    string c; //without ignore
    tie(aa,b,c)=tup;
    //or if we want to ignore a value we just code like this tie(ignore,b,c)=nameOftuple;
    //merging tuple in tuple
    tuple<int,int,int>tp1(0,1,2),tp2(3,4,5);
    auto tp3=tuple_cat(tp1,tp2);
    //tp3 0,1,2,3,4,5


    cout << "\n***********************************\n";
    //the set       tree container
    //so special container
    //the element always ordered and unique
    //fast in adding and deleting and searching O(log n)
    //there is no random access like set[] ,or set.at()
    //there aren't functions like push_back(),push_front()
    //we can't edit the set it's for read only

    /*      ||      shape of    binary tree
           /  \
          ||   ||
         /  \  / \
        ||  || || ||   */

    //syntax set<dataType> nameOfSet;
    //All the default iterators exist begin(),end(),cbegin(),cend(),rbegin(),rend(),crbegin(),crend()
    //every iterator has two values *it.first is the value,*it.second is boolean value 1 if the element is not exist or 0 if it is exist
    cout << "The Set" << endl;
    set <int> s;  //or to order the elements from bigger to lower we use set<int,greater<int>>s;
    //adding values
    s.insert(1);
    s.emplace(3);
    //to reduce complexity O(log n) -> O(1) we use this way
    auto setIterator=s.begin();
    s.emplace_hint(setIterator,2);
    setIterator=s.emplace_hint(setIterator,3);
    /*      ..
            ..
            ..             */
    s.emplace_hint(s.end(),4);
    //  1 2 3 4
    //deleting
    s.erase(5);
    auto ITERator=s.begin();
    ++++ITERator;                //fixing the place of iterator we can use ++ or -- to infinity
    s.erase(ITERator);
    s.erase(s.find(2),s.find(4));//erasing in range
    //we can define iterator from first value to the last value with fixed iterators called lower_bound and upper_bound
    auto itSlow=s.lower_bound(3);
    auto itSup=s.upper_bound(6);    //then we but them in range s.erase(itSlow,itSup);
    // 1 4
    //other functions;
    cout << s.empty() << " " << s.size() << " " << s.max_size() << endl;
    //we can swap two sets s1.swap(s2)
    //auto compare way to output a set
    auto com=s.key_comp();
    auto SEtIt=s.begin();
    int constant=50;
    /*for( ;com(*SEtIt,constant);SEtIt++)
      {
        cout << *SEtIt << endl;
      }       */
    cout << s.count(5) << endl;            //give one if it's exist and zero if not
    auto functionOfRange=s.equal_range(1); //return two values the same and the bigger than the fist one directly   //access it.first and it.second for pointers
    cout << *functionOfRange.first << " " << *functionOfRange.second << endl;
    s.clear();
    cout << "\n***************************************\n";
    //the mutliset  No Random access so fast depends on binary  tree
    //like the regular set but it store values ordered and duplicates
    //and difference with count(function) it return the number of counts of an value
    //syntax multiset<dataType>nameOfMultiSet;
    cout << "The MultiSet" << endl;
    multiset<int>ms{1,2,3,4,5,2,2,2};
    // 1 2 2 2 2 3 4 5
    cout << ms.count(2) << endl;
    cout << "\n********************************\n" ;
    //the map   depends on binary tree  associative container
    //we use it instead of two arrays
    //every map has two things map{key,value}  the elements be ordered on key not value
    //support random access map[key]=value;
    //syntax map<dataTypeOfKey,dataTypeOfValue> nameOfMap;

    cout << "The Map" << endl;
    map<int,string>mp{{1,"hello"},{2,"world"}};  //map<int,string,greater<int>>mp;
    //assigning values
    mp[1]="taj";
    mp.at(2)="najem";
    for(auto mm:mp)
    {
        cout << mm.first << " " << mm.second << endl;
    }
    for(auto mpIterator=mp.begin();mpIterator!=mp.end();mpIterator++)//in reserve use rbegin and rend
    {
        cout << mpIterator->first << " " << mpIterator->second << endl;
    }
    //adding values
    mp[3]="wow";
    mp.insert({4,"omg"});
    mp.insert(make_pair(5,"tabban"));
    mp.insert(pair<int,string>(6,"tube"));
    //we can use the hint iterator to reduce the complexity
    //m.emplace_hint
    //deleting
    mp.erase(4); //will delete the key and value of the key
    //we can use range in erase function
    //or lower_bound and upper_bound for range
    cout << mp.count(2) << endl;//1 if exist and 0 if not
    cout << mp.empty() << " " << mp.size() << " " << mp.max_size() << endl;
    auto mapRange=mp.equal_range(2);    //the same key and the key bigger with one
    cout << mapRange.first->first << " " << mapRange.second->first << endl;
    //we can use key compare function to output the map
    mp.clear();
    cout << "\n****************************************\n";
    //MultiMap  binary tree
    //we can store duplicates same keys
    //No Random access
    //fast operations O(log n) -> O(1)
    //we can't edit the key
    //and difference with count(function) it return the number of counts of an key
    //syntax multimap<dataTypeOfKey,dataTypeOfValue> nameOfMultiMap;

    cout << "The MultiMap" <<endl;
    multimap<int,string>mump{{1,"wow"},{1,"omg"}};
    cout << mump.count(1) << endl;
    cout << "\n********************************\n" ;
    //unordered set unordered associative container
    //the elements inside it will be ordered using the hash table
    //The hash table depends on a hash function to like a group of elements together that share the same result of hash function
    //Every bucket will store elements through a hash function condition
    //A hash table contain an array of buckets and every bucket contain linked list of entries
    /* hash table shape

    buckets
        # || || || || ||    entries
        # || || || || ||
        # || || || || ||
        # || || || || ||
        # || || || || ||
        # || || || || ||

    */
    //Fastest container (adding,deleting,searching) O(1)
    //ordered element in hash way and not duplicates
    //syntax unordered_set<dataType> nameOfUnorderedSet
    cout << "The Unordered Set" << endl;
    unordered_set<int> us;
    //adding
    us.insert(1);
    us.emplace(2);
    us.emplace_hint(us.begin(),4);
    //operations with buckets and hash table
    cout << us.bucket(2) << endl;         //printing out the number of # for an element
    cout << us.bucket_count() << endl;    //printing out the number of buckets
    cout << us.max_bucket_count() << endl;//max count of bucket that can be exist
    //printing out the hash table or the unordered set
    int NumberOfBuckets=us.bucket_count();
    for(int i=0;i<NumberOfBuckets;i++)
    {
                            //match point               match point
        for(auto iteratorUs=us.begin(i);iteratorUs!=us.end(i);iteratorUs++)
        {
            cout << *iteratorUs << endl;
        }
        cout << endl;
    }
    cout << us.bucket_size(1) << endl;   //printing out the number of elements in a certain bucket
    cout << us.load_factor() << endl;    //proximate value to every bucket how many elements does it store
    cout << us.max_load_factor() << endl;//max number of elements in every bucket
    unordered_set<int>::hasher fn;       //to store the hash table function
    fn=us.hash_function();               //store the value that will store the element depending on it
    cout << fn(1) << endl;
    //deleting
    us.erase(1);   //us.erase(place)    us.erase(Range:-> find(value) ,find(value) )
    //another functions
    //reverse swap
    cout << us.empty() << " " << us.count(1)/*one if exist and zero if not */ << endl;
    //in the worst case all the elements will placed in single bucket then we use
    //us.rehash(numberBigger than hash counts)
    us.rehash(10);
    us.clear();
    cout << "\n*******************************\n" ;
    //unordered multi set
    //same of unordered set but it allow you to get duplicates of an element
    //in addition the count function will return the number of duplicated element
    //syntax unordered_multiset<dataType> nameOfUnordered_multiSet
    cout << "The Unordered MultiSet" << endl;
    unordered_multiset<int> ums;
    ums.clear();
    cout << "\n**********************************\n";
    //unordered map
    //very fast depends on hash table
    //syntax unordered_map <dataTypeOfKey,dataTypeOfValue> nameOfUnordered_map
    //support random access UnorderedMap[key]=value,at()
    //we can't add a key that already exist
    cout << "Unordered Map" << endl;
    unordered_map<int,int> um;//um{{,},{,}};
    //iterator->first   iterator->second
    //assigning
    um.insert(make_pair(1,10));
    um.insert({2,20});
//  um.insert_or_assign({1,20}); //editing value of a key that already exist
    um.emplace(make_pair(3,30));
//  um.emplace_hint()   um.try_emplace()
//  um.extract()        editing value of a key that already exist
    //deleting
    um.erase(1);  //um.erase(range)   um.erase(place)
    //another function
    //swap   merge  um.reverse()
    cout << um.empty() << " " << um.size() << " " << um.max_size() << endl;

    //hashing
    cout << um.bucket(2) << endl;               //return the place of key in which bucket
    cout << um.bucket_count() << endl;          //number of bukets
    //when we are printing out the unordered multi map we use
    /*
    int NumberOfBuckets=us.bucket_count();
    for(int i=0;i<NumberOfBuckets;i++)
    {
                            //match point               match point
        for(auto iteratorUm=um.begin(i);iteratorUm!=um.end(i);iteratorUm++)
        {
            cout << *iteratorUm << endl;
        }
        cout << endl;
    }*/
    cout << um.bucket_size(1) << endl;           //how many elements exist in a certain bucket
    cout << um.max_bucket_count() << endl;       //max number of buckets
    //um.load_factor() -> size/bucket
    //um.max_load_factor()
    //um.find(key);
    //um.rehash();
    um.clear();
    cout << "\n******************************************\n";
    //the unordered multi map
    //we can add more than one unique key
    // No Random Access
    //syntax unordered_multimap<dataTypeOfKey,dataTypeOfValue> nameOfUnorderedMultiMap;
    //count function return number of the counts
    cout << "The Unordered Multi_map" << endl;
    unordered_multimap<int,int>umm;
    umm.clear();

    cout << "\n****************************\n";
    //The Stack     adapter container
    //last in first out LIFO
    //no random access
    //syntax stack<dataType> nameOfStack;
    //in default the stack is built on deque
    //add and delete from top only with O(1)
    //vector list deque
    cout << "The Stack" << endl;
    stack <int> st;
    //add
    st.push(2);
    st.push(2);
    st.push(3);
    st.emplace(3);  // 3 3 2 2
    //delete
    st.pop();       //3 2 2
    cout << st.top() << endl;
    //st1.swap(st2)
    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << "\n******************************\n" ;
    //The queue first in first out
    //deque list
    //syntax queue <dataType> nameOf Queue
    //add delete is O(1)
    cout << "The Queue" << endl;
    queue<int>q;
    //add
    q.push(1);
    q.push(2);
    q.push(3);
    q.emplace(4);
    //delete
    q.pop();
    //access
    cout << q.back() << endl; //last element added
    cout << q.front() << endl;//first element added
    //out put
    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    cout << "\n****************************\n";
    //priority Queue come ordered
    //first in first out but after ordering
    //syntax priority_queue<dataType>name of pq;
    // vector deque
    //add delete O(log n)
    //search for max and min O(1)
    cout << "The priority Queue" << endl;
    priority_queue<int> pq;
    // add
    pq.push(10);
    pq.emplace(20);
    //access
    cout << pq.top() << endl;// return the value with the highest priority
    //delete
    pq.pop();
    //output
    while(pq.size()!=0/*!pq.empty()*/)
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    //when we want to change the priority we must the container that it's built in
    priority_queue<int,vector<int>,greater<int>> changedPQ;//greater -> lower
    cout << "\n************************\n";
    cout << "The End" << endl;

    return 0;
}
