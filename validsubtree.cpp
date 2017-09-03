/*
to calculate number of tree in a given tree
*/
ll dp_include[N]; //dp_include[v] := number of subgraphs of v's subtree in a rooted tree containing v
ll dp_exclude[N]; //dp_exclude[v] := number of subgraphs of v's subtree in a rooted tree NOT containing v


void dfs(int v,int p)
{
dp_include[v]=1;
dp_exclude[v]=0;
for(int i=0;i<adj[v].size();i++)
{
int u=adj[u][i];
if(u==p)
continue;
dfs(u,v);
dp_include[v]*=(1+dp_include[u]);
dp_exclude[v]+=dp_include[u]+d_exclude[u];

}
}
