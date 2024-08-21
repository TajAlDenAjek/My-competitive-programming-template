vector<pair<ll,ll>> ans;
void TowerOfHanoi(ll disks,ll from,ll to,ll help)
{
    if(disks==0)
        return ;
    TowerOfHanoi(disks-1,from,help,to);
    ans.push_back({from,to});
    TowerOfHanoi(disks-1,help,to,from);
    return ;
}