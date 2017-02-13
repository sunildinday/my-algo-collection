#include<bits/stdc++.h>
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
int trie[500500][27];
int nxt=1;
bool leaf[500500];
void build(string s)
{
    int v=0;
    for(int i=0;i<s.size();i++)
    {
        int key=s[i]-'a';
        if(trie[v][key]==-1)
            trie[v][key]=nxt++;
        v=trie[v][key];
    }
    leaf[v]=true;
}
bool search(string s)
{
    int v=0;
for(int i=0;i<s.size();i++)
{
    int key=s[i]-'a';
    if(trie[v][key]==-1)
        return false;
    v=trie[v][key];
}
return leaf[v];
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
    string s;
    int n;
    memset(trie,-1,sizeof(trie));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        build(s);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
{
    cin>>s;
    cout<<search(s)<<endl;
}

    return 0;

}
