#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int maze[N][N];
int level[N][N];
int dx[]= {0,0,-1,1},dy[]= {1,-1,0,0};
int visited[N][N];
int n,m,a,b;
int parent[N][N];
int mons_level[N][N];
int mons_visited[N][N];
deque<char>r;
char c[]= {'R','L','U','D'};
bool path()
{
    for(int i=0; i<m; i++)
    {
        if(visited[0][i]==1&&(level[0][i]<mons_level[0][i]||mons_level[0][i]==-1))
        {
            a=0;
            b=i;
            return true;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(visited[i][0]==1&&(level[i][0]<mons_level[i][0]||mons_level[i][0]==-1))
        {
            a=i;
            b=0;
            return true;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(visited[i][m-1]==1&&(level[i][m-1]<mons_level[i][m-1]||mons_level[i][m-1]==-1))
        {
            a=i;
            b=m-1;
            return true;
        }
    }
    for(int i=0; i<m-1; i++)
    {
        if(visited[n-1][i]==1&&(level[n-1][i]<mons_level[n-1][i]||mons_level[n-1][i]==-1))
        {
            a=n-1;
            b=i;
            return true;
        }
    }
    return false;
}
bool is_inside(pair<int,int>coord)
{
    int x=coord.first;
    int y=coord.second;
    if(x>=0&&x<n && y>=0 && y<m)
    {
        return true;
    }
    return false;
}
bool is_safe(pair<int,int>coord)
{
    int x=coord.first;
    int y=coord.second;
    if(maze[x][y]==-1)
    {
        return false;
    }
    return true;
}
void monster(pair<int,int>coord)
{
    int x=coord.first;
    int y=coord.second;
    mons_level[x][y]=0;
    queue<pair<int,int>>q;
    q.push(coord);
    while(!q.empty())
    {
        pair<int,int>head=q.front();
        q.pop();
        int x=head.first,y=head.second;
        for(int i=0; i<4; i++)
        {
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            pair<int,int>adj_node= {new_x,new_y};
            if(is_inside(adj_node)&&is_safe(adj_node)&&mons_visited[new_x][new_y]==0 &&level[new_x][new_y]!=0)
            {
                mons_visited[new_x][new_y]=1;
                if(mons_level[new_x][new_y]==-1)
                {
                    mons_level[new_x][new_y]=mons_level[x][y]+1;
                }
                else
                {
                    mons_level[new_x][new_y]=min(mons_level[new_x][new_y],mons_level[x][y]+1);
                }
                q.push(adj_node);
            }
        }
    }
    //memset(mons_visited,0,sizeof(mons_visited));
}
void BFS(pair<int,int>src)
{
    queue<pair<int,int>>q;
    visited[src.first][src.second]=1;
    level[src.first][src.second]=0;
    parent[src.first][src.second]=0;
    q.push(src);
    while(!q.empty())
    {
        pair<int,int>head=q.front();
        q.pop();
        int x=head.first,y=head.second;
        for(int i=0; i<4; i++)
        {
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            pair<int,int>adj_node= {new_x,new_y};
            if(is_inside(adj_node) && is_safe(adj_node) && visited[new_x][new_y]==0)
            {
                visited[new_x][new_y]=1;
                level[new_x][new_y]=level[x][y]+1;
                parent[new_x][new_y]=i;
                q.push(adj_node);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    pair<int,int>src,dst;
    memset(level,-1,sizeof(level));
    memset(visited,0,sizeof(visited));
    memset(mons_visited,0,sizeof(mons_visited));
    memset(mons_level,-1,sizeof(mons_level));
    set<pair<int,int>>st;
    for(int i=0; i<n; i++)
    {
        string input;
        cin>>input;
        for(int j=0; j<m; j++)
        {
            if(input[j]=='#')
            {
                maze[i][j]=-1;
            }
            else if(input[j]=='M')
            {
                mons_level[i][j]=0;
                maze[i][j]=-1;
                st.insert({i,j});
            }
            else if(input[j]=='A')
            {
                src= {i,j};
                level[i][j]=0;
            }
        }
    }
    for(auto i:st)
    {
        monster({i.first,i.second});
    }
    BFS(src);
    if(!path())
    {
        cout<<"NO\n";
        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<mons_level[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return 0;
    }
    cout<<"YES\n";
    dst.first=a;
    dst.second=b;
    cout<<level[a][b]<<endl;
    //cout<<mons_level[a][b]<<endl;
    while(1)
    {
        int d=parent[dst.first][dst.second];
        if(src==dst)
        {
            break;
        }
        r.push_front(c[d]);
        dst.first-=dx[d];
        dst.second-=dy[d];
    }
    for(auto i:r)
    {
        cout<<i;
    }
}
