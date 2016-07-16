/*--------------------------Belleman-Ford (Shortest Path)-----------------
Note :can be used on edges with negative weight and can be used to detect cycle with negative weight(Total weight)
Complexity:O(n*m)

*/
                #include <bits/stdc++.h>
                #include<vector>
                #include<map>
                #include<set>
                #include<algorithm>
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
typedef unsigned long long int  ull;
typedef long long int  ll;
#define SETPRES  std::setprecision(6),std::fixed;
#define pb push_back
#define mp make_pair
#define FR freopen("input.txt", "r", stdin);
#define FW freopen("output.txt", "w", stdout);
#define  Help_me  ios_base::sync_with_stdio(false);
#define  lg(x)  ceil(log2(x))
#define MX 12345679
#define mod 1000000007
const int inf=100000005;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
std::vector<pair<int,int> > adj[100];//adjancy list for the graph
int dis[101];
int main()
{
    Help_me
    int start = clock();
    #ifndef ONLINE_JUDGE
    //int number
    //string s="646";
    //stringstream s1(s);
    //s1>>number
    //stringstream convert;
    //convert>>numbere;
    //convert<<s
    //getline(cin>>ws,s);
//  FR
//  FW
    #endif
int n;//number of vertex in graph numbered from 1 to n
int m;//number of edges in graph
cin>>n>>m;
int u,v,cost;//cost is weight of the  directed edge from u to v
for(int i=0;i<m;i++)
{
    cin>>u>>v>>cost;
    adj[u].push_back(make_pair(v,cost));
}
for(int i=1;i<=n;i++)
    dis[i]=inf;
//taking node 1 as the source node
dis[1]=0;
for(int i=1;i<n;i++)
{
    for( u=1;u<=n;u++)
    {
        for(int k=0;k<adj[u].size();k++)
        {
            v=adj[u][k].first;
            cost=adj[u][k].second;
            //relaxing the directed edge from u to v
            if(dis[v]>dis[u]+cost)
                dis[v]=dis[u]+cost;
        }
    }
}
//checking for negative weight cycle
for( u=1;u<=n;u++)
    {
        for(int k=0;k<adj[u].size();k++)
        {
            v=adj[u][k].first;
            cost=adj[u][k].second;
            //relaxing the directed edge from u to v
            if(dis[v]>dis[u]+cost)
                {
                    cout<<"Yes cycle with negative weight exist;"
                    return 0;
                }
        }
    }
for(int i=2;i<=n;i++)
    cout<<dis[i]<<" ";//shortest distance of every node from source vertex 1
return 0;
    }
