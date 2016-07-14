/*----------------------------__Dynamic Programming-------------
Question:How many different ways can you make change for an amount, given a list of coins?
Note:we can use a coin infinite amount of time and order does not matter. For Example:{1,2} and {2,1} will be considered as same way
Time Complexity:O(n*m)
Space Complexity:O(n*m)
Solutions:make a table  dp[][] where dp[i][j] means number of ways to exchange coin i by considering all the coins from cost[1] to cost[j] as the last element
Problem Link: https://www.hackerrank.com/challenges/coin-change
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
int  dp[252][51];
int cost[51];//cost of each coin
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
    
   
        int n,m;
        cin>>n>>m;//value of coins and m is integer that represent list of distinct coins that are available in infinite amount.
    for(int i=1;i<=m;i++)
        cin>>cost[i];
    dp[0][0]=1;
    for(int i=1;i<=m;i++)
        dp[0][i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(cost[j]>i)
                dp[i][j]=dp[i][j-1];
            else
            {
                dp[i][j]=dp[i-cost[j]][j]+dp[i][j-1];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    cout<<dp[n][m];
    
    #ifndef LOCAL_TEST
        cout << "[Finished in " << clock() - start << " ms]" << endl;
    #endif
    
return 0;
    }
