#include<bits/stdc++.h>
#define INF 10000000
#define  Help_me  ios_base::sync_with_stdio(false);
using namespace std;
std::vector<int> adj[500];
int pr[500];//for parents
int color[500];//white=0=unvisited gray=1=visited but not finished, black=2=finished
void printcycle(int strt,int stop)
{
    int current=strt;
    cout<<strt<<" ";
    while(current!=stop)
    {
        cout<<pr[current]<<" ";
        current=pr[current];
    }
    cout<<endl;
}
void dfs(int u,int p)
{
    color[u]=1;//gray color
    for(int i=0;i<adj[u].size();i++)
    {
        if(color[adj[u][i]]==0)
        {
            pr[adj[u][i]]=u;
            dfs(adj[u][i],u);
        }
        else if(color[adj[u][i]]==1)
        {
            printcycle(u,adj[u][i]);
        }
    }
    color[u]=2;//black color
}
int main()
{
Help_me
int x;
int n;//number of nodes
cin>>n;
for(int i=1;i<=n;i++)
{
    int child;
    cin>>child;//enter number of childes for node i
    for(int j=1;j<=child;j++)
    {
        cin>>x;//enter child number(node) for parent i
        adj[i].push_back(x);
    }
}
dfs(1,0);
    return 0;


}
