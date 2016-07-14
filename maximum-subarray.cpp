/*----------------------------_Dynamic Programing................
Question:given an array of n elements.find the subarray which have maximum sum
Time Complexity:O(n)
Space Complexity:O(n)
Note: can be solved using Divide and conquer.But complexity will be O(nlogn)
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
int pre[100001],mn[100001];
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
    int t;/number of test cases
    cin>>t;
    while(t--) {
        
        int n;//number of elements in the array
        cin>>n;
        int ns1=-1000000000;
        int sum=-1;
        int x;
        pre[0]=0;
        mn[0]=1000000000;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            pre[i]=x+pre[i-1];//calculating prefix sum
            calculating minimum prefix from 1 to i
            if(pre[i]<mn[i-1])
                mn[i]=pre[i];
            else
                mn[i]=mn[i-1];
        }
        int ns=-100000000;
        for(int i=1;i<=n;i++)
        {
            ns=max(ns,max(pre[i]-mn[i-1],pre[i]));//maximum subarray for upto index i will be maximum of pre[i] and pre[i]-min[i-1]
        }
        
        
            cout<<ns<<endl;
    }
    #ifndef LOCAL_TEST
        cout << "[Finished in " << clock() - start << " ms]" << endl;
    #endif
    
return 0;
    }
