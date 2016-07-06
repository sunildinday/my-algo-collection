/*-----------------------------------Dynamic Programming*************** Independent set in array----------------------------------------------------------------
 Given a tree T of N nodes, where each node i has Ci coins attached with it. 
 You have to choose a subset of nodes such that no two adjacent nodes are chosen and sum of coins attached with nodes in chosen subset is maximum.
*/
#include<iostream>
#include<vector>
using namespace std;
int val[101];
int dp1[101],dp2[101];
std::vector<int> adj[101];
void dfs(int V,int pV)
{
	int sum1,sum2=0;
	for (auto v:adj[V])
	{
		if(v==pV)
			continue;
		dfs(v,V);
		sum1+=dp2[v];
		sum2+=max(dp1[v],dp2[v]);
	}
	dp1[V]=val[V]+sum1;
	dp2[V]=sum2;
}
int main()
{
	    int n,v,u;
    cin >> n;
 
    for(int i=1; i<n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(1, 0);
    int ans = max(dp1[1], dp2[1]);
    cout << ans << endl;
	return 0;
}
