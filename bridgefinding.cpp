
/*
https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/fix-the-roads/
*/
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
typedef unsigned long long int  ull;
typedef long long int  ll;
#define FR freopen("input.txt", "r", stdin);
#define FW freopen("output.txt", "w", stdout);
#define SETPRES  std::setprecision(6),std::fixed;
#define pb push_back
#define mp make_pair
#define INF 10000000
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define  Help_me  ios_base::sync_with_stdio(false);
template <class T1>
T1 GCD(T1 A,T1 B)
{
if(B==0)
return A;
else
return GCD(B,A%B);
}
template <class T2>
   T2 mulmod(T2 a,T2 b)  {T2 x=0,y=a%mod;while(b){
       if(b%2==1){x=(x+y)%mod;}
       y=(2*y)%mod;b=b/2;}return x%mod;}
template<class T3>
   T3 power(T3 a,T3 b){T3 x=1,y=a%mod;while(b){if(b%2==1){x=mulmod(x,y)%mod;}y=mulmod(y,y)%mod;b=b/2;}return x%mod;}
template<class T4>
bool cmp(T4 x,T4 y)
{
  return x>y?1:0;
}
vector<vector<int> > adj;
vector<int> vis;
vector<int> arr,low;
set<pair<int,int> > bridge;
int n,m;
int tt=0;
int ans=0;
//here bridge is used to store all the bridges in the graph
void dfs(int u,int p)
{
	vis[u]=1;
	arr[u]=low[u]=tt++;

	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==p)
			continue;
		if(vis[v])
		{
			low[u]=min(low[u],arr[v]);
		}
		else 
		{
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>arr[u])
				bridge.insert(mp(min(v,u),max(v,u)));


		}
	}
	
}
int dfs2(int u,int p)
{
	vis[u]=1;
	int d1,d2;
	d1=d2=0;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(!vis[v])
		{
			d2=dfs2(v,u);
			if(d2>d1)
				swap(d1,d2);

			if(bridge.find(make_pair(min(v,u),max(v,u)))!=bridge.end());
			d1++;

		}
		ans=max(ans,d1+d2);
		return d1;
	}

}
int main()
{
Help_me

  cin>>n>>m;
  adj.resize(n+1,vector<int>(0));
vis.resize(n+1,0);
arr.resize(n+1,0);
low.resize(n+1,0);
int x,y;
for(int i=1;i<=m;i++)
 {   	
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);
}

dfs(1,0);
vis.resize(0);
vis.resize(n+1,0);
dfs2(1,0);
cout<<bridge.size()-ans;
    return 0;

    

}
