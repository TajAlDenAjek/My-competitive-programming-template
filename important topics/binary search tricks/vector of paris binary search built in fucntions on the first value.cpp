#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct comp_pair_int
{
    bool operator()(const pair<int,int> &a, const int & b)
    {
        return (a.first < b);
    }
    bool operator()(const int & a,const pair<int,int> &b)
    {
        return (a < b.first);
    }
};

int main(void)
{
    vector<pair<int,int>> data;
    data.push_back(make_pair(1,7));
    data.push_back(make_pair(5,5));
    data.push_back(make_pair(2,7));
    data.push_back(make_pair(6,7));
    data.push_back(make_pair(9,6));
    data.push_back(make_pair(2,4));
    data.push_back(make_pair(2,8));
    sort(data.begin(),data.end());
    int key=9;
    if(binary_search(data.begin(),data.end(), key,comp_pair_int()))
    {
        cout<<"Key found"<<endl;
    }
    else
    {
        cout<<"Key is not found"<<endl;
    }
}



https://stackoverflow.com/questions/55392781/how-to-use-lower-bound-on-set-of-pairs