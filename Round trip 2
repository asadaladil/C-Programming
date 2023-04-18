#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N];
int visited[N];
vector<int>adj_list[N];
vector<int>path;
int a;
bool DFS(int node)
{
    visited[node]=1;
    path.push_back(node);
    for(int adj_node:adj_list[node])
    {
        if(visited[adj_node]==0)
        {
            parent[adj_node]=node;
            bool run=DFS(adj_node);
 
            if(run)
            {
                return true;
            }
        }
        else if(visited[adj_node]==1)
        {
            parent[adj_node]=node;
            a=node;
            return true;
        }
    }
    visited[node]=2;
    return false;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
    }
    memset(parent,0,sizeof(parent));
    bool run;
    for(int i=1;i<=n;i++)
    {
        run=DFS(i);
        if(run)
        {
            //cout<<"cycle exist";
            break;
        }
    }
    if(!run)
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    int p=a;
    deque<int>d;
    d.push_back(p);
    p=parent[p];
    while(p!=a)
    {
        d.push_front(p);
        p=parent[p];
    }
    d.push_front(a);
    cout<<d.size()<<endl;
    //reverse(d.begin(),d.end());
    for(auto i:d)
    {
        cout<<i<<" ";
    }
}
