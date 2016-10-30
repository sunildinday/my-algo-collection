/*
[Problem Link](http://codeforces.com/problemset/problem/721/C)
*/

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int  ull;
typedef long long int  ll;
#define FR freopen("input.txt", "r", stdin);
#define FW freopen("output.txt", "w", stdout);
#define SETPRES  std::setprecision(6),std::fixed;
#define pb push_back
#define mp make_pair
#define INF 1000000001
#define mod 1000000007
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
int dp[5001][5001];
int print[5001][5001];
int n,m;
std::vector<pair<int,int> > adj[5001];
int solve(int i,int j)
{
if(j<=0)
    return INF;
if(dp[i][j]!=-1)
    return dp[i][j];
dp[i][j]=INF;
for(int k=0;k<adj[i].size();k++)
{
    int temp=adj[i][k] .second+solve(adj[i][k].first,j-1);
    if(dp[i][j]>=temp)
    {
dp[i][j]=temp;
print[i][j]=adj[i][k].first;
}
}
return dp[i][j];
}

void  dfs(int ro,int co)
{
if(ro==1)
{
    return ;
}
else
{
    dfs(print[ro][co],co-1);
cout<<print[ro][co]<<" ";
}
}
int main()
{
Help_me
#ifndef ONLINE_JUDGE
    //string s="646";
    //stringstream(s)>>number;
    FR
//    FW
    #endif
int t;
    cin>>n>>m>>t;
    memset(dp,-1,sizeof(dp));
int x,y,z;
for(int i=0;i<m;i++)
{
cin>>x>>y>>z;
adj[y].push_back(mp(x,z));
}
dp[1][1]=0;
for(int j=1;j<=n;j++)
{
dp[n][j]=INF;
for(int i=0;i<adj[n].size();i++)
{
    int temp=adj[n][i].second+solve(adj[n][i].first,j-1);
if(dp[n][j]>=temp)
{
    dp[n][j]=temp;
print[n][j]=adj[n][i].first;
}
}
}
int ans=0;
int idx;
for(int i=1;i<=n;i++)
{
if(dp[n][i]<=t)
{
    ans=max(ans,i);
idx=i;
}
}

cout<<ans<<endl;
dfs(print[n][idx],idx-1);
cout<<print[n][idx]<<" ";
cout<<n<<" ";

    return 0;

}
