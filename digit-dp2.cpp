/*
Problem Link:http://www.spoj.com/problems/NY10E/
*/
#include<bits/stdc++.h>
using namespace std;
long long int dp[65][10];
std::vector<int> digit;
long long int digitdp(int idx,int tight,int lastdigit)
{
if(idx==-1)
{
    return 1;
}
if(!tight&&dp[idx][lastdigit]!=-1)
    return dp[idx][lastdigit];
int newdigit;
if(tight)
    newdigit=digit[idx];
else
    newdigit=9;
long long int ans=0;
for(int d=0;d<=newdigit;d++)
{
if(d>=lastdigit)
ans+=digitdp(idx-1,tight&&(d==newdigit),d);
}
if(!tight)
dp[idx][lastdigit]=ans;
return ans;
}
long long int solve(long long int num)
{
digit.clear();

    while(num)
    {
        digit.push_back(9);
        num--;
    }
    return digitdp(digit.size()-1,1,0);


}
int main()
{
    long long int a,b;

int p;
cin>>p;
while(p--)
{
    cin>>b>>a;

    memset(dp,-1,sizeof(dp));
    cout<<b<<" "<<solve(a)<<endl;
  }
    return 0;
}
